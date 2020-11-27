#include <stdio.h>
#include <locale.h>
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
					peca.fn_movimentosPossiveis=possivelMovimentoPeao;
					colocarNovaPeca(&peca, posicao, PEAO_BRANCO, BRANCO);
					break;
				case PEAO_PRETO:
					peca.fn_movimentosPossiveis=possivelMovimentoPeao;
					colocarNovaPeca(&peca, posicao, PEAO_PRETO, PRETO);
					break;
				case TORRE_BRANCO:
					peca.fn_movimentosPossiveis=possivelMovimentoTorre;
					colocarNovaPeca(&peca, posicao, TORRE_BRANCO, BRANCO);
					break;
				case TORRE_PRETO:
					peca.fn_movimentosPossiveis=possivelMovimentoTorre;
					colocarNovaPeca(&peca, posicao, TORRE_PRETO, PRETO);
					break;
				case CAVALO_BRANCO:
					peca.fn_movimentosPossiveis=possivelMovimentoCavalo;
					colocarNovaPeca(&peca, posicao, CAVALO_BRANCO, BRANCO);
					break;
				case CAVALO_PRETO:
					peca.fn_movimentosPossiveis=possivelMovimentoCavalo;
					colocarNovaPeca(&peca, posicao, CAVALO_PRETO, PRETO);
					break;
				case BISPO_BRANCO:
					peca.fn_movimentosPossiveis=possivelMovimentoBispo;
					colocarNovaPeca(&peca, posicao, BISPO_BRANCO, BRANCO);
					break;
				case BISPO_PRETO:
					peca.fn_movimentosPossiveis=possivelMovimentoBispo;
					colocarNovaPeca(&peca, posicao, BISPO_PRETO, PRETO);
					break;
				case REI_BRANCO:
					peca.fn_movimentosPossiveis=possivelMovimentoRei;
					colocarNovaPeca(&peca, posicao, REI_BRANCO, BRANCO);
					break;
				case REI_PRETO:
					peca.fn_movimentosPossiveis=possivelMovimentoRei;
					colocarNovaPeca(&peca, posicao, REI_PRETO, PRETO);
					break;
				case RAINHA_BRANCO:
					peca.fn_movimentosPossiveis=possivelMovimentoRainha;
					colocarNovaPeca(&peca, posicao, RAINHA_BRANCO, BRANCO);
					break;
				case RAINHA_PRETO:
					peca.fn_movimentosPossiveis=possivelMovimentoRainha;
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

	int i,j;
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

    peca->fn_movimentosPossiveis(peca, posicaoDestino);

	return VERDADEIRO;
}
