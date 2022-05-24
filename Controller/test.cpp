#include <iostream>
using namespace std;
#include <cstring>
#include <fstream>
#include <istream>
#include <limits>
#include <list>
#include "../Model/SerieMesures.h"
#include "../Model/Temps.h"
#include "../Model/Mesure.h"

static list<SerieMesures> listeSeriesMesures;

void initialisationMesure(){
    ifstream fic("../dataset/measurements.csv");
    if(!fic){
        cout << " ERREUR D'OUVERTURE DU FICHIER ! " << endl;
    }

    while(!fic.eof()){
    
        Temps date;
        string tmp;
        getline(fic, tmp, '-');
        date.annee = stoi(tmp);
        getline(fic, tmp, '-');
        date.mois = stoi(tmp);
        getline(fic, tmp, ' ');
        date.jour = stoi(tmp);
        getline(fic, tmp, ':');
        date.heure = stoi(tmp);
        getline(fic, tmp, ':');
        date.min = stoi(tmp);
        getline(fic, tmp, ';');
        date.sec = stoi(tmp);
        string idCapteur;
        getline(fic, idCapteur, ';');
        list<Mesure *> liste_4_Mesures;
        Mesure* mesure;
        getline(fic, tmp, ';');
        mesure->setAttribut(tmp);
        getline(fic, tmp, ';');
        mesure->setValeur(stof(tmp));
        liste_4_Mesures.push_back(mesure);
        fic.ignore ( numeric_limits < streamsize >::max ( ), ';' );
        fic.ignore ( numeric_limits < streamsize >::max ( ), ';' );
        getline(fic, tmp, ';');
        mesure->setAttribut(tmp);
        getline(fic, tmp, ';');
        mesure->setValeur(stof(tmp));
        liste_4_Mesures.push_back(mesure);
        fic.ignore ( numeric_limits < streamsize >::max ( ), ';' );
        fic.ignore ( numeric_limits < streamsize >::max ( ), ';' );
        getline(fic, tmp, ';');
        mesure->setAttribut(tmp);
        getline(fic, tmp, ';');
        mesure->setValeur(stof(tmp));
        liste_4_Mesures.push_back(mesure);
        fic.ignore ( numeric_limits < streamsize >::max ( ), ';' );
        fic.ignore ( numeric_limits < streamsize >::max ( ), ';' );
        getline(fic, tmp, ';');
        mesure->setAttribut(tmp);
        getline(fic, tmp, ';');
        mesure->setValeur(stof(tmp));
        liste_4_Mesures.push_back(mesure);

        SerieMesures serieMesures(idCapteur, date, liste_4_Mesures);
        listeSeriesMesures.push_back(serieMesures);
    }
    fic.close();
}

int main(){
    cout << "****** Debut test initialisation des mesures" << endl;
    initialisationMesure();
    cout << "****** Fin test initialisation des mesures" << endl;
    return 0;
}