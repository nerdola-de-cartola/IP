#include <stdio.h>
#include <math.h>
#include "complex.h"

typedef struct {
    Complex x1;
    Complex x2;
} RaizEqu2;

/**
* Função que calula as raízes de uma equação de segundo grau.
*
* @param a coeficiente quadrado
* @param b coeficiente linear
* @param c constante
* @return retorna uma estrutura RaizEqu2 com dois números complexos
*/
RaizEqu2 calcula_raiz_equ_2(double a, double b, double c);

int main(void) {
    double a, b, c;
    RaizEqu2 raizes;

    scanf("%lf%lf%lf", &a, &b, &c);

    raizes = calcula_raiz_equ_2(a, b, c);

    printf("x1 = ");
    complexPrint(raizes.x1);
    printf("\n");
    printf("x2 = ");
    complexPrint(raizes.x2);
    printf("\n");

    return 0;
}

RaizEqu2 calcula_raiz_equ_2(double a, double b, double c) {
    RaizEqu2 r;
    double delta;

    delta = (b * b) - (4 * a * c);

    if(delta >= 0) {
        complexSet(&r.x1, (-b + sqrt(delta)) / 2 * a, 0);
        complexSet(&r.x2, (-b - sqrt(delta)) / 2 * a, 0);
    } else {
        complexSet(&r.x1, -b / 2*a, sqrt(-delta) / 2 * a);
        complexSet(&r.x2, -b / 2 * a, -sqrt(-delta) / 2 * a);
    }
    
    return r;
}