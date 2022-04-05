#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Fracao {
    int numerador;
    int denominador;
};

int main(void) {
    int total_testes, teste;
    struct Fracao ** v = NULL;
    int * qtd_fracoes;
    bool existe_equivalente;
    int i, j;
    double f1, f2;

    scanf("%d", &total_testes);
    v = (struct Fracao **) malloc(total_testes * sizeof (struct Fracao *));
    qtd_fracoes = (int *) malloc(total_testes * sizeof (int));

    for(teste = 0; teste < total_testes; teste++) {
        scanf("%d", &qtd_fracoes[teste]);
        v[teste] = (struct Fracao *) malloc(qtd_fracoes[teste] * sizeof (struct Fracao));

        for(i = 0; i < qtd_fracoes[teste]; i++) {
            scanf("%d/%d", &v[teste][i].numerador, &v[teste][i].denominador);
        }
    }

    for(teste = 0; teste < total_testes; teste++) {
        printf("Caso de teste %d\n", teste+1);

        for(i = 0, existe_equivalente = false; i < qtd_fracoes[teste]; i++) {
            for(j = i+1; j < qtd_fracoes[teste]; j++) {
                f1 = (double) v[teste][i].numerador / (double) v[teste][i].denominador;
                f2 = (double) v[teste][j].numerador / (double) v[teste][j].denominador;
                if(f1 == f2) {
                    printf("%d/%d", v[teste][i].numerador, v[teste][i].denominador);
                    printf(" equivalente a ");
                    printf("%d/%d\n", v[teste][j].numerador, v[teste][j].denominador);
                    existe_equivalente = true;
                }
            }
        }

        if(!existe_equivalente) printf("Nao ha fracoes equivalentes na sequencia\n");
        free(v[teste]);
    }

    free(v);
    free(qtd_fracoes);
    
    return 0;
}