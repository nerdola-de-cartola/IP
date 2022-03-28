#include <stdio.h>
#include <stdlib.h>
#include "complex.h"

void complexPrint(Complex c) {
    if(c.r != 0) printf("%.2lf", c.r);
    if(c.r != 0 && c.i != 0) printf("%+.2lfi", c.i);
    if(c.r == 0 && c.i != 0) printf("%.2lfi", c.i);
    if(c.r == 0 && c.i == 0) printf("0");
}

Complex complexRead(void) {
    Complex a;

    scanf("%lf%lf", &a.r, &a.i);

    return a;
}

void complexRead2(Complex * c) {
    scanf("%lf%lf", &c->r, &c->i);
}

Complex complexNeg(Complex c) {
    Complex a;

    a.r = -c.r;
    a.i = -c.i;

    return a;
}

void complexNeg2(Complex * c) {
    c->r = c->r;
    c->i = c->i;
}

Complex complexSum(Complex a, Complex b) {
    Complex c;

    c.r = a.r + b.r;
    c.i = a.i + b.i;

    return c;
}

void complexSum2(Complex const * a, Complex const * b, Complex * sum) {
    sum->r = a->r + b->r;
    sum->i = a->i + b->i;
}

Complex complexSub(Complex a, Complex b) {
    Complex c;

    c.r = a.r - b.r;
    c.i = a.i - b.i;

    return c;
}

void complexSub2(Complex const * a, Complex const * b, Complex * difference) {
    difference->r = a->r - b->r;
    difference->r = a->r - b->r;   
}

Complex complexMult(Complex a, Complex b) {
    Complex c;

    c.r = (a.r * b.r) - (a.i * b.i);
    c.i = (a.r * b.i) + (a.i * b.r);

    return c;
}

void complexMult2(Complex const * a, Complex const * b, Complex * product) {
    product->r = (a->r * b->r) - (a->i * b->i);
    product->i = (a->r * b->i) + (a->i * b->r);
}

Complex complexDiv(Complex dividend, Complex divider) {
    Complex c;
    double k;

    c = complexMult(dividend, complexConj(divider));

    k = (divider.r * divider.r) + (divider.i * divider.i);

    c.r /= k;
    c.i /= k;

    return c;
}

void complexDiv2(Complex const * dividend, Complex const * divider, Complex * quotient) {
    Complex tmp;
    double k;

    tmp = complexConj(*divider);
    
    complexMult2(dividend, &tmp, quotient); 
    
    k = (divider->r * divider->r) + (divider->i * divider->i);
    
    quotient->r /= k;
    quotient->i /= k;
}

Complex complexConj(Complex a) {
    a.i = -a.i;
    return a;
}

Complex complexConj2(Complex * a) {
    a->i = -a->i;
}

Complex * complexNew(void) {
    return (Complex *) malloc(sizeof(Complex));
}

inline void complexFree(Complex * p) {
    free(p);
}

void complexSet(Complex * c, double r, double i) {
    c->r = r;
    c->i = i;
}
