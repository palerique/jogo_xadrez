package aplicacao;

import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Scanner;

import gui.InterfaceUsuario;
import xadrez.XadrezException;
import xadrez.PartidaXadrez;
import xadrez.PosicaoXadrez;
import xadrez.PecaXadrez;

public class Programa {

	public static void main(String[] args) {
	 	
		Scanner sc = new Scanner(System.in);
		PartidaXadrez chessMatch = new PartidaXadrez();
		List<PecaXadrez> captured = new ArrayList<>();
		
		while (!chessMatch.getCheckMate()) {
			try {
				InterfaceUsuario.clearScreen();
				InterfaceUsuario.printMatch(chessMatch, captured);
				System.out.println();
				System.out.print("Origem: ");
				PosicaoXadrez source = InterfaceUsuario.readChessPosition(sc);
				
				boolean[][] possibleMoves = chessMatch.possibleMoves(source);
				InterfaceUsuario.clearScreen();
				InterfaceUsuario.printBoard(chessMatch.getPieces(), possibleMoves);
				System.out.println();
				System.out.print("Alvo: ");
				PosicaoXadrez target = InterfaceUsuario.readChessPosition(sc);
				
				PecaXadrez capturedPiece = chessMatch.performChessMove(source, target);
				
				if (capturedPiece != null) {
					captured.add(capturedPiece);
				}
				
				if (chessMatch.getPromoted() != null) {
					System.out.print("Entre com a peça para promoção (B/N/R/Q): ");
					String type = sc.nextLine();
					chessMatch.replacePromotedPiece(type);
				}
			}
			catch (XadrezException e) {
				System.out.println(e.getMessage());
				sc.nextLine();
			}
			catch (InputMismatchException e) {
				System.out.println(e.getMessage());
				sc.nextLine();
			}
		}
		InterfaceUsuario.clearScreen();
		InterfaceUsuario.printMatch(chessMatch, captured);
	}
}
