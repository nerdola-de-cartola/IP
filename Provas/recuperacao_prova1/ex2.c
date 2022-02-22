#include <stdio.h>

int main(void) {
    int matricula, qtd_dependentes;
    float salario_minimo, salario, taxa, imposto_bruto, imposto_liquido, diferenca;

    scanf("%d %f %d %f %f", &matricula, &salario_minimo, &qtd_dependentes, &salario, &taxa);

    if(salario > salario_minimo * 12){
        imposto_bruto = salario * 0.2;

    } else if(salario > salario_minimo * 5){
        imposto_bruto = salario * 0.08;
        
    } else {
        imposto_bruto = 0;
    }

    imposto_liquido = imposto_bruto - (300 * qtd_dependentes);
    diferenca = imposto_liquido - (salario * taxa / 100);

    printf("MATRICULA = %d\n", matricula);
    printf("IMPOSTO BRUTO = %.2f\n", imposto_bruto);
    printf("IMPOSTO LIQUIDO = %.2f\n", imposto_liquido);
    printf("RESULTADO = %.2f\n", diferenca);

    if(diferenca > 0) {
        printf("IMPOSTO A PAGAR\n");

    } else if (diferenca < 0) {
        printf("IMPOSTO A RECEBER\n");

    } else {
        printf("IMPOSTO QUITADO\n");

    }
    
    return 0;
}