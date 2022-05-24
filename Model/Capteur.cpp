/*************************************************************************
                           Capteur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Capteur> (fichier Capteur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Capteur.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
int Capteur::getIdCapteur() const
{
    return this->idCapteur;
}

float Capteur::getLatitudeCapteur() const
{
    return this->latitude;
}

void Capteur::setLatitudeCapteur(float lat)
{
    this->latitude = lat;
}

float Capteur::getLongitudeCapteur() const
{
    return this->longitude;
}

void Capteur::setLongitudeCapteur(float lon)
{
    this->longitude = lon;
}

//-------------------------------------------- Constructeurs - destructeur
Capteur::Capteur(int id, float lat, float lon)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Capteur>" << endl;
#endif
    this->idCapteur = id;
    this->latitude = lat;
    this->longitude = lon;
} //----- Fin de Capteur

Capteur::~Capteur()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Capteur>" << endl;
#endif
} //----- Fin de ~Capteur

bool Capteur::operator==(const Capteur &cap) const
{
    return (cap.idCapteur == idCapteur);
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
