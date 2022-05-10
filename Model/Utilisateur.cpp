#include <iostream>
using namespace std;


//------------------------------------------------------ Include personnel
#include "Utilisateur.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Utilisateur::Utilisateur(String login, String motDePasse)
{
    this->identifiantUtilisateur = login;
    this->motDePasse = motDePasse;
    #ifdef MAP
        cout << "Appel au constructeur de <Utilisateur>" << endl;
    #endif
} 

Utilisateur::getLogin() const{
    return this->identifiantUtilisateur;
}



Utilisateur::~Utilisateur()
{
    #ifdef MAP
        cout << "Appel au destructeur de <Utilisateur>" << endl;
    #endif
} 

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
