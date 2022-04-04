#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int largura, altura;
    int ** matriz = NULL;
    int qtd_elementos_unicos;
    int * elementos_unicos = NULL;
    int * p = NULL;
    int i, i2, j, j2, k;

    scanf("%d%d", &altura, &largura);

    if(largura > 10 || largura <= 0 || altura > 10 || altura <= 0) {
        printf("dimensao invalida\n");
        return 0;
    }

    matriz = calloc(altura, sizeof(int *));

    for(i = 0; i < altura; i++) {
        matriz[i] = calloc(largura, sizeof(int));
        for(j = 0; j < largura; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    elementos_unicos = malloc(largura*altura*sizeof(int));

    for(i = 0, k = 0; i < altura; i++) {
        for(j = 0; j < largura; j++) {
            for(i2 = 0; i2 < altura; i2++) {
                for(j2 = 0; j2 < largura; j2++) {
                    if(i == i2 && j == j2) continue;
                    if(matriz[i][j] == matriz[i2][j2]) break;
                }

                if(j2 != largura) break;
            }

            if(i2 == altura && j2 == largura) {
                elementos_unicos[k] = matriz[i][j];
                k++;
            }
        }
    }

    if(k == 0) printf("sem elementos unicos\n");
    else {
        p = realloc(elementos_unicos, k*sizeof(int));
        if(p != NULL) elementos_unicos = p;

        for(i = 0; i < k; i++) {
            if(i == k - 1) printf("%d\n", elementos_unicos[i]);
            else printf("%d,", elementos_unicos[i]);
        }
    }
    
    for(i = 0; i < altura; i++) {
        free(matriz[i]);
    }

    free(matriz);
    free(elementos_unicos);

    return 0;
}