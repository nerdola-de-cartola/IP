#include <stdio.h>
#include <stdbool.h>

bool aparece(int num, int vet[], int tamanho_vet);
int conta(int num, int vet[], int tamanho_vet);

int main(void) {
    int i, j;
    int tamanho;
    int qtd_numeros_unicos = 0;
    int numeros[5000];
    int conjunto[5000];

    scanf("%d", &tamanho);

    for(i = 0; i < tamanho; i++) {
        scanf("%d", &numeros[i]);
    }
    
    //Monta um conjunto que tenha somente uma de cada numero do array original
    for(i = 0, j = 0; i < tamanho; i++) {
        if(!aparece(numeros[i], conjunto, tamanho)) {
            conjunto[j] = numeros[i];
            j++;
        }
    }

    //Usa o conjunto para procurar por cada numero no array e verfica se ele é único
    for(i = 0, j = 0; i < tamanho; i++) {
        if(conta(conjunto[i], numeros, tamanho) == 1) qtd_numeros_unicos++;
    }

    printf("%d\n", qtd_numeros_unicos);

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

//Conta a quantidade de vezes que um número aparece em um array
int conta(int num, int vet[], int tamanho_vet) {
    int i;
    int contador = 0;

    for(i = 0; i < tamanho_vet; i++) {
        if(vet[i] == num) contador++;
    }

    return contador;
}