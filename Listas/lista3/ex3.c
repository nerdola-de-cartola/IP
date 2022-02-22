#include <stdio.h>

void separaDigitos(const int n, int * c, int * d, int * u);

int main(void) {
    int n, c, d, u;
    scanf("%d", &n);

    if(n == 0 || n % 10 == 0) {
        return 0;
    }

    separaDigitos(n, &c, &d, &u);
    printf("%d%d%d\n", u, d, c);

    return 0;
}

void separaDigitos(const int n, int * c, int * d, int * u) {
    *u = n % 10;
    *d = (n % 100 - *u) / 10;
    *c = (n % 1000 - *d - *u) / 100;
    return;
}