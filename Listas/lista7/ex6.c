#include <stdio.h>
#include "complex.h"

int main(void) {
    FILE * arq = NULL;
    Complex v[3];
    int i;

    complexRead2(&v[0]);
    complexRead2(&v[1]);
    complexRead2(&v[2]);

    arq = fopen("Complex", "wb");
    if(arq == NULL) return 1;

    for(i = 0; i < 3; i++) {
        fwrite(&v[i], sizeof(Complex), 1, arq);
    }

    fclose(arq);

    return 0;
}