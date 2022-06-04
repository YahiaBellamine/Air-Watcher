/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/
#include "Attribut.h"
//---------- Interface de la classe <Xxx> (fichier Xxx.h) ----------------
#if ! defined (MESURE_H)
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

    Mesure(float valeur, Attribut* attribut);
    Mesure();
    virtual ~Mesure();
    // Inutile

    float getValeur() const;

    void setValeur(float valeur);

    Attribut* getAttribut() const;

    void setAttribut(Attribut* attribut);

    friend ostream &operator<<(ostream &out, const Mesure &sm);

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    float valeur;
    Attribut *attribut;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // XXX_H
