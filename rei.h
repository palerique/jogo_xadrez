void possivelMovimentoRei(Peca *peca, Posicao posicaoDestino) {
    inicializarMatrizMovimentosPossiveis(peca);

    Posicao p;

    // movimenta cima - Norte
    p.linha = peca->posicao.linha - 1;
    p.coluna = peca->posicao.coluna;
    if (posicaoExiste(p) && !existePeca(p)) {
        salvarMovimentoPossivel(peca, &p);
    }
    if (posicaoExiste(p) && ehPecaOponente(*peca, p)) {
        salvarMovimentoPossivel(peca, &p);
    }

    // movimenta para baixo - SUL
    p.linha = peca->posicao.linha + 1;
    p.coluna = peca->posicao.coluna;
    if (posicaoExiste(p) && !existePeca(p)) {
        salvarMovimentoPossivel(peca, &p);
    }
    if (posicaoExiste(p) && ehPecaOponente(*peca, p)) {
        salvarMovimentoPossivel(peca, &p);
    }

    // movimenta para esquerda OESTE
    p.linha = peca->posicao.linha;
    p.coluna = peca->posicao.coluna - 1;
    if (posicaoExiste(p) && !existePeca(p)) {
        salvarMovimentoPossivel(peca, &p);
    }
    if (posicaoExiste(p) && ehPecaOponente(*peca, p)) {
        salvarMovimentoPossivel(peca, &p);
    }

    // movimenta para direita - LESTE
    p.linha = peca->posicao.linha;
    p.coluna = peca->posicao.coluna + 1;
    if (posicaoExiste(p) && !existePeca(p)) {
        salvarMovimentoPossivel(peca, &p);
    }
    if (posicaoExiste(p) && ehPecaOponente(*peca, p)) {
        salvarMovimentoPossivel(peca, &p);
    }

    // movimenta diagonal para cima e direita - Nordeste
    p.linha = peca->posicao.linha - 1;
    p.coluna = peca->posicao.coluna + 1;
    if (posicaoExiste(p) && !existePeca(p)) {
        salvarMovimentoPossivel(peca, &p);
    }
    if (posicaoExiste(p) && ehPecaOponente(*peca, p)) {
        salvarMovimentoPossivel(peca, &p);
    }

    // movimenta diagonal para cima e esquerda - Noroeste
    p.linha = peca->posicao.linha - 1;
    p.coluna = peca->posicao.coluna - 1;
    if (posicaoExiste(p) && !existePeca(p)) {
        salvarMovimentoPossivel(peca, &p);
    }
    if (posicaoExiste(p) && ehPecaOponente(*peca, p)) {
        salvarMovimentoPossivel(peca, &p);
    }

    // movimenta diagonal para baixo e esquerda - Sudoeste
    p.linha = peca->posicao.linha + 1;
    p.coluna = peca->posicao.coluna - 1;
    if (posicaoExiste(p) && !existePeca(p)) {
        salvarMovimentoPossivel(peca, &p);
    }
    if (posicaoExiste(p) && ehPecaOponente(*peca, p)) {
        salvarMovimentoPossivel(peca, &p);
    }

    // movimenta diagonal para baixo e direita - Sudeste
    p.linha = peca->posicao.linha + 1;
    p.coluna = peca->posicao.coluna + 1;
    if (posicaoExiste(p) && !existePeca(p)) {
        salvarMovimentoPossivel(peca, &p);
    }
    if (posicaoExiste(p) && ehPecaOponente(*peca, p)) {
        salvarMovimentoPossivel(peca, &p);
    }}
