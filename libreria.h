struct s_elemento{ //definizione elemento della lista
    int executeTime;
    int returnTime;
    int waitTime;
    int remaingTime;
    int arrivalTime;
    struct s_elemento *next;
};

typedef struct s_elemento elemento;

elemento* aggiungiTesta(elemento* first, int value);//prototipo funzione di aggiunta in testa per calcolo del tempo d'attesa inverso
elemento* aggiungiCoda(elemento* first, int value, int arrival);//protipo funzione di aggiunta in coda per calcolo del tempo d'attesa diretto
float calcolaTempo(elemento* first, int numeroProcessi);//prototipo funzione che calcola il tempo d'attesa dato un puntatore ad una lista e contatore di processi
void svuotaLista(elemento* first);//prototipo funzione che svuota la lista.
elemento* bubbleSort(elemento* first, int i);

elemento* simulazioneEsecuzione(elemento *first);
int verificaCompletamento(elemento *first);
elemento* calcolaAttesa(elemento *first);
elemento* assegnazioneMin(elemento *first);