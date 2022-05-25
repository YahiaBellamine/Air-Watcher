#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <limits>
#include <vector>
#include <list>
#include <map>
#include "Model/SerieMesures.h"
#include "Model/Temps.h"
#include "Model/Mesure.h"
#include "Model/Attribut.h"
#include "Model/Capteur.h"
#include "Model/Fournisseur.h"
#include "Model/IndividuPrive.h"

static list<SerieMesures> listeSeriesMesures;
static list<Attribut> listeAttributs;
static map<string, Capteur> listeCapteurs; 
static list<Nettoyeur> listeNettoyeurs;
static map<string, Fournisseur> listeFournisseurs;
static list<IndividuPrive> listeUtilisateurs;

void loadMeasurements(){
    ifstream fic("./dataset/measurements.csv");
    if(!fic){
        cout << " ERREUR D'OUVERTURE DU FICHIER ! " << endl;
    }
    string tmp1, tmp2;
    string idCapteur;
    Temps date;
    Mesure mesure;
    while(!fic.eof()){
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
        getline(fic, idCapteur, ';');
        SerieMesures serieMesures(idCapteur, date);
        getline(fic, tmp1, ';');
        getline(fic, tmp2, '\n');
        mesure = Mesure(stof(tmp2), tmp1);
        serieMesures.ajouterMesure(mesure);
        fic.ignore ( numeric_limits < streamsize >::max ( ), ';' );
        fic.ignore ( numeric_limits < streamsize >::max ( ), ';' );
        getline(fic, tmp1, ';');
        getline(fic, tmp2, '\n');
        mesure = Mesure(stof(tmp2), tmp1);
        serieMesures.ajouterMesure(mesure);
        fic.ignore ( numeric_limits < streamsize >::max ( ), ';' );
        fic.ignore ( numeric_limits < streamsize >::max ( ), ';' );
        getline(fic, tmp1, ';');
        getline(fic, tmp2, '\n');
        mesure = Mesure(stof(tmp2), tmp1);
        serieMesures.ajouterMesure(mesure);
        fic.ignore ( numeric_limits < streamsize >::max ( ), ';' );
        fic.ignore ( numeric_limits < streamsize >::max ( ), ';' );
        getline(fic, tmp1, ';');
        getline(fic, tmp2, '\n');
        mesure = Mesure(stof(tmp2), tmp1);
        serieMesures.ajouterMesure(mesure);        
        listeSeriesMesures.push_back(serieMesures);
        Capteur capteur = listeCapteurs.find(idCapteur)->second;
        capteur.ajouterSerieMesures(serieMesures);

        /* cout << listeSeriesMesures.back().getListeMesures().begin()->getValeur() << endl;
        cout << "Date : " << listeSeriesMesures.back().getDate();
        cout << "Id capteur : " << listeSeriesMesures.back().getCapteur() << endl;
        cout << "Mesures : " << endl;
        for (vector<Mesure>::iterator it = listeSeriesMesures.back().getListeMesures().begin() ; it != listeSeriesMesures.back().getListeMesures().end() ; ++it )
        {
            cout << "(" << it->getAttribut() << ") " << it->getValeur() << " ;" << endl;
        }
        cout << listeSeriesMesures.back().getListeMesures().begin()->getValeur() << endl; */
    }
}

void loadSensors(){ 
    ifstream fic;
    
    fic.open("./dataset/sensors.csv");
    if(!fic){
        cout << " ***  LE FICHIER EST INTROUVABLE" << endl;
    }

    // list<Capteur>::iterator it = maListeDeCapteur.begin();
    // char * buffer = new char[100];
    string id, buffer; 
    float lat;
    float lon; 
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
        Capteur capteur(id,lat,lon);
        listeCapteurs.insert(pair<string,Capteur>(id, capteur));
        // it++;
    }
}

void loadAttributes(){
    ifstream fic("./dataset/attributes.csv");
    if(!fic){
        cout << " ERREUR D'OUVERTURE DU FICHIER ! " << endl;
    }
    string id, unite, description;
    while(!fic.eof()){
        getline(fic, id, ';');
        getline(fic, unite, ';');
        getline(fic, description, ';');
        Attribut attribut(id, unite, description);
        listeAttributs.push_back(attribut);
    }
}

void loadProviders(){ 
    ifstream fic("./dataset/providers.csv");
    if(!fic){
        cout << " ERREUR D'OUVERTURE DU FICHIER ! " << endl;
    }
    string idFournisseur, idNettoyeur;
    while(!fic.eof()){
        getline(fic, idFournisseur, ';');
        Fournisseur fournisseur(idFournisseur);
        listeFournisseurs.insert(pair<string, Fournisseur>(idNettoyeur, fournisseur));
    }
}

void loadCleaners(){
    ifstream fic("./dataset/cleaners.csv");
    if(!fic){
        cout << " ERREUR D'OUVERTURE DU FICHIER ! " << endl;
    }
    string id, lat, lon, tmp;
    Temps tDeb, tFin;
    while(!fic.eof()){
        getline(fic, id, ';');
        getline(fic, lat, ';');
        getline(fic, lon, ';');
        
        getline(fic, tmp, '-');
        tDeb.annee = stoi(tmp);
        getline(fic, tmp, '-');
        tDeb.mois = stoi(tmp);
        getline(fic, tmp, ' ');
        tDeb.jour = stoi(tmp);
        getline(fic, tmp, ':');
        tDeb.heure = stoi(tmp);
        getline(fic, tmp, ':');
        tDeb.min = stoi(tmp);
        getline(fic, tmp, ';');
        tDeb.sec = stoi(tmp);

        getline(fic, tmp, '-');
        tFin.annee = stoi(tmp);
        getline(fic, tmp, '-');
        tFin.mois = stoi(tmp);
        getline(fic, tmp, ' ');
        tFin.jour = stoi(tmp);
        getline(fic, tmp, ':');
        tFin.heure = stoi(tmp);
        getline(fic, tmp, ':');
        tFin.min = stoi(tmp);
        getline(fic, tmp, ';');
        tFin.sec = stoi(tmp);

        Fournisseur f = listeFournisseurs.find(id)->second;
        Nettoyeur nettoyeur(id, stof(lat), stof(lon), tDeb, tFin, &f);
        f.ajouterNettoyeur(nettoyeur);
        listeNettoyeurs.push_back(nettoyeur);
    }
}

void loadUsers(){
    ifstream fic("./dataset/users.csv");
    if(!fic){
        cout << " ERREUR D'OUVERTURE DU FICHIER ! " << endl;
    }
    string idUser, idCapteur;
    while(!fic.eof()){
        getline(fic, idUser, ';');
        getline(fic, idCapteur, ';');
        IndividuPrive user(idUser);
        listeUtilisateurs.push_back(user);
        Capteur capteur = listeCapteurs.find(idCapteur)->second;
        user.ajouterCapteur(capteur);
    }
}

int main(){
    cout << "****** Debut test initialisation des capteurs" << endl;
    loadSensors();
    cout << "****** Fin test initialisation des capteurs" << endl;
    cout << "****** Debut test initialisation des mesures" << endl;
    loadMeasurements();
    cout << "****** Fin test initialisation des mesures" << endl;
    cout << "****** Debut test initialisation des fournisseurs" << endl;
    loadProviders();
    cout << "****** Fin test initialisation des fournisseurs" << endl;
    cout << "****** Debut test initialisation des nettoyeurs" << endl;
    loadCleaners();
    cout << "****** Fin test initialisation des nettoyeurs" << endl;
    cout << "****** Debut test initialisation des attributs" << endl;
    loadAttributes();
    cout << "****** Fin test initialisation des attributs" << endl;
    cout << "****** Debut test initialisation des utilisateurs" << endl;
    loadUsers();
    cout << "****** Fin test initialisation des utilisateurs" << endl;
    return 0;
}