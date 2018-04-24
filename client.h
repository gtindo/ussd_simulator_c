#ifndef CLIENT
#define CLIENT

//déclaration des fonctions
typedef struct Response Response ;
typedef struct CodeUSSD CodeUSSD ;
typedef struct Utilisateur Utilisateur ;

void valeurDeRetour(Response* reponse) ;
void modifCode(char* coddeIn, char *codeOut, int choix) ;

void lireChoix(char* codeIn, char* codeOut, int choix) ;

void navigation(Utilisateur* user, int* sortie) ;

#endif // CLIENT
