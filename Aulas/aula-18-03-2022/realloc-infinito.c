#include <stdio.h>
#include <stdlib.h>

#define MAX 500

int main(void) {
    int * p = NULL;
    int * np = NULL;
    long int n = 5;
    
    p = calloc(n, sizeof (int));

    for(n = 5; 1; n = n*n) {
        np = realloc(p, n*sizeof(int));
        if(np == NULL) {
            printf("Deu ruim!!!\n");
            return 1;
        }

        p = np;
        printf("%ld\n", n);
    }

    return 0;
}