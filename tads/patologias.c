#include "patologias.h"
#include <stdlib.h>

struct patologias{
    //saude normal
    int count0;
    int tempototal0;

    //patologia 1
    int count1;
    int tempototal1;

    //patologia 2
    int count2;
    int tempototal2;

    //patologia 3
    int count3;
    int tempototal3;

    //patologia 4
    int count4;
    int tempototal4;

};

Patologias* criar_patologias(){
    Patologias* patologias = (Patologias*)malloc(sizeof(Patologias));

    patologias->count0 = 0;
    patologias->count1 = 0;
    patologias->count2 = 0;
    patologias->count3 = 0;
    patologias->count4 = 0;
    patologias->tempototal0 = 0;
    patologias->tempototal1 = 0;
    patologias->tempototal2 = 0;
    patologias->tempototal3 = 0;
    patologias->tempototal4 = 0;

    return patologias;
}

int media_geral(Patologias* patologias){
    int tempototal = (patologias->tempototal0 + patologias->tempototal1 + patologias->tempototal2 + patologias->tempototal3 + patologias->tempototal4);
    int qtotal = (patologias->count0 + patologias->count1 + patologias->count2 + patologias->count3 + patologias->count4);

    if (qtotal == 0){
        return 0;
    }
    return (tempototal / qtotal);
}

int media_patologia(int idpatologia, Patologias* patologias) {
    int media;

    if (idpatologia == 0) {
        if (patologias->count0 == 0) {
            media = 0;
        } else {
            media = ((patologias->tempototal0) / (patologias->count0));
        }
    } else if (idpatologia == 1) {
        if (patologias->count1 == 0) {
            media = 0;
        } else {
            media = ((patologias->tempototal1) / (patologias->count1));
        }
    } else if (idpatologia == 2) {
        if (patologias->count2 == 0) {
            media = 0;
        } else {
            media = ((patologias->tempototal2) / (patologias->count2));
        }
    } else if (idpatologia == 3) {
        if (patologias->count3 == 0) {
            media = 0;
        } else {
            media = ((patologias->tempototal3) / (patologias->count3));
        }
    } else if (idpatologia == 4) {
        if (patologias->count4 == 0) {
            media = 0;
        } else {
            media = ((patologias->tempototal4) / (patologias->count4));
        }
    }
    return media;
}

void att_patologia(Patologias* patologias, int idpatologia, int tmediopatologia){
    if (idpatologia == 0) {
        patologias->count0++;
        patologias->tempototal0 += tmediopatologia;
    } else if (idpatologia == 1) {
        patologias->count1++;
        patologias->tempototal1 += tmediopatologia;
    } else if (idpatologia == 2) {
        patologias->count2++;
        patologias->tempototal2 += tmediopatologia;
    }else if (idpatologia == 3) {
        patologias->count3++;
        patologias->tempototal3 += tmediopatologia;
    }else if (idpatologia == 4){
            patologias->count4++;
            patologias->tempototal4 += tmediopatologia;
    }
}