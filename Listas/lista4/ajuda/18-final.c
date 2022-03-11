#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define N 100

int main(void){
    char sentenca[N];
    int tamanho, cont, i;

    while(scanf("%[^\n]%*c", sentenca) != EOF){
        tamanho = strlen(sentenca);
        
        for(i= 0, cont=0; i<tamanho;i++){
            if(isalpha(sentenca[i])) {
                if(cont%2 == 0) {
                    sentenca[i] = toupper(sentenca[i]);
                } else {
                    sentenca[i] = tolower(sentenca[i]);
                }
                cont++;
            }
        }

        printf("%s\n", sentenca);
    }

    return 0;
}
