#define LINHAS_TABULEIRO 	8
#define COLUNAS_TABULEIRO 	8
#define VERDADEIRO 			1
#define FALSO 				0
#define PEAO_BRANCO			'p'
#define PEAO_PRETO 			'P'
#define BISPO_BRANCO 		'b'
#define BISPO_PRETO 		'B'
#define CAVALO_BRANCO 		'c'
#define CAVALO_PRETO 		'C'
#define TORRE_BRANCO 		't'
#define TORRE_PRETO 		'T'
#define REI_BRANCO 			'k'
#define REI_PRETO 			'K'
#define RAINHA_BRANCO 		'q'
#define RAINHA_PRETO 		'Q'
#define ESPACO_VAZIO 		' '
#define PRETO 				1
#define BRANCO 				0

// typedef é para o programador C criar seus próprios tipos de dados
typedef struct {
	int linha, coluna;
} Posicao ;

typedef struct str_peca {
	char tipo;
	int cor;
	Posicao posicao;
	int movimentos;
	int matrizMovimentosPossiveis[LINHAS_TABULEIRO][COLUNAS_TABULEIRO];
    void (*fn_movimentosPossiveis) (struct str_peca *peca, Posicao posicaoDestino);
} Peca ;

Peca pecas[LINHAS_TABULEIRO][COLUNAS_TABULEIRO];

int posicaoExiste(Posicao posicao);
int existePeca(Posicao posicao);
int ehPecaOponente(Peca peca, Posicao posicaoDestino);
void possivelMovimentoPeao(Peca *peca, Posicao posicaoDestino);
void possivelMovimentoRainha(Peca *peca, Posicao posicaoDestino);
void possivelMovimentoCavalo(Peca *peca, Posicao posicaoDestino);
void possivelMovimentoRei(Peca *peca, Posicao posicaoDestino);
void possivelMovimentoTorre(Peca *peca, Posicao posicaoDestino);
void possivelMovimentoBispo(Peca *peca, Posicao posicaoDestino);
void inicializarMatrizMovimentosPossiveis(Peca *peca);

void inicializarMatrizMovimentosPossiveis(Peca *peca) {
	int i=0, j=0;
	for(i=0; i<LINHAS_TABULEIRO; i++) {
		for(j=0; j<COLUNAS_TABULEIRO; j++) {
			peca->matrizMovimentosPossiveis[i][j]=FALSO;
		}
	}
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

int ehPecaOponente(Peca peca, Posicao posicaoDestino) {
	Peca pecaDestino = pecas[posicaoDestino.linha][posicaoDestino.coluna];
	if(pecaDestino.cor != peca.cor)
		return VERDADEIRO;

	return FALSO;
}

#include "peao.h"
#include "torre.h"
#include "cavalo.h"
#include "rainha.h"
#include "bispo.h"
#include "rei.h"
