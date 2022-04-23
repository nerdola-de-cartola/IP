#include <stdio.h>
#include <stdbool.h>
#include "agenda.h"

#define PRINT 1
#define ADD 2
#define DEL 3
#define SEARCH 4
#define EXIT 0

void menu(void);

int main(int argc, char ** argv) {
    Agenda * ag = NULL;
    Contato * pc;
    Contato c;
    char str[20];
    int mode;

    if(argc != 2) return 1;

    ag = carregarAgenda(argv[1]);
    if(ag == NULL) return 1;

    while(true) {
        menu();
        scanf("%d", &mode);

        switch (mode) {
        case PRINT:
            imprimirAgenda(ag);
            break;
        case ADD:
            c = lerContato(stdin);
            adicionarContato(ag, c);
            break;
        case DEL:
            scanf("%s", str);
            pc = buscarContato(ag, str);
            if(pc == NULL) printf("Contato não encontrado\n");
            else apagarContato(ag, pc);
            break;
        case SEARCH:
            scanf("%s", str);
            pc = buscarContato(ag, str);
            if(pc == NULL) printf("Contato não encontrado\n");
            else imprimirContato(pc);
            break;
        case EXIT:
            salvarAgenda(ag, argv[1]);
            liberarAgenda(ag);
            return 0;
        }
    }

    return 0;
}

void menu(void) {
    printf("=====================\n");
    printf("(%d) Imprimir contatos\n", PRINT);
    printf("(%d) Adicionar contato\n", ADD);
    printf("(%d) Deletar contato\n", DEL);
    printf("(%d) Buscar contato\n", SEARCH);
    printf("(%d) Sair\n", EXIT);
}