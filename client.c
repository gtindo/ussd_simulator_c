#include "client.h"
#include "common.h"
#include "server.h"
#include "codes.h"
#include "cartes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void valeurDeRetour(Response* reponse)
{
    printf("Réponse : \t") ;
    scanf("%s", reponse->content) ;
}

void modifCode(char* codeIn, char* codeOut, int choix)
{
    int n ;
    n = strlen(codeIn) ;
    switch(choix)
    {
        case 1 :
            strcpy(codeOut, codeIn) ;
            codeOut[n - 1] = '*' ;
            codeOut[n] = '1' ;
            codeOut[n + 1] = '#' ;
            codeOut[n + 2] = '\0' ;
            break ;

        case 2 :
            strcpy(codeOut, codeIn) ;
            codeOut[n - 1] = '*' ;
            codeOut[n] = '2' ;
            codeOut[n + 1] = '#' ;
            codeOut[n + 2] = '\0' ;
            break ;

        case 3 :
            strcpy(codeOut, codeIn) ;
            codeOut[n - 1] = '*' ;
            codeOut[n] = '3' ;
            codeOut[n + 1] = '#' ;
            codeOut[n + 2] = '\0' ;
            break ;

        case 4 :
            strcpy(codeOut, codeIn) ;
            codeOut[n - 1] = '*' ;
            codeOut[n] = '4' ;
            codeOut[n + 1] = '#' ;
            codeOut[n + 2] = '\0' ;
            break ;

        case 5 :
            strcpy(codeOut, codeIn) ;
            codeOut[n - 1] = '*' ;
            codeOut[n] = '5' ;
            codeOut[n + 1] = '#' ;
            codeOut[n + 2] = '\0' ;
            break ;

        case 6 :
            strcpy(codeOut, codeIn) ;
            codeOut[n - 1] = '*' ;
            codeOut[n] = '6' ;
            codeOut[n + 1] = '#' ;
            codeOut[n + 2] = '\0' ;
            break ;

        case 7 :
            strcpy(codeOut, codeIn) ;
            codeOut[n - 1] = '*' ;
            codeOut[n] = '7' ;
            codeOut[n + 1] = '#' ;
            codeOut[n + 2] = '\0' ;
            break ;

        case 7777 :
            strcpy(codeOut, codeIn) ;
            codeOut[n - 3] = '#' ;
            codeOut[n - 2] = '\0' ;
            break ;

        case 9999 :
            strncpy(codeOut, codeIn, 4) ;
            codeOut[4] = '#' ;
            codeOut[5] = '\0' ;
            break ;

        case 0 :
            break ;
    }
}

void navigation(Utilisateur* user, int* sortie) //Permet la navigation entre les differents menus
{
    *sortie = 1 ;
    Response* reponse = malloc(sizeof(Response));
    Response* reqResponse = malloc(sizeof(Response)) ;
    CodeUSSD* theCode = malloc(sizeof(CodeUSSD)) ;
    int requette, choix ;
    system("cls") ;
    printf("Liste des codes : \n#104# - Etat Compte, #103*codeCarte# : achat credit, #102# : achat forfait.\nLes combinaisons #xxx*x*x# pourront etre utilises\n\n") ;
    printf("Code USSD: \t") ;
    scanf("%s", reponse->content) ;

    isTypeB(reponse) ;

    requette = server_connect(reponse) ;

    if(requette != 0)
    {
        server_response(requette, reponse->code, reqResponse, user) ;
        initCodeUSSD(reponse, theCode) ;
        system("cls") ;
        printf("%s", reqResponse->content) ;
        int test = 1 ;

        while(test == 1)
        {

            if(theCode->isFirstMenu == 1)
            {

                do
                {
                    printf("Reponse : \t") ;
                    scanf("%d", &choix) ;
                }while(choix > theCode->nbMenus && choix < 0) ;

                if(choix == 0)
                {
                    *sortie = 0 ;
                    break ;
                }
                modifCode(theCode->code, reponse->content, choix) ;

                requette = server_connect(reponse) ;

                if(requette != 0)
                {
                    server_response(requette, 0, reqResponse, user) ;
                    initCodeUSSD(reponse, theCode) ;
                    system("cls") ;
                    printf("%s", reqResponse->content) ;
                }
            }
            else
            {
                do
                {
                    printf("Reponse : \t") ;
                    scanf("%d", &choix) ;
                }while(choix > theCode->nbMenus && choix < 0 && choix != 7777 && choix != 9999) ;

                if(choix == 0)
                {
                    *sortie = 0 ;
                    break ;
                }

                modifCode(theCode->code, reponse->content, choix) ;

                requette = server_connect(reponse) ;

                if(requette != 0)
                {
                    server_response(requette, 0, reqResponse, user) ;
                    initCodeUSSD(reponse, theCode) ;
                    system("cls") ;
                    printf("%s", reqResponse->content) ;
                }
            }
        }
    }
    else
    {
        printf("\n\nLe code est incorrect.\n\n") ;
    }

}
