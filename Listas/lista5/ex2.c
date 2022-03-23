#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int ordem;
    int **matriz;
    int i, j;

    scanf("%d", &ordem);
    if(ordem < 1 || ordem > 1000) return 1;

    matriz = (int **) malloc(ordem * sizeof (int *));

    for(i = 0; i < ordem; i++) {
        matriz[i] = (int *) malloc(ordem * sizeof (int));
        for(j = 0; j < ordem; j++) scanf("%d", &matriz[i][j]);
    }

    for(i = 0, j = ordem - 1; i < ordem && j >= 0; i++, j--) printf("%d\n", matriz[i][j]);

    for(i = 0; i < ordem; i++) {
        free(matriz[i]);
    }

    free(matriz);

    return 0;
}