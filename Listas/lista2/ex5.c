#include <stdio.h>

int main(void) {
    int i, numero;
    unsigned long long int fatorial;

    scanf("%d", &numero);

    if (numero == 0)
    {
        fatorial = 1;

    } else {
        fatorial = numero;

        for(i = numero - 1; i > 1; i--) {
            fatorial *= i;
        }
    }

    printf("%d! = %lli\n", numero, fatorial);

    return 0;
}