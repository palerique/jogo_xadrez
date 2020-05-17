#include <stdio.h>
#include <locale.h>
#include <Windows.h>
#include "pecas.h"
#include "tela.h"


void colocarNovaPeca(Peca *peca, Posicao posicao, int tipoPeca, int cor);
void inicializar_tabuleiro();
void exibir_tabuleiro();
int validar_movimento(Peca *peca, Posicao posicaoDestino, int jogadorAtual);
int movimentar_peca(Posicao posicaoAtual, Posicao posicaoDestino, int jogadorAtual);



void inicializar_tabuleiro() {
	int linha, coluna;
	for (linha = 0; linha < LINHAS_TABULEIRO; linha++) {
		for (coluna = 0; coluna < COLUNAS_TABULEIRO; coluna++) {
			char pecaSelecionada = tabuleiro[linha][coluna];
			Peca peca;
			
			Posicao posicao;
			posicao.linha=linha;
			posicao.coluna=coluna;
			
			switch (pecaSelecionada) {
				case PEAO_BRANCO:
					colocarNovaPeca(&peca, posicao, PEAO_BRANCO, BRANCO);
					break;
				case PEAO_PRETO:
					colocarNovaPeca(&peca, posicao, PEAO_PRETO, PRETO);
					break;
				case TORRE_BRANCO:
					colocarNovaPeca(&peca, posicao, TORRE_BRANCO, BRANCO);
					break;
				case TORRE_PRETO:
					colocarNovaPeca(&peca, posicao, TORRE_PRETO, PRETO);
					break;
				case CAVALO_BRANCO:
					colocarNovaPeca(&peca, posicao, CAVALO_BRANCO, BRANCO);
					break;
				case CAVALO_PRETO:
					colocarNovaPeca(&peca, posicao, CAVALO_PRETO, PRETO);
					break;
				case BISPO_BRANCO:
					colocarNovaPeca(&peca, posicao, BISPO_BRANCO, BRANCO);
					break;
				case BISPO_PRETO:
					colocarNovaPeca(&peca, posicao, BISPO_PRETO, PRETO);
					break;
				case REI_BRANCO:
					colocarNovaPeca(&peca, posicao, REI_BRANCO, BRANCO);
					break;
				case REI_PRETO:
					colocarNovaPeca(&peca, posicao, REI_PRETO, PRETO);
					break;
				case RAINHA_BRANCO:
					colocarNovaPeca(&peca, posicao, RAINHA_BRANCO, BRANCO);
					break;
				case RAINHA_PRETO:
					colocarNovaPeca(&peca, posicao, RAINHA_PRETO, PRETO);
					break;
				case ESPACO_VAZIO:
					colocarNovaPeca(&peca, posicao, ESPACO_VAZIO, ESPACO_VAZIO);
					break;
			}
		}
	}
}

int movimentar_peca(Posicao posicaoAtual, Posicao posicaoDestino, int jogadorAtual) {
	int movimento_valido = 0;

	posicaoAtual.linha--; posicaoAtual.coluna--; posicaoDestino.linha--; posicaoDestino.coluna--;
	Peca peca = pecas[posicaoAtual.linha][posicaoAtual.coluna];
	peca.posicao.linha=posicaoAtual.linha;
	peca.posicao.coluna=posicaoAtual.coluna;
	movimento_valido = validar_movimento(&peca, posicaoDestino, jogadorAtual);

	printf("%d %d %d %d\n", posicaoDestino.linha, posicaoDestino.coluna, peca.posicao.linha, peca.posicao.coluna);
	int i,j;
	for(i=0; i<8; i++) {
		for(j=0; j<8; j++){
			printf("%d ", peca.matrizMovimentosPossiveis[i][j] );
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
		printf("\nMovimento invalido\n");
	}
		
	return 1;
}

void colocarNovaPeca(Peca *peca, Posicao posicao, int tipoPeca, int cor) {
	peca->tipo=tipoPeca;
	peca->cor=cor;
	peca->movimentos=0;
	pecas[posicao.linha][posicao.coluna]=*peca;
	peca->posicao=posicao;
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

