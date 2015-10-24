#include "libreria.h" //includo libreria.h comprendente prototipi, strutture e librerie

int main(int argc, char** argv) {
    int flag, i = 0;
    int ExecuteTime;
    float tempoMedio;
    elemento *primo = NULL, *scorri;
    //fase di input
    do{
        
        printf("Inserisci il tempo d'esecuzione del processo n.%d :", i);
        scanf("%d", &ExecuteTime);
        primo=aggiungiCoda(primo, ExecuteTime, i);
        printf("Vuoi inserire un nuovo processo (1|0) : ");;//Conferma dell'utente nel caso voglia inserire un altro processo
        scanf("%d", &flag);
        i++;
    }while(flag!=0);
    
    primo = simulazioneEsecuzione(primo); //richiamo a funzione che simulando esecuzione dei processi calcola i tempi di ritorno e attesa
    
    tempoMedio = calcolaMedia(primo, i); //funzione che calcola la media matematica dei tempi d'attesa
    //fase di output
    scorri = primo;
    while(scorri != NULL) {
        printf("\nProcesso %d :\n"
                "   Tempo d'attesa : %d\n"
                "   Tempo di ritorno : %d\n"
                "   Tempo di esecuzione : %d\n",
                scorri->arrivalTime, scorri->waitTime, scorri->returnTime, scorri->executeTime);
        scorri = scorri->next;
    }
    printf("\nTempo medio d'attesa : %5.2f\n", tempoMedio);
    svuotaLista(primo);
    return (EXIT_SUCCESS);
}

