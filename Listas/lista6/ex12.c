#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct tRacional {
    long int num;
    long int den;
} RNum;

int * divisores(int a, int * qtd);
/**
* Calcula o MDC de x e y
* @param x
* @param y
* @return
*/
int MDC(int x, int y);

/**
* Recebe dois inteiros a e b e retorna o racional
* @param a numerador
* @param b denominador
* @return
*/
RNum racional(int a, int b);

/**
* Recebe um racional e retorna o seu negativo (-r).
* @param r numero racional
* @return
*/
RNum negativo(RNum r);

/**
* Recebe dois racionais e retorna a adição de ambos (r1 + r2).
* @param r1 fator esquerdo da soma
* @param r2 fator direito da soma
* @return
*/
RNum soma(RNum r1, RNum r2);

/**
* Recebe dois racionais e retorna o produto de ambos (r1 * r2).
* @param r1 primeiro fator do produto
* @param r2 segundo fator do produto
* @return
*/
RNum mult(RNum r1, RNum r2);

/**
* Recebe dois racionais e retorna o quociente de ambos (r1/r2).
* @param r1 numerador
* @param r2 denominador
* @return
*/
RNum divR(RNum r1, RNum r2);

/**
* Recebe um racional e reduz a fração ao máximo.
* @param r o número racional a ser reduzido
*/
void reduzFracao(RNum * r);

/**
* Imprime no terminal um racional.
* @param r o número racional a ser impresso
*/
void imprime(RNum r);

int main(void) {

    while(true) {
        RNum a, b, c;
        char op;

        if(scanf("%ld%ld%*c", &a.num, &a.den) == EOF) break;
        if(scanf("%c%*c", &op) == EOF) break;
        if(scanf("%ld%ld%*c", &b.num, &b.den) == EOF) break;

        switch (op) {
        case '+':
            c = soma(a, b);
            break;
        case '-':
            c = soma(a, negativo(b));
            break;
        case '*':
            c = mult(a, b);
            break;
        case '/':
            c = divR(a, b);
            break;        
        default:
            return 1;
            break;
        }

        reduzFracao(&c);
        imprime(c);
    }

    return 0;
}

int * divisores(int a, int * qtd) {
    int * tmp;
    int * vet;
    int i;
    
    vet = calloc(abs(a), sizeof(int));
    *qtd = 0;

    for(i = 1; i <= abs(a); i++) {
        if(a % i == 0) {
            vet[*qtd] = i;
            (*qtd)++;
        };
    }

    tmp = realloc(vet, *qtd * sizeof(int));
    if(tmp == NULL) exit(1);
    vet = tmp;
    return vet;
}

int MDC(int x, int y) {
    int * div_x = NULL;
    int * div_y = NULL;
    int * div_mut = NULL;
    int i, j, k, maior;
    int qtd_x, qtd_y, qtd_mut;

    div_x  = divisores(x, &qtd_x);
    div_y = divisores(y, &qtd_y);

    if(qtd_x >= qtd_y) qtd_mut = qtd_x;
    else qtd_mut = qtd_y;

    div_mut = calloc(qtd_mut, sizeof(int));

    k = 0;
    qtd_mut = 0;
    for(i = 0; i < qtd_x; i++) {
        for(j = 0; j < qtd_y; j++) {
            if(div_x[i] == div_y[j]) {
                div_mut[k] = div_x[i];
                qtd_mut++;
                break;
            }
        }
    }

    maior = div_mut[0];
    for(i = 1; i < qtd_mut; i++) {
        if(div_mut[i] > maior) maior = div_mut[i];
    }

    free(div_mut);
    free(div_x);
    free(div_y);

    //printf("%d\n", maior);
    return maior;
}

RNum racional(int a, int b) {
    RNum r;

    r.num = a;
    r.den = b;

    return r;
}

RNum negativo(RNum r) {
    RNum rf;

    rf.num = -r.num;
    rf.den = r.den;

    return rf;
}

RNum soma(RNum r1, RNum r2) {
    RNum r;
    int n1, n2;

    n1 = r1.num * r2.den;
    n2 = r2.num * r1.den;

    r.num = n1 + n2;
    r.den = r1.den * r2.den;

    return r;
}

RNum mult(RNum r1, RNum r2) {
    RNum r;

    r.num = r1.num * r2.num;
    r.den = r1.den * r2.den;

    return r;
}

RNum divR(RNum r1, RNum r2) {
    RNum r;

    r.num = r1.num * r2.den;
    r.den = r1.den * r2.num;

    return r;
}

void reduzFracao(RNum * r) {
    int div;

    div = MDC(r->num, r->den);

    r->num /= div;
    r->den /= div;
}

void imprime(RNum r) {
    printf("%ld %ld\n", r.num, r.den);
}