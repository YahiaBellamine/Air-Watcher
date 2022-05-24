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
bool ActionNettoyeur::evaluerImpactNettoyeur(Nettoyeur leNettoyeur, float longitude, float latitude, float rayon)
// Algorithme :
//
{
    /*Fonction evaluerImpactNettoyeur(nettoyeur, longitude, latitude, rayon)
	Entrée : Nettoyeur nettoyeur
					 réel longitude
					 réel latitude
					 réel rayon
	Précondition : nettoyeur est une instance d'objet contenant des attributs de latitude, 
								 longitude, timeStart et timeStop non nuls
	Postcondition : Renvoie la valeur du rayon de la zone nettoyée par nettoyeur 
	Déclaration : List<Capteur> capteurs
								reel rayonMaxNettoyeur
								List <Nettoyeur> listeNettoyeurs
								List<SerieMesures> listeSerieMesures
								Date dateSerieMesures
								reel moyenneAvant
								reel moyenneApres
								reel sommeAvant
								reel sommeApres
								entier nbMesuresAvant
								entier nbMesuresApres
								reel rayonMaxNettoyeur
								reel rayonZoneNettoyee
	
	// On récupère tous les capteurs
	vector<Capteur*> capteurs = AgenceGouvernementale::getListeCapteurs();
	vector<Capteur*> c = IndividuPrive::getListeCapteurs();
	vector < int >::const_iterator iv;
	for ( iv = c.cbegin ( ) ; iv != c.cend ( ) ; ++iv )
	{
		capteurs.push_back(c);
	}
	
	// On calcule le rayon maximal d'un nettoyeur qui délimite une aire prise par aucun 
	// nettoyeur
	rayonMaxNettoyeur <- distance(listeNettoyeur[1], nettoyeur)/2
	Pour chaque n dans listeNettoyeurs
		si distance(n, nettoyeur)/2 < rayonMaxNettoyeur
			rayonMaxNettoyeur <- distance(n, nettoyeur)/2

	// On calcule la moyenne des mesures de chaque capteur dans la zone du nettoyeur
	// avant et après le fonctionnement du nettoyeur et on prend la plus grande distance
	// entre le nettoyeur et la capteur qui detécté une amélioration dans cette zone 
	rayonZoneNettoyee <- 0
	Pour chaque capteur dans capteurs faire
		si distance(capteur, nettoyeur) <= rayonMaxNettoyeur
			listeSerieMesures <- capteur.getListeSerieMesures()
			sommeAvant <- 0
			sommeApres <- 0
			nbMesuresAvant <- 0
			nbMesuresApres <- 0
			Pour chaque serieMesure dans listeSerieMesures
				si serieMesure.dateSerieMesure < nettoyeur.timeStart
					sommeAvant <- sommeAvant + somme(serieMesure.mesures)
					nbMesuresAvant <- nbMesuresAvant + 1
				sinon si serieMesure.dateSerieMesure > nettoyeur.timeStop
					sommeApres <- sommeApres + somme(serieMesure.mesures)
					nbMesuresApres <- nbMesuresApres + 1
			
			moyenneAvant <- sommeAvant/nbMesuresAvant
			moyenneApres <- sommeApres/nbMesuresApres
		
			si moyenneApres < moyenneAvant et distance(capteur, Nettoyeur) > rayonZoneNettoyee
				rayonZoneNettoyee <- distance(capteur, nettoyeur)		
	 
	retourne rayonZoneNettoyee */

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

