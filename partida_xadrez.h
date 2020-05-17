#include <stdio.h>
#include "pecas.h"

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
int validar_movimento(Peca *peca, Posicao posicaoDestino, int jogadorAtual);
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
	movimento_valido = validar_movimento(&peca, posicaoDestino, jogadorAtual);

	int i,j;
	for(i=0; i<LINHAS_TABULEIRO; i++) {
		for(j=0; j<LINHAS_TABULEIRO; j++) {
			printf("%d", peca.matrizMovimentosPossiveis[i][j]);
		}
		printf("\n");
	}

	if(peca.matrizMovimentosPossiveis[posicaoDestino.linha][posicaoDestino.coluna]==VERDADEIRO) {
		peca.posicao=posicaoDestino;
		pecas[posicaoDestino.linha][posicaoDestino.coluna]=peca;

		Peca pecaVazia;
		pecaVazia.tipo=ESPACO_VAZIO;
		pecas[posicaoAtual.linha][posicaoAtual.coluna]=pecaVazia;

		printf("\nMovimento realizado com SUCESSO!!\n");
	} else {

		printf("\nMovimento invAlido %d %d\n", peca.posicao.linha, peca.posicao.coluna);
	}
		
	return 1;
}

int validar_movimento(Peca *peca, Posicao posicaoDestino, int jogadorAtual) {
	if (peca->posicao.linha < 0 || peca->posicao.linha > (LINHAS_TABULEIRO-1) 
		|| peca->posicao.coluna < 0 || peca->posicao.coluna > (COLUNAS_TABULEIRO-1) 
		|| posicaoDestino.linha < 0 || posicaoDestino.linha > (LINHAS_TABULEIRO-1) 
		|| posicaoDestino.coluna <0 || posicaoDestino.coluna > (LINHAS_TABULEIRO-1))
			return FALSO;

	switch (peca->tipo) {
		case PEAO_BRANCO:
			possivelMovimentoPeao(peca, posicaoDestino);
			break;
		case PEAO_PRETO:
			possivelMovimentoPeao(peca, posicaoDestino);
			break;
		case TORRE_BRANCO:
    		possivelMovimentoTorre(peca, posicaoDestino);
			break;
		case TORRE_PRETO:
    		possivelMovimentoTorre(peca, posicaoDestino);
			break;
		case CAVALO_BRANCO:
    		possivelMovimentoCavalo(peca, posicaoDestino);
			break;
		case CAVALO_PRETO:    			
			possivelMovimentoCavalo(peca, posicaoDestino);
			break;
		case BISPO_BRANCO:
			possivelMovimentoBispo(peca, posicaoDestino);
			break;
		case BISPO_PRETO:
    		possivelMovimentoBispo(peca, posicaoDestino);
			break;
		case REI_BRANCO:
    		possivelMovimentoRei(peca, posicaoDestino);
			break;
		case REI_PRETO:
    		possivelMovimentoRei(peca, posicaoDestino);
			break;
		case RAINHA_BRANCO:
    		possivelMovimentoRainha(peca, posicaoDestino);
			break;
		case RAINHA_PRETO:
    		possivelMovimentoRainha(peca, posicaoDestino);
			break;
	}

	return VERDADEIRO;
}

