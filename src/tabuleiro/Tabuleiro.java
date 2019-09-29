package tabuleiro;

public class Tabuleiro {

	private int rows;
	private int columns;
	private Peca[][] pieces; 
	
	public Tabuleiro(int rows, int columns) {
		if (rows < 1 || columns < 1) {
			throw new TabuleiroException("Erro ao criar tabuleiro: deve haver pelo menos 1 linha e 1 coluna");
		}
		this.rows = rows;
		this.columns = columns;
		pieces = new Peca[rows][columns];
	}

	public int getRows() {
		return rows;
	}

	public int getColumns() {
		return columns;
	}
	
	public Peca piece(int row, int column) {
		if (!positionExists(row, column)) {
			throw new TabuleiroException("Posição fora do tabuleiro");
		}
		return pieces[row][column];
	}
	
	public Peca piece(Posicao position) {
		if (!positionExists(position)) {
			throw new TabuleiroException("Posição fora do tabuleiro");
		}
		return pieces[position.getLinha()][position.getColuna()];
	}
	
	public void placePiece(Peca piece, Posicao position) {
		if (thereIsAPiece(position)) {
			throw new TabuleiroException("Já existe uma peça na posição " + position);
		}
		pieces[position.getLinha()][position.getColuna()] = piece;
		piece.position = position;
	}
	
	public Peca removePiece(Posicao position) {
		if (!positionExists(position)) {
			throw new TabuleiroException("Posição fora do tabuleiro ");
		}
		if (piece(position) == null) {
			return null;
		}
		Peca aux = piece(position);
		aux.position = null;
		pieces[position.getLinha()][position.getColuna()] = null;
		return aux;
	}
	
	private boolean positionExists(int row, int column) {
		return row >= 0 && row < rows && column >= 0 && column < columns;
	}
	
	public boolean positionExists(Posicao position) {
		return positionExists(position.getLinha(), position.getColuna());
	}
	
	public boolean thereIsAPiece(Posicao position) {
		if (!positionExists(position)) {
			throw new TabuleiroException("Posição fora do tabuleiro");
		}
		return piece(position) != null;
	}
}
