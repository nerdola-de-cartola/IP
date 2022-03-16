#include <stdio.h>

void over(int n);

int main(void) {
    over(0);
    return 0;
}

void over(int n) {
    int v[100];
    printf("Nova função %d\n", n);
    over(n + 1);
}