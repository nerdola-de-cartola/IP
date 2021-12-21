#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MIN -5
#define MAX 5

int main(void)
{
    int a, b, c, delta;
    double x1, x2;
    bool fora = false, fato1 = false, fato2 = false;

    scanf("%d %d %d", &a, &b, &c);
    
    delta = (b*b) - (4*a*c);

    if (delta < 0) {
        printf("POSICOES IMAGINARIAS\n");
        return 0;
    } 
    
    x1 = (-b + sqrt(delta)) / (2*a); 
    x2 = (-b - sqrt(delta)) / (2*a);

    if ((x1 > MAX || x1 < MIN) || (x2 > MAX || x2 < MIN)) { //A partícula está fora do experimento
        fora = true;

    } if ((a + b + c) % 3 == 0) { //A soma dos coeficientes é divisível por 3
        fato1 = true;
        
    } if (c % 2 == 0 && c < (a + b)) { //O coeficiente C é par e menor que a soma dos coeficientes A e B
        fato2 = true;
    }

    printf("POSICOES: X1=%.2lf e X2=%.2lf ", x1, x2);

    if (fora) {
        printf("(FORA DO EXPERIMENTO)\n");        

    } else {
        printf("\n");

    } if (fato1) {
        printf("FATO1: DESAPARECIDA\n");

    } if (fato2) {
        printf("FATO2: ORIGEM\n");
    }

    return 0;
}
