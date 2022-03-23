#include <stdio.h>
#include <stdlib.h>

#define QTD_CIDADES 6

void iniciaCidades(void);
int calculaDistancia(int * rota, int tamanho_rota);

int DISTANCIAS[QTD_CIDADES][QTD_CIDADES];

int main(void) {
    int i;
    int tamanho_rota, distancia;
    int * rota;

    iniciaCidades();

    scanf("%d", &tamanho_rota);

    rota = calloc(tamanho_rota, sizeof (int));

    for(i = 0; i < tamanho_rota; i++) {
        scanf("%d", &rota[i]);
    }

    distancia = calculaDistancia(rota, tamanho_rota);

    if(distancia == -1) printf("rota invalida!\n");
    else printf("%d\n", distancia);

    free(rota);

    return 0;
}

void iniciaCidades(void) {
    DISTANCIAS[0][0] = 0;
    DISTANCIAS[1][1] = 0;
    DISTANCIAS[2][2] = 0;
    DISTANCIAS[3][3] = 0;
    DISTANCIAS[4][4] = 0;
    DISTANCIAS[5][5] = 0;

    DISTANCIAS[0][1] = 63;
    DISTANCIAS[0][2] = 210;
    DISTANCIAS[0][3] = 190;
    DISTANCIAS[0][4] = -1;
    DISTANCIAS[0][5] = 190;

    DISTANCIAS[1][0] = 63;
    DISTANCIAS[1][2] = 160;
    DISTANCIAS[1][3] = 150;
    DISTANCIAS[1][4] = 95;
    DISTANCIAS[1][5] = 10;

    DISTANCIAS[2][0] = 210;
    DISTANCIAS[2][1] = 160;
    DISTANCIAS[2][3] = 10;
    DISTANCIAS[2][4] = 1;
    DISTANCIAS[2][5] = 10;

    DISTANCIAS[3][0] = 190;
    DISTANCIAS[3][1] = 150;
    DISTANCIAS[3][2] = 10;
    DISTANCIAS[3][4] = 10;
    DISTANCIAS[3][5] = 20;

    DISTANCIAS[4][0] = 10;
    DISTANCIAS[4][1] = 95;
    DISTANCIAS[4][2] = 7;
    DISTANCIAS[4][3] = 21;
    DISTANCIAS[4][5] = 80;

    DISTANCIAS[5][0] = 190;
    DISTANCIAS[5][1] = 2;
    DISTANCIAS[5][2] = -1;
    DISTANCIAS[5][3] = 41;
    DISTANCIAS[5][4] = 80;
}

int calculaDistancia(int * rota, int tamanho_rota) {
    int i;
    int distancia;
    int inicio, fim;

    tamanho_rota--;

    for(i = 0, distancia = 0; i < tamanho_rota; i++) {
        inicio = rota[i];
        fim = rota[i+1];
        if(DISTANCIAS[inicio][fim] == -1) return -1;
        
        distancia += DISTANCIAS[inicio][fim];
    }

    return distancia;
}