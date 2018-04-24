#include "server.h"
#include "codes.h"
#include "common.h"
#include "cartes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printTel(Response* reponse, Utilisateur* user)
{
    sprintf(reponse->content, "\nVotre numero : \t +237 %d\n\n0 - Quitter\n7777- Retour\n9999- Accueil\n", user->tel) ;
}

void printCredit(Response* reponse, Utilisateur* user)
{
    sprintf(reponse->content, "\nVotre credit est de %.2f valable jusqu au %d/%d/%d.\n\n0 - Quitter\n7777- Retour\n9999- Accueil\n", user->creditUtilisateur.montant, user->creditUtilisateur.validite.jour, user->creditUtilisateur.validite.mois, user->creditUtilisateur.validite.annee) ;
}

void printMenuInfo(Response* reponse)
{
    strcpy(reponse->content, "\n=== Informations sur mon compte ===\n\n1- Mon numero\n2- Mon credit\n3- Etat de mes forfaits\n\n0- Quitter\n\n") ;
}

//FONCTIONS ACHAT CREDIT

void printMenuForfait(Response* reponse)
{
    strcpy(reponse->content,"\n=== Achat d'un forfait ===\n\n1- Forfait internet\n2- Forfait SMS\n3- Forfait Appel\n\n0- Quitter.\n") ;
}

void printMenuForfaitInternet(Response* reponse)
{
    strcpy(reponse->content, "\n=== Forfaits Internet ===\n\n1- Jour\n2- Semaine\n3- Mois\n\n0- Quitter\n7777- Retour\n9999- Accueil.\n") ;
}

void printMenuForfaitSMS(Response* reponse)
{
    strcpy(reponse->content, "\n=== Forfaits SMS ===\n\n1- Jour\n2- Semaine\n3- Mois\n\n0- Quitter\n7777- Retour\n9999- Accueil.\n") ;
}

void printMenuForfaitAppel(Response* reponse)
{
    strcpy(reponse->content, "\n=== Forfaits Appel ===\n\n1- Jour\n2- Semaine\n3- Mois\n\n0- Quitter\n7777- Retour\n9999- Accueil.\n") ;
}

void printForfaitInternetJour(Response* reponse)
{
    Date validite ;
    char description[250] ;
    todayDate(&validite) ;

    float montant = montantForfait('J', 'I', description) ;

    validiteJour(&validite) ;
    reponse->content[0] = '\0' ;
    sprintf(reponse->content, "\nVous allez sourscrire au forfait internet illimite\nvalide jusqu'au %d/%d/%d a %d:%d:%d. \nCela vous coutera : %.2f FCFA\n\n1- Valider\n\n0- Quitter\n7777- retour\n9999- Accueil\n\n", validite.jour, validite.mois, validite.annee, validite.heure, validite.minutes, validite.seconde, montant) ;
}

void printForfaitSMSJour(Response* reponse)
{
    Date validite ;
    char description[250] ;
    todayDate(&validite) ;

    float montant = montantForfait('J', 'S', description) ;
    validiteJour(&validite) ;

    sprintf(reponse->content, "\nVous allez sourscrire au forfait SMS illimite\nvalide jusqu'au %d/%d/%d a %d:%d:%d. \nCela vous coutera : %.2f FCFA\n\n1- Valider\n\n0- Quitter\n7777- retour\n9999- Accueil\n\n", validite.jour, validite.mois, validite.annee, validite.heure, validite.minutes, validite.seconde, montant) ;
}

void printForfaitAppelJour(Response* reponse)
{
    Date validite ;
    char description[250] ;
    todayDate(&validite) ;

    float montant = montantForfait('J', 'A', description) ;
    validiteJour(&validite) ;

    sprintf(reponse->content, "\nVous allez sourscrire au forfait d'appels illimite\nvalide jusqu'au %d/%d/%d a %d:%d:%d.\nCela vous coutera : %.2f FCFA\n\n1- Valider\n0- Quitter\n7777- retour\n9999- Accueil\n\n", validite.jour, validite.mois, validite.annee, validite.heure, validite.minutes, validite.seconde, montant) ;
}

void printForfaitInternetSemaine(Response* reponse)
{
    Date validite ;
    char description[250] ;
    todayDate(&validite) ;

    float montant = montantForfait('S', 'I', description) ;

    validiteSemaine(&validite) ;

    sprintf(reponse->content, "\nVous allez sourscrire au forfait internet illimite\nvalide jusqu'au %d/%d/%d a %d:%d:%d.\nCela vous coutera : %.2f FCFA\n\n1- Valider\n0- Quitter\n7777- retour\n9999- Accueil", validite.jour, validite.mois, validite.annee, validite.heure, validite.minutes, validite.seconde, montant) ;
}

void printForfaitSMSSemaine(Response* reponse)
{
    Date validite ;
    char description[250] ;
    todayDate(&validite) ;

    float montant = montantForfait('S', 'S', description) ;
    validiteSemaine(&validite) ;

    sprintf(reponse->content, "\nVous allez sourscrire au forfait SMS illimite\nvalide jusqu'au %d/%d/%d a %d:%d:%d.\nCela vous coutera : %.2f FCFA\n\n1- Valider\n0- Quitter\n7777- retour\n9999- Accueil", validite.jour, validite.mois, validite.annee, validite.heure, validite.minutes, validite.seconde, montant) ;
}

void printForfaitAppelSemaine(Response* reponse)
{
    Date validite ;
    char description[250] ;
    todayDate(&validite) ;

    float montant = montantForfait('S', 'A', description) ;
    validiteSemaine(&validite) ;

    sprintf(reponse->content, "\nVous allez sourscrire au forfait d'appels illimite\nvalide jusqu'au %d/%d/%d a %d:%d:%d.\nCela vous coutera : %.2f FCFA\n\n1- Valider\n0- Quitter\n7777- retour\n9999- Accueil", validite.jour, validite.mois, validite.annee, validite.heure, validite.minutes, validite.seconde, montant) ;
}

void printForfaitInternetMois(Response* reponse)
{
    Date validite ;
    char description[250] ;
    todayDate(&validite) ;

    float montant = montantForfait('M', 'I', description) ;

    validiteMois(&validite) ;

    sprintf(reponse->content, "\nVous allez sourscrire au forfait internet illimite\nvalide jusqu'au %d/%d/%d a %d:%d:%d.\nCela vous coutera : %.2f FCFA\n\n1- Valider\n0- Quitter\n7777- retour\n9999- Accueil", validite.jour, validite.mois, validite.annee, validite.heure, validite.minutes, validite.seconde, montant) ;
}

void printForfaitSMSMois(Response* reponse)
{
    Date validite ;
    char description[250] ;
    todayDate(&validite) ;

    float montant = montantForfait('M', 'S', description) ;
    validiteMois(&validite) ;

    sprintf(reponse->content, "\nVous allez sourscrire au forfait SMS illimite\nvalide jusqu'au %d/%d/%d a %d:%d:%d.\nCela vous coutera : %.2f FCFA\n\n1- Valider\n0- Quitter\n7777- retour\n9999- Accueil", validite.jour, validite.mois, validite.annee, validite.heure, validite.minutes, validite.seconde, montant) ;
}

void printForfaitAppelMois(Response* reponse)
{
    Date validite ;
    char description[250] ;
    todayDate(&validite) ;

    float montant = montantForfait('M', 'A', description) ;
    validiteMois(&validite) ;

    sprintf(reponse->content, "\nVous allez sourscrire au forfait d'appels illimite\nvalide jusqu'au %d/%d/%d a %d:%d:%d.\nCela vous coutera : %.2f FCFA\n\n1- Valider\n0- Quitter\n7777- retour\n9999- Accueil", validite.jour, validite.mois, validite.annee, validite.heure, validite.minutes, validite.seconde, montant) ;
}

//dfdfdfdfdfdfdfdfdfdfdfdfdfdfdfvd

void printEtatCompte(Response* reponse, Utilisateur* user)
{
    char chaineAppel[100], chaineSMS[100], chaineInternet[100] ;
    float montantAppel, montantSMS, montantInternet ;

    printf("\n\n%c %c\n\n", user->forfaitInternet.type, user->forfaitInternet.nature) ;
    montantAppel = montantForfait(user->forfaitAppel.type, user->forfaitAppel.nature, chaineAppel) ;
    montantSMS = montantForfait(user->forfaitSMS.type, user->forfaitSMS.nature, chaineSMS) ;
    montantInternet = montantForfait(user->forfaitInternet.type, user->forfaitInternet.nature, chaineInternet) ;

    sprintf(reponse->content,"\n=== Appel ===\n%s, montant : %.2f.\n\n=== SMS ===\n%s, montant : %.2f.\n\n=== Internet ===\n%s, montant : %.2f.\n\n0- Quitter.\n7777- Retour\n9999- Accueil\n", chaineAppel, montantAppel, chaineSMS, montantSMS, chaineInternet, montantInternet) ;
}

void achatForfait(Utilisateur* user, Forfait* newForfait, Response* testCredit)
{
    int testUnites = 0 ;
    FILE* fichier = NULL ;
    Utilisateur userTest ;
    fichier = fopen("userList.usd", "rb+") ;

    if(fichier == NULL)
    {
        exit(EXIT_FAILURE) ;
    }

    while(fread(&userTest, sizeof(Utilisateur), 1, fichier), !feof(fichier))
    {
        if(user->codePuk == userTest.codePuk && userTest.creditUtilisateur.montant >= newForfait->montant)
        {
            testUnites = 1 ;
            switch(newForfait->nature)
            {
                case 'A' :
                    cpyForfait(&(user->forfaitAppel), newForfait) ;
                    user->creditUtilisateur.montant -= newForfait->montant ;
                    break ;

                case 'I' :
                    cpyForfait(&(user->forfaitInternet), newForfait) ;
                    user->creditUtilisateur.montant -= newForfait->montant ;
                    break ;

                case 'S' :
                    cpyForfait(&(user->forfaitSMS), newForfait) ;
                    user->creditUtilisateur.montant -= newForfait->montant ;
                    break ;

                default :
                    exit(EXIT_FAILURE) ;
            }

            fseek(fichier, -sizeof(Utilisateur), SEEK_CUR) ;
            fwrite(user, sizeof(Utilisateur), 1, fichier) ;
            printf("%c", user->forfaitInternet.nature) ;

            break ;
        }

    }

    fclose(fichier) ;

    if(testUnites == 0)
    {
        strcpy(testCredit->content, "Vous n'avez pas assez de credit pour effectuer cette operation.") ;
    }
    else
    {
        strcpy(testCredit->content, ".") ;
    }
}

void achatCredit(Utilisateur* user, int code, Response* reponse)
{
    FILE* fichier1 = NULL ;
    FILE* fichier2 = NULL ;
    int testExistence = 0 ;
    CartePrep theCard ;
    Utilisateur userTest ;

    fichier1 = fopen("cartesList.usd", "rb+") ;

    if(fichier1 == NULL)
    {
        exit(EXIT_FAILURE) ;
    }

    while(fread(&theCard, sizeof(CartePrep), 1, fichier1), !feof(fichier1))
    {
        if(theCard.code == code)
        {
            testExistence = 1 ;
            if(theCard.etat == 'I')
            {
                sprintf(reponse->content, "\nLe code %d a deja ete utilise.\n\n0 - Quitter\n", code) ;
            }
            else
            {
                sprintf(reponse->content, "\nVous avez Ajoute %1.f FCFA a votre credit.\n0 - Quitter\n", theCard.montant) ;
                theCard.etat = 'I' ;
                fseek(fichier1, -sizeof(CartePrep), SEEK_CUR) ;
                fwrite(&theCard, sizeof(CartePrep), 1, fichier1) ;

                fichier2 = fopen("userList.usd", "rb+") ;

                if(fichier2 == NULL)
                {
                    exit(EXIT_FAILURE) ;
                }

                while(fread(&userTest, sizeof(Utilisateur), 1, fichier2), !feof(fichier2))
                {
                    if(userTest.codePuk == user->codePuk)
                    {
                        user->creditUtilisateur.montant += theCard.montant ;

                        user->creditUtilisateur.validite.mois += 6 ;

                        if(user->creditUtilisateur.validite.mois > 12)
                        {
                            user->creditUtilisateur.validite.annee += 1 ;
                            user->creditUtilisateur.validite.mois = 12 - userTest.creditUtilisateur.validite.mois ;
                        }

                        fseek(fichier2, -sizeof(Utilisateur), SEEK_CUR) ;
                        fwrite(user, sizeof(Utilisateur), 1, fichier2) ;

                        break ;
                    }

                }

                fclose(fichier2) ;
            }
            break ;
        }
    }

    if(testExistence == 0)
    {
        sprintf(reponse->content, "\nLe code %d entre est incorrect.\n0 - Quitter.\n", code) ;
    }

    fclose(fichier1) ;

}

int server_connect(Response* reponse)
{
    int test = issetCode(reponse->content) ;
    return test ;
}

void server_response(int req, int code, Response* reqResponse, Utilisateur* user)
{
    Forfait newForfait ;
    char descriptionForfait[250] ;
    Response testCredit ;

    switch(req)
    {
        case 1 :
            printMenuInfo(reqResponse) ; //#104# 1 3 1
            break ;

        case 2 :
            printTel(reqResponse, user) ; //#104*1# 2 0 0
            break ;

        case 3 :
            printCredit(reqResponse, user) ; //#104*2# 3 0 0
            break ;

        case 4 :
            printEtatCompte(reqResponse, user) ; //#104*3# 4 0 0
            break ;

        case 5 :             //#102# 5 3 1
            printMenuForfait(reqResponse) ;
            break ;

        case 6 :            //#102*1# 6 3 0
            printMenuForfaitInternet(reqResponse) ;
            break ;

        case 7 :            //#102*2# 7 3 0
            printMenuForfaitSMS(reqResponse) ;
            break ;

        case 8 :            //#102*3# 8 3 0
            printMenuForfaitAppel(reqResponse) ;
            break ;

        case 9 :            //#102*1*1# 9 1 0
            printForfaitInternetJour(reqResponse) ;
            break ;

        case 10 :           //#102*1*2# 10 1 0
            printForfaitInternetSemaine(reqResponse) ;
            break ;

        case 11 :           //#102*1*3# 11 1 0
            printForfaitInternetMois(reqResponse) ;
            break ;

        case 12 :           //#102*2*1# 12 1 0
            printForfaitSMSJour(reqResponse) ;
            break ;

        case 13 :           //#102*2*2# 13 1 0
            printForfaitSMSSemaine(reqResponse) ;
            break ;

        case 14 :           //#102*2*3# 14 1 0
            printForfaitSMSMois(reqResponse) ;
            break ;

        case 15 :           //#102*3*1# 15 1 0
            printForfaitAppelJour(reqResponse) ;
            break ;

        case 16 :           //#102*3*2# 16 1 0
            printForfaitAppelSemaine(reqResponse) ;
            break ;

        case 17 :           //#102*3*3# 17 1 0
            printForfaitAppelMois(reqResponse) ;
            break ;

        case 18 :          //#102*1*1*1# 18 0 1
            initialiserForfait(&(newForfait)) ;
            newForfait.nature = 'I' ;
            newForfait.type = 'J' ;
            newForfait.montant = montantForfait(newForfait.type, newForfait.nature, descriptionForfait) ;

            achatForfait(user, &newForfait, &testCredit) ;

            if(strcmp(testCredit.content, ".") == 0)
            {
                sprintf(reqResponse->content,"%s \n\n 0- Quitter\n\n", descriptionForfait) ;
            }
            else
            {
                sprintf(reqResponse->content,"%s \n\n 0- Quitter\n\n", testCredit.content) ;
            }
            break ;

        case 19 :          //#102*1*2*1# 19 0 1
            initialiserForfait(&(newForfait)) ;
            newForfait.nature = 'I' ;
            newForfait.type = 'S' ;
            newForfait.montant = montantForfait(newForfait.type, newForfait.nature, descriptionForfait) ;

            achatForfait(user, &newForfait, &testCredit) ;

            if(strcmp(testCredit.content, ".") == 0)
            {
                sprintf(reqResponse->content,"%s \n\n 0- Quitter\n\n", descriptionForfait) ;
            }
            else
            {
                sprintf(reqResponse->content,"%s \n\n 0- Quitter\n\n", testCredit.content) ;
            }
            break ;

        case 20 :          //#102*1*3*1# 20 0 1
            initialiserForfait(&(newForfait)) ;
            newForfait.nature = 'I' ;
            newForfait.type = 'M' ;
            newForfait.montant = montantForfait(newForfait.type, newForfait.nature, descriptionForfait) ;

            achatForfait(user, &newForfait, &testCredit) ;

            if(strcmp(testCredit.content, ".") == 0)
            {
                sprintf(reqResponse->content,"%s \n\n 0- Quitter\n\n", descriptionForfait) ;
            }
            else
            {
                sprintf(reqResponse->content,"%s \n\n 0- Quitter\n\n", testCredit.content) ;
            }
            break ;

        case 21 :          //#102*2*1*1# 21 0 1
            initialiserForfait(&(newForfait)) ;
            newForfait.nature = 'S' ;
            newForfait.type = 'J' ;
            newForfait.montant = montantForfait(newForfait.type, newForfait.nature, descriptionForfait) ;

            achatForfait(user, &newForfait, &testCredit) ;

            if(strcmp(testCredit.content, ".") == 0)
            {
                sprintf(reqResponse->content,"%s \n\n 0- Quitter\n\n", descriptionForfait) ;
            }
            else
            {
                sprintf(reqResponse->content,"%s \n\n 0- Quitter\n\n", testCredit.content) ;
            }
            break ;

        case 22 :          //#102*2*2*1# 22 0 1
            initialiserForfait(&(newForfait)) ;
            newForfait.nature = 'S' ;
            newForfait.type = 'S' ;
            newForfait.montant = montantForfait(newForfait.type, newForfait.nature, descriptionForfait) ;

            achatForfait(user, &newForfait, &testCredit) ;

            if(strcmp(testCredit.content, ".") == 0)
            {
                sprintf(reqResponse->content,"%s \n\n 0- Quitter\n\n", descriptionForfait) ;
            }
            else
            {
                sprintf(reqResponse->content,"%s \n\n 0- Quitter\n\n", testCredit.content) ;
            }
            break ;

        case 23 :          //#102*2*3*1# 23 0 1
            initialiserForfait(&(newForfait)) ;
            newForfait.nature = 'S' ;
            newForfait.type = 'M' ;
            newForfait.montant = montantForfait(newForfait.type, newForfait.nature, descriptionForfait) ;

            achatForfait(user, &newForfait, &testCredit) ;

            if(strcmp(testCredit.content, ".") == 0)
            {
                sprintf(reqResponse->content,"%s \n\n 0- Quitter\n\n", descriptionForfait) ;
            }
            else
            {
                sprintf(reqResponse->content,"%s \n\n 0- Quitter\n\n", testCredit.content) ;
            }
            break ;

        case 24 :          //#102*3*1*1# 24 0 1
            initialiserForfait(&(newForfait)) ;
            newForfait.nature = 'A' ;
            newForfait.type = 'J' ;
            newForfait.montant = montantForfait(newForfait.type, newForfait.nature, descriptionForfait) ;

            achatForfait(user, &newForfait, &testCredit) ;

            if(strcmp(testCredit.content, ".") == 0)
            {
                sprintf(reqResponse->content,"%s \n\n 0- Quitter\n\n", descriptionForfait) ;
            }
            else
            {
                sprintf(reqResponse->content,"%s \n\n 0- Quitter\n\n", testCredit.content) ;
            }
            break ;

        case 25 :          //#102*3*2*1# 25 0 1
            initialiserForfait(&(newForfait)) ;
            newForfait.nature = 'A' ;
            newForfait.type = 'S' ;
            newForfait.montant = montantForfait(newForfait.type, newForfait.nature, descriptionForfait) ;

            achatForfait(user, &newForfait, &testCredit) ;

            if(strcmp(testCredit.content, ".") == 0)
            {
                sprintf(reqResponse->content,"%s \n\n 0- Quitter\n\n", descriptionForfait) ;
            }
            else
            {
                sprintf(reqResponse->content,"%s \n\n 0- Quitter\n\n", testCredit.content) ;
            }
            break ;

        case 26 :          //#102*3*3*1# 26 0 1
            initialiserForfait(&(newForfait)) ;
            newForfait.nature = 'A' ;
            newForfait.type = 'M' ;
            newForfait.montant = montantForfait(newForfait.type, newForfait.nature, descriptionForfait) ;

            achatForfait(user, &newForfait, &testCredit) ;

            if(strcmp(testCredit.content, ".") == 0)
            {
                sprintf(reqResponse->content,"%s \n\n 0- Quitter\n\n", descriptionForfait) ;
            }
            else
            {
                sprintf(reqResponse->content,"%s \n\n 0- Quitter\n\n", testCredit.content) ;
            }
            break ;

        case 27 :         //#103# 27 0 1
            achatCredit(user, code , reqResponse) ;
            break ;
        default  :
            exit(EXIT_FAILURE) ;
    }
}

int verifCodePuk(int codePuk)
{
    FILE* fichier = NULL ;
    Utilisateur user ;
    int testExistence = 0;
    fichier = fopen("userList.usd", "rb") ;

    if(fichier == NULL)
    {
        exit(EXIT_FAILURE) ;
    }

    while(fread(&user, sizeof(Utilisateur), 1, fichier), !feof(fichier))
    {
        if(codePuk == user.codePuk)
        {
            testExistence = 1 ;
            break ;
        }
    }

    fclose(fichier) ;

    return testExistence ;
}

void co_user_init(Utilisateur* user, int codePuk)
{
    Utilisateur userTest ;
    FILE* fichier = NULL ;

    fichier = fopen("userList.usd", "rb") ;

    if(fichier == NULL)
    {
        exit(EXIT_FAILURE) ;
    }

    while(fread(&userTest, sizeof(Utilisateur), 1, fichier))
    {
        if(userTest.codePuk == codePuk)
        {
            cpyUser(user, &userTest) ;
            break ;
        }
    }

    fclose(fichier) ;
}


