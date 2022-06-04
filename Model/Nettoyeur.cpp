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
#include "Fournisseur.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
string Nettoyeur::getIdNettoyeur()
{
    return this->idNettoyeur;
}

float Nettoyeur::getLatitude()
{
    return this->latitude;
}

float Nettoyeur::getLongitude()
{
    return this->longitude;
}

Temps Nettoyeur::getTimeStart()
{
    return this->timeStart;
}

Temps Nettoyeur::getTimeStop()
{
    return this->timeStop;
}

//-------------------------------------------- Constructeurs - destructeur
Nettoyeur::Nettoyeur(string id, float lat, float lon, Temps tDeb, Temps tFin, Fournisseur *f)
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

Nettoyeur::Nettoyeur(string id, float lat, float lon, Temps tDeb, Temps tFin)
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
    this->fournisseur = nullptr;
} //----- Fin de Nettoyeur

Nettoyeur::~Nettoyeur()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Nettoyeur>" << endl;
#endif
} //----- Fin de ~Nettoyeur

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
