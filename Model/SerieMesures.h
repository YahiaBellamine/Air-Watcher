/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/
#include "Mesure.h"
#include "Time.cpp"
#include <iterator>
#include <list>
#include <string>
using namespace std;
//---------- Interface de la classe <SerieMesures> (fichier SerieMesures.h) ----------------
#if !defined(SERIEMESURE_H)
#define SERIEMESURE_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Mesure>
//
//
//------------------------------------------------------------------------

class SerieMesures
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool atmo();

    bool ajouterMesure(Mesure mesure);
    //------------------------------------------------- Surcharge d'opérateurs
    // Xxx &operator=(const Xxx &unXxx);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    // Xxx(const Xxx &unXxx);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    SerieMesures(/*Capteur capteur*/ temps date);

    virtual ~SerieMesures();
    // Inutile

    Mesure getMesure(int index);

    temps getDate();

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées
    list<Mesure> *listeMesures;
    temps date;
    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // SERIEMESURES_H
