#include <stdio.h>
#include <stdbool.h>

int maiorElemento(int lista[], int tamanho_da_lista);

int main(void) {
    int i = 0, j = 0, k = 0, contador = 0;
    int qtd_listas;
    int tamanho_das_listas[100];
    int lista[100][10000];
    int maior, input;

    while(true) {
        scanf("%d", &input);

        if(input == 0) {
            break;
        }

        tamanho_das_listas[i] = input;

        for(j = 0; j < tamanho_das_listas[i]; j++) {
            scanf("%d", &lista[i][j]);
        }

        i++;
    }

    qtd_listas = i;

    for(i = 0; i < qtd_listas; i++) {
        maior = maiorElemento(lista[i], tamanho_das_listas[i]);

        for(j = 0, contador = 0; j <= maior; j++) {
            for(k = 0; k < tamanho_das_listas[i]; k++) {
                if(lista[i][k] == j) {
                    contador++;
                }
            }

            printf("(%d) %d\n", j, contador);
        }
    }

    return 0;
}

int maiorElemento(int lista[], int tamanho_da_lista) {
    int i;
    int maior = 0;

    for(i = 0; i < tamanho_da_lista; i++) {
        if(lista[i] > maior) {
            maior = lista[i];
        }
    }

    return maior;
}