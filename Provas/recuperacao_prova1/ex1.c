#include <stdio.h>

int main(void) {
    char tipo;
    int qtd_pessoas;
    double salario_bruto, salario_liquido, total_plano, desconto_plano, porcentagem;

    scanf("%lf %d %c %lf", &salario_bruto, &qtd_pessoas, &tipo, &total_plano);

    if(tipo != 'A' && tipo != 'E') {
        printf("TIPO DE PLANO INVALIDO\n");
        return 0;
    }

    if(salario_bruto > 5000) {
        if(tipo == 'E') {
            porcentagem = 0.31;
        } else {
            porcentagem = 0.40;
        }
    } else if(salario_bruto > 1800 ) {
        if(tipo == 'E') {
            porcentagem = 0.28;
        } else {
            porcentagem = 0.35;
        }
    } else {
        if(tipo == 'E') {
            porcentagem = 0.25;
        } else {
            porcentagem = 0.30;
        }
    }

    desconto_plano = total_plano * porcentagem * qtd_pessoas;
    salario_liquido = salario_bruto - desconto_plano;

    if(salario_liquido < salario_bruto * 0.30) {
        printf("DESCONTO NAO AUTORIZADO\n");
        return 0;
    }

    if(tipo == 'E') {
        printf("ENFERMAGEM %.2lf\n", desconto_plano);
    } else {
        printf("APARTAMENTO %.2lf\n", desconto_plano);
    }
    
    return 0;
}