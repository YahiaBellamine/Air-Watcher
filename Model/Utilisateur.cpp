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
    identifiantUtilisateur = login;
    motDePasse = mdp;
#ifdef MAP
    cout << "Appel au constructeur de <Xxx>" << endl;
#endif
}

string Utilisateur::getIdentifiantUtilisateur() const
{
    return identifiantUtilisateur;
}

string Utilisateur::getMotDePasse() const
{
    return motDePasse;
}

Utilisateur::~Utilisateur()
{
#ifdef MAP
    cout << "Appel au destructeur de <Xxx>" << endl;
#endif
} //----- Fin de ~Xxx

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
