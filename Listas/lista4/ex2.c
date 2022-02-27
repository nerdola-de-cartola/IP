#include <stdio.h>

#define MAXIMO 1000

int main(void) {
    int i, contador;
    int qtd_numeros = 0, parametro;
    int numeros[MAXIMO];

    while(qtd_numeros < 1 || qtd_numeros > 1000) {
        scanf("%d", &qtd_numeros);
    }

    for(i = 0; i < qtd_numeros; i++) {
        scanf("%d", &numeros[i]);
    }

    scanf("%d", &parametro);

    for(i = 0; i < qtd_numeros; i++) {
        if(numeros[i] >= parametro) {
            contador++;
        }
    }

    printf("%d", contador);
    
    return 0;
}