#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "common.h"

void todayDate(Date* aDate)
{
    time_t secondes;
    time_t t1 = time(NULL) ;
    struct tm instant;

    time(&secondes);
    instant=*localtime(&secondes);

    aDate->jour = instant.tm_mday ;
    aDate->mois = instant.tm_mon+1 ;
    aDate->heure = instant.tm_hour ;
    aDate->minutes = instant.tm_min ;
    aDate->seconde = instant.tm_sec ;
    aDate->annee = 1970 + (t1 / 31536000) ;

    // une année a 365 * 24 * 60 * 60 = 31536000 secondes
}

void validiteJour(Date* aDate)
{
    if(aDate->jour <= 30)
    {
        aDate->jour += 1 ;
    }
    else
    {
        aDate->mois += 1 ;

        if(aDate->mois > 12)
        {
            aDate->annee += 1 ;
            aDate->mois = 1 ;
        }
    }
}

void validiteSemaine(Date* aDate)
{
    if(aDate->jour <= 23)
    {
        aDate->jour += 7 ;
    }
    else
    {
        aDate->jour = 7 - (30 - aDate->jour) ;
        if(aDate->mois > 12)
        {
            aDate->annee += 1 ;
            aDate->mois = 1 ;
        }
    }
}

void validiteMois(Date* aDate)
{
    aDate->mois += 1 ;

        if(aDate->mois > 12)
        {
            aDate->annee += 1 ;
            aDate->mois = 1 ;
        }
}

void initialiserForfait(Forfait* unForfait)
{
    unForfait->montant = 0 ;
    unForfait->nature ='N' ;
    unForfait->type = 'N' ;
    todayDate(&(unForfait->validite)) ;
}

float montantForfait(char type, char nature, char* description)
{
    float montant = 0 ;
    switch(nature)
    {
        case 'A' :  //appel
            switch(type)
            {
                case 'J' :
                    strcpy(description, "Vous avez souscrit au forfait Appel journalier illimite ") ;
                    montant = 500 ;
                    break ;

                case 'S' :
                    strcpy(description, "Vous avez souscrit au forfait Appel une semaine illimite ") ;
                    montant = 3000 ;
                    break ;

                case 'M' :
                    strcpy(description, "Vous avez souscrit au forfait Appel Mensuel illimite ") ;
                    montant = 10000 ;
                    break ;
            }
            break ;

        case 'S' :  //sms
            switch(type)
            {
                case 'J' :
                    strcpy(description, "Vous avez souscrit au forfait SMS journalier illimite ") ;
                    montant = 100 ;
                    break ;

                case 'S' :
                    strcpy(description, "Vous avez souscrit au forfait SMS une semaine illimite ") ;
                    montant = 250 ;
                    break ;

                case 'M' :
                    strcpy(description, "Vous avez souscrit au forfait SMS Mensuel illimite ") ;
                    montant = 500 ;
                    break ;
            }
            break ;

        case 'I' : //Inernet
            switch(type)
            {
                case 'J' :
                    strcpy(description, "Vous avez souscrit au forfait Internet journalier illimite ") ;
                    montant = 450 ;
                    break ;

                case 'S' :
                    strcpy(description, "Vous avez souscrit au forfait Internet une semaine illimite ") ;
                    montant = 4000 ;
                    break ;

                case 'M' :
                    strcpy(description, "Vous avez souscrit au forfait Internet Mensuel illimite ") ;
                    montant = 15000 ;
                    break ;
            }
            break ;

        default :
            strcpy(description, "Vous n'avez pas souscrit a un forfait.") ;
    }

    return montant ;
}

void cpyForfait(Forfait* forfaitDest, Forfait* forfaitMain)
{
    forfaitDest->montant = forfaitMain->montant ;
    forfaitDest->nature = forfaitMain->nature ;
    forfaitDest->type = forfaitMain->type ;
    forfaitDest->validite.annee = forfaitMain->validite.annee ;
    forfaitDest->validite.mois = forfaitMain->validite.mois ;
    forfaitDest->validite.jour = forfaitMain->validite.jour ;
    forfaitDest->validite.heure = forfaitMain->validite.heure ;
    forfaitDest->validite.minutes = forfaitMain->validite.minutes ;
    forfaitDest->validite.seconde = forfaitMain->validite.seconde ;
}

void cpyUser(Utilisateur* userDest, Utilisateur* userMain )
{
    userDest->tel = userMain->tel ;
    userDest->codePuk = userMain->codePuk ;

    userDest->creditUtilisateur.montant = userMain->creditUtilisateur.montant ;
    userDest->creditUtilisateur.validite.annee = userMain->creditUtilisateur.validite.annee ;
    userDest->creditUtilisateur.validite.mois = userMain->creditUtilisateur.validite.mois ;
    userDest->creditUtilisateur.validite.jour = userMain->creditUtilisateur.validite.jour ;
    userDest->creditUtilisateur.validite.heure = userMain->creditUtilisateur.validite.heure ;
    userDest->creditUtilisateur.validite.minutes = userMain->creditUtilisateur.validite.minutes ;
    userDest->creditUtilisateur.validite.minutes = userMain->creditUtilisateur.validite.seconde ;

    userDest->forfaitAppel.montant = userMain->forfaitAppel.montant ;
    userDest->forfaitAppel.nature = userMain->forfaitAppel.nature ;
    userDest->forfaitAppel.type = userMain->forfaitAppel.type ;

    userDest->forfaitSMS.montant = userMain->forfaitSMS.montant ;
    userDest->forfaitSMS.nature = userMain->forfaitSMS.nature ;
    userDest->forfaitSMS.type = userMain->forfaitSMS.type ;

    userDest->forfaitInternet.montant = userMain->forfaitInternet.montant ;
    userDest->forfaitInternet.nature = userMain->forfaitInternet.nature ;
    userDest->forfaitInternet.type = userMain->forfaitInternet.type ;

    userDest->forfaitAppel.validite.annee = userMain->forfaitAppel.validite.annee ;
    userDest->forfaitAppel.validite.mois = userMain->forfaitAppel.validite.mois ;
    userDest->forfaitAppel.validite.jour = userMain->forfaitAppel.validite.jour ;
    userDest->forfaitAppel.validite.heure = userMain->forfaitAppel.validite.heure ;
    userDest->forfaitAppel.validite.minutes = userMain->forfaitAppel.validite.minutes ;
    userDest->forfaitAppel.validite.seconde = userMain->forfaitAppel.validite.seconde ;

    userDest->forfaitSMS.validite.annee = userMain->forfaitSMS.validite.annee ;
    userDest->forfaitSMS.validite.mois = userMain->forfaitSMS.validite.mois ;
    userDest->forfaitSMS.validite.jour = userMain->forfaitSMS.validite.jour ;
    userDest->forfaitSMS.validite.heure = userMain->forfaitSMS.validite.heure ;
    userDest->forfaitSMS.validite.minutes = userMain->forfaitSMS.validite.minutes ;
    userDest->forfaitSMS.validite.seconde = userMain->forfaitSMS.validite.seconde ;

    userDest->forfaitInternet.validite.annee = userMain->forfaitInternet.validite.annee ;
    userDest->forfaitInternet.validite.mois = userMain->forfaitInternet.validite.mois ;
    userDest->forfaitInternet.validite.jour = userMain->forfaitInternet.validite.jour ;
    userDest->forfaitInternet.validite.heure = userMain->forfaitInternet.validite.heure ;
    userDest->forfaitInternet.validite.minutes = userMain->forfaitInternet.validite.minutes ;
    userDest->forfaitInternet.validite.seconde = userMain->forfaitInternet.validite.seconde ;
}

void isTypeB(Response *reponse)
{
    int n2 = 0 ;
    int n1 = 0 ;
    sscanf(reponse->content, "#%d*%d#",&n1, &n2) ;

    if(n2 != 0  && n1 == 103)
    {
        strcpy(reponse->content, "#103#") ;
        reponse->code = n2 ;
    }
    else
    {
        reponse->code = 0 ;
    }
}
