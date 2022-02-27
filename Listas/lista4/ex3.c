#include <stdio.h>

#define MAXIMO 5000

int main(void) {
    int i;
    int numeros[MAXIMO];
    int qtd_numeros;

    scanf("%d", &qtd_numeros);

    for(i = 0; i < qtd_numeros; i++) {
        scanf("%d", &numeros[i]);
    }

    for(i = qtd_numeros - 1; i >= 0; i--) {
        printf("%d ", numeros[i]);
    }

    printf("\n");
    
    return 0;
}