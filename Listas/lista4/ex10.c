#include <stdio.h>

void imprimeVetor(int vetor[], int tamanho);

int main(void) {
    int i;
    int tamanho, maior = -2147483648, menor = 2147483647;
    int entrada;
    int v[1000] = {0};
    int w[1000] = {0};
    
    scanf("%d", &tamanho);
    
    for(i = 0; i < tamanho; i++) {
        scanf("%d", &entrada);
        
        if(entrada > maior) {
            maior = entrada;
        }
        
        if(entrada < menor) {
            menor = entrada;
        }
        
        v[i] = entrada;
        w[tamanho - i - 1] = entrada;
    }
    
    imprimeVetor(v, tamanho);
    imprimeVetor(w, tamanho);
    printf("%d\n", maior);
    printf("%d\n", menor);
    
    return 0;
}

void imprimeVetor(int vetor[], int tamanho) {
    int i;
    
    for(i = 0; i < tamanho; i++) {
        printf("%d", vetor[i]);
        
        if(i != tamanho - 1) {
            printf(" ");
        }
    }
    
    printf("\n");
    
    return;
}