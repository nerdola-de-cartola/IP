#include <stdio.h>

int imprime(char posicao, int a, int b, int c);

int main(void) {
    int a, b, c, tmp;
    char primeiro, segundo, terceiro;

    //Recebe o input
    scanf("%d %d %d \n", &a, &b, &c);
    scanf("%c %c %c", &primeiro, &segundo, &terceiro);

    //Ordena as variáveis
    if (a > b) {
        tmp = a;
        a = b;
        b = tmp;

    } if ( b > c) {
        tmp = b;
        b = c;
        c = tmp;
        
    } if (a > b) {
        tmp = a;
        a = b;
        b = tmp;
    }

    //Imprime o resultado
    imprime(primeiro, a, b, c);
    imprime(segundo, a, b, c);
    imprime(terceiro, a, b, c);
    printf("\n");
    
    return 0;
}

int imprime(char posicao, int a, int b, int c) {
    if (posicao == 'A' || posicao == 'a') {
        printf("%d ", a);

    } else if (posicao == 'B' || posicao == 'b') {
        printf("%d ", b);

    } else {
        printf("%d ", c);
    }

    return 0;
}