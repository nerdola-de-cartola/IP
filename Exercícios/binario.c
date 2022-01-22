#include <stdio.h>

int main(void)
{
    unsigned short int numero;
    unsigned short int bits[4];

    printf("Insira um número entre 0 e 15: ");
    scanf("%hi", &numero);

    for (unsigned short int i = 0; i < 4; i++)
    {
        bits[i] = numero % 2;
        numero /= 2;
    }

    printf("Número em binario: %hi%hi%hi%hi \n", bits[0], bits[1], bits[2], bits[3]);
    return 0;
}
