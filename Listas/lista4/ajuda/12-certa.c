#include <stdio.h>

char * subStr(char str[], int qtd_caracteres);

int main(void) {
    int i, j;
    int qtd_textos;
    int tamanho_sub_str;
    char str[499];

    scanf("%d", &qtd_textos);
    
    for(i = 0; i < qtd_textos; i++) {
        scanf("%d", &tamanho_sub_str);
        scanf("%*c %[^\n]", str);
        subStr(str, tamanho_sub_str);
    }
    
    return 0;
}

char * subStr(char str[], int qtd_caracteres) {
    int i;
    char sub_str[qtd_caracteres];

    for(i = 0; i < qtd_caracteres; i++) {
            sub_str[i] = str[i];
    }

    sub_str[i] = '\0';

    printf("%s\n", sub_str);
}
