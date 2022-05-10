/*************************************************************************
                           ActionNettoyeur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <ActionNettoyeur> (fichier ActionNettoyeur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "ActionNettoyeur.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool ActionNettoyeur::evaluerImpactNettoyeur(Nettoyeur leNettoyeur, int longitude, int latitude, int rayon)
// Algorithme :
//
{
    /*int resultat[4];
    int moyennesConcentrationAvantT[4];
    int moyennesConcentrationApresT[4];
    int i=0;
    for(i=0; i<4; i++){
        resultat[i] = 0;
        moyennesConcentrationAvantT[i] = 0;
        moyennesConcentrationApresT[i] = 0;
    }

	int nombreDeMesuresO3AvantT = 0;
	int nombreDeMesuresSO2AvantT = 0; 
	int nombreDeMesuresNO2AvantT = 0; 
	int nombreDeMesuresPM10AvantT = 0;
	int nombreDeMesuresO3ApresT = 0;
	int nombreDeMesuresSO2ApresT = 0; 
	int nombreDeMesuresNO2ApresT = 0; 
	int nombreDeMesuresPM10ApresT = 0;

	Pour chaque capteur dans capteurs: 
		Si (capteur.x-centre.x)^2+(capteur.y-centre.y)^2 < rayon^2:
			capteursDansAire.ajouter(capteur)
			nombreCapteurs++;
		Fin Si
	Fin Pour

	Pour chaque mesure dans mesures:
		Pour i allant de 0 à nombreCapteurs:
			Si capteur.idCapteur == mesure.idCapteur :
				Si mesure.getDateMesure() < nettoyeur.getTimeStart()
					Si mesure.getType() = O3
						moyennesConcentrationAvantT[0] += mesure.getValeur() 
						nombreDeMesureO3AvantT++
					Sinon mesure.getType() = SO2
						moyennesConcentrationAvantT[1] += mesure.getValeur() 
						nombreDeMesureSO2AvantT++
					Sinon Si mesure.getType() = NO2
						moyennesConcentrationAvantT[2] += mesure.getValeur() 
						nombreDeMesureNO2AvantT++
					Sinon Si mesure.getType() = PM10
						moyennesConcentrationAvantT[3] += mesure.getValeur() 
						nombreDeMesurePM10AvantT++
				Si mesure.getDateMesure() > nettoyeur.getTimeEnd()
					Si mesure.getType() = O3
						moyennesConcentrationApresT[0] += mesure.getValeur() 
						nombreDeMesureO3ApresT++
					Sinon mesure.getType() = SO2
						moyennesConcentrationApresT[1] += mesure.getValeur() 
						nombreDeMesureSO2ApresT++
					Sinon Si mesure.getType() = NO2
						moyennesConcentrationApresT[2] += mesure.getValeur() 
						nombreDeMesureNO2ApresT++
					Sinon Si mesure.getType() = PM10
						moyennesConcentrationApresT[3] += mesure.getValeur() 
						nombreDeMesurePM10ApresT++
		Fin pour 
	Fin pour

	moyennesConcentrationAvantT[0] /= nombreDeMesuresO3AvantT
	moyennesConcentrationAvantT[1] /= nombreDeMesuresSO2AvantT
	moyennesConcentrationAvantT[2] /= nombreDeMesuresNO2AvantT
	moyennesConcentrationAvantT[3] /= nombreDeMesuresPM10AvantT

	moyennesConcentrationApresT[0] /= nombreDeMesuresO3ApresT
	moyennesConcentrationApresT[1] /= nombreDeMesuresSO2ApresT
	moyennesConcentrationApresT[2] /= nombreDeMesuresNO2ApresT
	moyennesConcentrationApresT[3] /= nombreDeMesuresPM10ApresT

	Pour i allant de 0 à 3:
		resultat[i] = (moyennesConcentrationAvantT[i] - moyennesConcentrationApresT[i])/ moyennesConcentrationAvantT[i]

return resultat
Fin*/
} //----- Fin de Méthode

//-------------------------------------------- Constructeurs - destructeur
ActionNettoyeur::ActionNettoyeur ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ActionNettoyeur>" << endl;
#endif
} //----- Fin de ActionNettoyeur


ActionNettoyeur::~ActionNettoyeur ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ActionNettoyeur>" << endl;
#endif
} //----- Fin de ~ActionNettoyeur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

