#include <stdio.h>
#include <string.h>

struct Pessoa {
    char nome[128];
    int idade;
    float altura;
    char sexo;
};

void printPessoa(struct Pessoa const * p);
struct Pessoa lePessoa(void);

int main(void) {
    struct Pessoa p[2];

    strcpy(p[0].nome, "Matheus Lucas");
    p[0].idade = 18;
    p[0].altura = 1.78;
    p[0].sexo = 'M';

    p[1] = lePessoa();

    printPessoa(&p[0]);
    printPessoa(&p[1]);

    return 0;
}

void printPessoa(struct Pessoa const * p) {
    printf("Nome: %s\n", p->nome);
    printf("Idade: %d\n", p->idade);
    printf("Altura: %.2lf\n", p->altura);
    printf("Sexo: %c\n", p->sexo);
}

struct Pessoa lePessoa(void) {
    struct Pessoa p;

    scanf("%[^\n]", p.nome);
    scanf("%d", &p.idade);
    scanf("%f", &p.altura);
    scanf("%*c %c", &p.sexo);

    return p;
}