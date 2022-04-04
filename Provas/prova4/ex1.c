#include <stdio.h>
#include <stdlib.h>

typedef struct data Data;
typedef struct aluno Aluno;

struct data {
    int dia;
    int mes;
    int ano;
};

struct aluno {
    int matricula;
    Data nascimento;
    char nome[200];
};

void printAluno(Aluno a);
void ordenaAlunos(Aluno * vet, int size);
int comparaData(Data a, Data b);

int main(void) {
    int qtd_alunos;
    int i;
    Aluno * turma = NULL;

    scanf("%d", &qtd_alunos);

    turma = calloc(qtd_alunos, sizeof(Aluno));

    for(i = 0; i < qtd_alunos; i++) {
        scanf("%d%d%d%d%*c%[^\n]",
            &turma[i].matricula,
            &turma[i].nascimento.dia,
            &turma[i].nascimento.mes,
            &turma[i].nascimento.ano,
            turma[i].nome
        );
    }

    ordenaAlunos(turma, qtd_alunos);

    for(i = 0; i < qtd_alunos; i++) {
        printAluno(turma[i]);
    }

    free(turma);

    return 0;
}

void printAluno(Aluno a) {
    printf("Matric.: %d Nome: %s Data Nasc: %d/%d/%d\n",
        a.matricula,
        a.nome,
        a.nascimento.dia,
        a.nascimento.mes,
        a.nascimento.ano
    );
}

void ordenaAlunos(Aluno * vet, int size) {
    int i, j;
    int mais_novo;
    Aluno tmp;

    for(i = 0; i < size - 1; i++) {
        mais_novo = i;

        for(j = i+1; j < size; j++) {
            if(comparaData(vet[j].nascimento, vet[mais_novo].nascimento) == 0) mais_novo = j;
        }

        if(mais_novo != i) {
            tmp = vet[i];
            vet[i] = vet[mais_novo];
            vet[mais_novo] = tmp;
        }
    }
}

int comparaData(Data a, Data b) {
    if(a.ano < b.ano) return 1;
    else if(a.ano == b.ano) {
        if(a.mes < b.mes) return 1;
        else if(a.mes == b.mes) {
            if(a.dia <= b.dia) return 1;
        }
    }

    return 0;
}