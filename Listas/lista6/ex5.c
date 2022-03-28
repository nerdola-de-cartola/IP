#include <stdio.h>
#include <stdlib.h>

struct curso {
    int codigo;
    float credito;
    char nome[100];
};

struct aluno {
    char nome[500];
    int codigo_curso;
    int creditos_usados;
};

typedef struct curso Curso;
typedef struct aluno Aluno;

int main(void) {
    int qtd_cursos, qtd_alunos;
    int i, j;
    Curso * cursos = NULL;
    Aluno * alunos = NULL;


    scanf("%d", &qtd_cursos);

    cursos = calloc(qtd_cursos, sizeof(Curso));

    for(i = 0; i < qtd_cursos; i++) {
        scanf("%d%f%*c%[^\n]", &cursos[i].codigo, &cursos[i].credito, cursos[i].nome);
    }

    scanf("%d%*c", &qtd_alunos);

    alunos = calloc(qtd_alunos, sizeof(Curso));

    for(i = 0; i < qtd_alunos; i++) {
        scanf("%[^\n]%d%d%*c", alunos[i].nome, &alunos[i].codigo_curso, &alunos[i].creditos_usados);
    }

    for(i = 0; i < qtd_alunos; i++) {
        for(j = 0; j < qtd_cursos; j++) {
            if(alunos[i].codigo_curso == cursos[j].codigo) {
                printf("Aluno(a): %s Curso: %s Num. Creditos: %d Valor Credito: %.2lf Mensalidade: %.2lf\n",
                    alunos[i].nome,
                    cursos[j].nome,
                    alunos[i].creditos_usados,
                    cursos[j].credito,
                    alunos[i].creditos_usados*cursos[j].credito
                );
            }
        }
    }

    free(alunos);
    free(cursos);
    
    return 0;
}