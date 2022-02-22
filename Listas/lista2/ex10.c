#include <stdio.h>

int main(void) {
    int linhas, colunas;
    int linha, coluna;

    scanf("%d %d", &linhas, &colunas);

    char matriz[colunas][linhas];

    for(linha = 1; linha <= linhas; linha++) {
        for(coluna = 1; coluna <= colunas; coluna++) {

            if(linha > coluna) {
                printf("(%d,%d)", linha, coluna);

                if(coluna != linha - 1 && coluna != colunas) {
                    printf("-");
                }
            }
        }

        printf("\n");
    }

    return 0;
}