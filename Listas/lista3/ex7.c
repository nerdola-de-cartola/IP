#include <stdio.h>

/**
 * Imprime os bits dos n bytes endereçados por end_byte.
 * @param end_byte endereço do primeiro byte a ser impresso
 * @param quantidade de bytes a serem impressos
**/
void print_bytes( const void * end_byte, int n );

int main(void) {
    unsigned char ucn;
    unsigned short int usin;
    unsigned int uin;
    float fn;
    double dn;

    scanf("%lf", &dn);

    ucn = (unsigned char) dn;
    usin = (unsigned short int) dn;
    uin = (unsigned int) dn;
    fn = (float) dn;

    print_bytes(&ucn, sizeof (unsigned char));
    print_bytes(&usin, sizeof (unsigned short int));
    print_bytes(&uin, sizeof (unsigned int));
    print_bytes(&fn, sizeof (float));
    print_bytes(&dn, sizeof (double));
    return 0;
}

void print_bytes( const void * end_byte, int n ) {
    long long int i, j;
    char *p = (char*) end_byte;
    char bit;

    for(i = 0; i < n; i++) {
        for(j = 7; j >= 0; j--) {
            bit = (p[i] >> j) & 1;
            printf("%hhx", bit);
        }

        printf(" ");
    }

    printf("\n");
}