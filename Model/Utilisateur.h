#if ! defined (UTILISATEUR_H)
#define UTULISATEUR_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

class Utilisateur
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    Utilisateur(string login, string mdp);

    string getIdentifiantUtilisateur() const;

    string getMotDePasse() const;

    virtual ~Utilisateur();

    //------------------------------------------------------------------ PRIVE

protected:
    string identifiantUtilisateur;
    string motDePasse;
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // UTILISATEUR_H
