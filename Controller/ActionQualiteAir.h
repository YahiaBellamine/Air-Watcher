/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/
#include <iostream>
#include <ctime>
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
    static float moyenneQualiteAir(/*Measurement measure, Date date*/);
    // static float moyenneQualiteAir(Measurement measure, Date dateDebut, Date dateFin);

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // XXX_H
