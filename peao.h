void possivelMovimentoPeao(Peca *peca, Posicao posicaoDestino) {
	inicializarMatrizMovimentosPossiveis(peca);

	if(peca->cor==BRANCO) {
		Posicao p;

		// Movimento 1 - Peão Branco vai descendo uma casa para baixo
		// p é para verificar se o peão branco consegue movimentar para baixo
		p.linha = peca->posicao.linha+1;
		p.coluna=peca->posicao.coluna;

		// Avalia se o p é uma posição válida e para o lugar onde ele deseja ir
		// não existe peça(rei, rainha, torre, bispo, peão, cavalo)
		if (posicaoExiste(p) && !existePeca(p)) {
			// Se atender as condições você atribui VERDADEIRO
			peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
		}

		// Movimento 2 - Peão Branco vai descendo uma ou duas casas para baixo 
		// Na primeira movimentação
		// eu simulo o peão branco indo duas linhas para baixo
		p.linha=peca->posicao.linha+2; // projeta duas linhas para baixo
		p.coluna=peca->posicao.coluna;
		Posicao p2;
		p2.linha=peca->posicao.linha+1; // projeta uma linha para baixo
		p2.coluna=peca->posicao.coluna;
		if (posicaoExiste(p) && !existePeca(p) && posicaoExiste(p2) && !existePeca(p2)  && peca->movimentos== 0) {
			peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
		}

		// Movimento 3 - Capturar uma peça e um peão captura uma peça pela diagonal 
		// esquerda e indo para baixo
		if(peca->posicao.coluna > 0) {
			p.linha=peca->posicao.linha+1;
			p.coluna=peca->posicao.coluna-1;
			if(posicaoExiste(p) && ehPecaOponente(*peca, p)) {
				peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
			}			
		}

		// Movimento 4 - Capturar uma peça e lembrando que um peão pode capturar uma peça 
		// pela diagonal direita e indo para baixo
		if(peca->posicao.coluna < 7) {
			p.linha=peca->posicao.linha+1;
			p.coluna=peca->posicao.coluna+1;
			if(posicaoExiste(p) && ehPecaOponente(*peca, p)) {
				peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
			}			
		}
	} else {
		Posicao p;

		p.linha=peca->posicao.linha-1;
		p.coluna=peca->posicao.coluna;

		if (posicaoExiste(p) && !existePeca(p)) {
			peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
		}

		p.linha=peca->posicao.linha-2;
		p.coluna=peca->posicao.coluna;
		Posicao p2;
		p2.linha=peca->posicao.linha-1;
		p2.coluna=peca->posicao.coluna;

		if (posicaoExiste(p) && !existePeca(p) && posicaoExiste(p2) && !existePeca(p2)  && peca->movimentos== 0) {
			peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
		}

		// Movimento 3 - Capturar uma peça e um peão Preto captura uma peça pela diagonal 
		// esquerda e indo para cima
		if(peca->posicao.coluna > 0) {
			p.linha=peca->posicao.linha-1; // indo para cima
			p.coluna=peca->posicao.coluna-1; // indo para esquerda
			if(posicaoExiste(p) && ehPecaOponente(*peca, p)) {
				peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
			}			
		}

		// Movimento 4 - Capturar uma peça e lembrando que um peão Preto pode capturar uma peça 
		// pela diagonal direita e indo para cima
		if(peca->posicao.coluna < 7) {
			p.linha=peca->posicao.linha-1;
			p.coluna=peca->posicao.coluna+1;
			if(posicaoExiste(p) && ehPecaOponente(*peca, p)) {
				peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
			}			
		}
	}
}
