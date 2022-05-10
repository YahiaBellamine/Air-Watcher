/*************************************************************************
                           ActionCapteur  -  description
                             -------------------
    début                : $10-05-2022$
    copyright            : (C) $2022$ par $alexisreis$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <ActionCapteur> (fichier ActionCapteur.h) ----------------
#if ! defined ( AC_H )
#define AC_H

//--------------------------------------------------- Interfaces utilisées
#include "../Model/Capteur.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ActionCapteur>
//
//
//------------------------------------------------------------------------

class ActionCapteur 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Capteur comparerCapteur(Capteur capteur);
    // Mode d'emploi :
    //
    // Contrat :
    // 

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées
    
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <ActionCapteur>

#endif // AC_H
