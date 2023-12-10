#ifndef PATOLOGIAS_H
#define PATOLOGIAS_H

typedef struct patologias Patologias;

Patologias* criar_patologias();

int media_geral(Patologias* patologias);

int media_patologia(int idpatologia, Patologias* patologias);

void att_patologia(Patologias* patologias, int patologia, int ttotalpatologia);

#endif