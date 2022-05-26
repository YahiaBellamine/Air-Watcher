/*************************************************************************
                           Fournisseur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Fournisseur> (fichier Fournisseur.h) ----------------
#if ! defined (FOURNISSEUR_H)
#define FOURNISSEUR_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <vector>
#include "Capteur.h"
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
class Fournisseur
{
    //----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool ajouterNettoyeur (Nettoyeur nettoyeur);
    vector<Nettoyeur> getListeNettoyeurs() const;
    string getIdFournisseur() const;

    //-------------------------------------------- Constructeurs - destructeur
    Fournisseur(string login, string mdp);
    Fournisseur(string idFournisseur);
    virtual ~Fournisseur();

    //------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées
    string idFournisseur;
    vector<Nettoyeur> listeNettoyeur;
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Fournisseur>

#endif // FOURNISSEUR_H
