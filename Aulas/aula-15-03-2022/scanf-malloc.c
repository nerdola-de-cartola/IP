#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, *p, i, j;

    scanf("%d", &n);

    p = (int*) malloc(n*sizeof(int));

    for(i = 0; i < n; i++, j++) p[i] = j;

    for(i = 0; i < n; i++) {
        printf("p[%d]: %d\n", i, p[i]);
        printf("(%p)\n", p+i);
    }

    free(p);
    
    return 0;
}