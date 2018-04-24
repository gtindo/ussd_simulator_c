#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "client.h"
#include "server.h"
#include "codes.h"
#include "common.h"
#include "gestCompte.h"
#include "cartes.h"

void menu()
{
    printf("=== Menu Simulation USSD ===\n\n") ;
    printf("1 - Creer utilisateur\n") ;
    printf("2 - Carte prepayee\n") ;
    printf("3 - Connexion\n") ;
    printf("4 - Quitter\n") ;
    printf("choix : \t") ;
}

void menuCarte()
{
    printf("=== Choix des cartes ===\n\n") ;
    printf("1 - 500 FCFA\n") ;
    printf("2 - 1000 FCFA\n") ;
    printf("3 - 2000 FCFA\n") ;
    printf("4 - 5000 FCFA\n") ;
    printf("5 - 10000 FCFA\n") ;
    printf("6 - 25000 FCFA\n") ;
}

int main()
{
    srand(time(NULL)) ;
    int test = 1, sortie = -1 ;
    int choix = 0, choixCarte = 0  ;
    float montantCarte = 0 ;
    Utilisateur user ;
    int codePuk ;
    CodeUSSD theCode ;
    CartePrep theCard ;

    do
    {
        menu() ;
        scanf("%d", &choix) ;

        switch(choix)
        {
            case 10 : //se case a ete utile pour l'ecriture du fichier contenant les codes USSD, mais n'est plus necessaire par la suite
                printf("\ncode USSD : \t") ;
                scanf("%s", theCode.code) ;
                printf("ID : \t") ;
                scanf("%d", &theCode.id) ;
                printf("Nombres de sous-menus : \t") ;
                scanf("%d", &theCode.nbMenus) ;
                printf("Menu principal ? \t") ;
                scanf("%d", &theCode.isFirstMenu) ;
                addCode(&theCode) ;
                system("pause") ;
                break ;

            case 1 :
                createUser(&user) ;
                printf("\nTel : %d \nCode puk : %d \nCredit : %.2f FCFA\n", user.tel, user.codePuk, user.creditUtilisateur.montant) ;
                printf("Valide jusqu'au : %d/%d/%d a %d:%d:%d\n\n", user.creditUtilisateur.validite.jour, user.creditUtilisateur.validite.mois, user.creditUtilisateur.validite.annee, user.creditUtilisateur.validite.heure, user.creditUtilisateur.validite.minutes, user.creditUtilisateur.validite.seconde) ;
                system("pause") ;
                break ;

            case 2 :
                system("cls") ;
                menuCarte() ;
                choixC:printf("choix : \t") ;
                scanf("%d", &choixCarte) ;
                switch(choixCarte)
                {
                    case 1 :
                        montantCarte = 500 ;
                        break ;
                    case 2 :
                        montantCarte = 1000 ;
                        break ;
                    case 3 :
                        montantCarte = 2000 ;
                        break ;
                    case 4 :
                        montantCarte = 5000 ;
                        break ;
                    case 5 :
                        montantCarte = 10000 ;
                        break ;
                    case 6 :
                        montantCarte = 25000 ;
                        break ;

                    default :
                        goto choixC ;
                }
                genererCarte(&theCard, montantCarte) ;
                printf("\n\nMontant : %1.f\nCode : %d\n\n", montantCarte, theCard.code) ;
                system("pause") ;
                break ;

            case 3 :
                do{
                    printf("\nEntrez votre code puk : \t") ;
                    scanf("%d", &codePuk) ;

                    if(verifCodePuk(codePuk) == 1)
                    {
                        co_user_init(&user, codePuk) ;
                        navigation(&user, &sortie) ;

                        if(sortie == 0)
                        {
                            break ;
                        }
                    }
                    else
                    {
                        printf("\nCode puk Incorrect\n.") ;
                        system("pause") ;
                        break ;
                    }
                    }while(test == 1) ;

                break ;

            case 4 :
                exit(EXIT_SUCCESS) ;

            default :
                printf("Choix Incorrect.\n\n") ;
                system("pause") ;
        }
        system("cls") ;
    }while(1) ;

    return EXIT_SUCCESS ;
}
