#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct voce               // Crea la struct voce
{
    char parola[30];
    char significato[100];
};

typedef struct voce Voce;   // Crea il tipo di dato Voce

void crea_parola(Voce *, int *);
void inserisci_parola(Voce [], int *);
void visualizza_dizionario(Voce [],int *);
void scambia_parola(Voce *, Voce *);
int max_ind_S(Voce *, int );
void ins_parola_da_ricercare(char []);
void ricerca_parola(char [], Voce *, int );
