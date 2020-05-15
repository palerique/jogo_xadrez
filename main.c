#include "xadrez.h"

int main () {
    int linhaPeca, colunaPeca, linhaDestino, colunaDestino, jogadorAtual=1, movimentoValido=0;
    
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
        
        movimentoValido=movimentar_peca(linhaPeca, colunaPeca, linhaDestino, colunaDestino, jogadorAtual);
        
        jogadorAtual*=-1;
    }
	return 1;
}
