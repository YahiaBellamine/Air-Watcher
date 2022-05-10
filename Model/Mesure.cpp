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

Mesure::Mesure(float valeur, string idAttribut)
// Algorithme :
//
{
    this->valeur = valeur;
    this->idAttribut = idAttribut;
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

float Mesure::getValeur()
{
    return valeur;
}

void Mesure::setValeur(float valeur)
{
    this->valeur = valeur;
}

string Mesure::getAttribut()
{
    return idAttribut;
}

void Mesure::setAttribut(string idAttribut)
{
    this->idAttribut = idAttribut;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
