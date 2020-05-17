#include "partida_xadrez.h"


int main () {
    int linhaPeca, colunaPeca, linhaDestino, colunaDestino, jogadorAtual=1, movimentoValido=0;


    inicializar_tabuleiro();
    
    while(1) {
        printf("Jogador Atual: %d\n", jogadorAtual);
        exibir_tabuleiro();
        printf("Entre com a linha da peça que deseja movimentar: ");
        scanf("%d", &linhaPeca);
        printf("Entre com a coluna da peça que deseja movimentar: ");
        scanf("%d", &colunaPeca);
        
        printf("Entre com a linha para onde deseja movimentar: ");
        scanf("%d", &linhaDestino);
        printf("Entre com a coluna para onde deseja movimentar: ");
        scanf("%d", &colunaDestino);
        
        Posicao posicaoAtual, posicaoDestino;
        posicaoAtual.linha=linhaPeca;
        posicaoAtual.coluna=colunaPeca;
        posicaoDestino.linha=linhaDestino;
        posicaoDestino.coluna=colunaDestino;

        movimentoValido=movimentar_peca(posicaoAtual, posicaoDestino, jogadorAtual);
        
        jogadorAtual*=-1;
    }
	return 1;
}
