#include <stdio.h>

int main(void) {
    FILE * arq;
    int i;

    arq = fopen("dados_binarios", "wb");
    if(arq == NULL) return 1;

    for(i = 1; i <= 100; i++) { 
        fwrite(&i, sizeof(char), 1, arq);
    }

    fclose(arq);
    
    return 0;
}