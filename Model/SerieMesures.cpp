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
#include "SerieMesures.h"

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

SerieMesures::SerieMesures(/*Capteur capteur, dateSerieMesures date*/)
// Algorithme :
//
{
    listeMesures = new list<Mesure>;
#ifdef MAP
    cout << "Appel au constructeur de <Xxx>" << endl;
#endif
} //----- Fin de Xxx

SerieMesures::~SerieMesures()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Xxx>" << endl;
#endif
} //----- Fin de ~Xxx

bool SerieMesures::ajouterMesure(Mesure mesure)
{
    list<Mesure>::iterator it = listeMesures->begin();
    listeMesures->insert(it, mesure);
}

bool SerieMesures::atmo()
{
}

Mesure SerieMesures::getMesure(int index)
{
    list<Mesure>::iterator it = listeMesures->begin();
    advance(it, index);
    return *it;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
