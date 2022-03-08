#include <stdio.h>

int le_String(char *str, int n);
void print_codes( char * str );

#define N 128 + 1

int main(void){
    char str[N] = "Teste 123";
    char s[N];
    char c;
    int i;

    scanf("%c", &c);
    le_String( str, 3);
    print_codes( str );
    printf("caracter:%c, str:%s\n", c, str);


    return 0;
}

int le_String(char *str, int n) {
    int i = 0;
    char x;

    while( EOF != scanf("%c", &x) && (x != '\n' || x != '\r') && i < n){
        *str = x;
        str++;
    }
    *str = '\0';
    return i;
    if(EOF == scanf("%c", &x) ) return; // End of file
}

void print_codes( char *str ){
    if(*str=='\0') return;
    printf("%d", (int)(*str) );
    str++;
    while(*str!='\0'){
        printf(",%d", (int)(*str) );
        str++;

    }
    printf("\n");
}