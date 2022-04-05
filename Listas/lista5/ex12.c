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
* @param qtd_palavras parametrô de retorno para a quantidade de palavras
* @param sep string com a lista de caracteres separadores
*/
void str_split(char * str, char m[][MAX_WORD_LEN], int * qtd_palavras, char * sep);
void printPalavras(char m[][MAX_WORD_LEN], int qtd_palavras);
int contaPalavraPeloTamanho(char m[][MAX_WORD_LEN], int qtd_palavras, int tamanho);
bool charInString(char c, char * str);
void stringCopySegment(char * dest, char * src, int start, int end);
int tamanhoMaiorPalavra(char m[][MAX_WORD_LEN], int qtd_palavras);

int main(void) {
    char str[MAX_WORDS*MAX_WORD_LEN*2];
    char separadores[MAX_WORDS];
    char matriz[MAX_WORDS][MAX_WORD_LEN];
    int qtd_palavras;
    int maior_palavra; //Tamanho da maior palavra

    scanf("%[^\n]%*c", str);
    scanf("%[^\n]%*c", separadores);

    str_split(str, matriz, &qtd_palavras, separadores);
    printPalavras(matriz, qtd_palavras);

    maior_palavra = tamanhoMaiorPalavra(matriz, qtd_palavras);
    printf("%d\n", contaPalavraPeloTamanho(matriz, qtd_palavras, maior_palavra));

    return 0;
}

void str_split(char * str, char m[MAX_WORDS][MAX_WORD_LEN], int * qtd_palavras, char * sep) {
    int i, j;
    int qtd;

    qtd = 0;
    i = 0;

    while(charInString(str[i], sep)) i++;

    while(str[i] != '\0') {
        j = i+1;

        while(!charInString(str[j], sep) && str[j] != '\0') j++;

        stringCopySegment(m[qtd], str, i, j-1);
        qtd++;

        i = j+1;
        while(charInString(str[i], sep)) i++;
    }

    *qtd_palavras = qtd;
}

void printPalavras(char m[][MAX_WORD_LEN], int qtd_palavras) {
    int i;

    for(i = 0; i < qtd_palavras; i++) {
        printf("(%ld)%s\n", strlen(m[i]), m[i]);
    }

    return;
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

int tamanhoMaiorPalavra(char m[][MAX_WORD_LEN], int qtd_palavras) {
    int i;
    int len;
    int maior = strlen(m[0]);

    for(i = 1; i < qtd_palavras; i++) {
        len = strlen(m[i]);
        if(len > maior) maior = len;
    }

    return maior;
}
