#include <stdio.h>

int main(void) {
    FILE * arq;
    int i;

    arq = fopen("dados.txt", "w");
    if(arq == NULL) return 1;

    for(i = 1; i <= 100; i++) {
        fprintf(arq, "%d\n", i);
    }

    fclose(arq);
    
    return 0;
}