#include <stdio.h>
#include <stdbool.h>

/**
* Converte a string str para o valor inteiro correspondente.
* @param str string contendo um número inteiro
* @return o número inteiro correspondente
*/
long int string2int( const char * str );

int main(void) {
    char str[128];
    long int num;

    while(scanf("%s", str) != EOF) {
        num = string2int(str);
        printf("%ld %ld\n", num, num*2);
    } 


    return 0;
}

long int string2int( const char * str ) {
    int i;
    long int num = 0;
    bool negativo = false;

    if(str[0] == '-') negativo = true;

    if(negativo) i = 1;
    else i = 0;

    while(str[i] != '\0') {
        num += str[i] - 48;

        if(str[i+1] != '\0') num *= 10;
        i++;
    }

    if(negativo) num *= -1;

    return num;
}