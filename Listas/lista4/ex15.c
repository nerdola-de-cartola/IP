#include <stdio.h>

int main(void) {
    int i, j;
    int total_de_alunos, minimo_de_alunos, qtd_alunos_presentes = 0;
    int presenca[1000];
    int alunos_presentes[1000];

    scanf("%d", &total_de_alunos);
    scanf("%d", &minimo_de_alunos);

    for(i = 0; i < total_de_alunos; i++) {
        scanf("%d", &presenca[i]);
    }

    //Conta os alunos presentes e adiciona eles ao array alunos_presentes
    for(i = 0, j = 0; i < total_de_alunos; i++) {
        if(presenca[i] <= 0) {
            qtd_alunos_presentes++;
            alunos_presentes[j] = i+1;
            j++;
        }    
    }

    if(qtd_alunos_presentes >= minimo_de_alunos) {
        printf("NAO\n");

        for(i = qtd_alunos_presentes - 1; i >= 0; i--) {
            printf("%d\n", alunos_presentes[i]);
        }
    } else {
        printf("SIM\n");
    }

    return 0;
}