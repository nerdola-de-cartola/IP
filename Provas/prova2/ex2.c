#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/**
* Função que verifica e decompõe um número n como uma potência prima. Esta
* função recebe o valor n e retorna o resultado da decomposição de n como uma
* potência prima via ponteiros. Quando a decomposição é possível, a função retorna 1.
* Quando a decomposição não é possível, a função retorna 0.
* @param n valor inteiro a ser verificado
* @param k ponteiro para a base da potência prima.
* @param p valor da potencia.
* @return retorna 1 caso n seja uma potência prima e 0 caso contrário.
* no último caso, quando n não é uma potência prima, os conteúdos de k
* e p devem ser desconsiderados.
**/
bool potencia_prima(int n, int * k, int * p);

bool primo(int n);

int main(void) {
    int n, i, count, base, expoente;

    scanf("%d", &n);

    for(i = 2, count = 0; count != n; i++) {
        if(potencia_prima(i, &base, &expoente) == 1) {
            printf("%d : %d^%d\n", i, base, expoente);
            count++;
        }
    }

    return 0;
}

bool potencia_prima(int n, int * k, int * p) {
    int base, expoente, potencia;

    for(base = 2; base <= n; base++) {
        if(primo(base)) {

            for(expoente = 1, potencia = 0; potencia < n; expoente++) {
                potencia = pow(base, expoente);

                if(potencia == n) {
                    *k = base;
                    *p = expoente;
                    return true;
                }
            }
        }
    }

    return false;
}

bool primo(int n) {
    int i;

    for(i = 2; i < n; i++) {
        if(n%i == 0) {
            return false;
        }
    }

    return true;
}