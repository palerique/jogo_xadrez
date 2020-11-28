void possivelMovimentoBispo(Peca *peca, Posicao posicaoDestino) {
	inicializarMatrizMovimentosPossiveis(peca);

	Posicao p;
	
	// movimenta diagonal para cima e direita - Nordeste
	p.linha = peca->posicao.linha - 1;
	p.coluna = peca->posicao.coluna + 1;
	while(posicaoExiste(p) && !existePeca(p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
		p.linha = p.linha - 1;
		p.coluna = p.coluna + 1;
	}
	if(posicaoExiste(p) && ehPecaOponente(*peca, p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
	}			

	// movimenta diagonal para cima e esquerda - Noroeste
	p.linha = peca->posicao.linha - 1;
	p.coluna = peca->posicao.coluna - 1;
	while(posicaoExiste(p) && !existePeca(p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
		p.linha = p.linha - 1;
		p.coluna = p.coluna - 1;
	}
	if(posicaoExiste(p) && ehPecaOponente(*peca, p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
	}		

	// movimenta diagonal para baixo e esquerda - Sudoeste
	p.linha = peca->posicao.linha + 1;
	p.coluna = peca->posicao.coluna - 1;
	while(posicaoExiste(p) && !existePeca(p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
		p.linha = p.linha + 1;
		p.coluna = p.coluna - 1;
	}
	if(posicaoExiste(p) && ehPecaOponente(*peca, p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
	}		

	// movimenta diagonal para baixo e direita - Sudeste
	p.linha = peca->posicao.linha + 1;
	p.coluna = peca->posicao.coluna + 1;
	while(posicaoExiste(p) && !existePeca(p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
		p.linha = p.linha + 1;
		p.coluna = p.coluna + 1;
	}
	if(posicaoExiste(p) && ehPecaOponente(*peca, p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
	}		

}
