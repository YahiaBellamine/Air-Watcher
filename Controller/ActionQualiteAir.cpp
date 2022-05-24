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

vector<Capteur> ActionQualiteAir::capteursDansAire(float centre_long, float centre_lat, float rayon, vector<Capteur> tousLesCapteurs)
{
    vector<Capteur> vecteurRetour;
    float distanceCentre;
    vector<Capteur>::iterator it;
    for (it = tousLesCapteurs.begin(); it != tousLesCapteurs.end(); it++)
    {
        distanceCentre = sqrt(pow((it->getLatitudeCapteur() - centre_lat), 2.0) + pow((it->getLongitudeCapteur() - centre_long), 2.0));
        if (rayon - distanceCentre > 0)
        {
            vecteurRetour.insert(vecteurRetour.begin(), *it);
        }
    }
    return vecteurRetour;
}

float *ActionQualiteAir::moyenneQualiteAir(float centre_lat, float centre_long, float rayon, vector<SerieMesures> toutesLesMesures, vector<Capteur> tousLesCapteurs, Temps dateDebutMesures)
{
    float *resultat = new float[4];
    resultat[0] = 0;
    resultat[1] = 0;
    resultat[2] = 0;
    resultat[3] = 0;
    vector<Capteur> vecteurCapteursDansAire = capteursDansAire(centre_lat, centre_long, rayon, tousLesCapteurs);

    vector<SerieMesures> vecteurMesuresDansAire;
    vector<SerieMesures>::iterator it;
    // for (SerieMesures serieMesures : *toutesLesMesures)
    SerieMesures serieMesures = *toutesLesMesures.begin();
    for (it = toutesLesMesures.begin(); it != toutesLesMesures.end(); it++)
    {
        serieMesures = *it;
        /*if ((find(vecteurCapteursDansAire.begin(), vecteurCapteursDansAire.end(), serieMesures.getCapteur()) != vecteurCapteursDansAire.end()) && (dateDebutMesures.difftime(serieMesures.getDate(), dateDebutMesures) != -1))
        {
            vecteurMesuresDansAire.insert(vecteurMesuresDansAire.begin(), serieMesures);
        }*/

        for (Capteur capteur : vecteurCapteursDansAire)
        {
            if (serieMesures.getCapteur() == capteur.getIdCapteur())
            {
                vecteurMesuresDansAire.push_back(serieMesures);
            }
        }
    }

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