#ifndef CARTES
#define CARTES

typedef struct CartePrep CartePrep ;
//fonction pour generer une carte prepayee
void genererCarte(CartePrep* carte, float montant) ;
struct CartePrep
{
    float montant ;
    int code ;
    char etat ;
};

#endif // CARTES
