/*************************************************************************
                           Fournisseur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Fournisseur> (fichier Fournisseur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel

#include "Fournisseur.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool Fournisseur::ajouterNettoyeur(Nettoyeur nettoyeur)
// Algorithme :
//
{
    bool added = false;
    int sizeBeforeAdd = listeNettoyeur.size();
    listeNettoyeur.push_back(nettoyeur);
    int sizeAfterAdd = listeNettoyeur.size();
    if (sizeAfterAdd == sizeBeforeAdd + 1)
    {
        added = true;
    }
    return added;
} //----- Fin de Méthode

vector<Nettoyeur> Fournisseur::getListeNettoyeurs() const
// Algorithme :
//
{
    return listeNettoyeur;
} //----- Fin de Méthode

//-------------------------------------------- Constructeurs - destructeur
Fournisseur::Fournisseur(string login, string mdp) : Utilisateur(login, mdp)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Fournisseur>" << endl;
#endif
} //----- Fin de Fournisseur

Fournisseur::Fournisseur(string id)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Fournisseur>" << endl;
#endif
    idFournisseur = id;
} //----- Fin de Fournisseur

Fournisseur::~Fournisseur()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Fournisseur>" << endl;
#endif
} //----- Fin de ~Fournisseur

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
