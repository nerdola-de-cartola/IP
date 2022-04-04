#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const ** argv) {
    FILE * arq;
    char ch;

    if(argc != 2) {
        printf(
            "Usage: \n"
            "   ./argv <file name>"
        );
        return 1;
    }

    arq = fopen(argv[1], "r");
    if(arq == NULL) {
        printf("Nao foi possível abrir o arquivo %s\n", argv[1]);
        return 1;       
    }

    while(true) {
        ch = fgetc(arq);
        if(ch == EOF) break;

        printf("%c", ch);
    }

    printf("\n");

    fclose(arq);

    return 0;
}
