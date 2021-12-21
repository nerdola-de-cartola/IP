#include <stdio.h>

int main(void) {
    short int n1, n2, n3, numero, quadrado;

    scanf("%hd%hd%hd", &n1, &n2, &n3);

    if (n1 > 9 || n2 > 9 || n3 > 9 || n1 < 0 || n2 < 0 || n3 < 0)
    {
        printf("DIGITO INVALIDO\n");
        return 0;
    }

    numero = n1*100 + n2*10 + n3;
    quadrado = numero*numero;

    printf("%hd, %hd\n", numero, quadrado);
    return 0;
}