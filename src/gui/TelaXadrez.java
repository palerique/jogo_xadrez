package gui;

import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Scanner;

import javafx.application.Application;
import javafx.beans.InvalidationListener;
import javafx.beans.Observable;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.image.Image;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Priority;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import pecas.Bispo;
import pecas.Cavalo;
import pecas.Peao;
import pecas.Rainha;
import pecas.Rei;
import pecas.Torre;
import tabuleiro.Peca;
import xadrez.Cor;
import xadrez.PartidaXadrez;
import xadrez.PecaXadrez;
import xadrez.PosicaoXadrez;
import xadrez.XadrezException;

public class TelaXadrez extends Application {
	private Image peaoBranco = null;
	private Image cavaloBranco = null;
	private Image bispoBranco = null;
	private Image torreBranco = null;
	private Image reiBranco = null;
	private Image rainhaBranco = null;
	
	private Image peaoPreto = null;
	private Image cavaloPreto = null;
	private Image bispoPreto = null;
	private Image torrePreto = null;
	private Image reiPreto = null;
	private Image rainhaPreto = null;
	private int larguraTela=630;
	private int alturaTela=525;
	PosicaoXadrez source=null;
	PosicaoXadrez target=null;
	GridPane chessboard = null;
	VBox root = null;

	Scanner sc = new Scanner(System.in);
	PartidaXadrez chessMatch = new PartidaXadrez();
	List<PecaXadrez> captured = new ArrayList<>();

	public TelaXadrez() {
		inicializarPecas();
	}
 
    final int size = 8;
    
    void inicializarPecas() {
    	peaoBranco = new Image(getClass().getResourceAsStream("/peao_branco.png"));
    	cavaloBranco = new Image(getClass().getResourceAsStream("/cavalo_branco.png"));
    	bispoBranco = new Image(getClass().getResourceAsStream("/bispo_branco.png"));
    	torreBranco = new Image(getClass().getResourceAsStream("/torre_branco.png"));
    	reiBranco = new Image(getClass().getResourceAsStream("/rei_branco.png"));
    	rainhaBranco = new Image(getClass().getResourceAsStream("/rainha_branco.png"));
    	
    	peaoPreto = new Image(getClass().getResourceAsStream("/peao_preto.png"));
    	cavaloPreto = new Image(getClass().getResourceAsStream("/cavalo_preto.png"));
    	bispoPreto = new Image(getClass().getResourceAsStream("/bispo_preto.png"));
    	torrePreto = new Image(getClass().getResourceAsStream("/torre_preto.png"));
    	reiPreto = new Image(getClass().getResourceAsStream("/rei_preto.png"));
    	rainhaPreto = new Image(getClass().getResourceAsStream("/rainha_preto.png"));    	
    }

    @Override
    public void start(Stage primaryStage) {
        root = new VBox();

        chessboard = new GridPane();
        fillChessboard(chessboard, size);

        ChangeListener<Number> resizeListener = new ChangeListener<Number>() {
            @Override
            public void changed(ObservableValue<? extends Number> ov, Number t, Number t1) {
                double newWidth = chessboard.getWidth() / size;
                double newHeight = chessboard.getHeight() / size;

                for(Node n: chessboard.getChildren()) {
                    Canvas canvas = (Canvas)n;
                    canvas.setWidth(newWidth);
                    canvas.setHeight(newHeight);
                }
            }
        };

        chessboard.widthProperty().addListener(resizeListener);
        chessboard.heightProperty().addListener(resizeListener);

        root.getChildren().add(chessboard);
        root.setPadding(new Insets(10));

        VBox.setVgrow(chessboard, Priority.ALWAYS);

        Scene scene = new Scene(root, larguraTela, alturaTela);
        scene.setOnKeyPressed(new EventHandler<KeyEvent>() {
            @Override
            public void handle(KeyEvent t) {
                KeyCode key = t.getCode();
                if (key == KeyCode.ESCAPE){
                    target=null;
                    source=null;
                    System.out.println("source:"+source+ " target:" + target);
                }
            }
        });
        primaryStage.setTitle("Jogo de Xadrez");
        primaryStage.setScene(scene);
        primaryStage.setResizable(false);
        primaryStage.show();
        
        root.setOnMouseClicked(new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent event) {
            	int coluna = ((int)event.getX())/((larguraTela-(larguraTela/8))/7);
            	int linha = ((int)event.getY())/((alturaTela-(alturaTela/8))/7);
            	
            	char c = getColuna(coluna);

            	Peca peca = chessMatch.getPieces()[linha][coluna];
            	
            	if(peca!=null) {
	        		if(peca instanceof Peao) {
	        			Peao peao = (Peao) peca; 
	        			if(source==null)
	        				source = new PosicaoXadrez(peao.getChessPosition().getColuna(), peao.getChessPosition().getLinha());
	        			System.out.println("peao " + peao.getColor().toString()+ "  " + peao.getChessPosition().toString());
	        		}
	        		else
	        		if(peca instanceof Cavalo) {
	        			Cavalo cavalo = (Cavalo) peca;
	        			if(source==null)
	        				source = new PosicaoXadrez(cavalo.getChessPosition().getColuna(), cavalo.getChessPosition().getLinha());
	        			
	        			System.out.println("Cavalo " + cavalo.getColor().toString()+ "  " + cavalo.getChessPosition().toString());
	        		}
	        		else	
	        		if(peca instanceof Torre) {
	        			Torre torre = (Torre) peca;
	        			if(source==null)
	        				source = new PosicaoXadrez(torre.getChessPosition().getColuna(), torre.getChessPosition().getLinha());
	        			
	        			System.out.println("torre " + torre.getColor().toString()+ "  " + torre.getChessPosition().toString());
	        		}
	        		else	
	        		if(peca instanceof Bispo) {
	        			Bispo bispo = (Bispo) peca;
	        			if(source==null)
	        				source = new PosicaoXadrez(bispo.getChessPosition().getColuna(), bispo.getChessPosition().getLinha());
	        			
	        			System.out.println("bispo " + bispo.getColor().toString()+ "  " + bispo.getChessPosition().toString());
	        		}
	        		else
	        		if(peca instanceof Rei) {
	        			Rei rei = (Rei) peca; 
	        			if(source==null)
	        				source = new PosicaoXadrez(rei.getChessPosition().getColuna(), rei.getChessPosition().getLinha());
	        			
	        			System.out.println("rei " + rei.getColor().toString()+ "  " + rei.getChessPosition().toString());
	        		}
	        		else
	        		if(peca instanceof Rainha) {
	        			Rainha rainha = (Rainha) peca; 
	        			if(source==null)
	        				source = new PosicaoXadrez(rainha.getChessPosition().getColuna(), rainha.getChessPosition().getLinha());
	        			
	        			System.out.println("rainha " + rainha.getColor().toString()+ "  " + rainha.getChessPosition().toString());	        			
	        		} else {
	        			if(source!=null)
	        				target = new PosicaoXadrez(c, linha);
	        		}
                } else {
                	if(source!=null)
                		target = new PosicaoXadrez(c, linha);	
                }

            	if(source!=null && target!=null) {
    				boolean[][] possibleMoves = chessMatch.possibleMoves(source);
    				PecaXadrez capturedPiece = null;
    				try {
    					capturedPiece = chessMatch.performChessMove(source, target);
    				} catch(XadrezException e) {
    				}

    				if (capturedPiece != null) {
    					captured.add(capturedPiece);
    				}

    				PecaXadrez pecaXadrez =null;
    				pecaXadrez = chessMatch.getPieces()[target.getLinha()][getColuna(target.getColuna())];
        			chessMatch.getPieces()[target.getLinha()][getColuna(target.getColuna())]=pecaXadrez;
        			chessMatch.getPieces()[source.getLinha()][getColuna(source.getColuna())]=null;
    				
    				Canvas canvasDesenhar = null;
    				Canvas canvasLimpar = null;
    				
	                for(Node n: chessboard.getChildren()) {
	                    Canvas canvas = (Canvas)n;
	                    int colunaCanvas = (int)canvas.getLayoutX()/77;
	                	int linhaCanvas = -1;
	                	
	                	if(chessMatch.getCurrentPlayer().equals(Cor.BLACK)) {
	                		linhaCanvas = (int)canvas.getLayoutY()/64;
		                	if(getColuna(source.getColuna())==colunaCanvas && (8-source.getLinha())==linhaCanvas) {
		                		canvasLimpar=canvas;
		                	}

	                	} else {
	                		linhaCanvas = 8-(int)canvas.getLayoutY()/64;
		                	if(getColuna(source.getColuna())==colunaCanvas && (source.getLinha())==linhaCanvas) {
		                		canvasLimpar=canvas;
		                	}
	                	}

	                	if(coluna==colunaCanvas && linha==linhaCanvas) {
	                		canvasDesenhar=canvas;
	                	}
	                	
	                }
	                
	                if(canvasDesenhar!=null && canvasLimpar!=null) {
	    				if(chessMatch.getCurrentPlayer().equals(Cor.BLACK)) {
	    					desenharPeca(canvasDesenhar, chessMatch.getPieces()[8-source.getLinha()][getColuna(source.getColuna())]);
	                	} else {
	                		desenharPeca(canvasDesenhar, chessMatch.getPieces()[8-source.getLinha()][getColuna(source.getColuna())]);
	                	}
                		canvasLimpar.getGraphicsContext2D().fillRect(0, 0, canvasLimpar.getWidth(), canvasLimpar.getHeight());

	                	desenharPeca(canvasDesenhar, pecaXadrez);
	                	
	    				source=null;
	    				target=null;

	                }
            	}
            }
        });
    }
    
    private int getColuna(char letra) {
    	int x = 0;
		switch (letra) {
		case 'a': x = 0;break;
		case 'b':x = 1;break;
		case 'c':x = 2;break;
		case 'd':x = 3;break;
		case 'e':x = 4;break;
		case 'f':x = 5;break;
		case 'g':x = 6;break;
		case 'h':x = 7;break;
		}
		return x;
    }
    
    private char getColuna(int coluna) {
    	char c = 'a';
    	switch(coluna) {
    		case 0: c='a'; break;
    		case 1: c='b'; break;
    		case 2: c='c'; break;
    		case 3: c='d'; break;
    		case 4: c='e'; break;
    		case 5: c='f'; break;
    		case 6: c='g'; break;
    		case 7: c='h'; break;
    	}
		return c;
    }

    void fillChessboard(GridPane pane, int size) {
        class RedrawListener implements ChangeListener<Number> {
            Color color;
            Canvas canvas;
            Peca peca;
            

            public RedrawListener(Canvas c, int i) {
                if(i % 2 != 0) {
                    color = Color.GRAY;
                }
                else {
                    color = Color.WHITE;
                    
                }
                canvas = c;
            }

            @Override
            public void changed(ObservableValue<? extends Number> ov, Number t, Number t1) {
            	canvas.getGraphicsContext2D().setFill(color);
                canvas.getGraphicsContext2D().fillRect(0, 0, canvas.getWidth(), canvas.getHeight());
                
                desenharPeca(canvas, peca);
            }
        }

        for(int row = 0; row < size; row++) {
            for(int col = 0, i = row; col < size; col++, i++) {
                Canvas c = new Canvas();
                
                RedrawListener rl = new RedrawListener(c, i);
                
                rl.peca = chessMatch.getPieces()[row][col];

                c.widthProperty().addListener(rl);
                c.heightProperty().addListener(rl);
                pane.add(c, col, row);
            }
        }
    }

	public void desenharPeca(Canvas canvas, Peca peca) {
        if(peca!=null) {
    		if(peca instanceof Peao) {
    			if(((Peao) peca).getColor().equals(Cor.WHITE)) 
    				canvas.getGraphicsContext2D().drawImage(peaoBranco, 0, 0, canvas.getWidth(), canvas.getHeight());
    			else 
    				canvas.getGraphicsContext2D().drawImage(peaoPreto, 0, 0, canvas.getWidth(), canvas.getHeight());
    		}
    		
    		if(peca instanceof Cavalo) {
    			if(((Cavalo) peca).getColor().equals(Cor.WHITE)) 
    				canvas.getGraphicsContext2D().drawImage(cavaloBranco, 0, 0, canvas.getWidth(), canvas.getHeight());
    			else 
    				canvas.getGraphicsContext2D().drawImage(cavaloPreto, 0, 0, canvas.getWidth(), canvas.getHeight());
    		}
    			
    		if(peca instanceof Torre) {
    			if(((Torre) peca).getColor().equals(Cor.WHITE)) 
    				canvas.getGraphicsContext2D().drawImage(torreBranco, 0, 0, canvas.getWidth(), canvas.getHeight());
    			else 
    				canvas.getGraphicsContext2D().drawImage(torrePreto, 0, 0, canvas.getWidth(), canvas.getHeight());
    		}
    			
    		if(peca instanceof Bispo) {
    			if(((Bispo) peca).getColor().equals(Cor.WHITE)) 
    				canvas.getGraphicsContext2D().drawImage(bispoBranco, 0, 0, canvas.getWidth(), canvas.getHeight());
    			else 
    				canvas.getGraphicsContext2D().drawImage(bispoPreto, 0, 0, canvas.getWidth(), canvas.getHeight());
    		}
    		
    		if(peca instanceof Rei) {
    			if(((Rei) peca).getColor().equals(Cor.WHITE)) 
    				canvas.getGraphicsContext2D().drawImage(reiBranco, 0, 0, canvas.getWidth(), canvas.getHeight());
    			else 
    				canvas.getGraphicsContext2D().drawImage(reiPreto, 0, 0, canvas.getWidth(), canvas.getHeight());
    		}
    		
    		if(peca instanceof Rainha) {
    			if(((Rainha) peca).getColor().equals(Cor.WHITE)) 
    				canvas.getGraphicsContext2D().drawImage(rainhaBranco, 0, 0, canvas.getWidth(), canvas.getHeight());
    			else 
    				canvas.getGraphicsContext2D().drawImage(rainhaPreto, 0, 0, canvas.getWidth(), canvas.getHeight());
    		}	
        }
	}

	@Override
	public void stop() {
	}

	public void inicializar(String[] args) {
		launch(args);
	}

	public void partida() {

		if (!chessMatch.getCheckMate()) {
			try {
				InterfaceUsuario.clearScreen();
				InterfaceUsuario.printMatch(chessMatch, captured);
				System.out.println();
				System.out.print("Origem: ");
				PosicaoXadrez source = new PosicaoXadrez('a', 2);// InterfaceUsuario.readChessPosition(sc);

				boolean[][] possibleMoves = chessMatch.possibleMoves(source);
				InterfaceUsuario.clearScreen();
				InterfaceUsuario.printBoard(chessMatch.getPieces(), possibleMoves);
				System.out.println();
				System.out.print("Alvo: ");
				PosicaoXadrez target = new PosicaoXadrez('a', 2);// InterfaceUsuario.readChessPosition(sc);

				PecaXadrez capturedPiece = chessMatch.performChessMove(source, target);

				if (capturedPiece != null) {
					captured.add(capturedPiece);
				}

				if (chessMatch.getPromoted() != null) {
					System.out.print("Entre com a peça para promoção (B/N/R/Q): ");
					String type = "";// sc.nextLine();
					chessMatch.replacePromotedPiece(type);
				}
			} catch (XadrezException e) {
				System.out.println(e.getMessage());
				// sc.nextLine();
			} catch (InputMismatchException e) {
				System.out.println(e.getMessage());
				// sc.nextLine();
			}
		}
		InterfaceUsuario.clearScreen();
		InterfaceUsuario.printMatch(chessMatch, captured);
	}

}
