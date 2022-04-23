#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct fracao {
    int numerador;
    int denominador;
};

#define START 2

typedef struct fracao Fracao;

int main(void) {
    Fracao * v, * np;
    double fi, fj;
    bool existe_equivalente;
    char c;
    int total_testes, teste;
    int siz = START;
    int i, j;

    scanf("%d", &total_testes);
   
    for(teste = 0; teste < total_testes; teste++) {
        v = calloc(siz, sizeof(Fracao));
        scanf("%d/%d%c", &v[0].numerador, &v[0].denominador, &c);

        for(i = 1; c != '\n'; i++) {
            if(i >= siz) {
                siz = i+1;
                np = realloc(v, siz*sizeof(Fracao));
                if(np == NULL) return 1;
                v = np;
            }

            scanf("%d/%d%c", &v[i].numerador, &v[i].denominador, &c);
        }

        if(siz != i) {
            siz = i;
            np = realloc(v, siz*sizeof(Fracao));
            if(np == NULL) return 1;
            v = np;
        }

        printf("Caso de teste %d\n", teste+1);
        existe_equivalente = false;

        for(i = 0; i < siz; i++) {
            fi = (double) v[i].numerador / (double) v[i].denominador;

            for(j = i + 1; j < siz; j++) {
                fj = (double) v[j].numerador / (double) v[j].denominador;

                if(fi == fj) {
                    existe_equivalente = true;
                    
                    printf("%d/%d equivalente a %d/%d\n",
                        v[i].numerador,
                        v[i].denominador,
                        v[j].numerador,
                        v[j].denominador
                    );
                }
            }
        }

        if(!existe_equivalente) printf("Nao ha fracoes equivalentes na sequencia\n");

        free(v);
    }
    
    return 0;
}