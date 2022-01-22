# include <stdio.h>

int imprimeOrdenado(int ordem, float a, float b, float c);

int main(void) {
    int i;
    float a, b, c;

    scanf("%i %f %f %f", &i, &a, &b, &c);

    imprimeOrdenado(i, a, b, c);

    return 0;
}

int imprimeOrdenado(int ordem, float a, float b, float c) {
    float tmp;
    
    if (ordem == 1) { //Ordem crescente
        if (a > b) {
            tmp = a;
            a = b;
            b = tmp;

        } if (b > c) {
            tmp = b;
            b = c;
            c = tmp;

        } if (a > b) {
            tmp = a;
            a = b;
            b = tmp;
        }

    } else if (ordem == 2) { //Ordem decrescente
        if (a < b) {
                tmp = a;
                a = b;
                b = tmp;

            } if (b < c) {
                tmp = b;
                b = c;
                c = tmp;

            } if (a < b) {
                tmp = a;
                a = b;
                b = tmp;
            }

    } else { //Maior no meio e menor a direita
        if (a > b) {
            tmp = a;
            a = b;
            b = tmp;

        } if (b < c) {
            tmp = b;
            b = c;
            c = tmp;
            
        } if (c > a) {
            tmp = a;
            a = c;
            c = tmp;
        }
    }

    printf("%.2f %.2f %.2f\n", a, b, c);
}