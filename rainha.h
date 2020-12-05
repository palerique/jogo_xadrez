void movimentoPossivel(Peca *peca, Posicao *p);

void possivelMovimentoRainha(Peca *peca, Posicao posicaoDestino) {
    inicializarMatrizMovimentosPossiveis(peca);

    Posicao p;

    // movimenta cima - Norte
    p.linha = peca->posicao.linha - 1;
    p.coluna = peca->posicao.coluna;
    while (posicaoExiste(p) && !existePeca(p)) {
        movimentoPossivel(peca, &p);
        p.linha = p.linha - 1;
    }
    if (posicaoExiste(p) && ehPecaOponente(*peca, p)) {
        movimentoPossivel(peca, &p);
    }

    // movimenta para baixo - SUL
    p.linha = peca->posicao.linha + 1;
    p.coluna = peca->posicao.coluna;
    while (posicaoExiste(p) && !existePeca(p)) {
        movimentoPossivel(peca, &p);
        p.linha = p.linha - 1;
    }
    if (posicaoExiste(p) && ehPecaOponente(*peca, p)) {
        movimentoPossivel(peca, &p);
    }

    // movimenta para esquerda OESTE
    p.linha = peca->posicao.linha;
    p.coluna = peca->posicao.coluna - 1;
    while (posicaoExiste(p) && !existePeca(p)) {
        movimentoPossivel(peca, &p);
        p.coluna = p.coluna - 1;
    }
    if (posicaoExiste(p) && ehPecaOponente(*peca, p)) {
        movimentoPossivel(peca, &p);
    }

    // movimenta para direita - LESTE
    p.linha = peca->posicao.linha;
    p.coluna = peca->posicao.coluna + 1;
    while (posicaoExiste(p) && !existePeca(p)) {
        movimentoPossivel(peca, &p);
        p.coluna = p.coluna + 1;
    }
    if (posicaoExiste(p) && ehPecaOponente(*peca, p)) {
        movimentoPossivel(peca, &p);
    }

    // movimenta diagonal para cima e direita - Nordeste
    p.linha = peca->posicao.linha - 1;
    p.coluna = peca->posicao.coluna + 1;
    while (posicaoExiste(p) && !existePeca(p)) {
        movimentoPossivel(peca, &p);
        p.linha = p.linha - 1;
        p.coluna = p.coluna + 1;
    }
    if (posicaoExiste(p) && ehPecaOponente(*peca, p)) {
        movimentoPossivel(peca, &p);
    }

    // movimenta diagonal para cima e esquerda - Noroeste
    p.linha = peca->posicao.linha - 1;
    p.coluna = peca->posicao.coluna - 1;
    while (posicaoExiste(p) && !existePeca(p)) {
        movimentoPossivel(peca, &p);
        p.linha = p.linha - 1;
        p.coluna = p.coluna - 1;
    }
    if (posicaoExiste(p) && ehPecaOponente(*peca, p)) {
        movimentoPossivel(peca, &p);
    }

    // movimenta diagonal para baixo e esquerda - Sudoeste
    p.linha = peca->posicao.linha + 1;
    p.coluna = peca->posicao.coluna - 1;
    while (posicaoExiste(p) && !existePeca(p)) {
        movimentoPossivel(peca, &p);
        p.linha = p.linha + 1;
        p.coluna = p.coluna - 1;
    }
    if (posicaoExiste(p) && ehPecaOponente(*peca, p)) {
        movimentoPossivel(peca, &p);
    }

    // movimenta diagonal para baixo e direita - Sudeste
    p.linha = peca->posicao.linha + 1;
    p.coluna = peca->posicao.coluna + 1;
    while (posicaoExiste(p) && !existePeca(p)) {
        movimentoPossivel(peca, &p);
        p.linha = p.linha + 1;
        p.coluna = p.coluna + 1;
    }
    if (posicaoExiste(p) && ehPecaOponente(*peca, p)) {
        movimentoPossivel(peca, &p);
    }
}

void
movimentoPossivel(Peca *peca, Posicao *p) { peca->matrizMovimentosPossiveis[(*p).linha][(*p).coluna] = VERDADEIRO; }
