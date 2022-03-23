#include <stdio.h>
#include <stdlib.h>

double determinante2x2(double **matriz);

int main(void) {
    double det;
    double **matriz;
    int i;

    matriz = (double **) malloc(2 * sizeof (double *));

    for(i = 0; i < 2; i++) {
        matriz[i] = (double *) malloc(sizeof (double));
        scanf("%lf %lf", &matriz[i][0], &matriz[i][1]);
    }

    det = determinante2x2(matriz);

    printf("%.2lf\n", det);

    for(i = 0; i < 2; i++) {
        free(matriz[i]);
    }
    free(matriz);
    
    return 0;
}

double determinante2x2(double **matriz) {
    int i, j;
    double diagonal_principal;
    double diagonal_secundaria;

    diagonal_principal = matriz[0][0] * matriz[1][1];
    diagonal_secundaria = matriz[0][1] * matriz[1][0];

    return diagonal_principal - diagonal_secundaria;
}