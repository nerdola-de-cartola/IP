#include <stdio.h>
#include <math.h>

int fatorial(int num);

int main(void) {
    int qtd_times;
    int i = 1, j = i, k = j + 1;

    scanf("%d", &qtd_times);

    if(qtd_times < 2) {
        printf("Campeonato invalido!\n");
        return 0;
    }

    while(i <= fatorial(qtd_times) / (2 * fatorial(qtd_times - 2))) {
        printf("Final %d: Time%d X Time%d\n", i, j, k);

        if(k == qtd_times) {
            j++;
            k = j + 1;

        } else {
            k++;
        }

        i++;
    }

    return 0;
}

int fatorial(int num) {
    if(num < 0) {
        return -1;
    }

    int fat = 1;

    while (num > 0) {
        fat *= num;
        num--;
    }

    return fat;
}