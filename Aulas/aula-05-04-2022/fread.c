#include <stdio.h>

int main(void) {
    FILE * arq = NULL;
    int n;

    arq = fopen("int", "rb");
    if(arq == NULL) return 1;

    fread(&n, sizeof(int), 1, arq);
    fprintf(stdout, "Inteiro: %d\n", n);

    fclose(arq);
    
    return 0;
}