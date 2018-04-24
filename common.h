#ifndef COMMON
#define COMMON

//Structures de données

typedef struct Response Response ;
typedef struct Utilisateur Utilisateur ;
typedef struct Credit Credit ;
typedef struct Forfait Forfait ;
typedef struct Date Date ;

struct Response
{
    char content[500] ; //contenu de la reponse de l'utilisqteur ou du programme
    int code ;  //code pouvqant etre extrait du coontent
};

struct Date //pour gerer les dates
{
    int seconde ;
    int minutes ;
    int heure ;
    int jour ;
    int mois ;
    int annee ;
} ;

struct Credit //pour gerer le credit
{
    float montant ; //montant du credit
    Date validite ; //date de validite du credit
};

struct Forfait //pour gerer les forfaits
{
    char type ; //Moi, Jour, Semaine
    char nature ; //SMS, Appel, Internet ;
    float montant ;//cout du forfait
    Date validite ;//date d'expiration
} ;


struct Utilisateur
{
    int codePuk ;
    int tel ;
    Credit creditUtilisateur ;
    Forfait forfaitSMS ;
    Forfait forfaitAppel ;
    Forfait forfaitInternet ;
};

void todayDate(Date* aDate) ; //cette fonction initialise la date aujour en cours

void initialiserForfait(Forfait* unForfait) ;//pour initialiser un forfait

float montantForfait(char type, char nature, char* description) ;//reourne le montant d'un forfait

void validiteMois(Date* aDate) ;//Ajoute un moi a la date

void validiteSemaine(Date* aDate) ;//ajoute une semaine a la date

void validiteJour(Date* aDate) ;//ajoute 1 jour a la date

void cpyUser(Utilisateur* userDest, Utilisateur* userMain ) ;//affecter userMain a userDest

void cpyForfait(Forfait* forfaitDest, Forfait* forfaitMain) ;//affecter forfaitDest a forfaitMain

void isTypeB(Response *reponse) ;//verifie si la reponse comporte un code, si c'est le cas l'extrait et sauvegarde le code

#endif
