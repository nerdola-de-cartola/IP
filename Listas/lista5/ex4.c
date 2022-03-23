#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int m = 0, n = 0;
    int ** matriz;
    int i, j;

    while(m <= 0 || m > 10) {
        scanf("%d", &m);
    }

    while(n <= 0 || n > 10) {
        scanf("%d", &n);
    }

    matriz = (int **) malloc(m * sizeof (int *));

    for(i = 0; i < m; i++) {
        matriz[i] = (int *) malloc(n * sizeof (int));
    }

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    for(i = 0; i < m; i++) {
        printf("linha %d: ", i+1);
        for(j = 0; j < n; j++) {
            if(j != n - 1) printf("%d,", matriz[i][j]);
            else printf("%d", matriz[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < m; i++) {
        free(matriz[i]);
    }

    free(matriz);

    return 0;
}