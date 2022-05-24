#include <iostream>
using namespace std;


//------------------------------------------------------ Include personnel
#include "Utilisateur.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Utilisateur::Utilisateur(string login, string mdp)
{
    this->identifiantUtilisateur = login;
    this->motDePasse = mdp;
#ifdef MAP
    cout << "Appel au constructeur de <Xxx>" << endl;
#endif
}

string Utilisateur::getIdentifiantUtilisateur() const
{
    return this->identifiantUtilisateur;
}

string Utilisateur::getMotDePasse() const
{
    return this->motDePasse;
}

Utilisateur::~Utilisateur()
{
#ifdef MAP
    cout << "Appel au destructeur de <Xxx>" << endl;
#endif
} //----- Fin de ~Xxx

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
