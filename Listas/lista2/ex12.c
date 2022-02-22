#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool calculaHipotenusa(const int hip, const int ca1, const int ca2);

int main(void) {
    int n, h, c1, c2, maior_cateto, menor_cateto, tmp;

    scanf("%d", &n);

    if(n < 1) {
        return 0;
    }

    for(h = 1; h <= n; h++) {
        for(c1 = 1; c1 < h; c1++) {
            for(c2 = c1; c2 < h; c2++) {

                if(calculaHipotenusa(h, c1, c2)) {

                    if(c1 > c2) {
                        maior_cateto = c1;
                        menor_cateto = c2;
                    } else {
                        maior_cateto = c2;
                        menor_cateto = c1;
                    }

                    printf("hipotenusa = %d, catetos %d e %d\n", h, menor_cateto, maior_cateto);
                }
            }
        }
    }
    
    return 0;
}

bool calculaHipotenusa(const int hip, const int ca1, const int ca2) {    
    if(pow(hip, 2) == pow(ca1, 2) + pow(ca2, 2)) {
        return true;

    } else {
        return false;
    }
}