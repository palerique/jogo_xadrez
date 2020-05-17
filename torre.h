void possivelMovimentoTorre(Peca *peca, Posicao posicaoDestino) {
	inicializarMatrizMovimentosPossiveis(peca);
	Posicao p;
	p.linha=peca->posicao.linha-1;
	p.coluna=peca->posicao.coluna;
	while (posicaoExiste(p) && !existePeca(p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
		p.linha = p.linha - 1;
	}

	if (posicaoExiste(p) && ehPecaOponente(*peca, p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
	}

	// esquerda
	p.linha=peca->posicao.linha;
	p.coluna=peca->posicao.coluna - 1;
	while (posicaoExiste(p) && !existePeca(p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
		p.coluna = p.coluna - 1;
	}
	if(posicaoExiste(p) && ehPecaOponente(*peca, p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
	}
	
	// direita
	p.linha=peca->posicao.linha;
	p.coluna=peca->posicao.coluna + 1;
	while(posicaoExiste(p) && !existePeca(p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
		p.coluna=p.coluna + 1;
	}
	if (posicaoExiste(p) && ehPecaOponente(*peca, p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
	}
		
	// abaixo
	p.linha=peca->posicao.linha + 1;
	p.coluna=peca->posicao.coluna;
	while (posicaoExiste(p) && !existePeca(p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
		p.linha=p.linha + 1;
	}
	if(posicaoExiste(p) && ehPecaOponente(*peca, p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
	}
}
