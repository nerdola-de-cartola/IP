#include <stdio.h>

int main(){
    int resultado[6], aposta[6];
    int certo=0, quina=0, sena=0, quadra=0, cont, apostas, ind, a;

    for(cont=0; cont<6; cont++){
        scanf("%d", &resultado[cont]);
    }
    scanf("%d", &apostas);
    for(ind=0; ind<apostas; ind++){
        certo=0;
        for(cont=0; cont<6; cont++){
            scanf("%d", &aposta[cont]);
        }
        for(cont=0; cont<6; cont++){
            for(a=0; a<6; a++){
                if(aposta[cont]==resultado[a]){
                    certo++;
                }
            } 
        }
        if (certo==4){
            quadra++;
        }else if(certo==5){
            quina++;
            }else if(certo==6){
                sena++;
                } 
     
        if (sena==0){
            printf("Nao houve acertador para sena\n");
        }else{
            printf("Houve %d ganhador(es) da sena\n", sena);
        }
        if (quina==0){
            printf("Nao houve acertador para quina\n");
        }else{
            printf("Houve %d ganhador(es) da quina\n", quina);
        }
        if (quadra==0){
            printf("Nao houve acertador para quadra\n");
        }else{
            printf("Houve %d ganhador(es) da quadra\n", quadra);
        }
    }
    return 0;
}