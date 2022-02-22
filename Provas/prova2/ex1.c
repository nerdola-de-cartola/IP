#include <stdio.h>

int main(void) {
    int n, i, j;
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        for(j = i; j < n; j++) {
            if(i*j == 1 || (i*j) % n == 1) {
                printf("(%d,%d)\n", i, j);
            }
        }
    }
    
    return 0;
}