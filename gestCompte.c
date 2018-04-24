#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>
#include "gestCompte.h"
#include "common.h"

int generateTel()
{
    int tel ;
    srand(time(NULL)) ;
    tel = 600000000 + (rand() % 98754322) + 12345678 ;

    return tel ;
}

int generateCode()
{
    int code ;
    srand(time(NULL)) ;
    code = (rand() % 78965412) + 21547893 ;
    return code ;
}

void createUser(Utilisateur* user)
{
    FILE* fichier = NULL ;
    int tel, codePuk ;
    fichier = fopen("userList.usd", "rb") ;

    if(fichier == NULL)
    {
        exit(EXIT_FAILURE) ;
    }

    tel = generateTel() ;
    codePuk = generateCode() ;

    while(fread(user, sizeof(Utilisateur), 1, fichier), !feof(fichier))
    {
        if(tel == user->tel)
        {
            tel = generateTel() ;
        }

        if(codePuk == user->codePuk)
        {
            codePuk = generateCode() ;
        }
    }

    fclose(fichier) ;

    user->tel = tel ;
    user->codePuk = codePuk ;

    todayDate(&(user->creditUtilisateur.validite)) ;
    user->creditUtilisateur.validite.annee += 1 ;

    user->creditUtilisateur.montant = 1000 ;

    initialiserForfait(&(user->forfaitAppel)) ;
    initialiserForfait(&(user->forfaitSMS)) ;
    initialiserForfait(&(user->forfaitInternet)) ;

    fichier = fopen("userList.usd", "ab") ;

    if(fichier == NULL)
    {
        exit(EXIT_FAILURE) ;
    }

    fwrite(user, sizeof(Utilisateur), 1, fichier) ;

    fclose(fichier) ;

}
