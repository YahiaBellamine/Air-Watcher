/*************************************************************************
                           Fournisseur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Fournisseur> (fichier Fournisseur.h) ----------------
#if !defined(FOURNISSEUR_H)
#define FOURNISSEUR_H

//--------------------------------------------------- Interfaces utilisées
#include <cstring>
#include <list>
#include "Utilisateur.h"
#include "Nettoyeur.h"
#include "Capteur.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Fournisseur>
//
//
//------------------------------------------------------------------------

class Nettoyeur;

class Fournisseur : public Utilisateur
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    bool ajouterNettoyeur(Nettoyeur nettoyeur);
    list<Nettoyeur *> getListeNettoyeurs() const;

    //-------------------------------------------- Constructeurs - destructeur
    Fournisseur(string login, string mdp);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Fournisseur();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

private:
    //----------------------------------------------------- Méthodes protégées
    list<Nettoyeur *> listeNettoyeur;
    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <Fournisseur>

#endif // FOURNISSEUR_H
