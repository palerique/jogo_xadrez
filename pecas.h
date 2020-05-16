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
int movimentar_peao(Peca peca, Posicao posicaoDestino);
int movimentar_torre(Peca peca, Posicao posicaoDestino);
int movimentar_cavalo(Peca peca, Posicao posicaoDestino);
int movimentar_bispo(Peca peca, Posicao posicaoDestino);
int movimentar_rei(Peca peca, Posicao posicaoDestino);
int movimentar_rainha(Peca peca, Posicao posicaoDestino);

void inicializarMatrizMovimentosPossiveis(int matrizMovimentosPossiveis[LINHAS_TABULEIRO][COLUNAS_TABULEIRO]) {
	int i=0, j=0;
	for(i=0; i<LINHAS_TABULEIRO; i++) {
		for(j=0; j<COLUNAS_TABULEIRO; j++) {
			matrizMovimentosPossiveis[i][j]=FALSO;
		}
	}
}

int movimentar_peao(Peca peca, Posicao posicaoDestino) {
		int matrizMovimentosPossiveis[LINHAS_TABULEIRO][COLUNAS_TABULEIRO];
		inicializarMatrizMovimentosPossiveis(matrizMovimentosPossiveis);

		int sucesso = 0;
		Posicao p;

		p.linha=peca.posicao.linha+1;
		p.coluna=peca.posicao.coluna;

		if (posicaoExiste(p) && !existePeca(p)) {
			matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
		}

		p.linha=peca.posicao.linha+2;
		p.coluna=peca.posicao.coluna;
		Posicao p2;
		p2.linha=peca.posicao.linha+1;
		p2.coluna=peca.posicao.coluna;

		if (posicaoExiste(p) && !existePeca(p) && posicaoExiste(p2) && !existePeca(p2)  && peca.movimentos== 0) {
				matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
		}

		if(peca.posicao.coluna>0) {
			p.linha=peca.posicao.linha+1;
			p.coluna=peca.posicao.coluna-1;
			if (posicaoExiste(p) && ehPecaOponente(peca, p)) {
				matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
			}			
		}
		if(peca.posicao.coluna<7) {
			p.linha=peca.posicao.linha+1;
			p.coluna=peca.posicao.coluna+1;
			if (posicaoExiste(p) && ehPecaOponente(peca, p)) {
				matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
			}
		}

		return 1;
}

int movimentar_torre(Peca peca, Posicao posicaoDestino) {
		printf("\nTorre Preto\n");

		return 1;
}

int movimentar_cavalo(Peca peca, Posicao posicaoDestino) {
		printf("\nCavalo Preto\n");

		return 1;
}

int movimentar_bispo(Peca peca, Posicao posicaoDestino) {
		printf("\nBispo Branco\n");

 		return 1;
}

int movimentar_rei(Peca peca, Posicao posicaoDestino) {
		printf("\nRei Branco\n");

 		return 1;
}

int movimentar_rainha(Peca peca, Posicao posicaoDestino) {
		printf("\nRainha Branco\n");

 		return 1;
}
