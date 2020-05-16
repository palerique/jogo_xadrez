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
#define PRETO 1
#define BRANCO 0

#define LINHAS_TABULEIRO 8
#define COLUNAS_TABULEIRO 8

char tabuleiro[LINHAS_TABULEIRO][COLUNAS_TABULEIRO]= { 
  {TORRE_BRANCO, CAVALO_BRANCO, BISPO_BRANCO, REI_BRANCO, RAINHA_BRANCO, BISPO_BRANCO, CAVALO_BRANCO, TORRE_BRANCO},
  {PEAO_BRANCO, PEAO_BRANCO, PEAO_BRANCO, PEAO_BRANCO, PEAO_BRANCO, PEAO_BRANCO, PEAO_BRANCO, PEAO_BRANCO},
  {ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO},
  {ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO},
  {ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO},
  {ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO},
  {PEAO_PRETO, PEAO_PRETO, PEAO_PRETO, PEAO_PRETO, PEAO_PRETO, PEAO_PRETO, PEAO_PRETO, PEAO_PRETO},
  {TORRE_PRETO, CAVALO_PRETO, BISPO_PRETO, RAINHA_PRETO, REI_PRETO, BISPO_PRETO, CAVALO_PRETO, TORRE_PRETO}
};

typedef struct {
	int linha, coluna;
} Posicao ;

typedef struct {
	char tipo;
	int cor;
	Posicao posicao;
	int movimentos;
} Peca ;

Peca pecas[LINHAS_TABULEIRO][COLUNAS_TABULEIRO];

#define VERDADEIRO 1
#define FALSO 0

void inicializar_tabuleiro();
void exibir_tabuleiro();
int validar_movimento(Peca peca, Posicao posicaoDestino, int jogadorAtual);
int movimentar_peca(Posicao posicaoAtual, Posicao posicaoDestino, int jogadorAtual);
int movimentar_peao_branco(Peca peca, Posicao posicaoDestino);
int movimentar_peao_preto(Peca peca, Posicao posicaoDestino);
int movimentar_torre_branco(Peca peca, Posicao posicaoDestino);
int movimentar_torre_preto(Peca peca, Posicao posicaoDestino);
int movimentar_cavalo_branco(Peca peca, Posicao posicaoDestino);
int movimentar_cavalo_preto(Peca peca, Posicao posicaoDestino);
int movimentar_bispo_branco(Peca peca, Posicao posicaoDestino);
int movimentar_bispo_preto(Peca peca, Posicao posicaoDestino);
int movimentar_rei_branco(Peca peca, Posicao posicaoDestino);
int movimentar_rei_preto(Peca peca, Posicao posicaoDestino);
int movimentar_rainha_branco(Peca peca, Posicao posicaoDestino);
int movimentar_rainha_preto(Peca peca, Posicao posicaoDestino);

void exibir_tabuleiro() {
	int linha, coluna;

	printf(" \t");

	for (coluna = 0; coluna < COLUNAS_TABULEIRO; coluna++)
		printf("%3d", coluna+1);

	printf("\n");

	for (linha = 0; linha < LINHAS_TABULEIRO; linha++) {
		printf("%d\t", linha+1);
		for (coluna = 0; coluna < COLUNAS_TABULEIRO; coluna++) {
			printf("%3c", pecas[linha][coluna].tipo);
		}
		printf("\n");
	}
}

void inicializar_tabuleiro() {
	int linha, coluna;
	for (linha = 0; linha < LINHAS_TABULEIRO; linha++) {
		for (coluna = 0; coluna < COLUNAS_TABULEIRO; coluna++) {
			char pecaSelecionada = tabuleiro[linha][coluna];
			Peca peca;
			peca.posicao.linha=linha;
			peca.posicao.coluna=coluna;
			switch (pecaSelecionada) {
				case PEAO_BRANCO:
					peca.tipo=PEAO_BRANCO;
					peca.movimentos=0;
					peca.cor=BRANCO;
					break;
				case PEAO_PRETO:
					peca.tipo=PEAO_PRETO;
					peca.movimentos=0;
					peca.cor=PRETO;
					break;
				case TORRE_BRANCO:
					peca.tipo=TORRE_BRANCO;
					peca.movimentos=0;
					peca.cor=BRANCO;
					break;
				case TORRE_PRETO:
					peca.tipo=TORRE_PRETO;
					peca.movimentos=0;
					peca.cor=PRETO;
					break;
				case CAVALO_BRANCO:
					peca.tipo=CAVALO_BRANCO;
					peca.movimentos=0;
					peca.cor=BRANCO;
					break;
				case CAVALO_PRETO:
					peca.tipo=CAVALO_PRETO; 			
					peca.cor=PRETO;
					peca.movimentos=0;
					break;
				case BISPO_BRANCO:
					peca.tipo=BISPO_BRANCO;
					peca.movimentos=0;
					peca.cor=BRANCO;
					break;
				case BISPO_PRETO:
					peca.tipo=BISPO_PRETO;
					peca.movimentos=0;
					peca.cor=PRETO;
					break;
				case REI_BRANCO:
					peca.tipo=REI_BRANCO;
					peca.movimentos=0;
					peca.cor=BRANCO;
					break;
				case REI_PRETO:
					peca.tipo=REI_PRETO;
					peca.movimentos=0;
					peca.cor=PRETO;
					break;
				case RAINHA_BRANCO:
					peca.tipo=RAINHA_BRANCO;
					peca.movimentos=0;
					peca.cor=BRANCO;
					break;
				case RAINHA_PRETO:
					peca.tipo=RAINHA_PRETO;
					peca.movimentos=0;
					peca.cor=PRETO;
					break;
				case ESPACO_VAZIO:
					peca.tipo=ESPACO_VAZIO;
					peca.cor=ESPACO_VAZIO;
					peca.movimentos=0;
					break;
			}
			pecas[linha][coluna]=peca;
		}
	}
}

int movimentar_peca(Posicao posicaoAtual, Posicao posicaoDestino, int jogadorAtual) {
	int movimento_valido = 0;

	posicaoAtual.linha--; posicaoAtual.coluna--; posicaoDestino.linha--; posicaoDestino.coluna--;
	Peca peca = pecas[posicaoAtual.linha][posicaoAtual.coluna];
	movimento_valido = validar_movimento(peca, posicaoDestino, jogadorAtual);

	if (movimento_valido==1) {
		printf("\nMovimento realizado com SUCESSO!!\n");
		pecas[posicaoDestino.linha][posicaoDestino.coluna] = peca;
		pecas[posicaoAtual.linha][posicaoAtual.coluna].tipo = ESPACO_VAZIO;
	} else {
		printf("\nMovimento invAlido\n");
	}
		
	return 1;
}

int validar_movimento(Peca peca, Posicao posicaoDestino, int jogadorAtual) {
	int movimento_valido = 0;
	printf("%d %d %d %d", peca.posicao.linha, peca.posicao.coluna, posicaoDestino.linha, posicaoDestino.coluna);
		/*
		if (linhaPeca < LINHA_INFERIOR || linhaPeca > LINHA_SUPERIOR || colunaPeca < COLUNA_INFERIOR
				|| colunaPeca > COLUNA_SUPERIOR || linhaDestino < LINHA_INFERIOR || linhaDestino > LINHA_SUPERIOR
				|| colunaDestino < LINHA_INFERIOR || colunaDestino > LINHA_SUPERIOR)
			return movimento_valido;
		*/
	printf("\nPeça selecionada '%c'", peca.tipo);
	printf("\nAlvo do movimento '%c'\n", pecas[posicaoDestino.linha][posicaoDestino.coluna].tipo);

	switch (peca.tipo) {
		case PEAO_BRANCO:
			movimento_valido = movimentar_peao_branco(peca, posicaoDestino);
			break;
		case PEAO_PRETO:
		    movimento_valido = movimentar_peao_preto(peca, posicaoDestino);
			break;
		case TORRE_BRANCO:
    		movimento_valido = movimentar_torre_branco(peca, posicaoDestino);
			break;
		case TORRE_PRETO:
    		movimento_valido = movimentar_torre_preto(peca, posicaoDestino);
			break;
		case CAVALO_BRANCO:
    		movimento_valido = movimentar_cavalo_branco(peca, posicaoDestino);
			break;
		case CAVALO_PRETO:    			
			movimento_valido = movimentar_cavalo_preto(peca, posicaoDestino);
			break;
		case BISPO_BRANCO:
			movimento_valido = movimentar_bispo_branco(peca, posicaoDestino);
			break;
		case BISPO_PRETO:
    		movimento_valido = movimentar_bispo_preto(peca, posicaoDestino);
			break;
		case REI_BRANCO:
    		movimento_valido = movimentar_rei_branco(peca, posicaoDestino);
			break;
		case REI_PRETO:
    		movimento_valido = movimentar_rei_preto(peca, posicaoDestino);
			break;
		case RAINHA_BRANCO:
    		movimento_valido = movimentar_rainha_branco(peca, posicaoDestino);
			break;
		case RAINHA_PRETO:
    		movimento_valido = movimentar_rainha_preto(peca, posicaoDestino);
			break;
	}

	return movimento_valido;
}

int posicaoExiste(Posicao posicao) {
	int retorno=FALSO;

	if(posicao.linha>=0 && posicao.linha<LINHAS_TABULEIRO && posicao.coluna>=0 && posicao.coluna<COLUNAS_TABULEIRO)
		retorno=VERDADEIRO;

	return retorno;
}

int existePeca(Posicao posicao) {
	int retorno=VERDADEIRO;

	if(pecas[posicao.linha][posicao.coluna].tipo==ESPACO_VAZIO)
		retorno=FALSO;
	return retorno;
}

void inicializarMatrizMovimentosPossiveis(int matrizMovimentosPossiveis[LINHAS_TABULEIRO][COLUNAS_TABULEIRO]) {
	int i=0, j=0;
	for(i=0; i<LINHAS_TABULEIRO; i++) {
		for(j=0; j<COLUNAS_TABULEIRO; j++) {
			matrizMovimentosPossiveis[i][j]=FALSO;
		}
	}
}

int movimentar_peao_branco(Peca peca, Posicao posicaoDestino) {
		int matrizMovimentosPossiveis[LINHAS_TABULEIRO][COLUNAS_TABULEIRO];
		inicializarMatrizMovimentosPossiveis(matrizMovimentosPossiveis);
		/*		

		int sucesso = 0;
		Posicao p;

		p.linha=linhaPeca+1;
		p.coluna=colunaPeca;
		if (posicaoExiste(p) && !existePeca(p)) {
			matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
		}

		p.linha=linhaPeca+2;
		p.coluna=colunaPeca;
		Posicao p2;
		p2.linha=linhaPeca+1;
		p2.coluna=colunaPeca;

		if (posicaoExiste(p) && !existePeca(p) && posicaoExiste(p2) && !existePeca(p2) ) { //&& getContagemMovimento() == 0) {
				matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
		}
		if(posicao.getColuna()>0) {
			p.setValores(posicao.getLinha() + 1, posicao.getColuna() - 1);
			if (getTabuleiro().posicaoExiste(p) && ehPecaOponente(p)) {
				matrizMovimentosPossiveis[p.getLinha()][p.getColuna()] = true;
			}			
		}
		if(posicao.getColuna()<7) {
			p.setValores(posicao.getLinha() + 1, posicao.getColuna() + 1);
			if (getTabuleiro().posicaoExiste(p) && ehPecaOponente(p)) {
				matrizMovimentosPossiveis[p.getLinha()][p.getColuna()] = true;
			}
		}
*/		

		return 1;
}

	int movimentar_peao_preto(Peca peca, Posicao posicaoDestino) {
		int sucesso = 0;

 		return 1;
	}

	int movimentar_torre_branco(Peca peca, Posicao posicaoDestino) {
		printf("\nTorre Branco\n");

		return 1;
	}

	int movimentar_torre_preto(Peca peca, Posicao posicaoDestino) {
		printf("\nTorre Preto\n");

		return 1;
	}

	int movimentar_cavalo_branco(Peca peca, Posicao posicaoDestino) {
		printf("\nCavalo Branco\n");

		return 1;
	}

	int movimentar_cavalo_preto(Peca peca, Posicao posicaoDestino) {
		printf("\nCavalo Preto\n");

		return 1;
	}

	int movimentar_bispo_branco(Peca peca, Posicao posicaoDestino) {
		printf("\nBispo Branco\n");

 		return 1;
	}

	int movimentar_bispo_preto(Peca peca, Posicao posicaoDestino) {
		printf("\nBispo Preto\n");

 		return 1;
	}

	int movimentar_rei_branco(Peca peca, Posicao posicaoDestino) {
		printf("\nRei Branco\n");

 		return 1;
	}

	int movimentar_rei_preto(Peca peca, Posicao posicaoDestino) {
		printf("\nRei Preto\n");

 		return 1;
	}

	int movimentar_rainha_branco(Peca peca, Posicao posicaoDestino) {
		printf("\nRainha Branco\n");

 		return 1;
	}

	int movimentar_rainha_preto(Peca peca, Posicao posicaoDestino) {
		printf("\nRainha Preto\n");

 		return 1;
	}
