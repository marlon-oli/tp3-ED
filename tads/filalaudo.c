#include "filalaudo.h"
#include "paciente.h"
#include <stdlib.h>
#include <stdio.h>

struct filalaudo{
    int count;
    Paciente *first;
    Paciente *last;
};

FilaLaudo* criar_fila_laudo(){
    FilaLaudo* filalaudo = (FilaLaudo*)malloc(sizeof(FilaLaudo));
    filalaudo->count = 0;
    filalaudo->first = filalaudo->last = NULL;

    return filalaudo;
}

void entrar_fila_laudo(Paciente* paciente, FilaLaudo* filalaudo){
    if (filalaudo->last != NULL){
        suceder(filalaudo->last, paciente);
        filalaudo->last = paciente;
    } else {
        filalaudo->last = paciente;
        filalaudo->first = paciente;
    }
    filalaudo->count += 1;
}

Paciente* primeiro_fila_laudo(FilaLaudo* filalaudo){
    if (filalaudo->first != NULL){
        Paciente* first = filalaudo->first;

        if (get_next(first) != NULL){
            filalaudo->first = get_next(first);
        } else {
            filalaudo->first = NULL;
            filalaudo->last = NULL;
        }
        return first;
    } else {
        return NULL;
    }
}