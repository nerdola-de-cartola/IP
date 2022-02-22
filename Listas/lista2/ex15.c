#include <stdio.h>
#include <stdbool.h>

int somaDivisores(const int n);

int main(void) {
    int n, soma_div, i = 220, index = 0;
    scanf("%d", &n);
    int pares[n][2];

    while (index < n) {
        soma_div = somaDivisores(i);

        if(soma_div == i) {
            i++;
            continue;
        }

        if(i == somaDivisores(soma_div)) {
            pares[index][0] = i; 
            pares[index][1] = soma_div;
            index++;
            i = soma_div;
        }

        i++;
        // printf("%d\n", i);
    }

    for(i = 0; i < n; i++) {
        printf("(%d,%d)\n", pares[i][0], pares[i][1]);
    }

    return 0;
}

int somaDivisores(const int n) {
    int i, soma, index = 0;
    int divisores[n];


    for(i = 0; i < n; i++) {
        divisores[i] = 0;
    }

    for(i = 1; i < n; i++) {
        if(n % i == 0) {
            divisores[index] = i;
            index++;
        }
    }

    for(i = 0, soma = 0; i < n; i++) {
        soma += divisores[i];
    }

    return soma;
}