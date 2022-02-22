#include <stdio.h>

/**
* Funcao que calcula o fatorial de um numero n
* @param n um numero inteiro positivo
* @return o fatorial de n
*/
unsigned long int fat(unsigned int n);

int main(void) {
    int n;
    scanf("%d", &n);

    printf("%d! = %ld\n", n, fat(n));
    
    return 0;
}

unsigned long int fat(unsigned int n) {
    if(n == 0) {
        return 1;
    } else {
        return n * fat(n - 1);
    }
}