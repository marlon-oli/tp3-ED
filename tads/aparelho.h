#ifndef APARELHO_H
#define APARELHO_H
#include "filaexame.h"
#include "filalaudo.h"
#include "paciente.h"
#include "log.h"


typedef struct aparelho Aparelho;

typedef struct listaaparelhos ListaAparelhos;

Aparelho* criar_aparelho();

ListaAparelhos* criar_lista_aparelhos();

Exame* gerar_resultado(int ut);

void att_aparelhos(ListaAparelhos* lista_aparelhos, FilaExame* fila_exame, FilaLaudo* fila_laudo, Log* log, int ut);

#endif
