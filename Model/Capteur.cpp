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
string Capteur::getIdCapteur() const
{
    return idCapteur;
}

float Capteur::getLatitudeCapteur() const
{
    return latitude;
}

void Capteur::setLatitudeCapteur(float lat)
{
    latitude = lat;
}

float Capteur::getLongitudeCapteur() const
{
    return longitude;
}

void Capteur::setLongitudeCapteur(float lon)
{
    longitude = lon;
}

vector<SerieMesures> &Capteur::getSeriesMesures()
{
    return seriesMesures;
}

ostream &operator<<(ostream &out, const Capteur &c)
{
    out << "Capteur '" << c.idCapteur << "' (" << c.latitude << ", " << c.longitude << ")" << endl;
    return out;
}

//-------------------------------------------- Constructeurs - destructeur
Capteur::Capteur()
{
    idCapteur = "id";
    latitude = 0;
    longitude = 0;
}

Capteur::Capteur(string id, float lat, float lon)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Capteur>" << endl;
#endif
    idCapteur = id;
    latitude = lat;
    longitude = lon;
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

void Capteur::ajouterSerieMesures(SerieMesures &sm)
{
    seriesMesures.push_back(sm);
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
