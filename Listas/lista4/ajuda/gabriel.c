#include <stdio.h>

void espelho(int a, int b){
    int i;
    char string[1000];
    for(i = a; i <= b; i++){
        printf("%d", i);
    }
    for(i = b; i >= a; i--){
        printf("%d", i);
    }
    printf("\n");
}

int main(){
    int entrada, A, B, i;

    scanf("%d", &entrada);

    for(i = 0; i < entrada; i++){
        scanf("%d %d", &A, &B);

        espelho(A, B);
    }

    return 0;
}