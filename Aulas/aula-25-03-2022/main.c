#include <stdio.h>
#include "complex.h"

int main(void) {
    Complex a;
    Complex b;
    Complex c;
    Complex * p = NULL;

    //a = complexRead();
    //complexRead2(&b);

    p = complexNew();
    complexSet(&a, 2, -2);
    complexSet(&b, 3, -4);
    complexSet(p, 7.44, -2);

    /*
    c = complexNeg(c);
    complexPrint(c);
    printf("\n");

    complexNeg2(&c);
    complexPrint(c);
    printf("\n");

    c = complexSum(a, b);
    complexPrint(c);
    printf("\n");

    complexSum2(&a, &b, &c);
    complexPrint(c);
    printf("\n");

    c = complexSub(a, b);
    complexPrint(c);
    printf("\n");

    complexSub2(&a, &b, &c);
    complexPrint(c);
    printf("\n");

    c = complexMult(a, b);
    complexPrint(c);
    printf("\n");

    complexMult2(&a, &b, &c);
    complexPrint(c);
    printf("\n");

    c = complexConj(a);
    complexPrint(c);
    printf("\n");

    complexConj2(&c);
    complexPrint(c);
    printf("\n");

    c = complexDiv(a, b);
    complexPrint(c);
    printf("\n");

    complexDiv2(&a, &b, &c);
    complexPrint(c);
    printf("\n");
    */

    printf("%p\n", p);
    complexPrint(*p);
    complexFree(p);
    printf("\n");

    return 0;
}