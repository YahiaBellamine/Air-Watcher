/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Xxx> (fichier Xxx.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "ActionQualiteAir.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// Xxx::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

#include <math.h>
#include <iterator>
#include <algorithm>
#include <string>
using namespace std;

list<Capteur> *ActionQualiteAir::capteursDansAire(float centre_long, float centre_lat, float rayon, list<Capteur> *tousLesCapteurs)
{
    list<Capteur> *listeRetour = new list<Capteur>;
    float distanceCentre;
    list<Capteur>::iterator it;
    for (it = tousLesCapteurs->begin(); it != tousLesCapteurs->end(); it++)
    {
        distanceCentre = sqrt(pow((it->getLatitudeCapteur() - centre_lat), 2.0) + pow((it->getLongitudeCapteur() - centre_long), 2.0));
        if (rayon - distanceCentre > 0)
        {
            listeRetour->insert(listeRetour->begin(), *it);
        }
    }
    return listeRetour;
}

float *ActionQualiteAir::moyenneQualiteAir(float centre_lat, float centre_long, float rayon, list<SerieMesures> *toutesLesMesures, list<Capteur> *tousLesCapteurs, Temps dateDebutMesures)
{
    float *resultat = new float[4];
    resultat[0] = 0;
    resultat[1] = 0;
    resultat[2] = 0;
    resultat[3] = 0;
    list<Capteur> *listeCapteursDansAire = capteursDansAire(centre_lat, centre_long, rayon, tousLesCapteurs);

    list<SerieMesures> *listeMesuresDansAire = new list<SerieMesures>;
    list<SerieMesures>::iterator it;
    // for (SerieMesures serieMesures : *toutesLesMesures)
    SerieMesures serieMesures = *toutesLesMesures->begin();
    for (it = toutesLesMesures->begin(); it != toutesLesMesures->end(); it++)
    {
        serieMesures = *it;
        if ((find(listeCapteursDansAire->begin(), listeCapteursDansAire->end(), *serieMesures.getCapteur()) != listeCapteursDansAire->end()) && (dateDebutMesures.difftime(serieMesures.getDate(), dateDebutMesures) != -1))
        {
            listeMesuresDansAire->insert(listeMesuresDansAire->begin(), serieMesures);
        }
    }

    if (listeMesuresDansAire->size() == 0)
    {
        return resultat;
    }
    else
    {
        list<SerieMesures>::iterator it;
        for (it = listeMesuresDansAire->begin(); it != listeMesuresDansAire->end(); it++)
        {
            resultat[0] += (*it).getMesure("SO2").getValeur();
            resultat[1] += (*it).getMesure("O3").getValeur();
            resultat[2] += (*it).getMesure("NO2").getValeur();
            resultat[3] += (*it).getMesure("PM10").getValeur();
        }
    }
    float nbMesures = (float)listeMesuresDansAire->size();
    resultat[0] = resultat[0] / nbMesures;
    resultat[1] = resultat[1] / nbMesures;
    resultat[2] = resultat[2] / nbMesures;
    resultat[3] = resultat[3] / nbMesures;
    return resultat;
}