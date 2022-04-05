#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto {
    char nome[50];
    double preco;
};

struct compra {
    char nome[50];
    int quantidade;
};

typedef struct produto Produto;
typedef struct compra Compra;

int main(void) {
    int qtd_testes, teste;
    int qtd_produtos, qtd_compras;
    int i, j;
    double total;
    Produto * ofertas;
    Compra * lista;

    scanf("%d",  &qtd_testes);

    for(teste = 0; teste < qtd_testes; teste++) {
        scanf("%d", &qtd_produtos);

        ofertas = calloc(qtd_produtos, sizeof(Produto));

        for(i = 0; i < qtd_produtos; i++) {
            scanf("%s%lf", ofertas[i].nome, &ofertas[i].preco);
        }

        scanf("%d", &qtd_compras);

        lista = calloc(qtd_compras, sizeof(Compra));

        for(i = 0; i < qtd_compras; i++) {
            scanf("%s%d", lista[i].nome, &lista[i].quantidade);
        }

        total = 0;
        for(i = 0; i < qtd_compras; i++) {
            for(j = 0; j < qtd_produtos; j++) {
                if(strcmp(lista[i].nome, ofertas[j].nome) == 0) {
                    total += lista[i].quantidade * ofertas[j].preco; 
                    break;
                }
            }
        }

        printf("R$ %.2lf\n", total);

        free(ofertas);
        free(lista);
    }

    return 0;
}