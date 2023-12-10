#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "radiologista.h"
#include "paciente.h"
#include "filalaudo.h"


struct radiologista{
    Paciente* pacienteatual;
    bool status;
    int tempototal;
    Radiologista *next;
};

struct listaradiologistas{
    Radiologista* first;
};

Radiologista* criar_radiologista(){
    Radiologista* radiologista = (Radiologista*)malloc(sizeof(Radiologista));

    radiologista->pacienteatual = NULL;
    radiologista->next = NULL;
    radiologista->status = true;
    radiologista->tempototal = 0;

    return radiologista;
}

ListaRadiologistas* criar_lista_radiologistas(){
    ListaRadiologistas* listaradiologistas = (ListaRadiologistas*)malloc(sizeof(ListaRadiologistas));
    Radiologista* rad = criar_radiologista();
    listaradiologistas->first = rad;
    for (int i = 0; i < 2; i++){
        Radiologista* p = criar_radiologista();
        rad->next = p;
        rad = p;
    }

    return listaradiologistas;
}

void att_radiologistas(ListaRadiologistas* lista_radiologistas, FilaLaudo* fila_laudo, Patologias* patologias, Metricas* metricas, Log* log, int ut){
    for (Radiologista* p = lista_radiologistas->first; p != NULL; p = p->next){
        if((p->tempototal) != 0){
            p->tempototal -= 1;
        } else  {
            if (p->status == false) {
            //muda o status do exame para laudado
            laudar(p->pacienteatual);

            char result[50] = {"LAUDADO COM "};
            strcat(result, get_patologia(p->pacienteatual));

            new_log(log, result, ut, p->pacienteatual);

            //atualizando valores para metricas de acordo com a patologia em questao
            att_patologia(patologias, get_cod_patologia(p->pacienteatual), (ut - get_entrada_filalaudo(p->pacienteatual)));

            if ((ut - get_entrada_filalaudo(p->pacienteatual)) > 7200){
                timeout(metricas);
                new_log(log, "LAUDADO APOS LIMITE DE TEMPO", ut, p->pacienteatual);
            }

            //libera memoria do paciente
            free_paciente(p->pacienteatual);
            p->pacienteatual = NULL;

            //atualiza o status para disponivel (true)
            p->status = true;
            } else {
                //pega o primeiro da fila para laudo
                Paciente* paciente = primeiro_fila_laudo(fila_laudo);

                if (paciente != NULL){
                    new_log(log, "SAIU DA FILA PARA LAUDO", ut, paciente);
                    //atribui o paciente ao radiologista
                    p->pacienteatual = paciente;

                    //calcula o tempo para laudo
                    p->tempototal = 10 + (rand() % 21);

                    //muda o status para indisponivel (false)
                    p->status = false;
                }
            }
        }
    }
}
