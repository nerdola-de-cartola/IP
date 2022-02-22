#include <stdio.h>

/*
Função que calcula a raiz quadrada de n.
@param n um numero real qualquer
@param p precisão do cálculos
@return a raiz quadrada de n
*/
double raiz(double n, double p);

/*
Valor absoluto de um numero qualquer
@param n um número real qualquer
@return o valor absoluto de n
*/
double absoluto(double n);

int main(void) {
    double num, erro;

    scanf("%lf %lf", &num, &erro);

    raiz(num, erro);

    return 0;
}

double raiz(double n, double p) {
    double erro = 999999999999999999, aproximacao = 1;

    while(erro > p) {
        aproximacao = ((aproximacao + (n / aproximacao)) / 2);
        erro = absoluto(n - aproximacao*aproximacao);
        printf("r: %.9lf, err: %.9lf\n", aproximacao, erro);
    }

    return aproximacao;
}

double absoluto(double n) {
    if(n >= 0) {
        return n;
    } else {
        return -n;
    }
}