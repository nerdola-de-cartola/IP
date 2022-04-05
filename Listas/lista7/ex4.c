#include <stdio.h>

int main(void) {
    FILE * arq;
    int i;

    arq = fopen("abc", "wb");
    if( arq == NULL) return 1;

    for(i = 1629495328; i <= 1629495330; i++) {
        fwrite(&i, sizeof(int), 1, arq);       
    }

    fclose(arq);
    
    return 0;
}