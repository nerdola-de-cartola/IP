#include <stdio.h>

int main(void) {
    int a, b, c, d, e, menor, maior, ordem = 0;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);

    maior = a;
    menor = a;

    if (b > maior) {
        maior = b;
    } if (c > maior) {
        maior = c;
    } if (d > maior) {
        maior = d;
    } if (e > maior) {
        maior = e;
    }

    if (b < menor) {
        menor = b;
    } if (c < menor) {
        menor = c;
    } if (d < menor) {
        menor = d;
    } if (e < menor) {
        menor = e;
    }

    if (a < b && b < c && c < d && d < e) { //Decrescente
        ordem = 1;
    } else if (a > b && b > c && c > d && d > e) { //Crescente
        ordem = 2;
    } else { //Desordenado
        ordem = 3;
    }

    if (ordem == 1 ||ordem == 2) {
        printf("MENOR: %d, MAIOR: %d\n", menor, maior);
    }

    if (ordem == 1) {
        printf("ORDENADO CRESCENTE\n");
    } if (ordem == 2) {
        printf("ORDENADO DECRESCENTE\n");
    } if (ordem == 3) {
        printf("DESORDENADO\n");
    }
}