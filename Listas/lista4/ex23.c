#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int i, j;
    int tmp;
    bool terminou;
    int v1[999999];
    int v2[999999];
    int tamanho_v1, tamanho_v2;

    scanf("%d", &tamanho_v1);
    scanf("%d", &tamanho_v2);

    //Entradas de V1
    for(i = 0; i < tamanho_v1; i++) {
        scanf("%d", &v1[i]);
    }

    //Entradas de V2
    for(i = 0; i < tamanho_v2; i++) {
        scanf("%d", &v2[i]);
    }

    //Ordena V1
    do {
        terminou = true;
        
        for(i = 0; i < tamanho_v1 - 1; i++) {
            if(v1[i] > v1[i + 1]) {
                tmp = v1[i + 1];
                v1[i + 1] = v1[i];
                v1[i] = tmp;
                
                terminou = false;
            }
        }
    } while(!terminou);
    
    //Ordena V2
    do {
        terminou = true;
        
        for(i = 0; i < tamanho_v2 - 1; i++) {
            if(v2[i] > v2[i + 1]) {
                tmp = v2[i + 1];
                v2[i + 1] = v2[i];
                v2[i] = tmp;
                
                terminou = false;
            }
        }
    } while(!terminou);

    i = 0, j = 0;
    while(i + j < tamanho_v1 + tamanho_v2) {
        
        if(i >= tamanho_v1) {
            printf("%d\n", v2[j]);
            j++;
            continue; 
        }
        
        if(j >= tamanho_v2) {
            printf("%d\n", v1[i]);
            i++;
            continue; 
        }
        
        
        if(v1[i] <= v2[j]) {
            printf("%d\n", v1[i]);
            i++;
        } else {
            printf("%d\n", v2[j]);
            j++;

        }
    }
    
    return 0;
}