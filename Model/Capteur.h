/*************************************************************************
                           Capteur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Capteur> (fichier Capteur.h) ----------------
#if !defined(CAPTEUR_H)
#define CAPTEUR_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <string>
#include <vector>
#include "SerieMesures.h"

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Capteur>
//
//
//------------------------------------------------------------------------
#include <cstring>
class Capteur
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    string getIdCapteur() const;

    float getLatitudeCapteur() const;

    void setLatitudeCapteur(float lat);

    float getLongitudeCapteur() const;

    void setLongitudeCapteur(float lon);

    vector<SerieMesures> & getSeriesMesures();

    void ajouterSerieMesures(SerieMesures &m);

    //------------------------------------------------- Surcharge d'opérateurs
    Capteur &operator=(const Capteur &unXxx);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    Capteur(string id, float lat, float lon);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Capteur();
    // Mode d'emploi :
    //
    // Contrat :
    //
    bool operator==(const Capteur &cap) const;
    friend ostream & operator << (ostream & out, const Capteur & c);
    //------------------------------------------------------------------ PRIVE

private:
    //----------------------------------------------------- Méthodes protégées
    string idCapteur;
    float latitude;
    float longitude;
    vector<SerieMesures> seriesMesures;
    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <Capteur>

#endif // CAPTEUR_H
