//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "IndividuPrive.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool IndividuPrive::ajouterPoints(int points)
// Algorithme :
//
{
    // A developper
    return true;
} //----- Fin de Méthode

bool IndividuPrive::ajouterCapteur(Capteur capteur)
// Algorithme :
//
{
    bool added = false;
    int sizeBeforeAdd = listeCapteurs.size();
    listeCapteurs.push_back(capteur);
    int sizeAfterAdd = listeCapteurs.size();
    if (sizeAfterAdd == sizeBeforeAdd + 1)
    {
        added = true;
    }
    return added;
} //----- Fin de Méthode

int IndividuPrive::getNombrePoints() const
// Algorithme :
//
{
    return nombrePoints;
} //----- Fin de Méthode

void IndividuPrive::setNombrePoints(int points)
// Algorithme :
//
{
    nombrePoints = points;
} //----- Fin de Méthode

Fiabilite IndividuPrive::getFiabilite() const
// Algorithme :
//
{
    return fiabilite;
} //----- Fin de Méthode

void IndividuPrive::setFiabilite(Fiabilite fiabilite)
// Algorithme :
//
{
    fiabilite = fiabilite;
} //----- Fin de Méthode

vector<Capteur> IndividuPrive::getListeCapteurs() const
// Algorithme :
//
{
    return listeCapteurs;
} //----- Fin de Méthode

//-------------------------------------------- Constructeurs - destructeur
IndividuPrive::IndividuPrive(string login, string mdp)
{
    nombrePoints = 0;
    fiabilite = Fiabilite::Fiable;
#ifdef MAP
    cout << "Appel au constructeur de <Xxx>" << endl;
#endif
}
IndividuPrive::IndividuPrive()
{
}
IndividuPrive::IndividuPrive(string id)
{
    idUser = id;
    nombrePoints = 0;
    fiabilite = Fiabilite::Fiable;
#ifdef MAP
    cout << "Appel au constructeur de <Xxx>" << endl;
#endif
}

IndividuPrive::~IndividuPrive()
{
#ifdef MAP
    cout << "Appel au destructeur de <Xxx>" << endl;
#endif
} //----- Fin de ~Xxx

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées