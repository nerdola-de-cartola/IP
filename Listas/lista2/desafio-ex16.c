#include <stdio.h>

int main(void) {
    unsigned long long int qtd_termos, i, j;
    double angulo, cos = 0, numerador, denominador;

    scanf("%lf %lld", &angulo, &qtd_termos);

    for(i = 0, numerador = 1, denominador = 1; i <= qtd_termos; i++) {

        if(i != 0) {
            numerador *= angulo * angulo;
            denominador  *=  (i * 2) - 1;
            denominador  *=  i * 2;
        }

        if((i % 2) == 0) {
            cos += numerador / denominador;
        } else {
            cos -= numerador / denominador;
        }
    }

    printf("cos(%.2lf) = %.6lf\n", angulo, cos);
    return 0;
}