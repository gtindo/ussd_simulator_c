#ifndef SERVER
#define SERVER

typedef struct Response Response ;
typedef struct Utilisateur Utilisateur ;
typedef struct Forfait Forfait ;

int server_connect(Response* reponse) ;//retourne 1 si le code existe o sinon

//effectue une acction et ecrit le resultat dans reqResponse
//int req est le resultat de server_connect
void server_response(int req, int code, Response* reqResponse, Utilisateur* user) ;

int verifCodePuk(int codePuk) ;//verification d4un code puk

//initialise la structure utilisqteur
void co_user_init(Utilisateur* user, int codePuk) ;

//service affichage numero de telephone
void printTel(Response* reponse, Utilisateur* user) ;

//service affichage credit
void printCredit(Response* reponse, Utilisateur* user) ;

//service affichage du menu d'information
void printMenuInfo(Response* reponse) ;

//service affichage etat des comptes
void printEtatCompte(Response* reponse, Utilisateur* user) ;

//service afichage du choix de la nature du forfait
void printMenuForfait(Response* reponse) ;

//service affichage des types de forfaits internet
void printMenuForfaitInternet(Response* reponse) ;

//service affichage des types de forfaits SMS
void printMenuForfaitSMS(Response* reponse) ;

//service affichage des types de forfait d'appel
void printMenuForfaitAppel(Response* reponse) ;

//service affichage forfait intenet jour
void printForfaitInternetJour(Response* reponse) ;

//service affichage forfait SMS jour
void printForfaitSMSJour(Response* reponse) ;

//service affichage forfait Appel jour
void printForfaitAppelJour(Response* reponse) ;

//service affichage forfait intenet Semaine
void printForfaitInternetSemaine(Response* reponse) ;

//service affichage forfait SMS Semaine
void printForfaitSMSSemaine(Response* reponse) ;

//service affichage forfait Appels Semaine
void printForfaitAppelSemaine(Response* reponse) ;

//service affichage forfait intenet mois
void printForfaitInternetMois(Response* reponse) ;

//service affichage forfait SMS mois
void printForfaitSMSMois(Response* reponse) ;

//service affichage forfait Appel mois
void printForfaitAppelMois(Response* reponse) ;

//service achat d'un forfait
void achatForfait(Utilisateur* user, Forfait* newForfait, Response* testCredit) ;

//service achat de credit
void achatCredit(Utilisateur* user, int code, Response* reponse) ;



#endif // SERVER
