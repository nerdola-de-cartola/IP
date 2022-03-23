#include <stdio.h>
#include <stdlib.h>

void * meuCalloc(size_t num, size_t tamanho);

int main(void) {
    int *p;

    p = (int *) meuCalloc(5, sizeof(int));

    printf("%d\n%d\n", p[0], p[1]);

    return 0;
}

void * meuCalloc(size_t num, size_t tamanho) {
    void * p = malloc(num*tamanho);
    int i;

    for(i = 0; i < num*tamanho; i++) {
        ((char *)p)[i] = 0;
    }

    return p;
}