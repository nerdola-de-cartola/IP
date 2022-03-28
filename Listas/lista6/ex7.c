#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ponto {
    double u;
    double x;
    double y;
    double z;
};

typedef struct ponto Ponto;

double calculaDistancia(Ponto a, Ponto b);

int main(void) {
    Ponto * pontos = NULL;
    int qtd_pontos;
    int i;

    scanf("%d", &qtd_pontos);

    pontos = calloc(qtd_pontos, sizeof(Ponto));

    for(i = 0; i < qtd_pontos; i++) scanf("%lf%lf%lf%lf", &pontos[i].u, &pontos[i].x, &pontos[i].y, &pontos[i].z);

    for(i = 0; i < qtd_pontos-1; i++) {
        printf("%.2lf\n", calculaDistancia(pontos[i], pontos[i+1]));
    }

    free(pontos);

    return 0;
}

double calculaDistancia(Ponto a, Ponto b) {
    double u, x, y, z;

    u = a.u - b.u;
    u *= u;

    x = a.x - b.x;
    x *= x;

    y = a.y - b.y;
    y *= y;

    z = a.z - b.z;
    z *= z;

    return sqrt(u+x+y+z);
}
