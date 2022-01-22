#include <stdio.h>

int main(void) {
    double a, b, c, d, tmp;

    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

    if (a > b) {
        tmp = a;
        a = b;
        b = tmp;

    } if (b > c) {
        tmp = b;
        b = c;
        c = tmp;

    } if (c > d) {
        tmp = c;
        c = d;
        d = tmp;

    } if (a > b) {
        tmp = a;
        a = b;
        b = tmp;

    } if (b > c) {
        tmp = b;
        b = c;
        c = tmp;

    } if (a > b) {
        tmp = a;
        a = b;
        b = tmp;
    }

    printf("%.2lf, %.2lf, %.2lf, %.2lf\n", a, b, c, d);
    return 0;
}