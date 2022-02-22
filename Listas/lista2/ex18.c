#include <stdio.h>
#include <stdbool.h>

long long int menorDivisorPrimo(const long long int n);

int main(void) {
    long long int num, menor_divisor;

    num = 0;
    while(num < 1) {
        scanf("%lld", &num);

        if(num < 1) {
            printf("Fatoracao nao e possivel para o numero %lld!\n", num);
        }
    }

    printf("%lld = ", num);

    while(num != 1) {
        menor_divisor = menorDivisorPrimo(num);
        printf("%lld", menor_divisor);

        if(num != menor_divisor) {
            printf(" x ");
        }

        num /= menor_divisor;
    }

    printf("\n");

    return 0;
}

long long int menorDivisorPrimo(const long long int n) {
    int i;

    for(i = 2; i <= n; i++) {
        if(n % i == 0) { // Se n é divisível por i
            return i;
        }
    }
}