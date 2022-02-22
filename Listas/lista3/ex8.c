#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * Função que calcula a potencia de p mais próximo a n.
 * @param n valor inteiro
 * @param p valor da potencia
 * @return retorna o valor da potencia mais proxima.
**/
int next_power(int n, int p);

int main(void) {
    int numero, expoente, base;
    scanf("%d %d", &numero, &expoente);

    if(expoente < 0) {
        return 1;
    }

    base = next_power(numero, expoente);

    printf("%d -> %d^%d = %.0f\n", numero, base, expoente, pow(base, expoente));
    return 0;
}

int next_power(int n, int p) {
    float ultimo_resultado = 0;
    float penultimo_resultado = 0;
    int i;

    if(p == 0) {
        return 1;
    }

    for(i = 1; n - ultimo_resultado >= 0; i++) {
        penultimo_resultado = ultimo_resultado;
        ultimo_resultado = pow(i, p);
    }

    if(abs(n - ultimo_resultado) < abs(n - penultimo_resultado)) {
        return i - 1;
    } else {
        return i - 2;
    }
}