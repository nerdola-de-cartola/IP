struct complex {
    double r;
    double i;
};

typedef struct complex Complex;

void complexPrint(Complex c);

Complex complexRead(void);

void complexRead2(Complex * c);

Complex complexNeg(Complex c);

void complexNeg2(Complex * c);

Complex complexSum(Complex a, Complex b);

void complexSum2(Complex const * a, Complex const * b, Complex * sum);

Complex complexSub(Complex a, Complex b);

void complexSub2(Complex const * a, Complex const * b, Complex * difference);

Complex complexMult(Complex a, Complex b);

void complexMult2(Complex const * a, Complex const * b, Complex * product);

Complex complexDiv(Complex dividend, Complex divider);

void complexDiv2(Complex const * dividend, Complex const * divider, Complex * quotient);

Complex complexConj(Complex a);

void complexConj2(Complex * a);

Complex * complexNew(void);

void complexFree(Complex * p);

void complexSet(Complex * c, double r, double i);
