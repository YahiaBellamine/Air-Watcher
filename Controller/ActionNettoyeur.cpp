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
#include <math.h>

//------------------------------------------------------ Include personnel
#include "ActionNettoyeur.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
float ActionNettoyeur::evaluerImpactNettoyeur(Nettoyeur unNettoyeur, map<string, Capteur> &tousLesCapteurs, list<Nettoyeur> nettoyeurs)
{
	Nettoyeur leNettoyeur = unNettoyeur;

	float rayonMaxNettoyeur = 100000000.0;
	float distanceNN = 0;
	for (Nettoyeur n : nettoyeurs)
	{
		if (n.getIdNettoyeur() != leNettoyeur.getIdNettoyeur())
		{
			distanceNN = ActionNettoyeur::distance(n, leNettoyeur);
			if ((distanceNN / (2.0)) < rayonMaxNettoyeur)
			{
				rayonMaxNettoyeur = distanceNN / (2.0);
			}
		}
	}

	float rayonZoneNettoyee = 0;

	for (pair<string, Capteur> c : tousLesCapteurs)
	{

		float sommeAvant = 0;
		float sommeApres = 0;
		int nbMesuresAvant = 0;
		int nbMesuresApres = 0;
		float moyenneAvant = 0;
		float moyenneApres = 0;
		float distanceCN = ActionNettoyeur::distanceCN(c.second, leNettoyeur);

		if (distanceCN <= rayonMaxNettoyeur)
		{
			vector<SerieMesures> vectorSerieMesures = c.second.getSeriesMesures();
			for (SerieMesures serie : vectorSerieMesures)
			{
				// <
				if (Temps::difftime(serie.getDate(), leNettoyeur.getTimeStart()) == -1)
				{
					for (Mesure m : serie.getVecMesures())
					{
						sommeAvant = sommeAvant + m.getValeur();
					}
					nbMesuresAvant = nbMesuresAvant + 1;
				}
				else if (Temps::difftime(serie.getDate(), leNettoyeur.getTimeStart()) == 1)
				{
					for (Mesure m : serie.getVecMesures())
					{
						sommeApres = sommeApres + m.getValeur();
					}
					nbMesuresApres = nbMesuresApres + 1;
				}
			}
			moyenneAvant = sommeAvant / nbMesuresAvant;
			moyenneApres = sommeApres / nbMesuresApres;
			if ((moyenneApres < moyenneAvant) && (distanceCN > rayonZoneNettoyee))
			{
				rayonZoneNettoyee = distanceCN;
			}
		}
	}
	return rayonZoneNettoyee;

} //----- Fin de Méthode

float ActionNettoyeur::distance(Nettoyeur premierNettoyeur, Nettoyeur deuxiemeNettoyeur)
{
	float distance = sqrt(pow((premierNettoyeur.getLatitude() - deuxiemeNettoyeur.getLatitude()), 2.0) + pow((premierNettoyeur.getLongitude() - deuxiemeNettoyeur.getLongitude()), 2.0));
	return distance;
}

float ActionNettoyeur::distanceCN(Capteur capteur, Nettoyeur nettoyeur)
{
	float distance = sqrt(pow((capteur.getLatitudeCapteur() - nettoyeur.getLatitude()), 2.0) + pow((capteur.getLongitudeCapteur() - nettoyeur.getLongitude()), 2.0));
	return distance;
}

//-------------------------------------------- Constructeurs - destructeur
// ActionNettoyeur::ActionNettoyeur()
// {
// #ifdef MAP
// 	cout << "Appel au constructeur de <ActionNettoyeur>" << endl;
// #endif
// } //----- Fin de ActionNettoyeur

// ActionNettoyeur::~ActionNettoyeur()
// {
// #ifdef MAP
// 	cout << "Appel au destructeur de <ActionNettoyeur>" << endl;
// #endif
// } //----- Fin de ~ActionNettoyeur

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
