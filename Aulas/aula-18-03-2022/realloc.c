#include <stdio.h>
#include <stdlib.h>

#define MAX 500

int main(void) {
    int * p = NULL;
    int * np = NULL;
    int n = 5;
    
    p = calloc(n, sizeof (int));

    p[0] = 2;
    p[1] = 5;
    p[2] = 0;
    p[3] = 8;
    p[4] = 7;

    printf("%d %d %d %d %d\n", p[0], p[1], p[2], p[3], p[4]);

    np = realloc(p, (n+1) * sizeof (int));
    if(np == NULL) {
        printf("Deu ruim!!!\n");
        return 1;
    }

    p = np;
    p[5] = 10;
    printf("%d %d %d %d %d %d\n", p[0], p[1], p[2], p[3], p[4], p[5]);

    np = realloc(p, (n-1) * sizeof (int));
    if(np == NULL) {
        printf("Deu ruim!!!\n");
        return 1;
    }

    p = np;
    printf("%d %d %d %d %d\n", p[0], p[1], p[2], p[3], p[4]);

    return 0;
}