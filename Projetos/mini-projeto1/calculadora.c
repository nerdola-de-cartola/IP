#include <stdio.h>
#include <math.h>

int main(void) {
    float n1, n2;
    char operador;

    scanf("%f %c %f", &n1, &operador, &n2);

    if (operador == '+') { //Soma
        printf("%g \n", n1+n2);

    } else if (operador == '-') { //Subtração
        printf("%g \n", n1-n2);

    } else if (operador == '*') { //Multiplicação
        printf("%g \n", n1*n2);

    } else if (operador == '/') { //Divisão
        printf("%g \n", n1/n2);

    } else if (operador == '%') { //Modulo
        printf("%d \n", (int) n1% (int) n2);

    } else if (operador == '~') { //Potência
        printf("%g \n", pow(n1, n2));

    } else if (operador == '=') { //Igual
        if (n1 == n2) {
            printf("true \n");

        } else {
            printf("false \n");
        }

    } else if (operador == '!') { //Diferente
        if (n1 != n2) {
            printf("true \n");

        } else {
            printf("false \n");
        }

    } else if (operador == '<') { //Menor
        if (n1 < n2) {
            printf("true \n");

        } else {
            printf("false \n");
        }

    } else if (operador == '>') { //Maior
        if (n1 > n2) {
            printf("true \n");

        } else {
            printf("false \n");
        }
        
    } else if (operador == '^') { //E
        if (n1 && n2) {
            printf("true \n");

        } else {
            printf("false \n");
        }

    } else if (operador == 'V') { //Ou
        if (n1 || n2) {
            printf("true \n");

        } else {
            printf("false \n");
        }

    } else if (operador == 'X') { //Ou exclusivo
        if ((n1 && !n2) || (n2 && !n1)) {
            printf("true \n");

        } else {
            printf("false \n");
        }
    }
    
    // printf("%lf %c %lf \n", n1, operador, n2);

    return 0;
}