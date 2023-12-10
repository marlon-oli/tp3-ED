#include "paciente.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct paciente{
    int id, idade;
    char nome[20];
    int cpf;
    Exame *exame;
    Paciente *next;
};

struct exame{
    bool status; //true para laudado e false para nao laudado
    char resultado[20];
    int idpatologia;
    long int entrada_fila_laudo;
};

Exame* criar_exame(int idpatologia, char resultado[20], int ut){
    Exame* exame = (Exame*)malloc(2*sizeof(Exame));

    exame->idpatologia = idpatologia;
    exame->entrada_fila_laudo = ut;
    exame->status = false;
    strcpy(exame->resultado, resultado);

    return exame;
}

Paciente* criar_paciente(int id) {
    Paciente* paciente = (Paciente *) malloc(sizeof(Paciente));

    paciente->id = id;

    strcpy(paciente->nome, "Fulano");

    paciente->cpf = 1000 + id;

    paciente->idade = 10 + (rand() % 90);

    //exame a next iniciam nulos
    paciente->exame = NULL;
    paciente->next = NULL;

    return paciente;
}

void suceder(Paciente* antecessor, Paciente* sucessor){
    antecessor->next = sucessor;
}

int get_id(Paciente* paciente){
    return paciente->id;
}

int get_cod_patologia(Paciente* paciente){
    return ((paciente->exame)->idpatologia);
}

char* get_patologia(Paciente* paciente){
    return paciente->exame->resultado;
}

int get_entrada_filalaudo(Paciente* paciente){
    return (paciente->exame)->entrada_fila_laudo;
}

Paciente* get_next(Paciente* paciente){
    return paciente->next;
}

void set_exame(Paciente* paciente, Exame* exame){
    paciente->exame = exame;
}

void laudar(Paciente* paciente){
    paciente->exame->status = true;
}

void free_paciente(Paciente* paciente){
    free(paciente->exame);
    free(paciente);
}



