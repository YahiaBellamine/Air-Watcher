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
    ++this->nombrePoints;
}//----- Fin de Méthode

bool IndividuPrive::ajouterCapteur(Capteur capteur)
// Algorithme :
//
{
    bool added = false;
    int sizeBeforeAdd = listeCapteurs.size();
    listeCapteurs.push_back(capteur);
    int sizeAfterAdd = listeCapteurs.size();
    if(sizeAfterAdd==sizeBeforeAdd+1){
        added = true;
    }
    return added;
} //----- Fin de Méthode

int IndividuPrive::getNombrePoints() const
// Algorithme :
//
{
    return this->nombrePoints;
}//----- Fin de Méthode

void IndividuPrive::setNombrePoints(int points)
// Algorithme :
//
{
    this->nombrePoints = points;
}//----- Fin de Méthode

Fiabilite IndividuPrive::getFiabilite() const
// Algorithme :
//
{
    return this->fiabilite;
}//----- Fin de Méthode

void IndividuPrive::setFiabilite(Fiabilite fiabilite)
// Algorithme :
//
{
    this->fiabilite = fiabilite;
}//----- Fin de Méthode

vector<Capteur*> IndividuPrive::getListeCapteurs() const
// Algorithme :
//
{
    return this->listeCapteur;
}//----- Fin de Méthode

//-------------------------------------------- Constructeurs - destructeur
IndividuPrive::IndividuPrive(string login, string mdp) : Utilisateur(login, mdp)
{
    this->nombrePoints = 0;
    this->fiabilite = Fiabilite::Fiable;
#ifdef MAP
    cout << "Appel au constructeur de <Xxx>" << endl;
#endif
}

Utilisateur::~Utilisateur()
{
#ifdef MAP
    cout << "Appel au destructeur de <Xxx>" << endl;
#endif
} //----- Fin de ~Xxx

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées