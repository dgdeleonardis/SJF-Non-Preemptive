#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"

elemento* aggiungiCoda(elemento* first, int value, int arrival){
    elemento* scorri=first;
    elemento* temp;
    temp = (elemento*) malloc(sizeof(elemento));
    if(temp == NULL) {
        exit(1);
    }
    temp->executeTime = value;
    temp->remaingTime = value;
    temp->arrivalTime = arrival;
    temp->waitTime = 0;
    temp->returnTime = 0;
    if (first!=NULL){
        while(scorri->next!=NULL){
            scorri=scorri->next;
        }
       scorri->next=temp; 
    }
    else {
        first=temp;
    }
    return first;
}

elemento* simulazioneEsecuzione(elemento* first) {
    int slice = 0, completamento;
    elemento* scorri, *min;
    scorri = first;
    min = scorri;
    slice++;
    min->remaingTime--;
    min->returnTime = slice;
    scorri = scorri->next;
    completamento = verificaCompletamento(first);

    while (!completamento) {
        if(min->remaingTime == 0)
            min->returnTime = slice;      
        scorri = first;
        while(scorri != NULL) {
            if(scorri->arrivalTime <= slice) {
                if ((((scorri->remaingTime) < (min->remaingTime)) && scorri->remaingTime > 0) || min->remaingTime == 0)
                    min = scorri;
                }
            scorri = scorri->next;
        }
        slice++;
        min->remaingTime--;
        min->returnTime = slice;
        completamento = verificaCompletamento(first);
    }

    first = calcolaAttesa(first);
    return first;
}

int verificaCompletamento(elemento *first) {
    int completamento = 1;
    elemento *scorri;
    scorri = first;
    while(scorri != NULL) {
        if(scorri->remaingTime == 0)
            completamento = completamento * 1;
        else
            completamento = completamento * 0;
        scorri = scorri->next;
    }
    return completamento;
}

elemento *calcolaAttesa(elemento *first) {
    elemento *scorri;
    scorri = first;
    while(scorri != NULL) {
        scorri->waitTime = (scorri->returnTime - scorri->executeTime) - scorri->arrivalTime;
        scorri = scorri->next;
    }
    return first;
}

float calcolaMedia(elemento *first, int numProcessi) {
    float tempoMedio = 0;
    elemento *scorri = first;
    while(scorri != NULL) {
        tempoMedio+= scorri->waitTime;
        scorri = scorri->next;
    }
    tempoMedio = tempoMedio / numProcessi;
    return tempoMedio;
}

void svuotaLista (elemento* first){
    elemento* temp;
    printf("Svuotamento lista in corso...\n");
    while(first!=NULL){
        temp=first->next;
        free(first);
        first=temp;
    }
    printf("Completato.");
}