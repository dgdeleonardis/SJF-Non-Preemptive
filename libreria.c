#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"

elemento* aggiungiTesta(elemento* first, int value){
    elemento* temp;
    temp = (elemento*) malloc(sizeof(elemento));
    if(temp == NULL) {
        exit(1);
    }
    temp->value=value;
    temp->next = first;
    first = temp;
    return first;
}

elemento* aggiungiCoda(elemento* first, int value){
    elemento* scorri=first;
    elemento* temp;
    temp = (elemento*) malloc(sizeof(elemento));
    if(temp == NULL) {
        exit(1);
    }
    temp->value=value;
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
        accExecuteTime+=scorri->value;
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
            if((pj->value) > (pk->value)) {
                value = pj->value;
                pj->value = pk->value;
                pk->value = value;
            }
            pj = pj->next;
         }
        i--;
    }
    return first;
}
