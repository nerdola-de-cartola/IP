#include <stdio.h>

int main(void)
{
    int b1, b2, b3, b4, b5, b6, b7, b8, numero;

    scanf("%d", &numero);

    if (numero > 255 || numero < 0) {
        printf("Numero invalido!\n");
        return 0;
    }

    b1 = (numero/128) % 2;
    b2 = (numero/64) % 2;
    b3 = (numero/32) % 2;
    b4 = (numero/16) % 2;
    b5 = (numero/8) % 2;
    b6 = (numero/4) % 2;
    b7 = (numero/2) % 2;
    b8 = numero % 2;

    printf("%d%d%d%d%d%d%d%d\n", b1, b2, b3, b4, b5, b6, b7, b8);
    return 0;
}
