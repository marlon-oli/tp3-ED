#include "filaexame.h"
#include "paciente.h"
#include <stdlib.h>

struct filaexame{
    int count;
    Paciente *first;
    Paciente *last;
};

FilaExame* criar_fila_exame(){
    FilaExame* filaexame = (FilaExame*)malloc(sizeof(FilaExame));
    filaexame->count = 0;
    filaexame->first = filaexame->last = NULL;

    return filaexame;
}

void entrar_fila_exame(Paciente* paciente, FilaExame* filaexame){
    if (filaexame->last != NULL){
        suceder(filaexame->last, paciente);
        filaexame->last = paciente;
    } else {
        filaexame->last = paciente;
        filaexame->first = paciente;
    }

    filaexame->count += 1;
}

Paciente* primeiro_fila_exame(FilaExame* filaexame){
    if (filaexame->first != NULL){
        Paciente* first = filaexame->first;

        if (get_next(first) != NULL){
            filaexame->first = get_next(first);
        } else {
            filaexame->first = NULL;
            filaexame->last= NULL;
        }

        suceder(first, NULL);

        return first;
    } else {
        return NULL;
    }
}




