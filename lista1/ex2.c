#include <stdio.h>

int main(void) {
    float f_temperatura, c_temperatura, p_volume, mm_volume;

    scanf("%f %f", &f_temperatura, &p_volume);

    c_temperatura = 5*(f_temperatura - 32)/9;
    mm_volume = p_volume*25.4;

    printf("O VALOR EM CELSIUS = %.2f\n", c_temperatura);
    printf("A QUANTIDADE DE CHUVA E = %.2f\n", mm_volume);

    return 0;
}