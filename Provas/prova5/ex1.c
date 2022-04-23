#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ItemEstoque {
    float valor; // valor de 1 unidade do produto
    char nome[50]; // nome do produto
    int quantidade; // quantidade em estoque
} Item;

typedef struct mercado {
    Item * ip;
    int qtd;
} Mercado;

#define ADD 1
#define PRINT 2
#define EXIT 3

int main(void) {
    FILE * arq = NULL;
    Item * tmp = NULL;
    Mercado merc;
    int mode, qtd, i;

    merc.ip = NULL;
    merc.qtd = 0;

    arq = fopen("estoque.bin", "rb+");
    if(arq == NULL) return 1;

    i = 0;
    merc.ip = calloc(1, sizeof(Item));

    while(fread(&merc.ip[i], sizeof(Item), 1, arq) > 0) {
        i++;
        tmp = realloc(merc.ip, (i + 1) * sizeof(Item));
        if(tmp == NULL) return 1;
        merc.ip = tmp;
    }

    merc.qtd = i;
    if(merc.qtd != 0) {
        tmp = realloc(merc.ip, merc.qtd * sizeof(Item));
        if(tmp == NULL) return 1;
        merc.ip = tmp;
        tmp = NULL;
    }

    while(true) {
        printf("1 - cadastrar itens\n");
        printf("2 - listar itens\n");
        printf("3 - sair\n");

        scanf("%d", &mode);

        switch (mode) {
            case ADD:
                scanf("%d", &qtd);

                tmp = realloc(merc.ip, (merc.qtd + qtd) * sizeof(Item));
                if(tmp == NULL) return 1;
                merc.ip = tmp;
                tmp = NULL;

                for(i = merc.qtd; i < qtd + merc.qtd; i++) {
                    scanf("%f%s%d", &merc.ip[i].valor, merc.ip[i].nome, &merc.ip[i].quantidade);
                }

                merc.qtd += qtd;
                break;
            case PRINT:
                for(i = 0; i < merc.qtd; i++) {
                    printf("Item %d----------------------\n", i+1);
                    printf("Valor: %.2f\n", merc.ip[i].valor);
                    printf("nomeItem: %s\n", merc.ip[i].nome);
                    printf("quantidade: %d\n", merc.ip[i].quantidade);
                    printf("\n");
                }
                break;
            case EXIT:
                fopen("estoque.bin", "wb");
                if(arq == NULL) return 1;

                fwrite(merc.ip, sizeof(Item), merc.qtd, arq);
                free(merc.ip);
                return 0;
                break;
            default:
                return 1;
                break;
        }
    }
}