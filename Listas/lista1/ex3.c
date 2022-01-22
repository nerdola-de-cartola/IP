#include <stdio.h>

int main(void)
{
    float a, b, c, delta;

    scanf("%f%f%f", &a, &b, &c);
    
    delta = (b*b) - (4*a*c);

    printf("O VALOR DE DELTA E = %.2f\n", delta);

    return 0;
}
