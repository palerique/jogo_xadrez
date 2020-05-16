
typedef struct {
	int linha, coluna;
} Posicao ;

typedef struct {
	char tipo;
	int cor;
	Posicao posicao;
	int movimentos;
} Peca ;

#define LINHAS_TABULEIRO 8
#define COLUNAS_TABULEIRO 8
#define VERDADEIRO 1
#define FALSO 0

void inicializarMatrizMovimentosPossiveis(int matrizMovimentosPossiveis[LINHAS_TABULEIRO][COLUNAS_TABULEIRO]);

void inicializarMatrizMovimentosPossiveis(int matrizMovimentosPossiveis[LINHAS_TABULEIRO][COLUNAS_TABULEIRO]) {
	int i=0, j=0;
	for(i=0; i<LINHAS_TABULEIRO; i++) {
		for(j=0; j<COLUNAS_TABULEIRO; j++) {
			matrizMovimentosPossiveis[i][j]=FALSO;
		}
	}
}

int movimentar_peao(Peca peca, Posicao posicaoDestino);
int movimentar_rainha(Peca peca, Posicao posicaoDestino);
int movimentar_cavalo(Peca peca, Posicao posicaoDestino);
int movimentar_rei(Peca peca, Posicao posicaoDestino);
int movimentar_torre(Peca peca, Posicao posicaoDestino);
int movimentar_bispo(Peca peca, Posicao posicaoDestino);

#include "peao.h"
#include "torre.h"
#include "cavalo.h"
#include "rainha.h"
#include "bispo.h"
#include "rei.h"