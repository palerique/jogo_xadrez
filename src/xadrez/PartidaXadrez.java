package xadrez;

import java.security.InvalidParameterException;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

import pecas.Bispo;
import pecas.Cavalo;
import pecas.Peao;
import pecas.Rainha;
import pecas.Rei;
import pecas.Torre;
import tabuleiro.Tabuleiro;
import tabuleiro.Peca;
import tabuleiro.Posicao;

public class PartidaXadrez {

	private int turn;
	private Cor currentPlayer;
	private Tabuleiro board;
	private boolean check;  
	private boolean checkMate;
	private PecaXadrez enPassantVulnerable;
	private PecaXadrez promoted; 
	
	private List<Peca> piecesOnTheBoard = new ArrayList<>();
	private List<Peca> capturedPieces = new ArrayList<>();
	
	public PartidaXadrez() {
		board = new Tabuleiro(8, 8);
		turn = 1;
		currentPlayer = Cor.WHITE;
		initialSetup();
	}
	
	public int getTurn() {
		return turn;
	}
	
	public Cor getCurrentPlayer() {
		return currentPlayer;
	}
	
	public void setCurrentPlayer(Cor currentPlayer) {
		this.currentPlayer=currentPlayer;
	}
	
	public boolean getCheck() {
		return check;
	}
	
	public boolean getCheckMate() {
		return checkMate;
	}
	
	public PecaXadrez getEnPassantVulnerable() {
		return enPassantVulnerable;
	}
	
	public PecaXadrez getPromoted() {
		return promoted;
	}
	
	public PecaXadrez[][] getPieces() {
		PecaXadrez[][] mat = new PecaXadrez[board.getRows()][board.getColumns()];
		for (int i=0; i<board.getRows(); i++) {
			for (int j=0; j<board.getColumns(); j++) {
				mat[i][j] = (PecaXadrez) board.piece(i, j);
			}
		}
		return mat;
	}
	
	public boolean[][] possibleMoves(PosicaoXadrez sourcePosition) {
		Posicao position = sourcePosition.toPosition();
		validateSourcePosition(position);
		return board.piece(position).possibleMoves();
	}
	
	public PecaXadrez performChessMove(PosicaoXadrez sourcePosition, PosicaoXadrez targetPosition) {
		Posicao source = sourcePosition.toPosition();
		Posicao target = targetPosition.toPosition();
		validateSourcePosition(source);
		validateTargetPosition(source, target);
		Peca capturedPiece = makeMove(source, target);
		
		if (testCheck(currentPlayer)) {
			undoMove(source, target, capturedPiece);
			throw new XadrezException("Você não pode se colocar em xeque");
		}
		
		PecaXadrez movedPiece = (PecaXadrez)board.piece(target);
		
		// #specialmove promotion
		promoted = null;
		if (movedPiece instanceof Peao) {
			if ((movedPiece.getColor() == Cor.WHITE && target.getLinha() == 0) || (movedPiece.getColor() == Cor.BLACK && target.getLinha() == 7)) {
				promoted = (PecaXadrez)board.piece(target);
				promoted = replacePromotedPiece("Q");
			}
		}
		
		check = (testCheck(opponent(currentPlayer))) ? true : false;

		if (testCheckMate(opponent(currentPlayer))) {
			checkMate = true;
		}
		else {
			nextTurn();
		}
		
		// #specialmove en passant
		if (movedPiece instanceof Peao && (target.getLinha() == source.getLinha() - 2 || target.getLinha() == source.getLinha() + 2)) {
			enPassantVulnerable = movedPiece;
		}
		else {
			enPassantVulnerable = null;
		}
		
		return (PecaXadrez)capturedPiece;
	}

	public PecaXadrez replacePromotedPiece(String type) {
		if (promoted == null) {
			throw new IllegalStateException("Não há peça a ser promovida");
		}
		if (!type.equals("B") && !type.equals("N") && !type.equals("R") & !type.equals("Q")) {
			throw new InvalidParameterException("Tipo inválido para promoção");
		}
		
		Posicao pos = promoted.getChessPosition().toPosition();
		Peca p = board.removePiece(pos);
		piecesOnTheBoard.remove(p);
		
		PecaXadrez newPiece = newPiece(type, promoted.getColor());
		board.placePiece(newPiece, pos);
		piecesOnTheBoard.add(newPiece);
		
		return newPiece;
	}
	
	private PecaXadrez newPiece(String type, Cor color) {
		if (type.equals("B")) return new Bispo(board, color);
		if (type.equals("N")) return new Cavalo(board, color);
		if (type.equals("Q")) return new Rainha(board, color);
		return new Torre(board, color);
	}
	
	private Peca makeMove(Posicao source, Posicao target) {
		PecaXadrez p = (PecaXadrez)board.removePiece(source);
		p.increaseMoveCount();
		Peca capturedPiece = board.removePiece(target);
		board.placePiece(p, target);
		
		if (capturedPiece != null) {
			piecesOnTheBoard.remove(capturedPiece);
			capturedPieces.add(capturedPiece);
		}
		
		// #specialmove castling kingside rook
		if (p instanceof Rei && target.getColuna() == source.getColuna() + 2) {
			Posicao sourceT = new Posicao(source.getLinha(), source.getColuna() + 3);
			Posicao targetT = new Posicao(source.getLinha(), source.getColuna() + 1);
			PecaXadrez rook = (PecaXadrez)board.removePiece(sourceT);
			board.placePiece(rook, targetT);
			rook.increaseMoveCount();
		}

		// #specialmove castling queenside rook
		if (p instanceof Rei && target.getColuna() == source.getColuna() - 2) {
			Posicao sourceT = new Posicao(source.getLinha(), source.getColuna() - 4);
			Posicao targetT = new Posicao(source.getLinha(), source.getColuna() - 1);
			PecaXadrez rook = (PecaXadrez)board.removePiece(sourceT);
			board.placePiece(rook, targetT);
			rook.increaseMoveCount();
		}		
		
		// #specialmove en passant
		if (p instanceof Peao) {
			if (source.getColuna() != target.getColuna() && capturedPiece == null) {
				Posicao pawnPosition;
				if (p.getColor() == Cor.WHITE) {
					pawnPosition = new Posicao(target.getLinha() + 1, target.getColuna());
				}
				else {
					pawnPosition = new Posicao(target.getLinha() - 1, target.getColuna());
				}
				capturedPiece = board.removePiece(pawnPosition);
				capturedPieces.add(capturedPiece);
				piecesOnTheBoard.remove(capturedPiece);
			}
		}
		
		return capturedPiece;
	}
	
	private void undoMove(Posicao source, Posicao target, Peca capturedPiece) {
		PecaXadrez p = (PecaXadrez)board.removePiece(target);
		p.decreaseMoveCount();
		board.placePiece(p, source);
		
		if (capturedPiece != null) {
			board.placePiece(capturedPiece, target);
			capturedPieces.remove(capturedPiece);
			piecesOnTheBoard.add(capturedPiece);
		}

		// #specialmove castling kingside rook
		if (p instanceof Rei && target.getColuna() == source.getColuna() + 2) {
			Posicao sourceT = new Posicao(source.getLinha(), source.getColuna() + 3);
			Posicao targetT = new Posicao(source.getLinha(), source.getColuna() + 1);
			PecaXadrez rook = (PecaXadrez)board.removePiece(targetT);
			board.placePiece(rook, sourceT);
			rook.decreaseMoveCount();
		}

		// #specialmove castling queenside rook
		if (p instanceof Rei && target.getColuna() == source.getColuna() - 2) {
			Posicao sourceT = new Posicao(source.getLinha(), source.getColuna() - 4);
			Posicao targetT = new Posicao(source.getLinha(), source.getColuna() - 1);
			PecaXadrez rook = (PecaXadrez)board.removePiece(targetT);
			board.placePiece(rook, sourceT);
			rook.decreaseMoveCount();
		}
		
		// #specialmove en passant
		if (p instanceof Peao) {
			if (source.getColuna() != target.getColuna() && capturedPiece == enPassantVulnerable) {
				PecaXadrez pawn = (PecaXadrez)board.removePiece(target);
				Posicao pawnPosition;
				if (p.getColor() == Cor.WHITE) {
					pawnPosition = new Posicao(3, target.getColuna());
				}
				else {
					pawnPosition = new Posicao(4, target.getColuna());
				}
				board.placePiece(pawn, pawnPosition);
			}
		}
	}
	
	private void validateSourcePosition(Posicao position) {
		if (!board.thereIsAPiece(position)) {
			throw new XadrezException("Não há nenhuma peça na posição de origem");
		}
		if (currentPlayer != ((PecaXadrez)board.piece(position)).getColor()) {
			//throw new XadrezException("A peça escolhida não é sua");
		}
		if (!board.piece(position).isThereAnyPossibleMove()) {
			throw new XadrezException("Não há movimentos possíveis para a peça escolhida");
		}
	}
	
	private void validateTargetPosition(Posicao source, Posicao target) {
		if (!board.piece(source).possibleMove(target)) {
			throw new XadrezException("A peça escolhida não pode se mover para a posição alvo");
		}
	}
	
	private void nextTurn() {
		turn++;
		currentPlayer = (currentPlayer == Cor.WHITE) ? Cor.BLACK : Cor.WHITE;
	}
	
	private Cor opponent(Cor color) {
		return (color == Cor.WHITE) ? Cor.BLACK : Cor.WHITE;
	}
	
	private PecaXadrez king(Cor color) {
		List<Peca> list = piecesOnTheBoard.stream().filter(x -> ((PecaXadrez)x).getColor() == color).collect(Collectors.toList());
		for (Peca p : list) {
			if (p instanceof Rei) {
				return (PecaXadrez)p;
			}
		}
		throw new IllegalStateException("There is no " + color + " king on the board");
	}
	
	private boolean testCheck(Cor color) {
		Posicao kingPosition = king(color).getChessPosition().toPosition();
		List<Peca> opponentPieces = piecesOnTheBoard.stream().filter(x -> ((PecaXadrez)x).getColor() == opponent(color)).collect(Collectors.toList());
		for (Peca p : opponentPieces) {
			boolean[][] mat = p.possibleMoves();
			if (mat[kingPosition.getLinha()][kingPosition.getColuna()]) {
				return true;
			}
		}
		return false;
	}
	
	private boolean testCheckMate(Cor color) {
		if (!testCheck(color)) {
			return false;
		}
		List<Peca> list = piecesOnTheBoard.stream().filter(x -> ((PecaXadrez)x).getColor() == color).collect(Collectors.toList());
		for (Peca p : list) {
			boolean[][] mat = p.possibleMoves();
			for (int i=0; i<board.getRows(); i++) {
				for (int j=0; j<board.getColumns(); j++) {
					if (mat[i][j]) {
						Posicao source = ((PecaXadrez)p).getChessPosition().toPosition();
						Posicao target = new Posicao(i, j);
						Peca capturedPiece = makeMove(source, target);
						boolean testCheck = testCheck(color);
						undoMove(source, target, capturedPiece);
						if (!testCheck) {
							return false;
						}
					}
				}
			}
		}
		return true;
	}	
	
	private void placeNewPiece(char column, int row, PecaXadrez piece) {
		board.placePiece(piece, new PosicaoXadrez(column, row).toPosition());
		piecesOnTheBoard.add(piece);
	}
	
	private void initialSetup() {
        placeNewPiece('a', 1, new Torre(board, Cor.WHITE));
        placeNewPiece('b', 1, new Cavalo(board, Cor.WHITE));
        placeNewPiece('c', 1, new Bispo(board, Cor.WHITE));
        placeNewPiece('d', 1, new Rainha(board, Cor.WHITE));
        placeNewPiece('e', 1, new Rei(board, Cor.WHITE, this));
        placeNewPiece('f', 1, new Bispo(board, Cor.WHITE));
        placeNewPiece('g', 1, new Cavalo(board, Cor.WHITE));
        placeNewPiece('h', 1, new Torre(board, Cor.WHITE));
        placeNewPiece('a', 2, new Peao(board, Cor.WHITE, this));
        placeNewPiece('b', 2, new Peao(board, Cor.WHITE, this));
        placeNewPiece('c', 2, new Peao(board, Cor.WHITE, this));
        placeNewPiece('d', 2, new Peao(board, Cor.WHITE, this));
        placeNewPiece('e', 2, new Peao(board, Cor.WHITE, this));
        placeNewPiece('f', 2, new Peao(board, Cor.WHITE, this));
        placeNewPiece('g', 2, new Peao(board, Cor.WHITE, this));
        placeNewPiece('h', 2, new Peao(board, Cor.WHITE, this));

        placeNewPiece('a', 8, new Torre(board, Cor.BLACK));
        placeNewPiece('b', 8, new Cavalo(board, Cor.BLACK));
        placeNewPiece('c', 8, new Bispo(board, Cor.BLACK));
        placeNewPiece('d', 8, new Rainha(board, Cor.BLACK));
        placeNewPiece('e', 8, new Rei(board, Cor.BLACK, this));
        placeNewPiece('f', 8, new Bispo(board, Cor.BLACK));
        placeNewPiece('g', 8, new Cavalo(board, Cor.BLACK));
        placeNewPiece('h', 8, new Torre(board, Cor.BLACK));
        placeNewPiece('a', 7, new Peao(board, Cor.BLACK, this));
        placeNewPiece('b', 7, new Peao(board, Cor.BLACK, this));
        placeNewPiece('c', 7, new Peao(board, Cor.BLACK, this));
        placeNewPiece('d', 7, new Peao(board, Cor.BLACK, this));
        placeNewPiece('e', 7, new Peao(board, Cor.BLACK, this));
        placeNewPiece('f', 7, new Peao(board, Cor.BLACK, this));
        placeNewPiece('g', 7, new Peao(board, Cor.BLACK, this));
        placeNewPiece('h', 7, new Peao(board, Cor.BLACK, this));
	}
}
