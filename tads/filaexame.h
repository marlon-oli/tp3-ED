#ifndef FILAEXAME_H
#define FILAEXAME_H
#include "paciente.h"

typedef struct filaexame FilaExame;

FilaExame* criar_fila_exame();

void entrar_fila_exame(Paciente* paciente, FilaExame* filaexame);

Paciente* primeiro_fila_exame(FilaExame* filaexame);

#endif