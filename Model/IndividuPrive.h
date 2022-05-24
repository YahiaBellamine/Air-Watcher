#if !defined(INDIVIDUPRIVE_H)
#define INDIVIDUPRIVE_H

//--------------------------------------------------- Interfaces utilisées
#include <cstring>
#include <vector>
#include <list>
#include "Utilisateur.h"
#include "Capteur.h"
#include "Fiabilite.h"

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

class IndividuPrive : public Utilisateur
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    bool ajouterPoints(int points);
    bool ajouterCapteur(Capteur capteur);
    int getNombrePoints() const;
    void setNombrePoints(int points);
    Fiabilite getFiabilite() const;
    void setFiabilite(Fiabilite fiabilite);
    list<Capteur *> getListeCapteurs() const;

    //-------------------------------------------- Constructeurs - destructeur
    IndividuPrive(string login, string mdp);
    virtual ~IndividuPrive();

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    int nombrePoints;
    list<Capteur *> listeCapteurs;
    Fiabilite fiabilite;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // UTILISATEUR_H