#include <stdio.h>

int main(void) {
    FILE * arq = NULL;
    int i;
    double d;
    char str[60];

    arq = fopen("entrada2.txt", "r");
    if(arq == NULL) return 1;

    fscanf(arq, "%d%lf%[^\n]", &i, &d, str);

    printf("Inteiro: %d\n", i);
    printf("Real: %lf\n", d);    
    printf("String: %s\n", str);

    return 0;
}