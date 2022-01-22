#include <stdio.h>
#include <math.h>

int main(void)
{
    float a, b, c, x1, x2, delta;

    printf("Digite os coeficientes de sua equação: ");
    scanf("%f %f %f", &a, &b, &c);

    delta = (b*b) - (4*a*c);
    printf("a:%f b:%f c:%f delta:%f \n", a, b, c, delta);

    if (delta < 0) {
        printf("A equação não possui raiz nos números reais \n");
    }
    if (delta == 0) {
        x1 = (-b + sqrt(delta)) / (2*a);
        printf("A única raiz da equação é: %lf \n", x1);
    }
    else {
        x1 = (-b + sqrt(delta)) / (2*a);
        x2 = (-b - sqrt(delta)) / (2*a);

        if (x2 > x1)
        {
            double tmp = x1;
            x1 = x2;
            x2 = tmp;
        }

        printf("As raizes da equação são: %lf e %lf \n", x1, x2);
    }

    return 0;
}