#include <stdio.h>
#include <stdbool.h>

#define SALARIO_MINIMO 937.0

int main(void) {
    double renda_bruta, renda_per_capita;
    int qtd_pessoas, escola, etnia;
    bool cotista = false;
    unsigned short int tipo_cota;
    scanf("%lf %d %d %d", &renda_bruta, &qtd_pessoas, &escola, &etnia);

    renda_per_capita = renda_bruta / qtd_pessoas;

    //Estudou em escola pública
    if (escola == 2) {
        cotista = true;
        tipo_cota = 3;

        //Renda familiar menor ou igual a 1,5 salários mínimos
        if (renda_per_capita <= SALARIO_MINIMO * 1.5) {
            tipo_cota = 1;

            //Preto, pardo ou indígena 
            if (etnia < 4) {
                tipo_cota = 2;
            }

        //Preto, pardo ou indígena
        } else if (etnia < 4) {
                tipo_cota = 4;
        }
    }

    if (cotista == false) {
        printf("ALUNO NAO COTISTA\n");

    } else {
        printf("ALUNO COTISTA (L%hd)\n", tipo_cota);
    }

    return 0;
}