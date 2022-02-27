#include <stdio.h>
#include <string.h>

#define MAXIMO_DE_PALAVRAS 1000

int qualNumero(const char palavra[]);

int main(void) {
    int i, qtd_palavars;
    char palavras[MAXIMO_DE_PALAVRAS][5];

    scanf("%d", &qtd_palavars);

    for(i = 0; i < qtd_palavars; i++) {
        scanf("%s", &palavras[i][0]);
    }

    for(i = 0; i < qtd_palavars; i++) {
        printf("%d\n", qualNumero(palavras[i]));
    }

    return 0;
}

int qualNumero(const char palavra[]) {
    //three
    if(strlen(palavra) == 5) {
        return 3;
    }

    //one
    if(palavra[0] == 'o' && palavra[1] == 'n') {
        return 1;
    }

    if(palavra[0] == 'o' && palavra[2] == 'e') {
        return 1;
    }

    if(palavra[1] == 'n' && palavra[2] == 'e') {
        return 1;
    }

    // two
    if(palavra[0] == 't' && palavra[1] == 'w') {
        return 2;
    }

    if(palavra[0] == 't' && palavra[2] == 'o') {
        return 2;
    }

    if(palavra[1] == 'w' && palavra[2] == 'o') {
        return 2;
    }
}