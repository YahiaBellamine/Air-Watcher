/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/
#include "Attribut.h"
//---------- Interface de la classe <Xxx> (fichier Xxx.h) ----------------
#if !defined(MESURE_H)
#define MESURE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Mesure>
//
//
//------------------------------------------------------------------------

class Mesure
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------- Surcharge d'opérateurs
    // Xxx &operator=(const Xxx &unXxx);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    // Xxx(const Xxx &unXxx);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Mesure(float valeur, string idAttribut);
    Mesure();
    virtual ~Mesure();
    // Inutile

    float getValeur() const;

    void setValeur(float valeur);

    string getAttribut() const;

    void setAttribut(string idAttribut);

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    float valeur;
    string idAttribut;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // XXX_H
