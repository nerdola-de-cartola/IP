#include <stdio.h>
#include <math.h>

int main(void) {
    int limite, i;
    scanf("%d", &limite);

    for(i = 2; i <= limite; i+=2) {
        printf("%d^2 = %d\n", i, (int) pow((double) i, 2));
    }

    return 0;   
}