#include <stdio.h>
#include "complex.h"

int main(void) {
    FILE * arq = NULL;
    Complex v[3];
    int i, n;

    arq = fopen("Complex", "rb");
    if(arq == NULL) return 1;

    n = fread(v, sizeof(Complex), 3, arq);

    fclose(arq);

    for(i = 0; i < n; i++) {
        complexPrint(v[i]);
        printf("\n");
    }
    
    return 0;
}