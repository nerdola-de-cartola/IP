#include <stdio.h>

int main(void) {
    int i, tamanho_da_sequencia, maior_sequencia, sequencia_atual, num_atual, num_anterior;;

    //Recebe o input do tamanho da sequencia
    scanf("%d", &tamanho_da_sequencia);
    sequencia_atual = 1;
    maior_sequencia = 1;  

    for(i = 0; i < tamanho_da_sequencia; i++) {
        scanf("%d", &num_atual);

        if(i == 0) {
            num_anterior = num_atual;
            continue;
        }
        
        if(num_atual > num_anterior){
            sequencia_atual++;

        } else {
            sequencia_atual = 1;
        }

        if(sequencia_atual > maior_sequencia) {
            maior_sequencia = sequencia_atual;
        }

        num_anterior = num_atual;
    }
    
    printf("O comprimento do segmento crescente maximo e: %d\n", maior_sequencia);

    return 0;
}