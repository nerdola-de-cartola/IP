#include <stdio.h>

int main(void) {
    int c;
    FILE * arq;

    arq = fopen("alfabeto.txt", "w");
    if(arq == NULL) return 1;

    for(c = 'a'; c <= 'z'; c++) {
        fputc(c, arq);
    }

    fputc('\n', arq);

    for(c = 'A'; c <= 'Z'; c++) {
        fputc(c, arq);
    }

    fclose(arq);

    return 0;
}