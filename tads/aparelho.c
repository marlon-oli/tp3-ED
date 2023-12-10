#include "log.h"
#include "aparelho.h"
#include "paciente.h"
#include <stdbool.h>
#include <stdlib.h>

struct aparelho{
    bool status;
    Paciente* pacienteatual;
    int tempototal;
    Aparelho *next;
};

struct listaaparelhos {
    Aparelho* first;
};

Aparelho* criar_aparelho(){
    Aparelho* aparelho = (Aparelho*)malloc(sizeof(Aparelho));

    aparelho->status = true;
    aparelho->pacienteatual = NULL;
    aparelho->next = NULL;
    aparelho->tempototal =  0;

    return aparelho;
}

ListaAparelhos* criar_lista_aparelhos(){
    ListaAparelhos* listaaparelhos = (ListaAparelhos*)malloc(sizeof(ListaAparelhos));
    Aparelho* apa = criar_aparelho();
    listaaparelhos->first = apa;
    for (int i = 0; i < 4; i++){
        Aparelho* p = criar_aparelho();
        apa->next = p;
        apa = p;
    }

    return listaaparelhos;
}

Exame* gerar_resultado(int ut){
    int result = rand() % 100;
    Exame* exame;

    if (result < 30){
        exame = criar_exame(0,"SAUDE NORMAL", ut);
    } else if ((result > 29) && (result < 50)){
        exame = criar_exame(1,"BRONQUITE", ut);
    } else if ((result > 49) && (result < 70)) {
        exame = criar_exame(2,"PNEUMONIA", ut);
    } else if ((result > 69) && (result < 85)){
        exame = criar_exame(3,"FRATURA DE FEMUR", ut);
    } else if (result > 84) {
        exame = criar_exame(4,"APENDICITE", ut);
    }
    return exame;
}

void att_aparelhos(ListaAparelhos* lista_aparelhos, FilaExame* fila_exame, FilaLaudo* fila_laudo, Log* log, int ut){
    for (Aparelho* p = lista_aparelhos->first; p != NULL; p = p->next){
        if ((p->tempototal) != 0) {
            p->tempototal -= 1;
        } else {
            if ((p->status) == false) {
                //gera resultado do exame de acordo com as probabilidades
                set_exame(p->pacienteatual, gerar_resultado(ut));

                //adiciona paciente no final da fila para laudo
                entrar_fila_laudo(p->pacienteatual, fila_laudo);
                new_log(log, "ENTROU NA FILA PARA LAUDO", ut, p->pacienteatual);

                //remove a referencia para o paciente do aparelho
                p->pacienteatual = NULL;

                //muda o status para disponivel (true)
                p->status = true;

            } else {
                //pega o primeiro da fila para exame
                Paciente* paciente = primeiro_fila_exame(fila_exame);
                //verifica se existe alguem na fila

                if (paciente != NULL){
                    new_log(log, "SAIU DA FILA PARA EXAME", ut, paciente);
                    //atribui o paciente ao aparelho
                    p->pacienteatual = paciente;

                    //calcula o tempo de exame (5-10)
                    p->tempototal = 5 + (rand() % 6);

                    //muda o status para indisponivel (false)
                    p->status = false;
                }
            }
        }
    }
}