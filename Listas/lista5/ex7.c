#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int tamanho;
    char borda, meio;
    char ** quadrado;
    int inicio_quadrado, fim_quadrado;
    int i, j;

    scanf("%d %c %c", &tamanho, &borda, &meio);
    if(tamanho <= 1 || tamanho > 99 || tamanho%2 == 0) {
        printf("Dimensao invalida!\n");
        return 0;
    }

    quadrado = malloc(tamanho * sizeof (char *));
    for(i = 0; i < tamanho; i++) {
        quadrado[i] = malloc(tamanho * sizeof (char));
    }

    inicio_quadrado = (tamanho / 2) + 1;
    fim_quadrado = (tamanho / 2) - 1;
    for(i = 0; i < tamanho; i++) {
        if(i < (tamanho/2) + 1) {
            inicio_quadrado--;
            fim_quadrado++;
        } else {
            inicio_quadrado++;
            fim_quadrado--;
        }

        for(j = 0; j < tamanho; j++) {
            if(j == inicio_quadrado  || j == fim_quadrado) {
                quadrado[i][j] = borda;
            } else if(j > inicio_quadrado && j < fim_quadrado) {
                quadrado[i][j] = meio;
            } else {
                quadrado[i][j] = ' ';
            }
        }
    }

    for(i = 0; i < tamanho; i++) {
        for(j = 0; j < tamanho; j++) {
            printf("%c ", quadrado[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < tamanho; i++) {
        free(quadrado[i]);
    }

    free(quadrado);

    return 0;
}