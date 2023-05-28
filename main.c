#include <stdio.h>
#include <stdlib.h>
#include "lib_funzioni_dizionario.h"
#include <string.h>

int main()
{
    Voce dizionario[10];
    char parola_da_ricercare[30];
    int n_elementi = 0;

    printf("\n DIZIONARIO DELLA LINGUA ITALIANA \n\n");
    /* Il programma simula la costruzione di un dizionario della lingua italiana. Vi sono procedure per inserire
     e ricercare una parola e per stamparne a video il significato*/

    inserisci_voce(dizionario, &n_elementi);        // Inserisce alcune voci nel dizionario in ordine alfabetico
    inserisci_voce(dizionario, &n_elementi);
    inserisci_voce(dizionario, &n_elementi);

    visualizza_dizionario(dizionario, &n_elementi); // Visualizza il dizionario

    ins_parola_da_ricercare(parola_da_ricercare);  // Permette di ricercare una parola e, se presente nel dizionario, di visualizzarne il significato
    ricerca_parola(parola_da_ricercare, dizionario, n_elementi);



    return 0;
}
