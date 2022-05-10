/*************************************************************************
                           Attribut  -  description
                             -------------------
    début                : $10-05-2022$
    copyright            : (C) $2022$ par $alexisreis$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Attribut> (fichier Attribut.h) ----------------
#if ! defined ( ATT_H )
#define ATT_H

//--------------------------------------------------- Interfaces utilisées
#include <cstring>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Attribut>
//
//
//------------------------------------------------------------------------

class Attribut 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    enum idAttribut {O3, SO2, NO2, PM10};

    string getId() const;
    void setId(int attribut);

    string getUnite() const;
    void setUnite(string newUnite);

    string getDescription() const;
    void setDescription(string newDescription);

    Attribut(string id, string unite, string description);
    virtual ~Attribut ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    
//----------------------------------------------------- Attributs protégés
    string idAttribut;
    string unite;
    string description;
};

//-------------------------------- Autres définitions dépendantes de <Attribut>

#endif // ATT_H

