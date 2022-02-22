#include <stdio.h>
#include <math.h>

int raizesEq2Grau(double a, double b, double c, double *x1, double *x2);

int main(void) {
    int tipo;
    double a, b, c;
    double x1, x2;

    scanf("%lf %lf %lf", &a, &b, &c);

    if(a != 0) {
        tipo = raizesEq2Grau(a, b, c, &x1, &x2);

        if(tipo == 2) {
            printf("RAIZES DISTINTAS\n");
            printf("X1 = %.2lf\n", x1);
            printf("X2 = %.2lf\n", x2);

        } else if(tipo == 1) {
            printf("RAIZ UNICA\n");
            printf("X1 = %.2lf\n", x1);

        } else {
            printf("RAIZES IMAGINARIAS\n");
        }
    }

    return 0;
}

int raizesEq2Grau(double a, double b, double c, double *x1, double *x2) {
    double delta, r1 = 0, r2 = 0;
    int tipo = 0;
    
    delta = pow(b, 2) - (4*a*c);

    if(delta < 0) {
        return tipo;
    }

    r1 = (-b + sqrt(delta)) / (2*a);
    tipo = 1;

    if(delta > 0) {
        r2 = (-b - sqrt(delta)) / (2*a);
        tipo = 2;
    }

    if(r1 > r2) {
        int tmp = r1;
        r1 = r2;
        r2 = tmp;
    }

    *x1 = r1;
    *x2 = r2;

    return tipo;
}