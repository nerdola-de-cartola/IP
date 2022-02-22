#include <stdio.h>

int main(void) {
    int i;
    double limite, soma;
    scanf("%lf", &limite);

    if(limite < 0|| limite / (int) limite != 1) {
        printf("Numero invalido!\n");
        return 0;
    }

    for(i = 1, soma = 0; i <= limite; i++) {
        soma += (double) 1 / (double) i;
    }

    printf("%.6lf\n", soma);

    return 0;
}