#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct casa {
    int moradores;
    double consumo;
    double consumo_por_pessoa;
};

typedef struct casa Casa;

int main(void) {
    Casa * arr;
    Casa tmp;
    int i, j, menor;
    int qtd_casas, cidade;
    int total_pessoas, total_consumo;
    

    cidade = 1;
    while(true) {
        scanf("%d", &qtd_casas);
        if(qtd_casas == 0) return 0;

        arr = calloc(qtd_casas, sizeof(Casa));
        total_pessoas = 0;
        total_consumo = 0;

        for(i = 0; i < qtd_casas; i++) {
            scanf("%d%lf", &arr[i].moradores, &arr[i].consumo);
            arr[i].consumo_por_pessoa = arr[i].consumo / arr[i].moradores;
            total_pessoas += arr[i].moradores;
            total_consumo += arr[i].consumo;
        }

        for(i = 0; i < qtd_casas - 1; i++) {
            menor = i;

            for(j = i + 1; j < qtd_casas; j++) {
                if(arr[j].consumo_por_pessoa < arr[menor].consumo_por_pessoa) menor = j;
            }

            if(menor != i) {
                tmp = arr[i];
                arr[i] = arr[menor];
                arr[menor] = tmp;
            }
        }

        printf("Cidade# %d\n", cidade);
        for(i = 0; i < qtd_casas; i++) {
            printf("%d-%d ", arr[i].moradores, (int) arr[i].consumo_por_pessoa);
        }

        printf("\n");
        printf("Consumo medio: %.2lf m3.\n\n", (double) total_consumo / (double) total_pessoas);

        free(arr);

        cidade++;
    }
}