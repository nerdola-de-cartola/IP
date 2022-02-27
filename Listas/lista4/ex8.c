#include <stdio.h>
#include <string.h>

int main(void) {
    int i, j;
    int qtd_textos;
    char textos[1000][1000];
    char textos_criptografados1[1000][1000];
    char textos_criptografados2[1000][1000];
    char textos_criptografados3[1000][1000];
    int tamanho_da_str, metade_da_str;

    scanf("%d", &qtd_textos);

    for(i = 0; i < qtd_textos; i++) {
        scanf("%*c %[^\n]", &textos[i][0]);
    }

    for(i = 0; i < qtd_textos; i++) {
        j = 0;
        while(textos[i][j] != '\0') {
            if(textos[i][j] >= 'A' && textos[i][j] <= 'z') {
                textos_criptografados1[i][j] = textos[i][j] + 3;
            } else {
                textos_criptografados1[i][j] = textos[i][j];
            }

            j++;
        }
    }


    for(i = 0; i < qtd_textos; i++) {
        tamanho_da_str = strlen(textos_criptografados1[i]);

        j = 0;
        while(textos_criptografados1[i][j] != '\0') {
            textos_criptografados2[i][tamanho_da_str - j - 1] = textos_criptografados1[i][j];
            j++;
        }
    }

    for(i = 0; i < qtd_textos; i++) {
        metade_da_str = strlen(textos_criptografados2[i]) / 2;

        j = 0;
        while(textos_criptografados2[i][j] != '\0') {
            if(j >= metade_da_str) {
                textos_criptografados3[i][j] = textos_criptografados2[i][j] - 1;
            } else {
                textos_criptografados3[i][j] = textos_criptografados2[i][j];
            }
            j++;
        }
    }

    for(i = 0; i < qtd_textos; i++) {
        printf("%s\n", textos_criptografados3[i]);
    }

    return 0;
}