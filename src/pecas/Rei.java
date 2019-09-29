package pecas;

import tabuleiro.Tabuleiro;
import tabuleiro.Posicao;
import xadrez.PartidaXadrez;
import xadrez.Cor;
import xadrez.PecaXadrez;

public class Rei extends PecaXadrez {

	private PartidaXadrez chessMatch;
	
	public Rei(Tabuleiro board, Cor color, PartidaXadrez chessMatch) {
		super(board, color);
		this.chessMatch = chessMatch;
	}

	@Override
	public String toString() {
		return "K";
	}

	private boolean canMove(Posicao position) {
		PecaXadrez p = (PecaXadrez)getBoard().piece(position);
		return p == null || p.getColor() != getColor();
	}
	
	private boolean testRookCastling(Posicao position) {
		PecaXadrez p = (PecaXadrez)getBoard().piece(position);
		return p != null && p instanceof Torre && p.getColor() == getColor() && p.getMoveCount() == 0;
	}
	
	@Override
	public boolean[][] possibleMoves() {
		boolean[][] mat = new boolean[getBoard().getRows()][getBoard().getColumns()];
		
		Posicao p = new Posicao(0, 0);
		
		// above
		p.setValues(position.getLinha() - 1, position.getColuna());
		if (getBoard().positionExists(p) && canMove(p)) {
			mat[p.getLinha()][p.getColuna()] = true;
		}

		// below
		p.setValues(position.getLinha() + 1, position.getColuna());
		if (getBoard().positionExists(p) && canMove(p)) {
			mat[p.getLinha()][p.getColuna()] = true;
		}

		// left
		p.setValues(position.getLinha(), position.getColuna() - 1);
		if (getBoard().positionExists(p) && canMove(p)) {
			mat[p.getLinha()][p.getColuna()] = true;
		}

		// right
		p.setValues(position.getLinha(), position.getColuna() + 1);
		if (getBoard().positionExists(p) && canMove(p)) {
			mat[p.getLinha()][p.getColuna()] = true;
		}

		// nw
		p.setValues(position.getLinha() - 1, position.getColuna() - 1);
		if (getBoard().positionExists(p) && canMove(p)) {
			mat[p.getLinha()][p.getColuna()] = true;
		}

		// ne
		p.setValues(position.getLinha() - 1, position.getColuna() + 1);
		if (getBoard().positionExists(p) && canMove(p)) {
			mat[p.getLinha()][p.getColuna()] = true;
		}

		// sw
		p.setValues(position.getLinha() + 1, position.getColuna() - 1);
		if (getBoard().positionExists(p) && canMove(p)) {
			mat[p.getLinha()][p.getColuna()] = true;
		}
		
		// se
		p.setValues(position.getLinha() + 1, position.getColuna() + 1);
		if (getBoard().positionExists(p) && canMove(p)) {
			mat[p.getLinha()][p.getColuna()] = true;
		}

		// #specialmove castling
		if (getMoveCount() == 0 && !chessMatch.getCheck()) {
			// #specialmove castling kingside rook
			Posicao posT1 = new Posicao(position.getLinha(), position.getColuna() + 3);
			if (testRookCastling(posT1)) {
				Posicao p1 = new Posicao(position.getLinha(), position.getColuna() + 1);
				Posicao p2 = new Posicao(position.getLinha(), position.getColuna() + 2);
				if (getBoard().piece(p1) == null && getBoard().piece(p2) == null) {
					mat[position.getLinha()][position.getColuna() + 2] = true;
				}
			}
			// #specialmove castling queenside rook
			Posicao posT2 = new Posicao(position.getLinha(), position.getColuna() - 4);
			if (testRookCastling(posT2)) {
				Posicao p1 = new Posicao(position.getLinha(), position.getColuna() - 1);
				Posicao p2 = new Posicao(position.getLinha(), position.getColuna() - 2);
				Posicao p3 = new Posicao(position.getLinha(), position.getColuna() - 3);
				if (getBoard().piece(p1) == null && getBoard().piece(p2) == null && getBoard().piece(p3) == null) {
					mat[position.getLinha()][position.getColuna() - 2] = true;
				}
			}
		}
		
		return mat;
	}
}
