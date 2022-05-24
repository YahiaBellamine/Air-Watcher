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
#include "../Model/Mesure.h"
#include "../Model/SerieMesures.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type ActionCapteur::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

list<Capteur*>* ActionCapteur::comparerCapteur(Capteur *capteurSelectionne, list<Capteur*> *listeCapteurs, list<SerieMesures*> *listeSerieMesures)
{
	list<Capteur*> *capteursSimilaires = new list<Capteur *>();
	
	float moyenneO3 = 0;
	float moyenneSO2 = 0;
	float moyenneNO2 = 0;
	float moyennePM10 = 0;

	float moyenneCapteurO3 = 0;
	float moyenneCapteurSO2 = 0;
	float moyenneCapteurNO2 = 0;
	float moyenneCapteurPM10 = 0;

	int nombreDeMesuresO3 = 0;
	int nombreDeMesuresSO2 = 0;
	int nombreDeMesuresNO2 = 0;
	int nombreDeMesuresPM10 = 0;
	

	for(SerieMesures* sm : *listeSerieMesures)
	{
		if(*(sm->getCapteur()) == *capteurSelectionne /* && sm.getDate() > 7 JOURS */)
		{
			moyenneCapteurO3 += sm->getMesure("O3").getValeur();
			nombreDeMesuresO3 ++;
			
			moyenneCapteurSO2 += sm->getMesure("SO2").getValeur();
			nombreDeMesuresSO2 ++;
		
			moyenneCapteurNO2 += sm->getMesure("NO2").getValeur();
			nombreDeMesuresNO2 ++;
		
			moyenneCapteurPM10 += sm->getMesure("PM10").getValeur();
			nombreDeMesuresPM10 ++;			
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

	for(Capteur* c : *listeCapteurs)
	{
		if(!(*c == *capteurSelectionne))
		{
			for(SerieMesures* sm : *listeSerieMesures)
			{
				if(sm->getCapteur() == c /* && ->getDate()*/)
				{
					// cout << *sm; 

					moyenneO3 += sm->getMesure("O3").getValeur();
					nombreDeMesuresO3 ++;
					
					moyenneSO2 += sm->getMesure("SO2").getValeur();
					nombreDeMesuresSO2 ++;
				
					moyenneNO2 += sm->getMesure("NO2").getValeur();
					nombreDeMesuresNO2 ++;
				
					moyennePM10 += sm->getMesure("PM10").getValeur();
					nombreDeMesuresPM10 ++;	
				}
			}

			moyenneO3 /= nombreDeMesuresO3;
			moyenneSO2 /= nombreDeMesuresSO2;
			moyenneNO2 /= nombreDeMesuresNO2;
			moyennePM10 /= nombreDeMesuresPM10;

			if(sqrt(pow((moyenneO3 - moyenneCapteurO3), 2.0)
				+ pow((moyenneSO2 - moyenneCapteurSO2), 2.0)
				+ pow((moyenneNO2 - moyenneCapteurNO2), 2.0) 
				+ pow((moyennePM10 - moyenneCapteurPM10), 2.0)) < SIMILARITE_MAX_ADMISSIBLE){
					capteursSimilaires->push_back(c);
			}
			
			nombreDeMesuresO3 = 0;
			nombreDeMesuresSO2 = 0;
			nombreDeMesuresNO2 = 0;
			nombreDeMesuresPM10 = 0;
			moyenneO3 = 0;
			moyenneSO2 = 0;
			moyenneNO2 = 0;
			moyennePM10 = 0;
		}
	}

	for(Capteur *c : *capteursSimilaires)
	{
		cout << *c; 
	}

	return capteursSimilaires;
} // Fin de comparerCapteur

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
