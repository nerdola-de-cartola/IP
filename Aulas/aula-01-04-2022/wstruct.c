#include <stdio.h>
#include <string.h>

struct pessoa {
    char nome[8];
    int idade;
    char sexo;
};

typedef struct pessoa Pessoa;

int main(void) {
    Pessoa p1 = {
        "Joao",
        20,
        'M'
    };

    Pessoa p2 = {
        .sexo = 'F',
        .idade = 16,
        .nome = "Maria"
    };

    memset(p1.nome, '0', 8);
    memset(p2.nome, '0', 8);

    strcpy(p1.nome, "Joao");
    strcpy(p2.nome, "Maria");

    FILE * arq = fopen("pessoa", "w");
    if(arq == NULL);

    fwrite(&p1, sizeof(Pessoa), 1, arq);
    fwrite(&p2, sizeof(Pessoa), 1, arq);
    
    fclose(arq);

    return 0;
}