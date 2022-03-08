#include <stdio.h>
#include <string.h>

int main(void) {
    int i, j, k;
    int inicio, fim;
    int qtd_entradas;
    char str[12221];

    scanf("%d", &qtd_entradas);

    for(i = 0; i < qtd_entradas; i++) {
        scanf("%d %d", &inicio, &fim);

        for(j = inicio, k = 0; j <= fim; j++, k = strlen(str)) {
            sprintf(&str[k], "%d", j);
        }

        printf("%s", str);

        for(j = strlen(str) - 1; j >= 0; j--){
            printf("%c", str[j]);
        }

        printf("\n");
    }

    return 0;
}