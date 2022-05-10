/*************************************************************************
                           ActionNettoyeur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <ActionNettoyeur> (fichier ActionNettoyeur.h) ----------------
#if ! defined ( ACTIONNETTOYEUR_H )
#define ACTIONNETTOYEUR_H

//--------------------------------------------------- Interfaces utilisées
#include "Nettoyeur.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ActionNettoyeur>
//
//
//------------------------------------------------------------------------

class ActionNettoyeur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool evaluerImpactNettoyeur(Nettoyeur leNettoyeur, int longitude, int latitude, int rayon);
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    ActionNettoyeur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ActionNettoyeur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <ActionNettoyeur>

#endif // XXX_H

