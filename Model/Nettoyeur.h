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
#include "Fournisseur.h"
#include "Temps.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Nettoyeur>
//
//
//------------------------------------------------------------------------

class Nettoyeur
{
//----------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------- Constructeurs - destructeur
    Nettoyeur ( const Nettoyeur & unXxx );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Nettoyeur ( );
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
    int idNettoyeur;
    float latitude;
    float longitude;
    Temps timeStart;
    Temps timeStop;
    Fournisseur * fournisseur;

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Nettoyeur>

#endif // NETTOYEUR_H

