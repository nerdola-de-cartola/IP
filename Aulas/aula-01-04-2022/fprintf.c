#include <stdio.h>

int main(void) {
    FILE * arq;
    int id1, id2;
    double m;

    scanf("%d%d", &id1, &id2);
    m = (id1 + id2) / 2;

    arq = fopen("idade.txt", "w");
    if(arq == NULL) return 1;

    fprintf(arq, "Idade 1: %d\nIdade2: %d\nMedia: %lf\n", id1, id2, m);

    fclose(arq);

    return 0;
}