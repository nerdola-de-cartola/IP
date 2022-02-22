#include <stdio.h>

int main(void) {
    unsigned long long int qtd_termos, i, j;
    double x, e_elevado_x = 0, numerador, denominador;

    scanf("%lf %lld", &x, &qtd_termos);

    for(i = 0, numerador = 1, denominador = 1; i <= qtd_termos; i++) {

        if(i != 0) {
            numerador *= x;
            denominador  *=  i;
        }

        e_elevado_x += numerador / denominador;
    }

    printf("e^%.2lf = %.6lf\n", x, e_elevado_x);
    return 0;
}