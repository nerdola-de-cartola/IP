#include <stdio.h>

#define MAX 25

int main(void) {
    int sequencia[MAX] = {0};
    int i = 0, contador_par = 0, contador_impar = 0;
    double media_par = 0, media_impar = 0;

    while (1) {
        scanf("%d", &sequencia[i]);

        if(sequencia[i] == 0) {
            break;
        }

        i++;
    }

    for (i = 0; sequencia[i] != 0; i++) {
        if(sequencia[i] == 0) {
            continue;
        }

        if(sequencia[i] % 2 == 0) { // Número par
            contador_par++;
            media_par += sequencia[i];

        } else { // Número ímpar
            contador_impar++;
            media_impar += sequencia[i];
        }
    }

    if (contador_par != 0) {
        media_par /= contador_par;
    }

    if(contador_impar != 0) {
        media_impar /= contador_impar;
    }
    
    printf("MEDIA PAR: %lf\n", media_par);
    printf("MEDIA IMPAR: %lf\n", media_impar);

    return 0;
}