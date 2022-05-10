/*************************************************************************
                           Nettoyeur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Nettoyeur> (fichier Nettoyeur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Nettoyeur.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//-------------------------------------------- Constructeurs - destructeur
Nettoyeur::Nettoyeur ( const Nettoyeur & unXxx )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Nettoyeur>" << endl;
#endif
} //----- Fin de Nettoyeur (constructeur de copie)


Nettoyeur::Nettoyeur (int id, int lat, int lon, Temps tDeb, Temps tFin, Fournisseur * f)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Nettoyeur>" << endl;
#endif
    idNettoyeur = id;
    latitude = lat;
    longitude = lon;
    timeStart = tDeb;
    timeStop = tFin;
    fournisseur = f;
} //----- Fin de Nettoyeur


Nettoyeur::~Nettoyeur ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Nettoyeur>" << endl;
#endif
} //----- Fin de ~Nettoyeur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

