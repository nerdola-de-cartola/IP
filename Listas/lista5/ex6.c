#include <stdio.h>
#include <stdlib.h>

#define ORDEM 6

int maiorAmpulheta(int ** matriz);

int main(void) {
    int ** matriz;
    int i, j;

    matriz = malloc(ORDEM * sizeof (int *));

    for(i = 0; i < ORDEM; i++) {
        matriz[i] = malloc(ORDEM * sizeof (int));
    }

    for(i = 0; i < ORDEM; i++) {
        for(j = 0; j < ORDEM; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("%d\n", maiorAmpulheta(matriz));

    for(i = 0; i < ORDEM; i++) {
        free(matriz[i]);
    }

    free(matriz);

    return 0;
}

int maiorAmpulheta(int ** matriz) {
    int maior = -9999999, soma;
    int i, j;

    for(i = 0; i < ORDEM - 2; i++) {
        for(j = 0; j < ORDEM - 2; j++) {
            soma = 0;

            soma += matriz[i][j];
            soma += matriz[i][j+1];
            soma += matriz[i][j+2];
            soma += matriz[i+1][j+1];
            soma += matriz[i+2][j];
            soma += matriz[i+2][j+1];
            soma += matriz[i+2][j+2];

            if(soma > maior) maior = soma;
        }
    }

    

    return maior;
}