#include <stdio.h>

#define PEAO_BRANCO 'p'
#define PEAO_PRETO 'P'
#define BISPO_BRANCO 'b'
#define BISPO_PRETO 'B'
#define CAVALO_BRANCO 'c'
#define CAVALO_PRETO 'C'
#define TORRE_BRANCO 't'
#define TORRE_PRETO 'T'
#define REI_BRANCO 'k'
#define REI_PRETO 'K'
#define RAINHA_BRANCO 'q'
#define RAINHA_PRETO 'Q'
#define ESPACO_VAZIO ' '

#define LINHA_INFERIOR 1
#define LINHA_SUPERIOR 8
#define COLUNA_INFERIOR 1
#define COLUNA_SUPERIOR 8

char tabuleiro[9][9]= { 
  ESPACO_VAZIO, '1', '2', '3', '4', '5', '6', '7', '8',
  '1', TORRE_BRANCO, CAVALO_BRANCO, BISPO_BRANCO, REI_BRANCO, RAINHA_BRANCO, BISPO_BRANCO, CAVALO_BRANCO, TORRE_BRANCO,
  '2', PEAO_BRANCO, PEAO_BRANCO, PEAO_BRANCO, PEAO_BRANCO, PEAO_BRANCO, PEAO_BRANCO, PEAO_BRANCO, PEAO_BRANCO,
  '3', ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO,
  '4', ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO,
  '5', ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO,
  '6', ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO,
  '7', PEAO_PRETO, PEAO_PRETO, PEAO_PRETO, PEAO_PRETO, PEAO_PRETO, PEAO_PRETO, PEAO_PRETO, PEAO_PRETO,
  '8', TORRE_PRETO, CAVALO_PRETO, BISPO_PRETO, RAINHA_PRETO, REI_PRETO, BISPO_PRETO, CAVALO_PRETO, TORRE_PRETO
};

void exibir_tabuleiro();
int validar_movimento(int linhaPeca, int colunaPeca, int linhaDestino, int colunaDestino, int jogadorAtual);
int movimentar_peca(int linhaPeca, int colunaPeca, int linhaDestino, int colunaDestino, int jogadorAtual);
int movimentar_peao_branco(int linhaPeca, int colunaPeca, int linhaDestino, int colunaDestino);
int movimentar_peao_preto(int linhaPeca, int colunaPeca, int linhaDestino, int colunaDestino);
int movimentar_torre_branco(int linhaPeca, int colunaPeca, int linhaDestino, int colunaDestino);
int movimentar_torre_preto(int linhaPeca, int colunaPeca, int linhaDestino, int colunaDestino);
int movimentar_cavalo_branco(int linhaPeca, int colunaPeca, int linhaDestino, int colunaDestino);
int movimentar_cavalo_preto(int linhaPeca, int colunaPeca, int linhaDestino, int colunaDestino);
int movimentar_bispo_branco(int linhaPeca, int colunaPeca, int linhaDestino, int colunaDestino);
int movimentar_bispo_preto(int linhaPeca, int colunaPeca, int linhaDestino, int colunaDestino);
int movimentar_rei(int linhaPeca, int colunaPeca, int linhaDestino, int colunaDestino);
int movimentar_rainha(int linhaPeca, int colunaPeca, int linhaDestino, int colunaDestino);

	void exibir_tabuleiro() {
		int linha, coluna;

		for (linha = 0; linha < 9; linha++) {

			for (coluna = 0; coluna < 9; coluna++) {
				printf("%3c", tabuleiro[linha][coluna]);
			}

			printf("\n");
		}
	}

	int movimentar_peca(int linhaPeca, int colunaPeca, int linhaDestino, int colunaDestino, int jogadorAtual) {
		int movimento_valido = 0;

		movimento_valido = validar_movimento(linhaPeca, colunaPeca, linhaDestino, colunaDestino, jogadorAtual);

		if (movimento_valido==1) {
			printf("\nMovimento realizado com SUCESSO!!\n");
			tabuleiro[linhaDestino][colunaDestino] = tabuleiro[linhaPeca][colunaPeca];
			tabuleiro[linhaPeca][colunaPeca] = ESPACO_VAZIO;
		} else {
			printf("\nMovimento invAlido\n");
		}
		
		return 1;
	}

	int validar_movimento(int linhaPeca, int colunaPeca, int linhaDestino, int colunaDestino, int jogadorAtual) {
		int movimento_valido = 0;
		printf("%d %d %d %d", linhaPeca, colunaPeca, linhaDestino, colunaDestino);
		if (linhaPeca < LINHA_INFERIOR || linhaPeca > LINHA_SUPERIOR || colunaPeca < COLUNA_INFERIOR
				|| colunaPeca > COLUNA_SUPERIOR || linhaDestino < LINHA_INFERIOR || linhaDestino > LINHA_SUPERIOR
				|| colunaDestino < LINHA_INFERIOR || colunaDestino > LINHA_SUPERIOR)
			return movimento_valido;

		char pecaSelecionada = tabuleiro[linhaPeca][colunaPeca];

		printf("\nPeça selecionada '%c'", pecaSelecionada);
		printf("\nAlvo do movimento '%c'\n", tabuleiro[linhaDestino][colunaDestino]);

		switch (pecaSelecionada) {
		case PEAO_BRANCO:
			    movimento_valido = movimentar_peao_branco(linhaPeca, colunaPeca, linhaDestino, colunaDestino);
			break;
		case PEAO_PRETO:
			    movimento_valido = movimentar_peao_preto(linhaPeca, colunaPeca, linhaDestino, colunaDestino);
			break;
		case TORRE_BRANCO:
    			movimento_valido = movimentar_torre_branco(linhaPeca, colunaPeca, linhaDestino, colunaDestino);
			break;
		case TORRE_PRETO:
    			movimento_valido = movimentar_torre_preto(linhaPeca, colunaPeca, linhaDestino, colunaDestino);
			break;
		case CAVALO_BRANCO:
    			movimento_valido = movimentar_cavalo_branco(linhaPeca, colunaPeca, linhaDestino, colunaDestino);
			break;
		case CAVALO_PRETO:
    			movimento_valido = movimentar_cavalo_preto(linhaPeca, colunaPeca, linhaDestino, colunaDestino);
			break;
		case BISPO_BRANCO:
    			movimento_valido = movimentar_bispo_branco(linhaPeca, colunaPeca, linhaDestino, colunaDestino);
			break;
		case BISPO_PRETO:
    			movimento_valido = movimentar_bispo_preto(linhaPeca, colunaPeca, linhaDestino, colunaDestino);
			break;
		case REI_BRANCO:
    			movimento_valido = movimentar_rei_branco(linhaPeca, colunaPeca, linhaDestino, colunaDestino);
			break;
		case REI_PRETO:
    			movimento_valido = movimentar_rei_preto(linhaPeca, colunaPeca, linhaDestino, colunaDestino);
			break;
		case RAINHA_BRANCO:
    			movimento_valido = movimentar_rainha_branco(linhaPeca, colunaPeca, linhaDestino, colunaDestino);
			break;
		case RAINHA_PRETO:
    			movimento_valido = movimentar_rainha_preto(linhaPeca, colunaPeca, linhaDestino, colunaDestino);
			break;
		}

		return movimento_valido;
	}

	int movimentar_peao_branco(int linhaPeca, int colunaPeca, int linhaDestino, int colunaDestino) {
		int sucesso = 0;
		printf("\nPeão Branco\n");

		if (colunaPeca != colunaDestino)
			sucesso = 0;
		else if (linhaPeca == 3 && (linhaDestino == 4 || linhaDestino == 5))
			sucesso = 1;
		else if (linhaPeca <=8 && linhaPeca > 3)
			sucesso = 1;
		return 1;
	}

	int movimentar_peao_preto(int linhaPeca, int colunaPeca, int linhaDestino, int colunaDestino) {
		int sucesso = 0;

		printf("\nPeão Preto\n");
		if (colunaPeca != colunaDestino)
			sucesso = 0;
		else if (linhaPeca == 8 && (linhaDestino == 7 || linhaDestino == 6))
			sucesso = 1;
		else if (linhaPeca >=1 && linhaPeca < 8)
			sucesso = 1;
 		return 1;
	}

	int movimentar_torre_branco(int linhaPeca, int colunaPeca, int linhaDestino, int colunaDestino) {
		printf("\nTorre Branco\n");

		return 1;
	}

	int movimentar_torre_preto(int linhaPeca, int colunaPeca, int linhaDestino, int colunaDestino) {
		printf("\nTorre Preto\n");

		return 1;
	}

	int movimentar_cavalo_branco(int linhaPeca, int colunaPeca, int linhaDestino, int colunaDestino) {
		printf("\nCavalo Branco\n");

		return 1;
	}

	int movimentar_cavalo_preto(int linhaPeca, int colunaPeca, int linhaDestino, int colunaDestino) {
		printf("\nCavalo Preto\n");

		return 1;
	}

	int movimentar_bispo_branco(int linhaPeca, int colunaPeca, int linhaDestino, int colunaDestino) {
		printf("\nBispo Branco\n");

 		return 1;
	}

	int movimentar_bispo_preto(int linhaPeca, int colunaPeca, int linhaDestino, int colunaDestino) {
		printf("\nBispo Preto\n");

 		return 1;
	}

	int movimentar_rei_branco(int linhaPeca, int colunaPeca, int linhaDestino, int colunaDestino) {
		printf("\nRei Branco\n");

 		return 1;
	}

	int movimentar_rei_preto(int linhaPeca, int colunaPeca, int linhaDestino, int colunaDestino) {
		printf("\nRei Preto\n");

 		return 1;
	}

	int movimentar_rainha_branco(int linhaPeca, int colunaPeca, int linhaDestino, int colunaDestino) {
		printf("\nRainha Branco\n");

 		return 1;
	}

	int movimentar_rainha_preto(int linhaPeca, int colunaPeca, int linhaDestino, int colunaDestino) {
		printf("\nRainha Preto\n");

 		return 1;
	}
