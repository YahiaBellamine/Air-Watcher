/*************************************************************************
						   ActionCapteur  -  description
							 -------------------
	début                : $10/05/2022$
	copyright            : (C) $2022$ par $alexisreis$
	e-mail               : $alexis.reis@insa-lyon.fr$
*************************************************************************/

//---------- Réalisation de la classe <ActionCapteur> (fichier ActionCapteur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <math.h>
//------------------------------------------------------ Include personnel
#include "ActionCapteur.h"
#include "Mesure.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type ActionCapteur::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

list<Capteur> ActionCapteur::comparerCapteur(Capteur capteurSelectionne)
{
	list<Capteur> capteursSimilaires;
	
	double moyenneO3 = 0;
	double moyenneSO2 = 0;
	double moyenneNO2 = 0;
	double moyennePM10 = 0;

	double moyenneCapteurO3 = 0;
	double moyenneCapteurSO2 = 0;
	double moyenneCapteurNO2 = 0;
	double moyenneCapteurPM10 = 0;

	int nombreDeMesuresO3 = 0
	int nombreDeMesuresSO2 = 0 
	int nombreDeMesuresNO2 = 0 
	int nombreDeMesuresPM10 = 0
	

	for(Mesure mesure : listeMesures)
	{
		if(mesure.getCapteur() == capteurSelectionne.getIdCapteur() && /* mesure.getDate > 7 JOURS */)
		{
			switch(mesure.getAttribut())
			{
				case "O3" :
				{
					moyenneCapteurO3 += mesure.getValeur();
					nombreDeMesureO3 ++;
					break;
				}
				case "SO2" : 
				{
					moyenneCapteurSO2 += mesure.getValeur();
					nombreDeMesureSO2 ++;
					break;
				}
				case "NO2" :
				{
					moyenneCapteurNO2 += mesure.getValeur();
					nombreDeMesureNO2 ++;
					break;
				}
				case "PM10" : 
				{
					moyenneCapteurPM10 += mesure.getValeur();
					nombreDeMesurePM10 ++;
					break;
				}
			}
		}
	}

	moyenneCapteurO3 /= nombreDeMesuresO3;
	moyenneCapteurSO2 /= nombreDeMesuresSO2;
	moyenneCapteurNO2 /= nombreDeMesuresNO2;
	moyenneCapteurPM10 /= nombreDeMesuresPM10;

	nombreDeMesuresO3 = 0;
	nombreDeMesuresSO2 = 0;
	nombreDeMesuresNO2 = 0;
	nombreDeMesuresPM10 = 0;

	for(Capteur c : listeCapteurs)
	{
		if(c.getIdCapteur() != capteurSelectionne.getIdCapteur)
		{
			for(Mesure m : listeMesures)
			{
				if(m.getCapteur() == c.getIdCapteur() /* && mesure.getDate() > IL Y A 7 JOURS */)
				{
					switch(mesure.getAttribut())
					{
						case "O3" :
						{
							moyenneO3 += mesure.getValeur();
							nombreDeMesureO3 ++;
							break;
						}
						case "SO2" : 
						{
							moyenneSO2 += mesure.getValeur();
							nombreDeMesureSO2 ++;
							break;
						}
						case "NO2" :
						{
							moyenneNO2 += mesure.getValeur();
							nombreDeMesureNO2 ++;
							break;
						}
						case "PM10" : 
						{
							moyennePM10 += mesure.getValeur();
							nombreDeMesurePM10 ++;
							break;
						}
					}
				}
			}

			moyenneO3 /= nombreDeMesuresO3;
			moyenneSO2 /= nombreDeMesuresSO2;
			moyenneNO2 /= nombreDeMesuresNO2;
			moyennePM10 /= nombreDeMesuresPM10;

			if(sqrt(pow(moyenne03 - moyenneCapteur03), 2.0)
				+ pow((moyenneSO2 - moyenneCapteurSO2), 2.0)
				+ pow((moyenneNO2 - moyenneCapteurNO2), 2.0) 
				+ pow((moyennePM10 - moyenneCapteurPM10), 2.0)
				< 1.0) 
				{
					capteursSimilaires.push_back(c);
				}
			
			nombreDeMesuresO3 = 0;
			nombreDeMesuresSO2 = 0;
			nombreDeMesuresNO2 = 0;
			nombreDeMesuresPM10 = 0;
			moyenne03 = 0;
			moyenneSO2 = 0;
			moyenneNO2 = 0;
			moyennePM10 = 0;
		}
	}

	return capteursSimilaires;
} // Fin de comparerCapteur

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
