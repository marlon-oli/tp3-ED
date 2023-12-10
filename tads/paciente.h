#ifndef PACIENTE_H
#define PACIENTE_H
#include "paciente.h"

typedef struct paciente Paciente;

typedef struct exame Exame;

Exame* criar_exame(int idpatologia, char resultado[20], int ut);

Paciente* criar_paciente(int id);

void suceder(Paciente* antecessor, Paciente* sucessor);

int get_cod_patologia(Paciente* paciente);

int get_entrada_filalaudo(Paciente* paciente);

int get_id(Paciente* paciente);

char* get_patologia(Paciente* paciente);

Paciente* get_next(Paciente* paciente);

void set_exame(Paciente* paciente, Exame* exame);

void laudar(Paciente* paciente);

void free_paciente(Paciente*);

#endif