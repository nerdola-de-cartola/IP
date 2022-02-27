#include <stdio.h>

#define MAXIMO_DE_TESTES 1000

int contaLeds(char numero[]);

int main(void) {
    int i;
    int qtd_testes;
    char numeros_para_escrever[MAXIMO_DE_TESTES][100];

    scanf("%d", &qtd_testes);

    if(qtd_testes > MAXIMO_DE_TESTES) {
        return 1;
    }

    for(i = 0; i < qtd_testes; i++) {
        scanf("%s", &numeros_para_escrever[i][0]);
    }
    
    for(i = 0; i < qtd_testes; i++) {
        printf("%d leds\n", contaLeds(numeros_para_escrever[i]));
    }

    return 0;
}

int contaLeds(char numero[]) {
    int i = 0;
    int leds = 0;
    char digito = numero[i];

    while(digito != '\0') {
        switch (digito) {
            case '0':
                leds += 6;
                break;
            
            case '1':
                leds += 2;
                break;

            case '2':
                leds += 5;
                break;

            case '3':
                leds += 5;
                break;

            case '4':
                leds += 4;
                break;

            case '5':
                leds += 5;
                break;

            case '6':
                leds += 6;
                break;

            case '7':
                leds += 3;
                break;

            case '8':
                leds += 7;
                break;

            case '9':
                leds += 6;
                break;
            
        }

        i++;
        digito = numero[i];
    }

    return leds;
}