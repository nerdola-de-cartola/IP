#include <stdio.h>
#include <string.h>

/**
* @param str vetor de caracteres onde a string lida será gravada
* @param n quantidade máxima de caracteres a ser lidos
* @return quantidade de caracteres lidos
*/
int le_string(char * str, int n);

/**
* @param str string de entrada
*/
void print_codes(char * str);

#define N 128+1

int main(void) {
    char str[N];
    char s[N];
    char c;
    int i;

    scanf("%c", &c);
    le_string(str, 3);
    print_codes(str);
    printf("caracter:%c, str:%s\n", c, str);

    scanf("%c", &c);
    le_string(str, 5);
    print_codes(str);
    printf("caracter:%c, str:%s\n", c, str);

    scanf("%c", &c);
    le_string(str, 5);
    print_codes(str);
    printf("caracter:%c, str:%s\n", c, str);

    scanf("%d", &i);
    le_string(str, 3);
    print_codes(str);
    printf("inteiro:%d, str:%s\n", i, str);

    //printf("Digite inteiros separados por espaço: ");
    scanf("%d", &i);
    //printf("inteiro:%d\n", i);
    //printf("Le string (15):\n");
    le_string(str, 15);
    print_codes(str);
    printf("inteiro:%d, str:%s\n", i, str);

    //printf("Digite uma string sem espaços: ");
    scanf("%s", s);
    //printf("string:%s\n", str);
    //printf("Le string (10):\n");
    le_string(str, 100);
    print_codes(str);
    printf("string:%s, str:%s\n", s, str);

    //printf("Digite uma string com espaços: ");
    scanf("%s", s);
    //printf("string:%s\n", str);
    //printf("Le string (20):\n");
    le_string(str, 100);
    print_codes(str);
    printf("string:%s, str:%s\n", s, str);

    return 0;
}

void print_codes(char * str) {
    printf("%d", (int) str[0]);

    int i = 1;
    while(str[i] != '\0') {
        printf(",%d", (int) str[i]);
        i++;
    }

    printf("\n");

    return;
}

int le_string(char * str, int n) {
    int i = 0;
    char entrada;

    for(i = 0; i < n && scanf("%c", &entrada) != EOF; i++) {
        if(entrada != '\n' && entrada != '\r') {
            str[i]=entrada;
        } else {
            i--;
        }

        //Um caracter \n após o início da leitura termina faz com que a leitura termine
        if(entrada == '\n' && i >= 1) {
            i++;
            break;
        }
    }

    //Finaliza a string
    str[i] = '\0';

    //Limpa a stdin depois de ler o que era necessário
    while(entrada != '\n') {
        scanf("%c", &entrada);
    }

    return i;
}