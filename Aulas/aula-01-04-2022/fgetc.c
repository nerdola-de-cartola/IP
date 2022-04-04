#include <stdio.h>
#include <stdbool.h>

int main(void) {
    char c;
    FILE * arq;

    arq = fopen("entrada.txt", "r");
    if(arq == NULL) return 1;

    while(true) {
        c = (char) fgetc(arq);
        if(c == EOF) break;
        printf("%c", c);
    }

    return 0;
}