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

SerieMesures::SerieMesures(const Temps &laDate)
// Algorithme :
//
{
    date = laDate;
#ifdef MAP
    cout << "Appel au constructeur de <Mesure>" << endl;
#endif
} //----- Fin de Xxx

SerieMesures::~SerieMesures()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Mesure>" << endl;
#endif
} //----- Fin de ~Xxx

void SerieMesures::ajouterMesure(Mesure &mesure)
{
    vecMesures.insert(pair<string, Mesure>(mesure.getAttribut()->getId(), mesure));
}

bool SerieMesures::atmo()
{
    if (getMesure("O3").getValeur() < 104 && getMesure("SO2").getValeur() < 159 && getMesure("NO2").getValeur() < 109 && getMesure("PM10").getValeur() < 27)
    {
        return true;
    }
    return false;
}

Mesure SerieMesures::getMesure(string type) const
{
    return vecMesures.at(type);
}

map<string, Mesure> SerieMesures::getVecMesures()
{
    return vecMesures;
}

Temps SerieMesures::getDate()
{
    return date;
}

map<string, Mesure> SerieMesures::getListeMesures() const
{
    return vecMesures;
}

/* bool SerieMesures::operator==(const SerieMesures &sm) const
{
    return (sm.getListeMesures() == listeMesures && sm.date.difftime(sm.date, date) == 0);
}  */

ostream &operator<<(ostream &out, const SerieMesures &sm)
{
    for(pair<string, Mesure> m : sm.getListeMesures())
    {
        out << m.second;
    }
    return out;
}
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
