#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct string String;
typedef struct curso Curso;
typedef struct aluno Aluno;

struct string {
    char * str;
    int len;
};

struct curso {
    int codigo;
    float credito;
    String nome;
};

struct aluno {
    String nome;
    int codigo_curso;
    int creditos_usados;
};

int main(void) {
    int qtd_cursos, qtd_alunos;
    char buffer[1000];
    int i, j;
    Curso * cursos = NULL;
    Aluno * alunos = NULL;


    scanf("%d", &qtd_cursos);

    cursos = calloc(qtd_cursos, sizeof(Curso));

    for(i = 0; i < qtd_cursos; i++) {
        scanf("%d%f%*c%[^\n]", &cursos[i].codigo, &cursos[i].credito, buffer);
        cursos[i].nome.len = strlen(buffer)+1;
        cursos[i].nome.str = calloc(cursos[i].nome.len, sizeof(char));
        strcpy(cursos[i].nome.str, buffer);
    }

    scanf("%d%*c", &qtd_alunos);

    alunos = calloc(qtd_alunos, sizeof(Curso));

    for(i = 0; i < qtd_alunos; i++) {
        scanf("%[^\n]%d%d%*c", buffer, &alunos[i].codigo_curso, &alunos[i].creditos_usados);
        alunos[i].nome.len = strlen(buffer)+1;
        alunos[i].nome.str = calloc(alunos[i].nome.len, sizeof(char));
        strcpy(alunos[i].nome.str, buffer);
    }

    for(i = 0; i < qtd_alunos; i++) {
        for(j = 0; j < qtd_cursos; j++) {
            if(alunos[i].codigo_curso == cursos[j].codigo) {
                printf("Aluno(a): %s Curso: %s Num. Creditos: %d Valor Credito: %.2lf Mensalidade: %.2lf\n",
                    alunos[i].nome.str,
                    cursos[j].nome.str,
                    alunos[i].creditos_usados,
                    cursos[j].credito,
                    alunos[i].creditos_usados*cursos[j].credito
                );
                break;
            }
        }
    }

    for(i = 0; i < qtd_alunos; i++) {
        free(alunos[i].nome.str);
        alunos[i].nome.len = 0;
    }

    for(i = 0; i < qtd_cursos; i++) {
        free(cursos[i].nome.str);
        cursos[i].nome.len = 0;
    }

    free(alunos);
    free(cursos);
    
    return 0;
}