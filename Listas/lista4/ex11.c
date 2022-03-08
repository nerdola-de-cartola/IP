#include <stdio.h>
#include <stdbool.h>

double mediana(long long int vetor[], int tamanho);

int main(void) {
    int i;
    int tamanho;
    long long int v[1000000];
    
    scanf("%d", &tamanho);
    
    for(i = 0; i < tamanho; i++) {
        scanf("%lld", &v[i]);
    }
    
    printf("%.2lf\n", mediana(v, tamanho));
    
    return 0;
}

double mediana(long long int vetor[], int tamanho) {
    int i;
    bool terminou;
    long long int tmp;
    double mediana;
    
    // Ordena
    do {
        terminou = true;
        
        for(i = 0; i < tamanho - 1; i++) {
            if(vetor[i] > vetor[i + 1]) {
                tmp = vetor[i + 1];
                vetor[i + 1] = vetor[i];
                vetor[i] = tmp;
                
                terminou = false;
            }
        }
    } while(!terminou);
    
    // Ímpar
    if(tamanho % 2 != 0) {
        mediana = vetor[(tamanho - 1) / 2];
        
    // Par
    } else {
        mediana = (double) (vetor[tamanho / 2] + vetor[tamanho / 2 - 1]) / 2;
    }
    
    return mediana;
}
