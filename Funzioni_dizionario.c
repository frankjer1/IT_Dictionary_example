#include <stdio.h>
#include <stdlib.h>
#include "lib_funzioni_dizionario.h"
#include <string.h>



void crea_voce(Voce *nuova_voce) // Crea una voce del dizionario di tipo Voce
{
    printf("\n Inserisci parola: ");
    gets(nuova_voce->parola);
    printf("\n Inserisci significato: ");
    gets(nuova_voce->significato);

}


void inserisci_voce(Voce dizionario[],int *n_elementi) // Crea una nuova voce, la inserisce nel dizionario e poi la ordina in ordine alfabetico
{
    // int i, j, n;
    Voce nuova_voce;
    crea_voce(&nuova_voce);
    strcpy((dizionario + (*n_elementi))->parola, nuova_voce.parola);
    strcpy((dizionario + (*n_elementi))->significato, nuova_voce.significato);
    (*n_elementi)++; // Segnala il numero di elementi del dizionario al di fuori della procedura(necesssaria per l'algoritmo di ordinamento
    ord_sel_max(dizionario,n_elementi); // ordina il dizionario in ordine alfabetico tramite un'algoritmo di ordinamento per selez. di massimo
}


void visualizza_dizionario(Voce dizionario[],int *n_elementi) // visualizza a video il dizionario
{
    int i;
    printf(" \n DIZIONARIO \n ");

    for(i=0; i < *n_elementi;i++)
    {
        printf(" ------------------");
        printf("\n Parola: %s \n", dizionario[i].parola);
        printf("\n Significato: %s \n", dizionario[i].significato);
        printf(" ------------------");
    }
}

void scambia_parola(Voce *parola_1, Voce *parola_2) // Scambia due voci
{
    char temp_parola[30];
    char temp_significato[50];

    strcpy(temp_parola, parola_1 -> parola);
    strcpy(temp_significato, parola_1 ->significato);

    strcpy(parola_1->parola, parola_2->parola);
    strcpy(parola_1->significato, parola_2->significato);

    strcpy(parola_2->parola, temp_parola);
    strcpy(parola_2->significato, temp_significato);

}


void ord_sel_max(Voce *dizionario,int *n_elementi) // Ordinamento per selezione di massimo
{
    int i;

    for(i= (*n_elementi)-1; i>0; i--)
    {
        scambia_parola((dizionario + i), (dizionario + (max_ind_S(dizionario,i+1))));
    }
}

int max_ind_S(Voce *dizionario, int n) // Restituisce l'indice della stringa maggiore
{
    int i, i_max = 0;

    for(i=1; i<n; i++)
    {
        if((strcmp((dizionario + i)->parola,(dizionario + i_max)->parola))>0)
        {
            i_max = i;
        }
    }
    return i_max;

}


void ricerca_parola(char parola_da_ricercare[], Voce *dizionario, int n_elementi) // Ricerca la parola richiesta comparandola con quelle nel dizionario
{                                                                                  // in maniera ricorsiva e se la trova ne restituisce il significato
    int mediano;
    int n;

    if(n_elementi == 0)
    {
        printf("La parola non e' presente nel dizionario!");
    }
    else
    {
        mediano = ((n_elementi) - 1)/2;

        if(strcmp(parola_da_ricercare, (dizionario + mediano)->parola) == 0)
        {
            printf("\n Significato: %s", (dizionario + mediano)->significato);
        }
        else if(strcmp(parola_da_ricercare, (dizionario + mediano)->parola) < 0)
        {

            return ricerca_parola(parola_da_ricercare, dizionario, mediano);
        }
        else
        {

            return ricerca_parola(parola_da_ricercare, (dizionario + mediano + 1), (n_elementi) - mediano - 1);
        }


    }

}


void ins_parola_da_ricercare(char *parola_da_ricercare) // Permette all'utente di inserire una parola. La funzione è utilizzata per gestire
{                                                       //  la parola da ricercare

    printf("\n Inserisci la parola da ricercare: ");
    gets(parola_da_ricercare);
}




