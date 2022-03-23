#include <stdio.h>
#include <string.h>

struct FelizNatal {
    char pais[128];
    char mensagem[128];
};

#define QTD_PAISES 24

void mensagensNatal(struct FelizNatal * v);

int main(void) {
    struct FelizNatal v[QTD_PAISES];
    mensagensNatal(v);
    char str[128];
    int i;

    while(scanf("%s", str) != EOF) {
        for(i = 0; i < QTD_PAISES; i++) {
            if(strcasecmp(str, v[i].pais) == 0) {
                printf("%s\n", v[i].mensagem);
                break;
            }
        }

        if(i == QTD_PAISES) printf("-- NOT FOUND --\n");
    }
    
    return 0;
}

void mensagensNatal(struct FelizNatal * v) {
    strcpy(v[0].pais, "brasil");
    strcpy(v[0].mensagem, "Feliz Natal!");

    strcpy(v[1].pais, "alemanha");
    strcpy(v[1].mensagem, "Frohliche Weihnachten!");

    strcpy(v[2].pais, "austria");
    strcpy(v[2].mensagem, "Frohe Weihnacht!");

    strcpy(v[3].pais, "coreia");
    strcpy(v[3].mensagem, "Chuk Sung Tan!");

    strcpy(v[4].pais, "espanha");
    strcpy(v[4].mensagem, "Feliz Navidad!");

    strcpy(v[5].pais, "grecia");
    strcpy(v[5].mensagem, "Kala Christougena!");

    strcpy(v[6].pais, "estados-unidos");
    strcpy(v[6].mensagem, "Merry Christmas!");

    strcpy(v[7].pais, "inglaterra");
    strcpy(v[7].mensagem, "Merry Christmas!");

    strcpy(v[8].pais, "australia");
    strcpy(v[8].mensagem, "Merry Christmas!");

    strcpy(v[9].pais, "portugal");
    strcpy(v[9].mensagem, "Feliz Natal!");

    strcpy(v[10].pais, "suecia");
    strcpy(v[10].mensagem, "God Jul!");

    strcpy(v[11].pais, "turquia");
    strcpy(v[11].mensagem, "Mutlu Noeller");

    strcpy(v[12].pais, "argentina");
    strcpy(v[12].mensagem, "Feliz Navidad!");

    strcpy(v[13].pais, "chile");
    strcpy(v[13].mensagem, "Feliz Navidad!");

    strcpy(v[14].pais, "mexico");
    strcpy(v[14].mensagem, "Feliz Navidad!");
    
    strcpy(v[15].pais, "antardida");
    strcpy(v[15].mensagem, "Merry Christmas!");

    strcpy(v[16].pais, "canada");
    strcpy(v[16].mensagem, "Merry Christmas!");

    strcpy(v[17].pais, "irlanda");
    strcpy(v[17].mensagem, "Nollaig Shona Dhuit!");

    strcpy(v[18].pais, "belgica");
    strcpy(v[18].mensagem, "Zalig Kerstfeest!");

    strcpy(v[19].pais, "italia");
    strcpy(v[19].mensagem, "Buon Natale!");

    strcpy(v[20].pais, "libia");
    strcpy(v[20].mensagem, "Buon Natale!");

    strcpy(v[21].pais, "siria");
    strcpy(v[21].mensagem, "Milad Mubarak!");

    strcpy(v[22].pais, "marrocos");
    strcpy(v[22].mensagem, "Milad Mubarak!");

    strcpy(v[23].pais, "japao");
    strcpy(v[23].mensagem, "Merii Kurisumasu!");

    return;
}