#include <malloc.h>
#include <string.h>
#include "log.h"
#include "paciente.h"

struct log{
    LogNode* first;
    LogNode* last;
};

struct lognode{
    char info[50];
    int ut;
    int id;
    LogNode* next;
};

Log* criar_log(){
    Log* log = (Log*)malloc(sizeof(Log));

    log->first = NULL;

    return log;
}

void new_log(Log* log, const char* info, int ut, Paciente* paciente){
    LogNode* nlog = (LogNode*)malloc(sizeof(LogNode));
    strcpy(nlog->info, info);
    nlog->ut = ut;
    nlog->id = get_id(paciente);
    nlog->next = NULL;

    if ((log->first) == NULL){
        log->first = nlog;
        log->last = nlog;
    } else {
        log->last->next = nlog;
        log->last = nlog;
    }
}

void print_log(char* file, Log* log){
    FILE* arq = fopen(file, "w");

    if(arq == NULL){
        printf("ERRO AO GERAR ARQUIVO LOG.\n");
    }

    fprintf(arq, "LOG:\n\n");

    if (log->first != NULL) {
        for (LogNode *p = log->first; p != NULL; p = p->next) {
            fprintf(arq,"ID: %d\n", p->id);
            fprintf(arq, "EVENTO: %s\n", p->info);
            fprintf(arq, "INSTANTE: %dut\n\n", p->ut);
        }
    }
    fprintf(arq, "ENDOFLOG.");
}