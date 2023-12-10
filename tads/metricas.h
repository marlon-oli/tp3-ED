#ifndef METRICAS_H
#define METRICAS_H

#include "patologias.h"

typedef struct metricas Metricas;

Metricas* criar_metricas();

void att_metricas(Metricas* metricas, Patologias* patologias);

void timeout(Metricas* metricas);

void print_metricas(Metricas* metricas);

#endif