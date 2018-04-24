#ifndef CODES
#define CODES

typedef struct CodeUSSD CodeUSSD ;
typedef struct Response Response ;

struct CodeUSSD
{
    char code[500] ;
    int id ;
    int nbMenus ;
    int isFirstMenu ; // vaut 0 ou 1
} ;


int issetCode(char* theCode) ;
int verifyCode(CodeUSSD* theCode) ;
void addCode(CodeUSSD* theCode) ;
void initCodeUSSD(Response* reponse, CodeUSSD* codeEnCours) ;

#endif // CODES
