#include <stdio.h>

/**
* Retorna o n-ésimo termo da sequência de Fibonacci
* @param t1 primeiro termo da sequência
* @param t2 segundo termo da sequência
* @param n a posição do termo desejado da sequência
* @return o valor do n-ésimo termo da sequência
*/
int fibonacci(int t1, int t2, int n);

int main(void) {
    int a1, a2, n;
    scanf("%d %d %d", &a1, &a2, &n);

    printf("%d\n", fibonacci(a1, a2, n));

    return 0;
}

int fibonacci(int t1, int t2, int n) {
    int i;
    int sequencia[n];

    for(i = 0; i < n; i++) {
        if(i == 0) {
            sequencia[i] = t1;
        } else if(i == 1) {
            sequencia[i] = t2;
        } else {
            sequencia[i] = sequencia[i - 1] + sequencia[i - 2];
        }
    }

    return sequencia[n -1];
}
