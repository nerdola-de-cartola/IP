#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "agenda.h"

Agenda * carregarAgenda(char * file_name) {
    FILE * arq = NULL;
    Agenda * ag = NULL;
    Contato c;
    int i = 0;

    ag = malloc(sizeof(Agenda));
    ag->c = NULL;
    ag->qtd = 0;

    arq = fopen(file_name, "rt");
    if(arq == NULL) return ag;

    while(true) {
        c = lerContato(arq);
        if(feof(arq) != 0) break;
        adicionarContato(ag, c);
    }


    fclose(arq);

    return ag;
}

void salvarAgenda(Agenda * agenda, char * file_name) {
    FILE * arq = NULL;
    int i;

    arq = fopen(file_name, "wt");
    if(arq == NULL) exit(1);

    for(i = 0; i < agenda->qtd; i++) {
        fprintf(arq, "%s %d %d %02d %d\n",
            agenda->c[i].nome,
            agenda->c[i].telefone,
            agenda->c[i].nascimento.dia,
            agenda->c[i].nascimento.mes,
            agenda->c[i].nascimento.ano
        );
    }

    fclose(arq);
}

void imprimirAgenda(Agenda * agenda) {
    int i;

    for(i = 0; i < agenda->qtd; i++) {
        imprimirContato(&agenda->c[i]);
    }
}

void imprimirContato(Contato * c) {
    printf("------------------\n");
    printf("Nome: %s\n", c->nome);
    printf("Telefone: %d\n", c->telefone);
    printf("Nascimento: %d/%02d/%d\n", c->nascimento.dia, c->nascimento.mes, c->nascimento.ano);
}

Contato lerContato(FILE * arq) {
    Contato c;
    int qtd;

    fscanf(arq, "%s %d %d %d %d",
        c.nome,
        &c.telefone,
        &c.nascimento.dia,
        &c.nascimento.mes,
        &c.nascimento.ano
    );

    return c;
}

void adicionarContato(Agenda * agenda, Contato c) {
    Contato * tmp = NULL;

    tmp  = realloc(agenda->c, (agenda->qtd + 1) * sizeof(Contato));
    if(tmp == NULL) exit(1);
    agenda->c = tmp;
    agenda->c[agenda->qtd] = c;
    agenda->qtd++;
}

Contato * buscarContato(Agenda * agenda, char * nome) {
    int i;

    for(i = 0; i < agenda->qtd; i++) {
        if(strcasecmp(nome, agenda->c[i].nome) == 0) return &agenda->c[i];
    }

    return NULL;
}

void apagarContato(Agenda * agenda, Contato const * c) {
    Contato * tmp;
    int i;

    for(i = 0; i < agenda->qtd; i++) {
        if(&agenda->c[i] == c) break;
    }

    if(i == agenda->qtd) exit(0);
    imprimirContato(&agenda->c[i]);

    for(; i < agenda->qtd - 1; i++) {
        agenda->c[i] = agenda->c[i+1];
    }

    agenda->qtd--;
    tmp = realloc(agenda->c, agenda->qtd * sizeof(Contato));
    if(tmp == NULL) exit(0);
    agenda->c = tmp;
}

void liberarAgenda(Agenda * agenda) {
    free(agenda->c);
    free(agenda);
}