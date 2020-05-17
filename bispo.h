void possivelMovimentoBispo(Peca *peca, Posicao posicaoDestino) {
	inicializarMatrizMovimentosPossiveis(peca);
	Posicao p;
		
	// nw
	p.linha=peca->posicao.linha-1;
	p.coluna=peca->posicao.coluna-1;
	while (posicaoExiste(p) && !existePeca(p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
		p.linha=peca->posicao.linha-1;
		p.coluna=peca->posicao.coluna-1;
	}
	if (posicaoExiste(p) && ehPecaOponente(*peca, p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
	}
		
	// ne
	p.linha=peca->posicao.linha-1;
	p.coluna=peca->posicao.coluna+1;
	while (posicaoExiste(p) && !existePeca(p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
		p.linha=peca->posicao.linha-1;
		p.coluna=peca->posicao.coluna+1;
	}
	if (posicaoExiste(p) && ehPecaOponente(*peca, p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
	}
		
	// se
	p.linha=peca->posicao.linha + 1;
	p.coluna=peca->posicao.coluna + 1;
	while (posicaoExiste(p) && !existePeca(p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
		p.linha=peca->posicao.linha + 1;
		p.coluna=peca->posicao.coluna +1;
	}
	if (posicaoExiste(p) && ehPecaOponente(*peca, p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
	}
		
	// sw
	p.linha=peca->posicao.linha + 1;
	p.coluna=peca->posicao.coluna - 1;
	while (posicaoExiste(p) && !existePeca(p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
		p.linha=peca->posicao.linha + 1;
	}
	if (posicaoExiste(p) && ehPecaOponente(*peca, p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
	}
}
