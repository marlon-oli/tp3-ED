#include "metricas.h"
#include "patologias.h"
#include <stdio.h>
#include <stdlib.h>

struct metricas{
    //tempo medio de laudo
    int t_medio_laudo_geral;

    //tempo medio de laudo por patologia
    int t_medio_laudo_patologia0;
    int t_medio_laudo_patologia1;
    int t_medio_laudo_patologia2;
    int t_medio_laudo_patologia3;
    int t_medio_laudo_patologia4;

    //quantidade de exames laudados apos o limite de tempo
    int quanttimeout;
};

Metricas* criar_metricas(){
    Metricas* metricas = (Metricas*)malloc(sizeof(Metricas));

    metricas->t_medio_laudo_geral = 0;
    metricas->quanttimeout = 0;
    metricas->t_medio_laudo_patologia0 = 0;
    metricas->t_medio_laudo_patologia1 = 0;
    metricas->t_medio_laudo_patologia2 = 0;
    metricas->t_medio_laudo_patologia3 = 0;
    metricas->t_medio_laudo_patologia4 = 0;

    return metricas;
}

void att_metricas(Metricas* metricas, Patologias* patologias){
    //atualizando tempo medio geral de laudo
    metricas->t_medio_laudo_geral = media_geral(patologias);

    //atualizando tempo medio dos laudos por patologia
    metricas->t_medio_laudo_patologia0 = media_patologia(0, patologias);
    metricas->t_medio_laudo_patologia1 = media_patologia(1, patologias);
    metricas->t_medio_laudo_patologia2 = media_patologia(2, patologias);
    metricas->t_medio_laudo_patologia3 = media_patologia(3, patologias);
    metricas->t_medio_laudo_patologia4 = media_patologia(4, patologias);
}

void timeout(Metricas* metricas){
    metricas->quanttimeout += 1;
}

void print_metricas(Metricas* metricas) {
    printf("_________________________________MÉTRICAS:__________________________________\n\n");
    printf("TEMPO MÉDIO GERAL PARA LAUDO: %dut\n", metricas->t_medio_laudo_geral);
    printf("QUANTIDADE DE LAUDOS EMITIDOS APÓS LIMITE DE TEMPO: %d laudos\n\n", metricas->quanttimeout);
    printf("_________________________TEMPO MÉDIO POR PATOLOGIA:_________________________\n\n");
    printf("(%d)ut - SAÚDE NORMAL\n", metricas->t_medio_laudo_patologia0);
    printf("(%d)ut - BRONQUITE\n", metricas->t_medio_laudo_patologia1);
    printf("(%d)ut - PNEUMONIA\n", metricas->t_medio_laudo_patologia2);
    printf("(%d)ut - FRATURA DE FÊMUR\n", metricas->t_medio_laudo_patologia3);
    printf("(%d)ut - APENDICITE\n\n", metricas->t_medio_laudo_patologia4);
}