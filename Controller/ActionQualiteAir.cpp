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

#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "ActionQualiteAir.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// Xxx::Méthode ( vectore des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

#include <math.h>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

map<string, Capteur> ActionQualiteAir::capteursDansAire(float centre_long, float centre_lat, float rayon, map<string, Capteur> &tousLesCapteurs)
{
    map<string, Capteur> vecteurRetour;
    float distanceCentre;
    map<string, Capteur>::iterator it;
    for (it = tousLesCapteurs.begin(); it != tousLesCapteurs.end(); it++)
    {
        distanceCentre = sqrt(pow((it->second.getLatitudeCapteur() - centre_lat), 2.0) + pow((it->second.getLongitudeCapteur() - centre_long), 2.0));
        if (rayon - distanceCentre > 0)
        {
            vecteurRetour.insert(pair<string, Capteur>(*it));
        }
    }
    return vecteurRetour;
}

float *ActionQualiteAir::moyenneQualiteAir(float centre_lat, float centre_long, float rayon, map<string, Capteur> &tousLesCapteurs, Temps dateDebutMesures)
{
    float *resultat = new float[4];
    resultat[0] = 0;
    resultat[1] = 0;
    resultat[2] = 0;
    resultat[3] = 0;
    map<string, Capteur> vecteurCapteursDansAire = capteursDansAire(centre_lat, centre_long, rayon, tousLesCapteurs);

    vector<SerieMesures> vecteurMesuresDansAire;
    for (pair<string, Capteur> paire : vecteurCapteursDansAire)
    {
        for (SerieMesures sm : paire.second.getSeriesMesures())
        {
            if (dateDebutMesures.difftime(sm.getDate(), dateDebutMesures) != -1)
            {
                vecteurMesuresDansAire.push_back(sm);
            }
        }
    }

    /*vector<SerieMesures>::iterator it;
    // for (SerieMesures serieMesures : *toutesLesMesures)
    SerieMesures serieMesures = *toutesLesMesures.begin();
    for (it = toutesLesMesures.begin(); it != toutesLesMesures.end(); it++)
    {
        serieMesures = *it;


        for (Capteur capteur : vecteurCapteursDansAire)
        {
            if ((find(capteur.getSeriesMesures().begin(), capteur.getSeriesMesures().end(), serieMesures) != capteur.getSeriesMesures().end()) && (dateDebutMesures.difftime(serieMesures.getDate(), dateDebutMesures) != -1))
            {
                vecteurMesuresDansAire.insert(vecteurMesuresDansAire.begin(), serieMesures);
            }
        }
    }*/

    if (vecteurMesuresDansAire.size() == 0)
    {
        return resultat;
    }
    else
    {
        vector<SerieMesures>::iterator it;
        for (it = vecteurMesuresDansAire.begin(); it != vecteurMesuresDansAire.end(); it++)
        {
            resultat[0] += (*it).getMesure("SO2").getValeur();
            resultat[1] += (*it).getMesure("O3").getValeur();
            resultat[2] += (*it).getMesure("NO2").getValeur();
            resultat[3] += (*it).getMesure("PM10").getValeur();
        }
    }
    float nbMesures = (float)vecteurMesuresDansAire.size();
    resultat[0] = resultat[0] / nbMesures;
    resultat[1] = resultat[1] / nbMesures;
    resultat[2] = resultat[2] / nbMesures;
    resultat[3] = resultat[3] / nbMesures;
    return resultat;
}