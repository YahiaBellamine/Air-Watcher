
#if ! defined ( UTILISATEUR_H )
#define UTILISATEUR_H
using namespace std;
//--------------------------------------------------- Interfaces utilisées
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------

class  Utilisateur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Utilisateur (String login, String motDePasse);
    virtual ~Utilisateur ();
//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    String identifiantUtilisateur;
    String motDePasse;

};


#endif 

