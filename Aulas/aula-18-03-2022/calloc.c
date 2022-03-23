#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int * p;
    
    p = calloc(2, sizeof (int));

    printf("%d\n%d\n", p[0], p[1]);

    return 0;
}