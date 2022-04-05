#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct termoDoPolinomio {
    double coeficiente;
    int expoente;
};

typedef struct termoDoPolinomio Pol;

void printPolinomio(Pol * p, int tamanho);
Pol * lePolinomio(int * tamanho);
void ordenaPolinomio(Pol * p, int tamanho);
Pol * somaPolinomios(Pol * p1, Pol * p2, int tamanho1, int tamanho2, int * tamanho_final);
Pol * subtraiPolinomios(Pol * p1, Pol * p2, int tamanho1, int tamanho2, int * tamanho_final);

int main(void) {
    int i, qtd_termos1, qtd_termos2, qtd_termos_final, teste, qtd_testes;
    char sinal;
    Pol * polinomio1 = NULL;
    Pol * polinomio2 = NULL;
    Pol * polinomio_final = NULL;

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
    }

    return 0;

}

void printPolinomio(Pol * p, int tamanho) {
    int i;

    for(i = 0; i < tamanho; i++) {
        if(p[i].coeficiente == 0) continue;

        if(p[i].expoente != 0) printf("%+.2lfX^%d", p[i].coeficiente, p[i].expoente);
        else printf("%+.2lf", p[i].coeficiente);
    }

    printf("\n");
}

Pol * lePolinomio(int * tamanho) {
    int i, j, k;
    Pol * p = NULL;
    Pol * np = NULL;
    Pol tmp;

    scanf("%d%*c", tamanho); // Qtd de termos do polinomio
    p = calloc(*tamanho, sizeof(Pol));

    for(i = 0, k = 0; i < *tamanho; i++) {
        scanf("%lf%d%*c", &tmp.coeficiente, &tmp.expoente); // Coeficiente e expoente

        for(j = 0; j < k; j++) {
            if(p[j].expoente == tmp.expoente) {
                p[j].coeficiente += tmp.coeficiente;
                break;
            }
        }

        if(j == k) {
            p[k] = tmp;
            k++;
        }
    }

    np = realloc(p, k*sizeof(Pol));
    if(np != NULL) p = np;

    *tamanho = k;

    return p;
}

void ordenaPolinomio(Pol * p, int tamanho) {
    int i, j, maior;
    Pol tmp;

    for(i = 0; i < tamanho-1; i++) {
        maior = i;

        for(j = i+1; j < tamanho; j++) {
            if(p[j].expoente > p[maior].expoente) maior = j;
        }

        if(i != maior) {
            tmp = p[i];
            p[i] = p[maior];
            p[maior] = tmp;
        }
    }
}

Pol * somaPolinomios(Pol * p1, Pol * p2, int tamanho1, int tamanho2, int * tamanho_final) {
    Pol * polinomio = NULL;
    Pol * np = NULL;
    int tamanho;
    int i, j;
    bool unico;

    polinomio = calloc(tamanho1 + tamanho2, sizeof (Pol));

    for(i = 0; i < tamanho1; i++) {
        polinomio[i] = p1[i];   
    }

    tamanho = i;

    for(i = 0; i < tamanho2; i++) {
        unico =  true;

        for(j = 0; j < tamanho1; j++) {
            if(polinomio[j].expoente == p2[i].expoente) {
                polinomio[j].coeficiente += p2[i].coeficiente;
                unico = false;
            }
        }

        if(unico) {
            polinomio[tamanho] = p2[i];
            tamanho++;
        }
    }

    np = realloc(polinomio, tamanho * sizeof (Pol));
    if(np != NULL) polinomio = np;

    *tamanho_final = tamanho;
    return polinomio;
}

Pol * subtraiPolinomios(Pol * p1, Pol * p2, int tamanho1, int tamanho2, int * tamanho_final) {
    Pol * polinomio = NULL;
    int tamanho;
    int i;

    for(i = 0; i < tamanho2; i++) {
        p2[i].coeficiente *= -1;
    }

    polinomio = somaPolinomios(p1, p2, tamanho1, tamanho2, &tamanho);
    *tamanho_final = tamanho;

    return polinomio;
}