#include <stdio.h>

/**
* Converte a string str para o valor real correspondente.
* @param str string contendo um número real
* @return o número inteiro correspondente
*/
double string2double( const char * str );

#define N_MAX 128

int main(void) {
    char str[N_MAX];
    double num;

    while(scanf("%s", str) != EOF) {
        num = string2double(str);
        printf("%.3lf %.3lf\n", num, num*2);
    }
    return 0;
}

double string2double( const char * str ) {
    double num = 0;
    int i = 0, j = 10;

    if(str[0] == '-') i = 1;

    while(str[i] != '\0' && str[i] != '.') {
        num += str[i] - '0';
        num *= 10;
        i++;
    }

    num /= 10;

    if(str[i] == '.') {
        while(str[i] != '\0') {
            i++;
            if(str[i] == '\0') break;
            num += (double) (str[i] - '0') / (double) j;
            j *= 10;
        }
    }
    
    if(str[0] == '-') num *= -1;

    return num;
}