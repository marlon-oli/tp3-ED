#ifndef RADIOLOGISTA_H
#define RADIOLOGISTA_H
#include "paciente.h"
#include "filalaudo.h"
#include "patologias.h"
#include "metricas.h"
#include "log.h"
#include <string.h>

typedef struct radiologista Radiologista;

typedef struct listaradiologistas ListaRadiologistas;

Radiologista* criar_radiologista();

ListaRadiologistas* criar_lista_radiologistas();

void att_radiologistas(ListaRadiologistas* lista_radiologistas, FilaLaudo* fila_laudo, Patologias* patologias, Metricas* metricas, Log* log, int ut);

#endif