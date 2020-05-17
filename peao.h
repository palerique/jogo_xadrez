void possivelMovimentoPeao(Peca *peca, Posicao posicaoDestino) {
	inicializarMatrizMovimentosPossiveis(peca);
	if(peca->cor==BRANCO) {
		Posicao p;
		p.linha=peca->posicao.linha+1;
		p.coluna=peca->posicao.coluna;
		
		if (posicaoExiste(p) && !existePeca(p)) {
			peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
		}

		p.linha=peca->posicao.linha+2;
		p.coluna=peca->posicao.coluna;
		Posicao p2;
		p2.linha=peca->posicao.linha+1;
		p2.coluna=peca->posicao.coluna;
		if (posicaoExiste(p) && !existePeca(p) && posicaoExiste(p2) && !existePeca(p2)  && peca->movimentos== 0) {
			peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
		}

		if(peca->posicao.coluna>0) {
			p.linha=peca->posicao.linha+1;
			p.coluna=peca->posicao.coluna-1;
			if (posicaoExiste(p) && ehPecaOponente(*peca, p)) {
				peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
			}			
		}

		if(peca->posicao.coluna<7) {
			p.linha=peca->posicao.linha+1;
			p.coluna=peca->posicao.coluna+1;
			if (posicaoExiste(p) && ehPecaOponente(*peca, p)) {
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

		if(peca->posicao.coluna>0) {
			p.linha=peca->posicao.linha-1;
			p.coluna=peca->posicao.coluna-1;
			if (posicaoExiste(p) && ehPecaOponente(*peca, p)) {
				peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
			}			
		}

		if(peca->posicao.coluna<7) {
			p.linha=peca->posicao.linha-1;
			p.coluna=peca->posicao.coluna+1;
			if (posicaoExiste(p) && ehPecaOponente(*peca, p)) {
				peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
			}
		}
	}
}