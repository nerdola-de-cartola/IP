#include <stdio.h>

int main(void) {
    int i;
    int qtd_numeros;
    int numeros[1000];
    int metade;
    double media;
    int n_maior_media[2];

    scanf("%d", & qtd_numeros);

    if(qtd_numeros <= 5 || qtd_numeros > 1000) {
        printf("QUANTIDADE DE ELEMENTOS INVALIDOS!\n");
        return 0;
    }

    for(i = 0; i < qtd_numeros; i++) {
        scanf("%d", &numeros[i]);
    }

    metade = qtd_numeros/2;

    for(i = 0, media = 0; i < qtd_numeros; i++) {
        media += numeros[i];
    }

    media /= qtd_numeros;

    for(i = 0, n_maior_media[0] = 0; i < metade; i++) {
        if(numeros[i] > media) n_maior_media[0]++;
    }

    if(qtd_numeros%2 == 0) i = metade;
    else i = metade +1;

    for(n_maior_media[1] = 0; i < qtd_numeros; i++) {
        if(numeros[i] > media) n_maior_media[1]++;
    }

    printf("%.2lf ", media);
    printf("%d ", n_maior_media[0]);
    printf("%d ", n_maior_media[1]);
    if(n_maior_media[0] > n_maior_media[1]) printf("PRIMEIRA METADE\n");
    else if(n_maior_media[0] < n_maior_media[1]) printf("SEGUNDA METADE\n");
    else printf("EMPATE\n");

    return 0;
}