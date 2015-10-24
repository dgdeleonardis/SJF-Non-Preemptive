#include <stdio.h>
#include <stdlib.h>

struct s_elemento{ //definizione elemento della lista
    int executeTime;
    int returnTime;
    int waitTime;
    int remaingTime;
    int arrivalTime;
    struct s_elemento *next;
};

typedef struct s_elemento elemento;

elemento* aggiungiCoda(elemento* first, int value, int arrival); //protipo funzione di aggiunta in coda per calcolo del tempo d'attesa diretto

elemento* simulazioneEsecuzione(elemento *first); //prototipo funzione che simula l'esecuzione dei processi

int verificaCompletamento(elemento *first); //prototipo funzione che verifica il completamento di tutti processi

elemento* calcolaAttesa(elemento *first); //prototipo funzione che calcola il tempo d'attes di ogni processo

float calcolaMedia(elemento *first, int numProcessi); //prototipo funzione che calcola la media matematica dei tempi d'attesa dei processi

void svuotaLista(elemento* first); //prototipo funzione che svuota la lista.