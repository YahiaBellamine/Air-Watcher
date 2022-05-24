/*************************************************************************
                           ActionCapteur  -  description
                             -------------------
    début                : $10-05-2022$
    copyright            : (C) $2022$ par $alexisreis$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <ActionCapteur> (fichier ActionCapteur.h) ----------------
#if !defined(AC_H)
#define AC_H

//--------------------------------------------------- Interfaces utilisées
#include "../Model/Capteur.h"
#include "../Model/SerieMesures.h"
#include <vector>
#include <iterator>

using namespace std;
//------------------------------------------------------------- Constantes
const float SIMILARITE_MAX_ADMISSIBLE = 10.0;
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

    static vector<Capteur> comparerCapteur(Capteur &capteurSelectionne, vector<Capteur> &listeCapteurs, vector<SerieMesures> &listeSerieMesures);
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
