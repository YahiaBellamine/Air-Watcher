/*************************************************************************
                           Nettoyeur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Nettoyeur> (fichier Nettoyeur.h) ----------------
#if !defined(NETTOYEUR_H)
#define NETTOYEUR_H

//--------------------------------------------------- Interfaces utilisées

#include "Temps.h"
#include <string>
#include <vector>

using namespace std;
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
    string getIdNettoyeur();
    float getLatitude();
    float getLongitude();
    Temps getTimeStart();
    Temps getTimeStop();
    Fournisseur *getfournisseur();
    //-------------------------------------------- Constructeurs - destructeur
    Nettoyeur(string id, float lat, float lon, Temps tDeb, Temps tFin, Fournisseur *f);
    // Mode d'emploi :
    //
    // Contrat :
    //
    Nettoyeur(string id, float lat, float lon, Temps tDeb, Temps tFin);

    virtual ~Nettoyeur();
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
