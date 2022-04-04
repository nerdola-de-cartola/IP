#include <stdio.h>

int main(void) {
    FILE * arq;
    char ch;
    int x;

    scanf("%c%d", &ch, &x);

    arq = fopen("int", "wb");
    if(arq == NULL) return 1;

    fwrite(&x, sizeof(int), 1, arq);
    fwrite(&ch, sizeof(char), 1, arq);

    fclose(arq);

    return 0;
}