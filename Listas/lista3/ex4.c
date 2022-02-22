#include <stdio.h>

int somaDivisores(int n, int *divisores);

int main(void) {
    int n, i, soma_dos_divisores;

    scanf("%d", &n);

    int divisores_de_n[n];
    for(i = 0; i < n; i++) {
        divisores_de_n[i] = 0;
    }

    printf("%d = ", n);

    soma_dos_divisores = somaDivisores(n, divisores_de_n);

    i = 0;
    while (divisores_de_n[i] != 0) {
        printf("%d", divisores_de_n[i]);

        if(divisores_de_n[i + 1] != 0) {
            printf(" + ");
        }

        i++;
    }

    printf(" = %d", soma_dos_divisores);

    if(n == somaDivisores(soma_dos_divisores, NULL)) {
        printf(" (NUMERO PERFEITO)\n");

    } else {
        printf(" (NUMERO NAO E PERFEITO)\n");
    }

    return 0;
}

int somaDivisores(int n, int *divisores) {
    int soma = 1;
    int i, index = 1;

    if(divisores != NULL) {
        divisores[0] = 1;
    }

    for(i = 2; i <= n / 2; i++) {
        if(n % i == 0) {
            soma += i;

            if(divisores != NULL) {
                divisores[index] = i;
                index++;
            }
        }
    }

    return soma;
}