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

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Capteur>
//
//
//------------------------------------------------------------------------

class Capteur
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    int getIdCapteur() const;
    float getLatitudeCapteur() const;
    void setLatitudeCapteur(float lat);
    float getLongitudeCapteur() const;
    void setLongitudeCapteur(float lon);

    //------------------------------------------------- Surcharge d'opérateurs
    Capteur &operator=(const Capteur &unXxx);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    Capteur(int id, float lat, float lon);
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
    //------------------------------------------------------------------ PRIVE

private:
    //----------------------------------------------------- Méthodes protégées
    int idCapteur;
    float latitude;
    float longitude;
    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <Capteur>

#endif // CAPTEUR_H
