#include <stdio.h>
#include <math.h>

double calculaRaiz(double n, double num_anterior);

int main(void) {
    double num, erro_max;
    double aproximacao, aproximacao_anterior, erro;

    scanf("%lf %lf", &num, &erro_max);

    erro = erro_max + 1;
    aproximacao_anterior = 1;
    
    while(erro > erro_max) {
        aproximacao  = calculaRaiz(num, aproximacao_anterior);
        erro = num - pow(aproximacao, 2);

        if(erro < 0) {
            erro *= -1;
        }

        printf("r: %.9lf, err: %.9lf\n", aproximacao, erro);
        aproximacao_anterior = aproximacao;
    }

    return 0;
}

double calculaRaiz(double n, double num_anterior) {
    return  (num_anterior + (n / num_anterior)) / 2;
}