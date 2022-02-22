#include <stdio.h>

int main(){

    int cont = 0, n, segue = 0;
    int comp1 = 1, comp2 = 0;
    int sequen = 1;

    scanf("%d", &n);

    //segue == num_atual
    //comp2 == num_anterior
    //comp1 == sequencia_atual
    //sequen == maior_sequencia

    for(cont = 0; cont<n; cont++){
        scanf("%d", &segue);

        if(cont != 0) { // Coloquei esse if
            if(segue > comp2){ // Apaguei uma linha
                comp1++;
            } else { // Troquei if por else
                comp1 = 1;
            }

            if(sequen < comp1){
                sequen = comp1;
            }
        }
          
        comp2 = segue; // Movi essa linha para o final do loop
    }

    printf("O comprimento do segmento crescente maximo e: %d\n", sequen); // Coloca \n e troca comp1 por sequen
    
    return 0;
}