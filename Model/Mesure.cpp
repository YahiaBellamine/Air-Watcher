/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Xxx> (fichier Xxx.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Mesure.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Xxx::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
// Xxx &Xxx::operator=(const Xxx &unXxx)
// Algorithme :
// //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
// Mesure::Mesure(const Xxx &unXxx)
// Algorithme :
// //----- Fin de Xxx (constructeur de copie)

Mesure::Mesure(float lavaleur, string lIdAttribut)
// Algorithme :
//
{
    valeur = lavaleur;
    idAttribut = lIdAttribut;
#ifdef MAP
    cout << "Appel au constructeur de <Mesure>" << endl;
#endif
} //----- Fin de Xxx

Mesure::Mesure()
// Algorithme :
//
{
    valeur = 0;
    idAttribut = "";
#ifdef MAP
    cout << "Appel au constructeur de <Mesure>" << endl;
#endif
} //----- Fin de Xxx

Mesure::~Mesure()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Mesure>" << endl;
#endif
} //----- Fin de ~Xxx

float Mesure::getValeur() const
{
    return valeur;
}

void Mesure::setValeur(float lavaleur)
{
    valeur = lavaleur;
}

string Mesure::getAttribut() const
{
    return idAttribut;
}

void Mesure::setAttribut(string lidAttribut)
{
    idAttribut = lidAttribut;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
