#include <stdio.h>

int main(void) {
    int numero, inverso, d1, d2, d3, d4, d5;
    scanf("%d", &numero);

    //Verifica se o número é valido
    if (numero > 99999) {
        printf("NUMERO INVALIDO\n");
        return 0;
    }

    //Separa cada digito do número
    d1 = numero % 10;
    d2 = (numero % 100 - d1) / 10;
    d3 = (numero % 1000 - d2 -d1) / 100;
    d4 = (numero % 10000 - d3 -d2 - d1) / 1000;
    d5 = (numero % 100000 - d4 - d3 -d2 - d1) / 10000;

    //Encontra o número inverso
    if (d5) {
        inverso = d1*10000 + d2*1000 + d3*100 + d4*10 + d5;

    } else if (d4) {
        inverso = d1*1000 + d2*100 + d3*10 + d4;

    } else if (d3) {
        inverso = d1*100 + d2*10 + d3;

    } else if (d2) {
        inverso = d1*10 + d2;

    } else {
        inverso = d1;
    }

    //Verifica se é um palindromo
    if (numero == inverso) {
        printf("PALINDROMO\n");

    } else {
        printf("NAO PALINDROMO\n");
    }

    return 0;
}