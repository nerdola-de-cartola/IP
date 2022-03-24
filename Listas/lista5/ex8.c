#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
    
bool ehPermutacao(int ** matriz, int tamanho, int * soma);
    
int main(void) {
    int tamanho, soma;
    int ** matriz;
    bool permutacao;
    char mensagem[50];
    int i, j;
    
    scanf("%d", &tamanho);
    
    matriz = calloc(tamanho, sizeof (int *));
    
    for(i = 0; i < tamanho; i++) {
        matriz[i] = calloc(tamanho, sizeof (int));

        for(j = 0; j < tamanho; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
    
    permutacao = ehPermutacao(matriz, tamanho, &soma);
    
    if(permutacao) strcpy(mensagem, "PERMUTACAO");
    else strcpy(mensagem, "NAO EH PERMUTACAO");
    
    printf("%d\n%s\n%d\n", tamanho, mensagem, soma);
    
    for(i = 0; i < tamanho; i++) {
        free(matriz[i]);
    }
    
    free(matriz);
    
    return 0;
}
    
bool ehPermutacao(int ** matriz, int tamanho, int * soma) {
    int i, j, contador;
    bool permutacao = true;

    *soma = 0;
    
    for(i = 0; i < tamanho; i++) {
        for(j = 0, contador = 0; j < tamanho; j++) {
            *soma += matriz[i][j];
    
            if(matriz[i][j] == 1) contador++;
            else if(matriz[i][j] != 0) permutacao = false;
        }
    
        if(contador != 1) permutacao = false;
    }
    
    return permutacao;
}