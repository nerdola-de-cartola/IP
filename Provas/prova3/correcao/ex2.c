#include <stdio.h>
#include <string.h>

/**
* Função que remove vogais e calcula a quantidade de vogais removidas
* @param str string de entrada
* @param vogais vetor de 5 posições que contabiliza a quantidade
* de vogais removidas
* @return A função atualiza os vetores str e vogais.
*/
void remove_vogais(char * str, int * qtd_vogais);

#define N_MAX 256
#define MAX_VOGAIS 5
char vogais[MAX_VOGAIS*2] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

int main(void) {
    int i;
    char str[N_MAX];
    int qtd_vogais[MAX_VOGAIS] = {0};

    scanf("%[^\n]", str);

    remove_vogais(str, qtd_vogais);

    printf("%s\n", str);

    for(i = 0; i < MAX_VOGAIS; i++) {
        printf("%c: %d\n", vogais[i], qtd_vogais[i]);
    }

    return 0;
}

void remove_vogais(char * str, int * qtd_vogais) {
    int i = 0, j, k = 0;
    char nova_str[N_MAX];

    while(str[i] != '\0') {
        for(j = 0; j < MAX_VOGAIS*2; j++) {
            //Salva a quantidade de cada vogal
            if(str[i] == vogais[j]) {
                if(j >= MAX_VOGAIS) qtd_vogais[j - MAX_VOGAIS]++;
                else qtd_vogais[j]++;
                break;
            }
        }

        //Forma uma nova string sem as vogais
        if(j == MAX_VOGAIS*2) {
            nova_str[k] = str[i];
            k++;
        };

        i++;
    }

    nova_str[k] = '\0';

    strcpy(str, nova_str);
}