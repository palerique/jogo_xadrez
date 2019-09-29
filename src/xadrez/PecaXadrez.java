package xadrez;

import tabuleiro.Tabuleiro;
import tabuleiro.Peca;
import tabuleiro.Posicao;

public abstract class PecaXadrez extends Peca {

	private Cor color;
	private int moveCount; 
	private Tabuleiro board;

	public PecaXadrez(Tabuleiro board, Cor color) {
		super(board);
		this.color = color; 
	}
 
	public Cor getColor() {
		return color;
	}
	
	public int getMoveCount() {
		return moveCount;
	}
	
	public void increaseMoveCount() {
		moveCount++;
	}

	public void decreaseMoveCount() {
		moveCount--;
	}

	public PosicaoXadrez getChessPosition() {
		return PosicaoXadrez.fromPosition(position);
	}
	
	protected boolean isThereOpponentPiece(Posicao position) {
		PecaXadrez p = (PecaXadrez)getBoard().piece(position);
		return p != null && p.getColor() != color;
	}
}
