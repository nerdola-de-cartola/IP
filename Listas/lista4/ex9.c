#include <stdio.h>

int main(void) {
    int i;
    int qtd_notas;
    int maior_nota = -1;
    int entrada;
    int notas[11] = {0};
    int primeira_aparicao[11] = {0};
    
    scanf("%d", &qtd_notas);
    
    for(i = 0; i < qtd_notas; i++) {
        scanf("%d", &entrada);
        
        if(entrada < 0 || entrada > 10) {
            return 1;
        }
        
        if(entrada > maior_nota) {
            maior_nota = entrada;
        }
        
        if(notas[entrada]  == 0) {
            primeira_aparicao[entrada] = i;
        }
        notas[entrada]++;
    }
    
    printf("Nota %d, %d vezes\n", entrada, notas[entrada]);
    printf("Nota %d, indice %d\n", maior_nota, primeira_aparicao[maior_nota]);
    
    return 0;
}