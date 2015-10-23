#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"



int main(int argc, char** argv) {
    int flag, i = 0;
    int ExecuteTime;
    float tempoMedio;
    elemento *primo = NULL, *scorri;
    
    do{
        
        printf("Inserisci il tempo d'esecuzione del processo n.%d :", i);
        scanf("%d", &ExecuteTime);
        primo=aggiungiCoda(primo, ExecuteTime, i);
        printf("Vuoi inserire un nuovo processo (1|0) : ");;//Conferma dell'utente nel caso voglia inserire un altro processo
        scanf("%d", &flag);
        i++;
    }while(flag!=0);
    
    primo = simulazioneEsecuzione(primo);
    scorri = primo;
    while(scorri != NULL) {
        printf("Tempo d'attesa del processo %d : %d\n", scorri->arrivalTime, scorri->waitTime);
        scorri = scorri->next;
    }
    
    return (EXIT_SUCCESS);
}

