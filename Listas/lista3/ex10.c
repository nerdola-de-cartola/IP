#include <stdio.h>

/**
* Função que calcula o valor de pi usando a série proposta por John Wallis
* @param n quantidade de termos da série
* @return o valor aproximado da constante pi
**/
double compute_pi(int n);

int main(void) {
    int qtd_termos;
    scanf("%d", &qtd_termos);
    printf("%.12lf\n", compute_pi(qtd_termos));
    return 0;
}

double compute_pi(int n) {
    double pi = 1;
    int i;

    for(i = 1; i <= n; i++) {
        if(i%2 != 0) {
            pi *=  (double) (i+1) / (double) i;

        } else {
            pi *= (double) i / (double ) (i+1);
        }
    }

    return 2*pi;
}