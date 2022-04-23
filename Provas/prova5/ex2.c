#include <stdio.h>
#include <stdlib.h>

/**
* Estrutura que representa um vetor de inteiros.
*/
typedef struct {
    double * d; /** ponteiro para o vetor de inteiros */
    int n; /** quantidade de elementos inseridos no vetor */
} Vet;

/**
* Cria uma estrutura Vet com o vetor de elementos devidamente alocado
* @param n quantidade de elementos a ser alocada
* @return ponteiro para a estrutura Vet criada
*/
Vet * vet_new(int n);

/**
* Libera a memória ocupada por vet
* @param vet Ponteiro para a estrutura Vet
*/
void vet_free(Vet * vet);

/**
* Função que insere o valor k na estrutura vet de modo ordenado crescente.
* @param vet Ponteiro para a estrutura Vet
* @param k valor a ser inserido no vetor
*/
void vet_insert(Vet * vet, double k);

/**
* Função que verifica se o valor k está presente na estrutura vet.
* @param vet Ponteiro para a estrutura Vet
* @param k valor a ser pesquisado no vetor
* @return posição do vetor em que k aparece pela primeira vez.
* Caso k não esteja presente, a função retorna -1.
*/
int vet_search(Vet * vet, double k);

int main(void) {
    Vet * vet;
    int pos;
    vet = vet_new(10);
    vet_insert(vet, 0.2);
    vet_insert(vet, 20.2);
    vet_insert(vet, 0.1);
    vet_insert(vet, 15.2);
    vet_insert(vet, 10.5);
    vet_insert(vet, 10.2);
    printf("Posição do 0.1: %d\n", vet_search(vet, 0.1));
    printf("Posição do 0.2: %d\n", vet_search(vet, 0.2));
    printf("Posição do 10.2: %d\n", vet_search(vet, 10.2));
    printf("Posição do 10.5: %d\n", vet_search(vet, 10.5));
    printf("Posição do 15.2: %d\n", vet_search(vet, 15.2));
    printf("Posição do 20.2: %d\n", vet_search(vet, 20.2));
    vet_free(vet);
}

Vet * vet_new(int n) {
    Vet * v;

    v = calloc(1, sizeof(Vet));
    v->d = calloc(n, sizeof(double));
    v->n = 0;

    return v;
}

void vet_free(Vet * vet) {
    free(vet->d);
    free(vet);
}

int vet_search(Vet * vet, double k) {
    int i;

    for(i = 0; i < vet->n; i++) {
        if(vet->d[i] == k) return i;
    }

    return -1;
}

void vet_insert(Vet * vet, double k) {
    double * tmp;
    int i, j;

    tmp = realloc(vet->d, (vet->n + 1) * sizeof(double));
    if(tmp == NULL) exit(1);
    vet->d = tmp;
    
    for(i = 0; i < vet->n; i++) {
        if(k < vet->d[i]) {
            for(j = vet->n; j > i; j--) {
                vet->d[j] = vet->d[j - 1];
            }

            vet->d[i] = k;
            break;
        }
    }

    if(i == vet->n) {
        vet->d[vet->n] = k;
    }

    vet->n++;
}