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
Nettoyeur::Nettoyeur (int id, float lat, float lon, Temps tDeb, Temps tFin, Fournisseur * f)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Nettoyeur>" << endl;
#endif
    this->idNettoyeur = id;
    this->latitude = lat;
    this->longitude = lon;
    this->timeStart = tDeb;
    this->timeStop = tFin;
    this->fournisseur = f;
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
