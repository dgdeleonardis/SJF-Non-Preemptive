#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"



int main(int argc, char** argv) {
    int flag, ordine = 1, i = 0;
    int ExecuteTime;
    float tempoMedio;
    elemento *primo = NULL, *scorri;
    
    do{
        i++;
        printf("Inserisci il tempo d'esecuzione del processo n.%d :", i);
        scanf("%d", &ExecuteTime);
        if (ordine==0){//Se Ã¨ 1 ogni elemento verrÃ  aggiunto in coda. Se Ã¨ 0 ogni elemento verrÃ  salvato in testa
            primo=aggiungiTesta(primo, ExecuteTime);
        }
        else{
            primo=aggiungiCoda(primo, ExecuteTime);
        }
        printf("Vuoi inserire un nuovo processo (1|0) : ");;//Conferma dell'utente nel caso voglia inserire un altro processo
        scanf("%d", &flag);
    }while(flag!=0);
    
    
    tempoMedio=calcolaTempo(primo, i);//Calcolo del tempo d'attesa tramite funzione apposita
    
    printf("Tempo di attesa medio: %5.2f\n", tempoMedio);
    
    return (EXIT_SUCCESS);
}

