#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
    int i, a, b;

    if(argc != 3) {
        printf("Modo de uso: ./seq <numero inteiro> <numero inteiro>\n");
        return 1;
    }

    a = atoi(argv[1]);
    b = atoi(argv[2]);

    if(a < b) {
        for(i = a; i <= b; i++) {
            printf("%d ", i);
        }
    } else {
        for(i = a; i >= b; i--) {
            printf("%d ", i);
        }
    }
    

    printf("\n");

    return 0;
}