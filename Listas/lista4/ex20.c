#include <stdio.h>

int main(void) {
    int i, j;
    int posicao_maior;
    int qtd_testes = 0;
    int total_de_caracteres = 1;
    int caracteres_do_premio = 1;
    int limite_inferior;
    int limite_superior;
    char entrada, maior;
    char str[10000];
    char str_apagada[10000];

    while(total_de_caracteres != 0 && caracteres_do_premio != 0) {
        scanf("%d %d", &total_de_caracteres, &caracteres_do_premio);
        if(total_de_caracteres == 0 && caracteres_do_premio == 0) break;        

        for(i = 0; i < total_de_caracteres;) {
            scanf("%c", &entrada);

            if(entrada >= '0' && entrada <= '9') {
                str[i] = entrada;
                i++;
            }
        }

        limite_inferior = 0;
        limite_superior = total_de_caracteres - caracteres_do_premio;

        for(i = 0; i < caracteres_do_premio; i++) {

            //Coloca o melhor caracter possível
            for(j = limite_inferior, maior = 0; j <= limite_superior; j++) {
                if(str[j] > maior) {
                    maior = str[j];
                    posicao_maior = j;
                }
            }

            str_apagada[i] = maior;
            limite_inferior = posicao_maior + 1;
            limite_superior++;
        }

        str_apagada[i] = '\0';
        printf("%s\n", str_apagada);

        qtd_testes++;
    }

    return 0;
}