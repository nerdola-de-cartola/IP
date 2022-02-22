#include <stdio.h>

int inverteNumero(const int numero);

int main(void) {
    int qtd_numeros, i, maior;

    scanf("%d", &qtd_numeros);

    int numeros[qtd_numeros][2];
    int numeros_invertidos[qtd_numeros][2];

    for(i = 0; i < qtd_numeros; i++) {
        scanf("%d %d", &numeros[i][0], &numeros[i][1]);

        if(numeros[i][0] == 0 || numeros[i][1] == 0 || numeros[i][0] == numeros[i][1]) {
            break;
        }
       
        numeros_invertidos[i][0] = inverteNumero(numeros[i][0]);
        numeros_invertidos[i][1] = inverteNumero(numeros[i][1]);
    }

    for(i = 0; i < qtd_numeros; i++) {
        if(numeros_invertidos[i][0] > numeros_invertidos[i][1]) {
            maior = numeros_invertidos[i][0];

        } else {
            maior = numeros_invertidos[i][1];
        }

        printf("%d\n", maior);
    }

    return 0;
}


int inverteNumero(const int numero) {
    int c, d, u, numero_invertido;

    u = numero % 10;
    d = numero % 100 - u;
    c = numero % 1000 - d - u;

    return numero_invertido = u*100 + d + c/100;
}