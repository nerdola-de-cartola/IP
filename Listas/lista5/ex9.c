#include <stdio.h>
#include <stdlib.h>

struct maiorMenor {
    int ** matriz;
    int altura;
    int largura;
    int maior;
    int menor;
    double maior_frequencia;
    double menor_frequencia;
};
    
void maiorMenor(struct maiorMenor * a);

int main(void) {
    int i, j;
    struct maiorMenor mat;
    
    scanf("%d%d", &mat.altura, &mat.largura);
    
    mat.matriz = calloc(mat.altura, sizeof (int *));
    
    for(i = 0; i < mat.altura; i++) {
        mat.matriz[i] = calloc(mat.largura, sizeof (int));

        for(j = 0; j < mat.largura; j++) {
            scanf("%d", &mat.matriz[i][j]);
        }
    }

    maiorMenor(&mat);

    printf("%d %.2lf%c\n", mat.menor, mat.menor_frequencia*100, '%');
    printf("%d %.2lf%c\n", mat.maior, mat.maior_frequencia*100, '%');
    
    for(i = 0; i < mat.altura; i++) {
        free(mat.matriz[i]);
    }
    
    free(mat.matriz);
    
    return 0;
}

void maiorMenor(struct maiorMenor * a) {
    int i, j;
    int qtd_elementos = a->largura * a->altura;

    a->menor = 9999999;
    a->maior = -9999999;
    a->maior_frequencia = 0;
    a->menor_frequencia = 0;

    for(i = 0; i < a->altura; i++) {
        for(j = 0; j < a->largura; j++) {
            if(a->matriz[i][j] > a->maior) a->maior = a->matriz[i][j];
            if(a->matriz[i][j] < a->menor) a->menor = a->matriz[i][j];
        }
    }    

    for(i = 0; i < a->altura; i++) {
        for(j = 0; j < a->largura; j++) {
            if(a->matriz[i][j] == a->maior) a->maior_frequencia++;
            if(a->matriz[i][j] == a->menor) a->menor_frequencia++;
        }
    }

    a->maior_frequencia /= qtd_elementos;
    a->menor_frequencia /= qtd_elementos;
    
    return;
}