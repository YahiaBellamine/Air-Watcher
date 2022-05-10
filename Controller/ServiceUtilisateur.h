/*************************************************************************
                           ServiceUtilisateur  -  description
                             -------------------
    début                : $10-05-2022$
    copyright            : (C) $2022$ par $alexisreis$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <ServiceUtilisateur> (fichier ServiceUtilisateur.h) ----------------
#if ! defined ( SU_H )
#define SU_H

//--------------------------------------------------- Interfaces utilisées
#include <cstring>
#include "../Model/Utilisateur.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ServiceUtilisateur>
//
//
//------------------------------------------------------------------------

class ServiceUtilisateur 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool seConnecter(string id, string motDePasse);
    // Mode d'emploi : se connecter au service avec un id et son mdp
    // Contrat : renvoie true si connecté, false sinon

    bool creerCompteUtilisateur(string id, string motDePasse);
    // Mode d'emploi : créer un utilisateur avec un id et un mdp
    // Contrat : créer l'utilisateur sous réserve que celui n'existe pas déja

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées
    Utilisateur utilisateurCourant; 
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <ServiceUtilisateur>

#endif // SU_H

