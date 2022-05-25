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
    listeMesures.push_back(mesure);
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
    for (vector<Mesure>::const_iterator it = listeMesures.begin(); it != listeMesures.end(); it++)
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

vector<Mesure> SerieMesures::getListeMesures() const
{
    return listeMesures;
}

/* bool SerieMesures::operator==(const SerieMesures &sm) const
{
    return (sm.getListeMesures() == listeMesures && sm.date.difftime(sm.date, date) == 0);
} */

ostream & operator << (ostream & out, const SerieMesures & sm)
{ 
    cout << "O3 : " << sm.getMesure("O3").getValeur() << endl;
    cout << "SO2 : " << sm.getMesure("SO2").getValeur() << endl;
    cout << "NO2 : " << sm.getMesure("NO2").getValeur() << endl;
    cout << "PM10 : " << sm.getMesure("PM10").getValeur() << endl << endl;
    return out;
}
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
