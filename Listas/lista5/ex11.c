#include <stdio.h>
#include <stdlib.h>

struct termoDoPolinomio {
    float coeficiente;
    int expoente;
};

void printPolinomio(struct termoDoPolinomio * p, int tamanho);
struct termoDoPolinomio * lePolinomio(int * tamanho);
void ordenaPolinomio(struct termoDoPolinomio * p, int tamanho);
struct termoDoPolinomio * somaPolinomios(struct termoDoPolinomio * p1, struct termoDoPolinomio * p2, int tamanho1, int tamanho2, int * tamanho_final);
struct termoDoPolinomio * subtraiPolinomios(struct termoDoPolinomio * p1, struct termoDoPolinomio * p2, int tamanho1, int tamanho2, int * tamanho_final);

int main(void) {
    int i, qtd_termos1, qtd_termos2, qtd_termos_final, teste, qtd_testes;
    char sinal;
    struct termoDoPolinomio * polinomio1 = NULL;
    struct termoDoPolinomio * polinomio2 = NULL;
    struct termoDoPolinomio * polinomio_final = NULL;

    scanf("%d%*c", &qtd_testes);

    teste = 0;
    while(teste < qtd_testes) {
        scanf("%c", &sinal);
        polinomio1 = lePolinomio(&qtd_termos1);
        polinomio2 = lePolinomio(&qtd_termos2);

        if(sinal == '+') {
            polinomio_final = somaPolinomios(polinomio1, polinomio2, qtd_termos1, qtd_termos2, &qtd_termos_final); 
        } else if(sinal == '-'){
            polinomio_final = subtraiPolinomios(polinomio1, polinomio2, qtd_termos1, qtd_termos2, &qtd_termos_final);
        } else return 1;

        ordenaPolinomio(polinomio_final, qtd_termos_final);
        printPolinomio(polinomio_final, qtd_termos_final);
        free(polinomio1);
        free(polinomio2);
        free(polinomio_final);

        teste++;
        scanf("%*c");
    }

    return 0;

}

void printPolinomio(struct termoDoPolinomio * p, int tamanho) {
    int i;

    for(i = 0; i < tamanho; i++) {
        if(p[i].coeficiente == 0) continue;

        if(p[i].coeficiente > 0) printf("+");
        printf("%.2f", p[i].coeficiente);
        if(p[i].expoente != 0) printf("X∧%d", p[i].expoente);
    }

    printf("\n");
}

struct termoDoPolinomio * lePolinomio(int * tamanho) {
    int i;
    struct termoDoPolinomio * p;

    scanf("%d", tamanho); // Sinal e Qtd de termos do polinomio
    p = calloc(*tamanho, sizeof (struct termoDoPolinomio));

    for(i = 0; i < *tamanho; i++) {
        scanf("%f%d", &p[i].coeficiente, &p[i].expoente); // Coeficiente e expoente
    }

    return p;
}

void ordenaPolinomio(struct termoDoPolinomio * p, int tamanho) {
    int i, j, indice_maior;
    struct termoDoPolinomio tmp;

    for(i = 0; i < tamanho-1; i++) {
        indice_maior = i;

        for(j = i+1; j < tamanho; j++) {
            if(p[j].expoente > p[indice_maior].expoente) indice_maior = j;
        }

        if(i != indice_maior) {
            tmp.coeficiente = p[i].coeficiente;
            tmp.expoente = p[i].expoente;

            p[i].coeficiente = p[indice_maior].coeficiente;
            p[i].expoente = p[indice_maior].expoente;

            p[indice_maior].coeficiente = tmp.coeficiente;
            p[indice_maior].expoente = tmp.expoente;

        }
    }
}

struct termoDoPolinomio * somaPolinomios(struct termoDoPolinomio * p1, struct termoDoPolinomio * p2, int tamanho1, int tamanho2, int * tamanho_final) {
    int i, j, indice;
    int tamanho = tamanho1 + tamanho2;
    struct termoDoPolinomio * polinomio = NULL;
    struct termoDoPolinomio * np = NULL;

    polinomio = calloc(tamanho, sizeof (struct termoDoPolinomio));

    indice = 0;
    for(i = 0; i < tamanho1; i++) {
        polinomio[indice].coeficiente = p1[i].coeficiente; 
        polinomio[indice].expoente = p1[i].expoente; 

        for(j = 0; j < tamanho2; j++) {
            if(p1[i].expoente == p2[j].expoente) {
                polinomio[indice].coeficiente += p2[j].coeficiente;
                tamanho--;
            }
        }
        indice++;
    }

    for(i = 0; i < tamanho2; i++) {
        for(j = 0; j < tamanho1; j++) {
            if(p2[i].expoente == p1[j].expoente) break;
        }

        if(j == tamanho1) {
            polinomio[indice].coeficiente = p2[i].coeficiente;
            polinomio[indice].expoente = p2[i].expoente;
            indice++;
        }
    }

    np = realloc(polinomio, tamanho * sizeof (struct termoDoPolinomio));
    if(np != NULL) polinomio = np;

    *tamanho_final = tamanho;
    return polinomio;
}

struct termoDoPolinomio * subtraiPolinomios(struct termoDoPolinomio * p1, struct termoDoPolinomio * p2, int tamanho1, int tamanho2, int * tamanho_final) {
    int i, j, indice;
    int tamanho = tamanho1 + tamanho2;
    struct termoDoPolinomio * polinomio = NULL;
    struct termoDoPolinomio * np = NULL;

    polinomio = calloc(tamanho, sizeof (struct termoDoPolinomio));

    indice = 0;
    for(i = 0; i < tamanho1; i++) {
        polinomio[indice].coeficiente = p1[i].coeficiente; 
        polinomio[indice].expoente = p1[i].expoente; 

        for(j = 0; j < tamanho2; j++) {
            if(p1[i].expoente == p2[j].expoente) {
                polinomio[indice].coeficiente -= p2[j].coeficiente;
                tamanho--;
            }
        }
        indice++;
    }

    for(i = 0; i < tamanho2; i++) {
        for(j = 0; j < tamanho1; j++) {
            if(p2[i].expoente == p1[j].expoente) break;
        }

        if(j == tamanho1) {
            polinomio[indice].coeficiente = p2[i].coeficiente;
            polinomio[indice].expoente = p2[i].expoente;
        }
    }

    np = realloc(polinomio, tamanho * sizeof (struct termoDoPolinomio));
    if(np != NULL) polinomio = np;

    *tamanho_final = tamanho;
    return polinomio;
}