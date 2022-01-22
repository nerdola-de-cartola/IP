#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define PI 3.14

int main(void) {
    int angulo, angulo_correspondente;
    char operacao;
    double sen, cos, angulo_rad;
    bool invertido = false;
    scanf("%c%d", &operacao, &angulo);

    //Encontra o angulo correspondente
    angulo_correspondente = angulo;

    if (angulo > 90) {
        angulo_correspondente -= 180;

    } if (angulo > 270) {
        angulo_correspondente -= 180;
    }

    //Caso o sinal seja invertido
    if (angulo_correspondente < 0 ) {
        invertido = true;
        angulo_correspondente = -angulo_correspondente;
    }

    printf("%d\n", angulo_correspondente);

    //Angulo em radianos
    angulo_rad = (angulo_correspondente * PI) / 180;

    if (operacao == 'S' || operacao == 's') {
        if (angulo_correspondente == 30) {
            sen = (double) 1 / 2;
        } if (angulo_correspondente == 45) {
            sen = (double) sqrt(2)/2;
        } if (angulo_correspondente == 60) {
            sen = (double) sqrt(3)/2;
        } if (angulo_correspondente == 90) {
            sen = (double) 1;
        }
        
        printf("%.3lf\n", sen);
        
    }
    if (operacao == 'C' || operacao == 'c') {
        if (angulo_correspondente == 30) {
            cos = (double) sqrt(3) / 2;
        } if (angulo_correspondente == 45) {
            cos = (double) sqrt(2) / 2;
        } if (angulo_correspondente == 60) {
            cos = (double) 1 / 2;
        } if (angulo_correspondente == 90) {
            cos = (double) 0.001;
        }
        printf("%.3lf\n", cos);
    }

    if (invertido) {
        printf("SINAL INVERTIDO\n");

    } else {
        printf("SINAL IGUAL\n");
    }
    
    return 0;
}