#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"

elemento* aggiungiTesta(elemento* first, int value){
    elemento* temp;
    temp = (elemento*) malloc(sizeof(elemento));
    if(temp == NULL) {
        exit(1);
    }
    temp->executeTime=value;
    temp->next = first;
    first = temp;
    return first;
}

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

float calcolaTempo(elemento* first, int numeroProcessi){
    elemento* scorri=first;
    float acc,accExecuteTime=0;
    float tempo=0;
    
    while(scorri->next!=NULL){
        accExecuteTime+=scorri->executeTime;
        acc+=accExecuteTime;
        scorri=scorri->next;
    }
    tempo=acc/numeroProcessi;
    return tempo;
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

elemento* bubbleSort(elemento* first, int i) {
    elemento* pj, *pk;
    int value;
    while(i-1) {
        pj = first;
        while(pj->next != NULL) {
           pk = pj->next;
            if((pj->executeTime) > (pk->executeTime)) {
                value = pj->executeTime;
                pj->executeTime = pk->executeTime;
                pk->executeTime = value;
            }
            pj = pj->next;
         }
        i--;
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
            min = assegnazioneMin(first);
        scorri = first;
        while(scorri != NULL) {
            if(scorri->arrivalTime <= slice) {
                if (((scorri->remaingTime) < (min->remaingTime)) && scorri->remaingTime > 0)
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

elemento* assegnazioneMin(elemento *first) {
    elemento *min;
    min = first;
    while(min->remaingTime == 0)
        min = min->next;
    return min;
}