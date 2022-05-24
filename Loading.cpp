#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <limits>
#include <vector>
#include <list>
#include "Model/SerieMesures.h"
#include "Model/Temps.h"
#include "Model/Mesure.h"
#include "Model/Attribut.h"
#include "Model/Capteur.h"
#include "Model/Fournisseur.h"

static list<SerieMesures> listeSeriesMesures;
static list<Attribut> listeAttributs;
static list<Capteur> maListeDeCapteur; 
static list<Fournisseur> listeFournisseurs;

void loadMeasurements(){
    ifstream fic("./dataset/measurements.csv");
    if(!fic){
        cout << " ERREUR D'OUVERTURE DU FICHIER ! " << endl;
    }

    while(!fic.eof()){
    
        string tmp1, tmp2;
        Temps date;
        Mesure mesure;
        getline(fic, tmp1, '/');
        date.jour = stoi(tmp1);
        getline(fic, tmp1, '/');
        date.mois = stoi(tmp1);
        getline(fic, tmp1, ' ');
        date.annee = stoi(tmp1);
        getline(fic, tmp1, ':');
        date.heure = stoi(tmp1);
        getline(fic, tmp1, ';');
        date.min = stoi(tmp1);
        cout << date << endl;
        string idCapteur;
        getline(fic, idCapteur, ';');
        cout << idCapteur << endl;
        SerieMesures serieMesures(idCapteur, date);
        vector<Mesure> liste_4_Mesures;
        getline(fic, tmp1, ';');
        getline(fic, tmp2, '\n');
        getchar();
        mesure = Mesure(stof(tmp2), tmp1);
        serieMesures.ajouterMesure(mesure);
        liste_4_Mesures.push_back(mesure);
        fic.ignore ( numeric_limits < streamsize >::max ( ), ';' );
        fic.ignore ( numeric_limits < streamsize >::max ( ), ';' );
        getline(fic, tmp1, ';');
        getline(fic, tmp2, '\n');
        getchar();
        mesure = Mesure(stof(tmp2), tmp1);
        serieMesures.ajouterMesure(mesure);
        liste_4_Mesures.push_back(mesure);
        fic.ignore ( numeric_limits < streamsize >::max ( ), ';' );
        fic.ignore ( numeric_limits < streamsize >::max ( ), ';' );
        getline(fic, tmp1, ';');
        getline(fic, tmp2, '\n');
        getchar();
        mesure = Mesure(stof(tmp2), tmp1);
        serieMesures.ajouterMesure(mesure);
        liste_4_Mesures.push_back(mesure);
        fic.ignore ( numeric_limits < streamsize >::max ( ), ';' );
        fic.ignore ( numeric_limits < streamsize >::max ( ), ';' );
        getline(fic, tmp1, ';');
        getline(fic, tmp2, '\n');
        getchar();
        mesure = Mesure(stof(tmp2), tmp1);
        serieMesures.ajouterMesure(mesure);
        liste_4_Mesures.push_back(mesure);
        
        listeSeriesMesures.push_back(serieMesures);

        cout << "Date : " << listeSeriesMesures.back().getDate() << endl;
        cout << "Id capteur : " << listeSeriesMesures.back().getCapteur() << endl;
        cout << "Mesures : " ;
        for (vector<Mesure>::iterator it = listeSeriesMesures.back().getListeMesures().begin ( ) ; it != listeSeriesMesures.back().getListeMesures().end ( ) ; ++it )
        {
            cout << "(" << (*it).getAttribut() << ") " << (*it).getValeur() << " ;";
        }
        
    }
    fic.close();
}

void loadSensors(){
    string id; 
    float lat;
    float lon; 
    
    ifstream fic;
    
    fic.open("./dataset/sensors.csv");
    if(!fic){
        cout << " ***  LE FICHIER EST INTROUVABLE" << endl;
    }

    // list<Capteur>::iterator it = maListeDeCapteur.begin();
    // char * buffer = new char[100];
    string buffer;
    getline(fic, buffer, ';');
    while(!fic.eof()){
        
        id = buffer; 
        // cout <<"BUFFER id: " <<buffer << endl;
        getline(fic, buffer, ';');
        // cout <<"BUFFER lat: " <<buffer << endl;
        lat = stof(buffer);
        getline(fic, buffer, ';');
        // cout <<"BUFFER lon: " <<buffer << endl;
        lon = stof(buffer);
        getline(fic, buffer, ';');
        // cout <<"FIN: " <<buffer << endl;
        Capteur capteurARajoute = Capteur(id,lat,lon);
        maListeDeCapteur.push_back(capteurARajoute);
        // it++;
    }
}

int main(){
    cout << "****** Debut test initialisation des mesures" << endl;
    loadMeasurements();
    cout << "****** Fin test initialisation des mesures" << endl;
    cout << "****** Debut test initialisation des capteurs" << endl;
    loadSensors();
    cout << "****** Debut test initialisation des capteurs" << endl;
    return 0;
}