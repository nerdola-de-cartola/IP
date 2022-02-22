#include <stdio.h>
#include <math.h>

unsigned long long int fatorial(const int num);

int main(void) {
    unsigned short int i, qtd_termos;
    double x, e_elevado_x = 0;

    scanf("%lf %hd", &x, &qtd_termos);

    for(i = 0; i <= qtd_termos; i++) {
        e_elevado_x += pow(x, i) / fatorial(i);
    }

    printf("e^%.2lf = %.6lf\n", x, e_elevado_x);

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