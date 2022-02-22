#include <stdio.h>

void encontraDivisores(int *arr, const int n);

int main(void) {
    int n, i, soma;

    scanf("%d", &n);
    int divisores[n];

    for(i = 0; i < n; i++) {
        divisores[i] = 0;
    }

    //Encontra divisores
    encontraDivisores(divisores, n);

    printf("%d = ", n);

    //Imprime divisores
    for(i = 0; i < n; i++) {
        printf("%d", divisores[i]);

        if(divisores[i + 1] != 0) {
            printf(" + ");
        } else {
            break;
        }
    }

    //Imprime soma dos divisores
    for(i = 0, soma = 0; i < n; i++) {
        soma += divisores[i];
    }

    printf(" = %d ", soma);

    //Imprime n é um número perfeito ou não
    if(soma == n) {
        printf("(NUMERO PERFEITO)");

    } else {
        printf("(NUMERO NAO E PERFEITO)");
    }

    printf("\n");

    return 0;

}

void encontraDivisores(int *arr, const int n) {
    int i, index = 0;

    for(i = 1; i < n; i++) {
        if(n % i == 0) {
            arr[index] = i;
            index++;
        }
    }

}