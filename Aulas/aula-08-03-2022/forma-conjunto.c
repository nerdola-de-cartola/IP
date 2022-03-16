#include <stdio.h>
#include <stdbool.h>

bool aparece(int num, int vet[], int tamanho_vet);
int conta(int num, int vet[], int tamanho_vet);

int main(void) {
    int i, j;
    int num;
    int tamanho;
    int qtd_numeros_unicos;
    int conjunto[5000] = {0};

    scanf("%d", &tamanho);

    for(i = 0, j = 0; i < tamanho; i++) {
        scanf("%d", &num);

        //Se o número ainda não existe no vetor, coloca ele
        if(!aparece(num, conjunto, j)) {
            conjunto[j] = num;
            j++;
            qtd_numeros_unicos++;
        } else {
            qtd_numeros_unicos--;
        }
    }

    printf("%d\n", qtd_numeros_unicos);

    for(i = 0; i < j; i++) {
        printf("%d ", conjunto[i]);
    }

    printf("\n");

    return 0;
}

//Retorna true se um numero está presente em um array e false em caso contrário
bool aparece(int num, int vet[], int tamanho_vet) {
    int i;

    for(i = 0; i < tamanho_vet; i++) {
        if(vet[i] == num) return true;
    }

    return false;
}