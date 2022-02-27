#include <stdio.h>
#include <stdbool.h>

#define MAXIMO 100000

int main(void) {
    int numeros[MAXIMO];
    int buscas[MAXIMO];
    int i, j, qtd_numeros, qtd_buscas;
    bool numero_encontrado = false;

    scanf("%d", &qtd_numeros);

    for(i = 0; i < qtd_numeros; i++) {
        scanf("%d", &numeros[i]);
    }

    scanf("%d", &qtd_buscas);

    for(i = 0; i < qtd_buscas; i++) {
        scanf("%d", &buscas[i]);
    }

    for(i = 0; i < qtd_buscas; i++) {
        for(j = 0; j < qtd_numeros; j++) {
            if(buscas[i] == numeros[j]) {
                printf("ACHEI\n");
                numero_encontrado = true;
                break;
            }
        }

        if(!numero_encontrado) {
            printf("NAO ACHEI\n");
        }

        numero_encontrado = false;
    }

    return 0;
}