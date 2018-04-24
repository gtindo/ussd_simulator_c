#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codes.h"
#include "common.h"

int issetCode(char* theCode) //vérification de l'existence du codeUSSD
{
    CodeUSSD codeTest ;
    int testExistence = 0 ;
    FILE* fichier = NULL ;
    fichier = fopen("codeList.usd", "rb") ;

    if(fichier == NULL)
    {
        exit(EXIT_FAILURE) ;
    }

    while(fread(&codeTest, sizeof(CodeUSSD), 1, fichier), !feof(fichier))
    {
        if(strcmp(codeTest.code, theCode) == 0)
        {
            testExistence = codeTest.id ;
            break ;
        }
    }

    fclose(fichier) ;

    return testExistence ; // égale à 0 si le code en paramètre est incorrect
}

void addCode(CodeUSSD* theCode) //ajout d'un codeUSSD
{
    int test = 1 ;
    CodeUSSD codeTest ;
    FILE* fichier = NULL ;

    fichier = fopen("codeList.usd", "rb") ;
    if(fichier == NULL)
    {
        exit(EXIT_FAILURE) ;
    }

    while(fread(&codeTest, sizeof(CodeUSSD), 1, fichier), !feof(fichier))
    {
        if(theCode->id == codeTest.id)
        {
            test = 0 ;
            break ;
        }
    }
    fclose(fichier) ;

    fichier = fopen("codeList.usd", "ab") ;

    if(fichier == NULL)
    {
        exit(EXIT_FAILURE) ;
    }

    if(!issetCode(theCode->code))
    {
        if(verifyCode(theCode))
        {
            if(test == 1)
            {
                fwrite(theCode, sizeof(CodeUSSD), 1, fichier) ;
            }
            else
            {
                printf("Cet ID a déjà été entré\n\n") ;
            }
        }
        else
        {
            printf("Le code est incorrect.\n\n") ;
        }
    }
    else
    {
        printf("%d", test)  ;
        printf("Ce code a déja été entré\n\n") ;

    }

    fclose(fichier) ;
}

int verifyCode(CodeUSSD* theCode)
{
    int n = strlen(theCode->code) ;
    int test = 1 ;

    if((theCode->code)[0] != '#')
    {
        test = 0 ;
    }

    if((theCode->code)[n-1] != '#')
    {
        test = 0 ;
    }

    return test ; // &gale à 0 si le code en paramètre n'est pas valide
}

void initCodeUSSD(Response* reponse, CodeUSSD* codeEnCours)
{
    FILE* fichier = NULL ;
    CodeUSSD codeTest ;

    fichier = fopen("codeList.usd", "rb") ;

    if(fichier == NULL)
    {
        exit(EXIT_FAILURE) ;
    }

    while(fread(&codeTest, sizeof(CodeUSSD), 1, fichier), !feof(fichier))
    {
        if(strcmp(reponse->content, codeTest.code) == 0)
        {
            codeEnCours->id = codeTest.id ;
            codeEnCours->isFirstMenu = codeTest.isFirstMenu ;
            codeEnCours->nbMenus = codeTest.nbMenus ;
            strcpy(codeEnCours->code, codeTest.code) ;
            break ;
        }
    }

    fclose(fichier) ;
}
