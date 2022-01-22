#include <stdio.h>

int main(void) {
    double n1, n2, n3, tmp;
    scanf("%lf%lf%lf", &n1, &n2, &n3);

    if (n1 > n2) {
        tmp = n1;
        n1 = n2;
        n2 = tmp;
    } if (n2 > n3) {
        tmp = n2;
        n2 = n3;
        n3 = tmp;
    } if (n1 > n2) {
        tmp = n1;
        n1 = n2;
        n2 = tmp;
    }

    printf("%.2lf, %.2lf, %.2lf\n", n1, n2, n3);
    return 0;
}