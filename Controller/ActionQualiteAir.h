/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/
#include <iostream>
#include <ctime>
#include <list>
#include <string>
#include <map>
#include "../Model/Temps.h"
#include "../Model/Capteur.h"
#include "../Model/SerieMesures.h"
using namespace std;

//---------- Interface de la classe <Xxx> (fichier Xxx.h) ----------------
#if !defined(ACTIONQUALITEAIR_H)
#define ACTIONQUALITEAIR_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Xxx>
//
//

class ActionQualiteAir
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    //------------------------------------------------------------------------
    static float *moyenneQualiteAir(float centre_lat, float centre_long, float rayon, map<string, Capteur> tousLesCapteurs, Temps dateDebutMesures);
    // static float moyenneQualiteAir(Measurement measure, Date dateDebut, Date dateFin);
    static map<string, Capteur> capteursDansAire(float centre_long, float centre_lat, float rayon, map<string, Capteur> tousLesCapteurs);

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // XXX_H