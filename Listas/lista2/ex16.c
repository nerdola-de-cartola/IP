#include <stdio.h>
#include <math.h>

unsigned long long int fatorial(const int num);

int main(void) {
    unsigned short int i, qtd_termos;
    double angulo, cos = 0;

    scanf("%lf %hd", &angulo, &qtd_termos);

    for(i = 0; i <= qtd_termos; i++) {
        cos += pow(-1, i) * pow(angulo, 2 * i) / fatorial(2 * i);
    }

    printf("cos(%.2lf) = %.6lf\n", angulo, cos);

    return 0;
}

unsigned long long int fatorial(const int num) {
    unsigned long long int fatorial;
    int i;

     if (num == 0) {
        fatorial = 1;

    } else {
        fatorial = num;

        for(i = num - 1; i > 1; i--) {
            fatorial *= i;
        }
    }

    return fatorial;
}