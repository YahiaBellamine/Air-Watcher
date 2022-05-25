/*************************************************************************
                           AgenceGouvernementale  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <AgenceGouvernementale> (fichier AgenceGouvernementale.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>
#include <vector>
#include <list>
using namespace std;
//------------------------------------------------------ Include personnel
#include "AgenceGouvernementale.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool AgenceGouvernementale::ajouterCapteur(Capteur capteur)
// Algorithme :
//
{
    bool added = false;
    int sizeBeforeAdd = listeCapteurs.size();
    listeCapteurs.push_back(capteur);
    int sizeAfterAdd = listeCapteurs.size();
    if (sizeAfterAdd == sizeBeforeAdd + 1)
    {
        added = true;
    }
    return added;
} //----- Fin de Méthode

vector<Capteur> AgenceGouvernementale::getListeCapteurs() const
// Algorithme :
//
{
    return listeCapteurs;
} //----- Fin de Méthode

//-------------------------------------------- Constructeurs - destructeur
AgenceGouvernementale::AgenceGouvernementale(string login, string mdp) : Utilisateur(login, mdp)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <AgenceGouvernementale>" << endl;
#endif
} //----- Fin de AgenceGouvernementale

AgenceGouvernementale::~AgenceGouvernementale()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <AgenceGouvernementale>" << endl;
#endif
} //----- Fin de ~AgenceGouvernementale

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
