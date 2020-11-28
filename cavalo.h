// passagem por valor

int podeMover(Peca pecaOrigem, Posicao posicaoDestino) {
	Peca pecaDestino = pecas[posicaoDestino.linha][posicaoDestino.coluna];
	if(pecaDestino.tipo==ESPACO_VAZIO || pecaDestino.cor != pecaOrigem.cor ) {
		return VERDADEIRO;
	}

	return FALSO;
}

// movimento L do cavalo é ou duas casas para cima/baixo e uma casa para esquerda/direita
// movimento L do cavalo é ou uma casa para cima/baixo e duas casas para esquerda/direita
void possivelMovimentoCavalo(Peca *peca, Posicao posicaoDestino) {
	inicializarMatrizMovimentosPossiveis(peca);

	Posicao p;
	// Movimento 1 - uma linha para cima e duas colunas para esquerda
	p.linha = peca->posicao.linha - 1;
	p.coluna = peca->posicao.coluna - 2;
	if(posicaoExiste(p) && podeMover(*peca, p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
	}

	// Movimento 2 - uma linha para cima e duas colunas para direita
	// para ir para direita p.coluna = peca->posicao.coluna + 1; 
	// para ir para cimap.linha = peca->posicao.linha - 1;
	// p é uma posição que estou projetando que meu usuario possa querer ir
	p.linha = peca->posicao.linha - 1;
	p.coluna = peca->posicao.coluna + 2;
	if(posicaoExiste(p) && podeMover(*peca, p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
	}

	// Movimento 3 - uma linha para baixo e duas colunas para direita
	p.linha = peca->posicao.linha + 1;
	p.coluna = peca->posicao.coluna + 2;
	if(posicaoExiste(p) && podeMover(*peca, p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
	}

	// Movimento 4 - uma linha para baixo e duas colunas para esquerda
	p.linha = peca->posicao.linha + 1;
	p.coluna = peca->posicao.coluna - 2;
	if(posicaoExiste(p) && podeMover(*peca, p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
	}

	// Movimento 5 - duas linhas para cima e uma colunas para esquerda
	p.linha = peca->posicao.linha - 2;
	p.coluna = peca->posicao.coluna - 1;
	if(posicaoExiste(p) && podeMover(*peca, p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
	}

	// Movimento 6 - duas linhas para cima e uma coluna para direita
	p.linha = peca->posicao.linha - 2;
	p.coluna = peca->posicao.coluna + 1;
	if(posicaoExiste(p) && podeMover(*peca, p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
	}

	// Movimento 7 - duas linha para baixo e uma coluna para direita
	p.linha = peca->posicao.linha + 2;
	p.coluna = peca->posicao.coluna + 1;
	if(posicaoExiste(p) && podeMover(*peca, p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
	}

	// Movimento 8 - duas linha para baixo e uma colunas para esquerda
	p.linha = peca->posicao.linha + 2;
	p.coluna = peca->posicao.coluna - 1;
	if(posicaoExiste(p) && podeMover(*peca, p)) {
		peca->matrizMovimentosPossiveis[p.linha][p.coluna] = VERDADEIRO;
	}
}
