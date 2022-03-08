#include <stdio.h>

double maiorElementoAbsoluto(double arr[], int tamanho);
void calculaVetores(double pontos[][3], double vetores[][3], int numero_de_pontos);
double absoluto(double num);

void main(void) {
    int i;
    int numero_de_pontos;
    double pontos[1000][3];
    double vetores[999][3];

    scanf("%d", &numero_de_pontos);

    if(numero_de_pontos < 2 || numero_de_pontos > 1000) return 1;

    for(i = 0; i < numero_de_pontos; i++) {
        scanf("%lf", &pontos[i][0]); // X
        scanf("%lf", &pontos[i][1]); // Y
        scanf("%lf", &pontos[i][2]); // Z
    }
    
    calculaVetores(pontos, vetores, numero_de_pontos);

    for(i = 0; i < numero_de_pontos - 1; i++) {
        printf("%.2lf\n", maiorElementoAbsoluto(vetores[i], 3));
    }

    return 0;
}

double maiorElementoAbsoluto(double arr[], int tamanho) {
    int i;
    double elemente_atual;
    double maior = -1;

    for(i = 0; i < tamanho; i++) {
        elemente_atual = absoluto(arr[i]);
        if(elemente_atual > maior) maior = elemente_atual;
    }

    return maior;
}

void calculaVetores(double pontos[][3], double vetores[][3], int numero_de_pontos) {
    int i, j;

    for(i = 0; i < numero_de_pontos; i++) {
         for(j = 0; j < 3; j++) {
            vetores[i][j] = pontos[i+1][j] - pontos[i][j];
        }
    }

    return;
}

double absoluto(double num) {
    if(num >=0) return num;
    else return -num;
}