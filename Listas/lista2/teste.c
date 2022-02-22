#include <stdio.h>

int main(void) {
    int n=0, n2=2, x, y=2, c;

    while(n<=1) {
        scanf("%d", &n);
        x=n;

        if(n>1) {
            printf("%d =", n);

            while(n2>1) {
                n2 = x/y;

                if(x%y==0) {
                    printf(" %d", y);

                    if(x!=y) {
                        printf(" x");
                    }
                } else {
                    y++;
                    n2=x;
                }
                x=n2;
            }
            printf("\n");
        } else {
            printf("Fatoracao nao e possivel para o numero %d!\n", n);
        }
    }
    return 0;
}