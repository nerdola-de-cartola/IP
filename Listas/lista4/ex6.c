#include <stdio.h>
#include <string.h>

int numeroCorrespondente(char str[]);

int main(void) {
    int i;
    int qtd_entradas;
    char entrada[5];

    scanf("%d", &qtd_entradas);

    for(i = 0; i < qtd_entradas; i++) {
        scanf("%s", entrada);
        printf("%d\n", numeroCorrespondente(entrada));
    }
    
    return 0;
}

int numeroCorrespondente(char str[]) {
    if(strlen(str) == 5) return 3;

    if(str[0] == 't' && str[1] == 'w') return 2;
    if(str[0] == 't' && str[2] == 'o') return 2;
    if(str[1] == 'w' && str[2] == 'o') return 2;

    if(str[0] == 'o' && str[1] == 'n') return 1;
    if(str[0] == 'o' && str[2] == 'e') return 1;
    if(str[1] == 'n' && str[2] == 'e') return 1;

    return 0;
}