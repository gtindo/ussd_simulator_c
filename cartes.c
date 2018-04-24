#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "common.h"
#include "server.h"
#include "cartes.h"

void genererCarte(CartePrep* carte, float montant)
{
    srand(time(NULL)) ;
    FILE *fichier = NULL ;
    CartePrep carteTest ;
    carte->code = (rand() % 78965412) + 21547893 ;

    fichier = fopen("cartesList.usd", "rb") ;

    if(fichier == NULL)
    {
        exit(EXIT_FAILURE) ;
    }

    while(fread(&carteTest, sizeof(CartePrep), 1, fichier), !feof(fichier))
    {
        if(carte->code == carteTest.code)
        {
            carte->code = (rand() % 78965412) + 21547893 ;
        }
    }
    fclose(fichier) ;

    carte->etat = 'A' ;
    carte->montant = montant ;

    fichier = fopen("cartesList.usd", "ab") ;
    fwrite(carte, sizeof(CartePrep), 1, fichier) ;
    fclose(fichier) ;

}
