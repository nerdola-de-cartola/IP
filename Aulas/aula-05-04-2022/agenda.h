#include <stdio.h>

typedef struct data {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct contato {
    char nome[20];
    int telefone;
    Data nascimento;
} Contato;

typedef struct agenda {
    Contato * c;
    int qtd;
} Agenda;

Agenda * carregarAgenda(char * file_name);
void salvarAgenda(Agenda * agenda, char * file_name);
void imprimirAgenda(Agenda * agenda);
void imprimirContato(Contato * c);
Contato lerContato(FILE * arq);
void adicionarContato(Agenda * agenda, Contato c);
Contato * buscarContato(Agenda * agenda, char * nome);
void apagarContato(Agenda * agenda, Contato const * c);
void liberarAgenda(Agenda * agenda);
