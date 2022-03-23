#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 200
#define MAX_WORD_LEN 64+1

/**
* @brief Função de separação de palavras de acordo com a uma lista de separadores.
* Exemplo de chamada da função:
* str_split("Ola mundo! 1,23", m, ", .!?");
*
* O resultado é a separação das strings "Ola", "mundo", "1", "23", cada uma
* ocupando uma linha da matriz m, com base nos caracteres de pontuação fornecidos.
*
* @param str ponteiro para o início da string original
* @param m matriz de caracteres, sendo cada linha uma palavra da string original
* @param sep string com a lista de caracteres separadores
* @return int quantidade de palavras detectadas
*/
int str_split(char * str, char m[][MAX_WORD_LEN], char * sep);
int printPalavras(char m[][MAX_WORD_LEN], int qtd_palavras);
int contaPalavraPeloTamanho(char m[][MAX_WORD_LEN], int qtd_palavras, int tamanho);
bool charInString(char c, char * str);
void stringCopySegment(char * dest, char * src, int start, int end);

int main(void) {
    char str[MAX_WORD_LEN*MAX_WORD_LEN*2];
    char separadores[MAX_WORD_LEN];
    char matriz[MAX_WORD_LEN][MAX_WORD_LEN];
    int qtd_palavras;
    int maior_palavra; //Tamanho da maior palavra

    scanf("%[^\n]%*c", str);
    scanf("%[^\n]", separadores);

    qtd_palavras = str_split(str, matriz, separadores);
    maior_palavra = printPalavras(matriz, qtd_palavras);

    printf("%d\n", contaPalavraPeloTamanho(matriz, qtd_palavras, maior_palavra));

    return 0;
}

int str_split(char * str, char m[][MAX_WORD_LEN], char * sep) {
    int i, j, contador = 0;
    char palavra[MAX_WORD_LEN];

    i = 0;
    while(str[i] != '\0') {
        j = i+1;

        while(!charInString(str[j], sep) && str[j] != '\0') j++;

        stringCopySegment(m[contador], str, i, j-1);
        contador++;

        i = j+1;
        while(charInString(str[i], sep)) i++;
    }

    return contador;
}

int printPalavras(char m[][MAX_WORD_LEN], int qtd_palavras) {
    int i;
    int tamanho;
    int maior_palavra = -1;

    for(i = 0; i < qtd_palavras; i++) {
        tamanho = strlen(m[i]);
        if(tamanho > maior_palavra) maior_palavra = tamanho;
        printf("(%d)%s\n", tamanho, m[i]);
    }

    return maior_palavra;
}

int contaPalavraPeloTamanho(char m[][MAX_WORD_LEN], int qtd_palavras, int tamanho) {
    int i, contador;

    for(i = 0, contador = 0; i < qtd_palavras; i++) {
        if(tamanho == strlen(m[i])) contador++;
    }

    return contador;
}

bool charInString(char c, char * str) {
    int i = 0;

    while(str[i] != '\0') {
        if(c == str[i]) return true;
        i++;
    }

    return false;
}

void stringCopySegment(char * dest, char * src, int start, int end) {
    int i, j;

    for(i = start, j = 0; i <= end; i++, j++) {
        dest[j] = src[i];
    }

    dest[j] = '\0';

    return;
}
