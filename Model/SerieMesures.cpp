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
#include "Capteur.h"

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

SerieMesures::SerieMesures(Capteur *capteur, Temps date)
// Algorithme :
//
{
    this->capteur = capteur;
    this->date = date;
    this->listeMesures = new list<Mesure>;
#ifdef MAP
    cout << "Appel au constructeur de <Mesure>" << endl;
#endif
} //----- Fin de Xxx

SerieMesures::~SerieMesures()
// Algorithme :
//
{
    listeMesures->clear();
#ifdef MAP
    cout << "Appel au destructeur de <Mesure>" << endl;
#endif
} //----- Fin de ~Xxx

bool SerieMesures::ajouterMesure(Mesure *mesure)
{
    list<Mesure>::iterator it = listeMesures->begin();
    .listeMesures->insert(it, *mesure);
    return true;
}

bool SerieMesures::atmo()
{
    if (this->getMesure("O3").getValeur() < 104 && this->getMesure("SO2").getValeur() < 159 && this->getMesure("NO2").getValeur() < 109 && this->getMesure("PM10").getValeur() < 27)
    {
        return true;
    }
    return false;
}

Mesure SerieMesures::getMesure(string type)
{
    list<Mesure>::iterator it = listeMesures->begin();
    for (it = listeMesures->begin(); it != listeMesures->end(); it++)
    {

        if ((*it).getAttribut() == type)
        {
            return *it;
        }
    }
    return Mesure(5, "");
}

Temps SerieMesures::getDate()
{
    return date;
}

Capteur *SerieMesures::getCapteur()
{
    return capteur;
}

bool SerieMesures::operator==(const SerieMesures &sm) const
{
    return (*sm.capteur == *capteur && sm.date.difftime(sm.date, date) == 0);
}
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
