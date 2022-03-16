#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int **matriz;
    int i;

    matriz = (int **) malloc(2 * sizeof (int *));

    for(i = 0; i < 2; i++) {
        matriz[i] = (int *) malloc(4 * sizeof (int));
    }

    for(i = 0; i < 2; i++) {
        free(matriz[i]);
    }

    free(matriz);
    
    return 0;
}