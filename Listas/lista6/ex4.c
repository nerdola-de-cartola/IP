#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ponto {
    double u;
    double x;
    double y;
    double z;
    double norma;
};

typedef struct ponto Ponto;

int main(void) {
    int qtd_pontos;
    int i, j, menor;
    Ponto * arr = NULL;
    Ponto tmp;

    scanf("%d", &qtd_pontos);

    arr = calloc(qtd_pontos, sizeof(Ponto));

    for(i = 0; i < qtd_pontos; i++) {
        scanf("%lf%lf%lf%lf", &arr[i].u, &arr[i].x, &arr[i].y, &arr[i].z);
        arr[i].norma = sqrt(arr[i].u*arr[i].u + arr[i].x*arr[i].x + arr[i].y*arr[i].y + arr[i].z*arr[i].z);
    }

    for(i = 0; i < qtd_pontos - 1; i++) {
        menor = i;

        for(j = i + 1; j < qtd_pontos; j++) {
            if(arr[j].norma < arr[menor].norma) menor = j;
        }

        if(i != menor) {
            tmp = arr[i];
            arr[i] = arr[menor];
            arr[menor] = tmp;
        }
    }

    for(i = 0; i < qtd_pontos; i++) {
        printf("Vetor: (%.2lf, %.2lf, %.2lf, %.2lf) Norma: %.2lf\n", arr[i].u, arr[i].x, arr[i].y, arr[i].z, arr[i].norma);
    }

    free(arr);

    return 0;
}