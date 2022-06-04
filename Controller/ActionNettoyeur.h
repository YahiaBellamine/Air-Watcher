/*************************************************************************
                           ActionNettoyeur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <ActionNettoyeur> (fichier ActionNettoyeur.h) ----------------
#if !defined(ACTIONNETTOYEUR_H)
#define ACTIONNETTOYEUR_H

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <list>
#include "../Model/Nettoyeur.h"
#include "../Model/Capteur.h"
#include "../Model/Temps.h"
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
    static float evaluerImpactNettoyeur(Nettoyeur leNettoyeur, map<string, Capteur> &tousLesCapteurs, list<Nettoyeur> listeNettoyeurs);
    // Mode d'emploi :
    //
    // Contrat :
    //

    static float distance(Nettoyeur premierNettoyeur, Nettoyeur deuxiemeNettoyeur);

    static float distanceCN(Capteur capteur, Nettoyeur nettoyeur);

    //-------------------------------------------- Constructeurs - destructeur
    // ActionNettoyeur();
    // // Mode d'emploi :
    // //
    // // Contrat :
    // //

    // virtual ~ActionNettoyeur();
    // // Mode d'emploi :
    // //
    // // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <ActionNettoyeur>

#endif // XXX_H
