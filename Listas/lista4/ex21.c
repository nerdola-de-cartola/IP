#include <stdio.h>

int qtdItensIguais(int loteria[], int apostas[]);

int main(void) {
    int i, j;
    int qtd_apostas, acertos;
    int ganhadores_sena = 0;
    int ganhadores_quina = 0;
    int ganhadores_quadra = 0;
    int numeros_sorteados[6];
    int apostas[50000][6];

    for(i = 0; i < 6; i++) {
        scanf("%d", &numeros_sorteados[i]);
    }

    scanf("%d", &qtd_apostas);

    for(i = 0; i < qtd_apostas; i++) {
        for(j = 0; j < 6; j++) {
            scanf("%d", &apostas[i][j]);
        }
    }

    for(i = 0; i < qtd_apostas; i++) {
        acertos = qtdItensIguais(numeros_sorteados, apostas[i]);
        if (acertos == 4) ganhadores_quadra++;
        if (acertos == 5) ganhadores_quina++;
        if (acertos == 6) ganhadores_sena++;
    }

    if(ganhadores_sena == 0) printf("Nao houve acertador para sena\n");
    else printf("Houve %d acertador(es) da sena\n", ganhadores_sena);
    
    if(ganhadores_quina == 0) printf("Nao houve acertador para quina\n");
    else printf("Houve %d acertador(es) da quina\n", ganhadores_quina);

    if(ganhadores_quadra == 0) printf("Nao houve acertador para quadra\n");
    else printf("Houve %d acertador(es) da quadra\n", ganhadores_quadra);

    return 0;
}

int qtdItensIguais(int loteria[], int apostas[]) {
    int i, j;
    int qtd_itens_iguais = 0;

    for(i = 0; i < 6; i++) {
        for(j = 0; j < 6; j++) {
            if(apostas[j] == loteria[i]) qtd_itens_iguais++;
        }
    }

    return qtd_itens_iguais;
}