#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int i, j;
    char sentenca[50];
    bool letra_minuscula;
    bool par;

    while(scanf("%[^\n]s", sentenca) != EOF) {
        i = 0;
        j = 0;

        while(sentenca[i] != '\0') {
            if((sentenca[i] >= 'A' && sentenca[i] <= 'Z') || (sentenca[i] >= 'a' && sentenca[i] <= 'z')) {
                if(sentenca[i] >= 'A' && sentenca[i] <= 'Z') letra_minuscula = false;
                else if(sentenca[i] >= 'a' && sentenca[i] <= 'z')letra_minuscula = true;

                if(j % 2 == 0) par = true;
                else par = false;

                if(par && letra_minuscula) {
                    sentenca[i] -= 32; //Vira maiúscula
                } else if(!par && !letra_minuscula) {
                    sentenca[i] += 32; //Vira minúscula
                }

                j++;
            }

            i++;
        }

        printf("%s\n", sentenca);
        scanf("%*c");
    }

    return 0;
}