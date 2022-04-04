#include <stdio.h>

int main(void) {
    FILE * arq = NULL;

    arq = fopen("name.txt", "a");
    if(arq == NULL) return 1;

    fclose(arq);

    return 0;
}