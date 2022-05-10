/*************************************************************************
                           Attribut  -  description
                             -------------------
    début                : $10/05/2022$
    copyright            : (C) $2022$ par $alexisreis$
    e-mail               : $alexis.reis@insa-lyon.fr$
*************************************************************************/

//---------- Réalisation de la classe <Attribut> (fichier Attribut.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Attribut.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Attribut::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

string Attribut::getId() const
{
    return idAttribut;
}

void Attribut::setId(string attribut)
{
    idAttribut = attribut;
}

string Attribut::getUnite() const
{
    return unite;
}

void Attribut::setUnite(string newUnite)
{
    unite = newUnite;
}

string Attribut::getDescription() const
{
    return description;
}

void Attribut::setDescription(string newDescription)
{
    description = newDescription;
}

Attribut::Attribut(string id, string uni, string desc)
{
    #ifdef MAP
    cout << "Appel au constructeur de <Attribut>" << endl;
    #endif
    
    idAttribut = id;
    unite = uni;
    description = desc; 
}

Attribut::~Attribut()
{
    #ifdef MAP
    cout << "Appel au destructeur de <Attribut>" << endl;
    #endif
}





//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

