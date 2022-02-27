#include <stdio.h>

int contaLetras(char texto[], int * v, int * c);

int main(void) {
    int i;
    int qtd_textos;
    int letras, consoantes, vogais;

    scanf("%d", &qtd_textos);

    char textos[qtd_textos][10000];

    for(i = 0; i < qtd_textos; i++) {
        scanf("%*c %[^\n]", textos[i]);
    }

    for(i = 0; i < qtd_textos; i++) {
        letras  = contaLetras(textos[i], &vogais, &consoantes);
        printf("Letras = %d\n", letras);
        printf("Vogais = %d\n", vogais);
        printf("Consoantes = %d\n", consoantes);
    }

    return 0;
}

int contaLetras(char texto[], int * v, int * c) {
    int letras = 0, vogais = 0, consoantes = 0;
    int i = 0;

    while(texto[i] != '\0') {
        if(texto[i] >= 'A' && texto[i] <= 'z') {
            letras++;

            if(texto[i] == 'a' || texto[i] == 'A' || texto[i] == 'e' || texto[i] == 'E' || texto[i] == 'i' || texto[i] == 'I' || texto[i] == 'o' || texto[i] == 'O' || texto[i] == 'u' || texto[i] == 'U') {
                vogais++;
            } else {
                consoantes++;
            }
        }

        i++;
    }

    *v = vogais;
    *c = consoantes;
    return letras;
}