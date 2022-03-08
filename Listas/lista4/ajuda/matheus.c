#include <stdio.h>
#include <string.h>

int main() {
    int n, m, c, h, l, g, y=0;
    char i[12221];
    char esp[12221];
    
    scanf("%d", &c);
    
    for(h=0; h<c; h++) {
        scanf("%d%d", &n, &m);
        for(l=n; l<=m; l++){
            sprintf(i,"%s%d", i, l);
          
        }
        g=strlen(i);
        esp[g]='\0';
        
        for(g=g-1; g>=0; g--) {
            esp[y]=i[g];
            y++;
        }
        y=0;
        printf("%s%s\n", i, esp);

        i[0]='\0';
        esp[0]='\0';
    }
    
    return 0;
}