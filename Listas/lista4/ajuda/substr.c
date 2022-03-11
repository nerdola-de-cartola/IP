#include <stdio.h>
#include <string.h>

#define N 1000

int main(void){
    char palavra1[N], palavra2[N];
    int resultados[10][2];
    int tamanho_1, tamanho_2, i, j, subseq = 0, ultimo, testes=0, k;
    
    while(1){
        if(scanf("%s", palavra1) == EOF) break;
        if(scanf("%s", palavra2) == EOF) break;
        //printf("\n");
        //printf("%s - %s\n", palavra1, palavra2);

        tamanho_1= strlen(palavra1);
        tamanho_2 = strlen(palavra2);

        for(i = 0; i < tamanho_2; i++) {
            for(j = 0, k = 0; j < tamanho_1; j++) {
                if(palavra2[i+k] == palavra1[j]){
                    k++;
                    continue;
                } 

                break;
            }

            if(j == tamanho_1) {
                ultimo = i;
                subseq++;
            }
        }

        resultados[testes][0] = subseq;
        resultados[testes][1] = ultimo;
        testes++;
    }

    for(i = 0; i < testes; i++) {
        printf("Caso #%d\n", i+1);

        if(resultados[i][0] > 0){
            printf("Qtd. Subsequencias: %d\n", resultados[i][0]);
            printf("Pos: %d\n", resultados[i][1]);
        } else printf("Nao existe subsequencia\n");
        
    }
    
    return 0;
}