/*************************************************************************
                           Nettoyeur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Nettoyeur> (fichier Nettoyeur.h) ----------------
#if ! defined ( NETTOYEUR_H )
#define NETTOYEUR_H

//--------------------------------------------------- Interfaces utilisées

#include "Temps.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Nettoyeur>
//
//
//------------------------------------------------------------------------
class Fournisseur;
class Nettoyeur
{
//----------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------- Constructeurs - destructeur
    Nettoyeur(string id, float lat, float lon, Temps tDeb, Temps tFin, Fournisseur *f);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Nettoyeur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées
    string idNettoyeur;
    float latitude;
    float longitude;
    Temps timeStart;
    Temps timeStop;
    Fournisseur *fournisseur;

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Nettoyeur>

#endif // NETTOYEUR_H

