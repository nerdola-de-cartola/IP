#include <stdio.h>
#include <stdbool.h>

int somaAnoes(int anoes[]);
void combinaAnoes(int anoes[], int combinacoes[36][7]);

int main(void) {
    int teste, i, j;
    int tmp;
    int qtd_testes;
    int anoes[9];
    int combinacoes_anoes[36][7];
    bool terminou;

    scanf("%d", &qtd_testes);

    for(teste = 0; teste < qtd_testes; teste++) {
        for(i = 0; i < 9; i++) {
            scanf("%d", &anoes[i]);
        }

        combinaAnoes(anoes, combinacoes_anoes);

        for(i = 0; i < 36; i++) {
            if(somaAnoes(combinacoes_anoes[i]) == 100) {

                //Ordena os anões
                do {
                    terminou = true;
                    
                    for(j = 0; j < 7 - 1; j++) {
                        if(combinacoes_anoes[i][j] > combinacoes_anoes[i][j + 1]) {
                            tmp = combinacoes_anoes[i][j + 1];
                            combinacoes_anoes[i][j + 1] = combinacoes_anoes[i][j];
                            combinacoes_anoes[i][j] = tmp;
                            
                            terminou = false;
                        }
                    }
                } while(!terminou);

                //Imprime os anões
                for(j = 0; j < 7; j++) {
                    printf("%d\n", combinacoes_anoes[i][j]);
                }
            }
        }
    }
    
    return 0;
}

int somaAnoes(int anoes[]) {
    int i;
    int soma = 0;

    for(i = 0; i < 7; i++) {
        soma += anoes[i];
    }

    return soma;
}

void combinaAnoes(int anoes[], int combinacoes[36][7]) {
    int combinacao, i, j;
    int ultima_posicao_inativa;
    int qtd_anoes_ativos;
    bool anoes_ativos[9] = {false, false, false, false, false, false, false, false, false};

    combinacao = 0;
    while(combinacao < 36) {
        //Encontra a última posicao inativa
        for(i = 0; i < 9; i++) {
            if(!anoes_ativos[i]) ultima_posicao_inativa = i;
        }

        //Ativa a última posicao inativa
        anoes_ativos[ultima_posicao_inativa] = true;

        //Ativa as posições posteriores
        for(i = ultima_posicao_inativa + 1; i < 9; i++) {
            anoes_ativos[i] = false;
        }

        //Conta a quantidade de anões ativos
        for(i = 0, qtd_anoes_ativos = 0; i < 9; i++) {
            if(anoes_ativos[i]) qtd_anoes_ativos++;
        }

        if(qtd_anoes_ativos == 7) {
            for(i = 0, j = 0; i < 9; i++) {
                if(anoes_ativos[i]) {
                    combinacoes[combinacao][j] = anoes[i];
                    j++;
                }
            }

            combinacao++;
        }
    }
}