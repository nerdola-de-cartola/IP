#include <stdio.h>
#include <string.h>


int le_string(char *str, int n) {
    int i = 0;
    int x=0;
    char ch;
    for(x=0; x<n && scanf("%c", &ch)!=EOF; x++){
               
        if(ch !='\n'){
            if(ch != '\r') {
                str[x]=ch;
            }    
        } else{
            x--;
        }
        
        if(ch=='\n' && x>=1){
            x++;
            break;
        }
    }

    str[x] = '\0';
    while(ch!='\n') {
        scanf("%c", &ch);
        if(ch=='\n'){
            break;
        }

    }
    return x;
}

void print_codes( char * str ) {
    int n, c;
    n=strlen(str);
    for(c=0; c<n; c++) {
        if(c==0) {
            printf("%d", str[c]);
        }
        else {
            printf(",%d", str[c]);
        } 
    }
    printf("\n");
}
#define N 128+1

int main() {
    char str[N], s[N];
    char c;
    int i;

    scanf("%c", &c);
    le_string(str, 3);
    print_codes(str);
    printf("caracter:%c, str:%s\n", c, str);

    scanf("%c", &c);
    le_string(str, 5);
    print_codes(str);
    printf("caracter:%c, str:%s\n", c, str);

    scanf("%c", &c);
    le_string(str, 5);
    print_codes(str);
    printf("caracter:%c, str:%s\n", c, str);

    scanf("%d", &i);
    le_string(str, 3);
    print_codes(str);
    printf("inteiro:%d, str:%s\n", i, str);

    //printf("Digite inteiros separados por espaco: ");
    scanf("%d", &i);
    //printf("inteiro:%d\n", i);
    //printf("Le string (15):\n");
    le_string(str, 15);
    print_codes(str);
    printf("inteiro:%d, str:%s\n", i, str);

    //printf("Digite uma string sem espacos: ");
    scanf("%s", s);
    //printf("string:%s\n", str);
    //printf("Le string (10):\n");
    le_string(str, 100);
    print_codes(str);
    printf("string:%s, str:%s\n", s, str);

    //printf("Digite uma string com espacos: ");
    scanf("%s", s);
    //printf("string:%s\n", str);
    //printf("Le string (20):\n");
    le_string(str, 100);
    print_codes(str);
    printf("string:%s, str:%s\n", s, str);

    return 0;
}