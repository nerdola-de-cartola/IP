#include <stdio.h>

int main(void) {
    FILE * arq = NULL;
    char c;

    arq = fopen("abc", "rb");
    if(arq == NULL) return 1;

    for(c = fgetc(arq); c != EOF; c = fgetc(arq)) {
        printf("(%d): %c\n", c, c);
    }

    fclose(arq);

    return 0;
}