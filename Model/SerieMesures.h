/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/
#include "Mesure.h"
#include "Temps.h"
#include "Capteur.h"
#include <iterator>
#include <vector>
#include <string>
using namespace std;
//---------- Interface de la classe <SerieMesures> (fichier SerieMesures.h) ----------------
#if ! defined (SERIEMESURE_H)
#define SERIEMESURE_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Mesure>
//
//
//------------------------------------------------------------------------

class SerieMesures
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool atmo();

    void ajouterMesure(Mesure &mesure);
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

    SerieMesures(const string id, const Temps &date);

    virtual ~SerieMesures();
    // Inutile

    Mesure getMesure(string type) const;

    Temps getDate();
    string getCapteur();
    vector<Mesure> getListeMesures() const;

    //bool operator==(const SerieMesures &sm) const;

    friend ostream &operator<<(ostream &out, const SerieMesures &sm);

    //------------------------------------------------------------------ PRIVE

private:
    //----------------------------------------------------- Méthodes protégées
    string idCapteur;
    vector<Mesure> listeMesures;
    Temps date;
    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // SERIEMESURES_H
