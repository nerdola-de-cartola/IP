#include <stdio.h>

int main(void) {
    int i, j;
    int qtd_textos;
    int tamanho_sub_str;
    char str[20][499];
    char sub_str[20][499];
    
    scanf("%d", &qtd_textos);
    
    for(i = 0; i < qtd_textos; i++) {
        scanf("%d", &tamanho_sub_str);
        scanf("%*c %[^\n]", &str[i][0]);
        
        for(j = 0; j < tamanho_sub_str; j++) {
            sub_str[i][j] = str[i][j];
        }
    }
    
    for(i = 0; i < qtd_textos; i++) {
        printf("%s\n", sub_str[i]);
    }
    
    return 0;
}
