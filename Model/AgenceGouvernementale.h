/*************************************************************************
                           AgenceGouvernementale  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <AgenceGouvernementale> (fichier AgenceGouvernementale.h) ----------------
#if !defined(AGENCEGOUVERNEMENTALE_H)
#define AGENCEGOUVERNEMENTALE_H

//--------------------------------------------------- Interfaces utilisées
#include <cstring>
#include <vector>
#include "Utilisateur.h"
#include "Capteur.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <AgenceGouvernementale>
//
//
//------------------------------------------------------------------------

class AgenceGouvernementale : public Utilisateur
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    bool ajouterCapteur(Capteur capteur);
    vector<Capteur> getListeCapteurs() const;

    //-------------------------------------------- Constructeurs - destructeur
    AgenceGouvernementale(string login, string mdp);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~AgenceGouvernementale();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

private:
    vector<Capteur> listeCapteurs;

};

//-------------------------------- Autres définitions dépendantes de <AgenceGouvernementale>

#endif // AGENCEGOUVERNEMENTALE_H
