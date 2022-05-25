#if !defined(INDIVIDUPRIVE_H)
#define INDIVIDUPRIVE_H

//--------------------------------------------------- Interfaces utilisées
#include <cstring>
#include <vector>
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
    vector<Capteur> getListeCapteurs() const;
    
    //-------------------------------------------- Constructeurs - destructeur
    IndividuPrive(string login, string mdp);
    IndividuPrive(string id);
    virtual ~IndividuPrive();

    //------------------------------------------------------------------ PRIVE

private:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    string idUser;
    int nombrePoints;
    vector<Capteur> listeCapteurs;
    Fiabilite fiabilite;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // UTILISATEUR_H