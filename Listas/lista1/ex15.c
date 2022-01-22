#include <stdio.h>

int main(void) {
    float a1, b1, c1, a2, b2, c2;
    float x, y;
    float det, det_x, det_y;
    scanf("%f%f%f%f%f%f", &a1, &b1, &c1, &a2, &b2, &c2);

    //Calcula o determinante das matrizes
    det = (a1 * b2) - (a2 * b1); 
    det_x = (c1 * b2) - (c2 * b1); //det_x é o mesmo que det só que substituindo os coeficientes A pelo resultado C
    det_y = (a1 * c2) - (a2 * c1); //det_y é o mesmo que det só que substituindo os coeficientes B pelo resultado C

    //Calcula c e y
    x = det_x / det;
    y = det_y / det;

    printf("O VALOR DE X E = %.2f\n", x);
    printf("O VALOR DE Y E = %.2f\n", y);

    return 0;
}