#ifndef FILALAUDO_H
#define FILALAUDO_H
#include "paciente.h"

typedef struct filalaudo FilaLaudo;

FilaLaudo* criar_fila_laudo();

void entrar_fila_laudo(Paciente* paciente, FilaLaudo* filalaudo);

Paciente* primeiro_fila_laudo(FilaLaudo* filalaudo);

#endif