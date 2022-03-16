#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int * p_int;

    p_int = malloc(sizeof (int));
    *p_int = 15;

    printf("%p\n", p_int);
    printf("%p\n", &p_int);
    printf("%d\n", *p_int);
    
    return 0;
}