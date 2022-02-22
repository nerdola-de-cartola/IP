#include <stdio.h>

void converteEmNotasMoedas(int valor, int *n100, int *n50, int *n10, int *n1);

int main(void) {
    int valor, notas100, notas50, notas10, moedas;
    scanf("%d", &valor);

    if(valor < 0) {
        return -1;
    }
    
    converteEmNotasMoedas(valor, &notas100, &notas50, &notas10, &moedas);

    printf("NOTAS DE 100 = %d\n", notas100);
    printf("NOTAS DE 50 = %d\n", notas50);
    printf("NOTAS DE 10 = %d\n", notas10);
    printf("MOEDAS DE 1 = %d\n", moedas);

    return 0;
}

void converteEmNotasMoedas(int valor, int *n100, int *n50, int *n10, int *n1) {
    int notas[4] = {0};
    
    while(valor != 0) {
        if(valor >= 100) {
            notas[0]++;
            valor -= 100;
        } else if(valor >= 50) {
            notas[1]++;
            valor -= 50;
        } else if(valor >= 10) {
            notas[2]++;
            valor -= 10;
        } else {
            notas[3]++;
            valor--;
        }
    }

    *n100 = notas[0];
    *n50 = notas[1];
    *n10 = notas[2];
    *n1 = notas[3];

    return;
}