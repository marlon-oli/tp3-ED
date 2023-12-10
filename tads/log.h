#ifndef LOG_H
#define LOG_H

#include "paciente.h"

typedef struct log Log;

typedef struct lognode LogNode;

Log* criar_log();

void new_log(Log* log, const char* info, int ut, Paciente* paciente);

void print_log(char* file, Log* log);

#endif
