#include <stdio.h>
#include "pecas.h"
#include "tabuleiro.h"

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

void inicializar_tabuleiro();
void exibir_tabuleiro();
int validar_movimento(Peca peca, Posicao posicaoDestino, int jogadorAtual);
int movimentar_peca(Posicao posicaoAtual, Posicao posicaoDestino, int jogadorAtual);

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
			movimento_valido = movimentar_peao(peca, posicaoDestino);
			break;
		case PEAO_PRETO:
		    movimento_valido = movimentar_peao(peca, posicaoDestino);
			break;
		case TORRE_BRANCO:
    		movimento_valido = movimentar_torre(peca, posicaoDestino);
			break;
		case TORRE_PRETO:
    		movimento_valido = movimentar_torre(peca, posicaoDestino);
			break;
		case CAVALO_BRANCO:
    		movimento_valido = movimentar_cavalo(peca, posicaoDestino);
			break;
		case CAVALO_PRETO:    			
			movimento_valido = movimentar_cavalo(peca, posicaoDestino);
			break;
		case BISPO_BRANCO:
			movimento_valido = movimentar_bispo(peca, posicaoDestino);
			break;
		case BISPO_PRETO:
    		movimento_valido = movimentar_bispo(peca, posicaoDestino);
			break;
		case REI_BRANCO:
    		movimento_valido = movimentar_rei(peca, posicaoDestino);
			break;
		case REI_PRETO:
    		movimento_valido = movimentar_rei(peca, posicaoDestino);
			break;
		case RAINHA_BRANCO:
    		movimento_valido = movimentar_rainha(peca, posicaoDestino);
			break;
		case RAINHA_PRETO:
    		movimento_valido = movimentar_rainha(peca, posicaoDestino);
			break;
	}

	return movimento_valido;
}

