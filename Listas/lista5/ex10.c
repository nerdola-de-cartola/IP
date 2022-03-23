#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printEspiral(int ** matriz, int qtd_linhas, int qtd_colunas);

int main(void) {
    int qtd_linhas, qtd_colunas;
    int i, j;
    int ** matriz;

    scanf("%d%d", &qtd_linhas, &qtd_colunas);

    if(qtd_linhas > 10 || qtd_colunas > 10) {
        printf("Dimensao invalida\n");
        return 0;
    }

    matriz = calloc(qtd_linhas, sizeof (int *));

    for(i = 0; i < qtd_linhas; i++) {
        matriz[i] = calloc(qtd_colunas, sizeof (int));

        for(j = 0; j < qtd_colunas; j++) {
            scanf("%d", &matriz[i][j]);    
        }
    }

    printEspiral(matriz, qtd_linhas, qtd_colunas);

    for(i = 0; i < qtd_linhas; i++) {
        free(matriz[i]);
    }

    free(matriz);
    
    return 0;
}

void printEspiral(int ** matriz, int qtd_linhas, int qtd_colunas) {
    int i;
    int qtd_itens, linha_limite, linha_inicio, coluna_limite, coluna_inicio;
    int linha, coluna;
    bool direita, baixo, esquerda, cima;

    linha = 0;
    coluna = 0;

    qtd_itens = qtd_linhas * qtd_colunas;
    linha_inicio = 1;
    linha_limite = qtd_linhas - 1;
    coluna_inicio = 0;
    coluna_limite = qtd_colunas - 1;

    direita = true;
    baixo = false;
    esquerda = false;
    cima = false;

    i = 0;
    while(i < qtd_itens) {
        if(direita) {
            for(;coluna < coluna_limite && i < qtd_itens; coluna++) {
                printf("%d ", matriz[linha][coluna]);
                i++;
            }

            coluna_limite--;
            baixo = true;
            direita = false;
        } else if(baixo) {
            for(;linha < linha_limite && i < qtd_itens; linha++) {
                printf("%d ", matriz[linha][coluna]);
                i++;
            }

            linha_limite--;
            baixo = false;
            esquerda = true;
        } else if(esquerda) {
            for(; coluna >= coluna_inicio && i < qtd_itens; coluna--) {
                printf("%d ", matriz[linha][coluna]);
                i++;
            }

            linha--;
            coluna++;
            coluna_inicio++;
            esquerda = false;
            cima = true;
        } else if(cima) {
            for(; linha >= linha_inicio && i < qtd_itens; linha--) {
                printf("%d ", matriz[linha][coluna]);
                i++;
            }

            coluna++;
            linha++;
            linha_inicio++;
            cima = false;
            direita = true;
        }
    }

    printf("\n");

    return;
}