#include <stdio.h>

int main(void) {
    int i, num, limite;
    scanf("%d %d", &num, &limite);

    // printf("teste1");

    if(num % 2 != 0) {
        printf("O PRIMEIRO NUMERO NAO E PAR\n");
        return 0;
    }

    // printf("teste2");


    for(i = 0; i < limite; i++, num+=2) {
        printf("%d ", num);

        if(i == limite - 1) {
            printf("\n");
        }
    }

    // printf("teste3");

    return 0;
}