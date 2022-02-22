#include <stdio.h>
#include <math.h>

int somaImpares(const int inicio, const int fim);

int main(void) {
    int limite, i, j, proximo_impar = 1;

    scanf("%d", &limite);

    if(limite <= 0) {
        return 0;
    }

    for(i = 1; i <= limite; i++) {
        printf("%d*%d*%d = ", i, i, i);

        for(j = proximo_impar; somaImpares(proximo_impar, j) <= pow(i, 3); j += 2) {
            printf("%d", j);

            if(somaImpares(proximo_impar, j) == pow(i, 3)) {
                break;
            }
            
            printf("+");
        }

        printf("\n");
        proximo_impar = j + 2;
    }

    return 0;
}

int somaImpares(const int inicio, const int fim) {
    int i, soma;

    for(i = inicio, soma = 0; i <= fim; i += 2) {
        soma += i;
    }

    return soma;
}