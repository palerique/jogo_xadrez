void possivelMovimentoTorre(Peca *peca, Posicao posicaoDestino) {
	inicializarMatrizMovimentosPossiveis(peca);

	Posicao p;
	
	// movimenta cima - Norte
	p.linha = peca->posicao.linha - 1;
	p.coluna = peca->posicao.coluna;
	while(posicaoExiste(p) && !existePeca(p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
		p.linha = p.linha - 1;
	}
	if(posicaoExiste(p) && ehPecaOponente(*peca, p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
	}			

	// movimenta para baixo - SUL
	p.linha = peca->posicao.linha + 1;
	p.coluna = peca->posicao.coluna;
	while(posicaoExiste(p) && !existePeca(p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
		p.linha = p.linha - 1;
	}
	if(posicaoExiste(p) && ehPecaOponente(*peca, p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
	}		

	// movimenta para esquerda OESTE
	p.linha = peca->posicao.linha;
	p.coluna = peca->posicao.coluna - 1;
	while(posicaoExiste(p) && !existePeca(p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
		p.coluna = p.coluna - 1;
	}
	if(posicaoExiste(p) && ehPecaOponente(*peca, p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
	}		

	// movimenta para direita - LESTE
	p.linha = peca->posicao.linha;
	p.coluna = peca->posicao.coluna + 1;
	while(posicaoExiste(p) && !existePeca(p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
		p.coluna = p.coluna + 1;
	}
	if(posicaoExiste(p) && ehPecaOponente(*peca, p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
	}		
}
