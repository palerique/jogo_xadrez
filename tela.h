#include <windows.h>

char tabuleiro[LINHAS_TABULEIRO][COLUNAS_TABULEIRO]= { 
  {TORRE_BRANCO, CAVALO_BRANCO, BISPO_BRANCO, REI_BRANCO, RAINHA_BRANCO, BISPO_BRANCO, CAVALO_BRANCO, TORRE_BRANCO},
  {PEAO_BRANCO, PEAO_BRANCO, PEAO_BRANCO, PEAO_BRANCO, PEAO_BRANCO, PEAO_BRANCO, PEAO_BRANCO, PEAO_BRANCO},
  {ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO},
  {ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO},
  {ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO},
  {ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO, ESPACO_VAZIO},
  {PEAO_PRETO, PEAO_PRETO, PEAO_PRETO, PEAO_PRETO, PEAO_PRETO, PEAO_PRETO, PEAO_PRETO, PEAO_PRETO},
  {TORRE_PRETO, CAVALO_PRETO, BISPO_PRETO, RAINHA_PRETO, REI_PRETO, BISPO_PRETO, CAVALO_PRETO, TORRE_PRETO}
};

void exibir_tabuleiro() {
	int linha, coluna;
    SetConsoleOutputCP(CP_UTF8);

	printf("   ");

	for (coluna = 0; coluna < COLUNAS_TABULEIRO; coluna++)
		printf("%d  ", coluna+1);

	printf("\n");
	for (coluna = 0; coluna < COLUNAS_TABULEIRO*3+1; coluna++)
		printf("%s","\xe2\x94\x81");
	printf("\n");

	for (linha = 0; linha < LINHAS_TABULEIRO; linha++) {
		printf("%d\xe2\x94\x83", linha+1);

		for (coluna = 0; coluna < COLUNAS_TABULEIRO; coluna++) {
			switch (pecas[linha][coluna].tipo) {
				case REI_BRANCO:
					printf("%s  ","\xe2\x99\x9a");
					break;
				case REI_PRETO:
					printf("%s  ","\xe2\x99\x94");
					break;
				case PEAO_BRANCO:
					printf("%s  ","\xe2\x99\x9f");
					break;
				case PEAO_PRETO:
					printf("%s  ","\xe2\x99\x99");
					break;
				case BISPO_PRETO:
					printf("%s  ","\xe2\x99\x97");
					break;
				case BISPO_BRANCO:
					printf("%s  ","\xe2\x99\x9d");
					break;
				case RAINHA_PRETO:
					printf("%s  ","\xe2\x99\x95");
					break;
				case RAINHA_BRANCO:
					printf("%s  ","\xe2\x99\x9b");
					break;
				case TORRE_BRANCO:
					printf("%s  ","\xe2\x99\x9c");
					break;
				case TORRE_PRETO:
					printf("%s  ","\xe2\x99\x96");
					break;
				case CAVALO_PRETO:
					printf("%s  ","\xe2\x99\x98");
					break;
				case CAVALO_BRANCO:
					printf("%s  ","\xe2\x99\x9e");
					break;
				case ESPACO_VAZIO:
					printf("   ");
					break;
			}
		}
		printf("\n");

	}

	for (coluna = 0; coluna < COLUNAS_TABULEIRO*3+1; coluna++)
		printf("%s","\xe2\x94\x81");
	printf("\n");

}
