#include <iostream>
using namespace std;
#include <cstdio>
#include <list>
#include "../Model/Nettoyeur.h"
#include "../Model/Temps.h"
#include <fstream>
#include <istream>
#include <cassert>
#include "../Model/Attribut.h"
static list<Nettoyeur> maListeDeNettoyeur; 
static list<Attribut> maListeDAttribut;


void initialiserAttribut(){
    string idAttribut;
    string unite;
    string description;

    ifstream fic;
    string url = "../dataset/attributes.csv";
    fic.open(url);
    if(!fic){
        cout << " *****  LE FICHIER "<< url <<" EST INTROUVABLE" << endl;
    }



    string buffer;
    getline(fic, buffer, ';'); // Pour passer les 3 cases d'en têtes
    cout << "BUFFER" << buffer << endl;
    getline(fic, buffer, ';');
    cout << "BUFFER" << buffer << endl;
    getline(fic, buffer, ';');
    cout << "BUFFER" << buffer << endl;
    fic.fgetc();
    getline(fic, buffer, ';');
    while(!fic.eof()){
        idAttribut = buffer;
        cout << "id: " << buffer<< endl;

        getline(fic, buffer, ';');
        unite = buffer; 
        cout << "unite: " << buffer<< endl;

        getline(fic, buffer, ';');
        description = buffer; 
        cout << "description: " << description << endl;

        getline(fic, buffer, ';');
        Attribut attributARajouter = Attribut(idAttribut, unite, description);
        maListeDAttribut.push_back(attributARajouter);

        cout << "ATTRIBUT: " << attributARajouter.getId() << " ("  << attributARajouter.getUnite() << ") : " << attributARajouter.getDescription() << ""<< endl;
        // it++;
    }

}





void  initialisationNettoyeur(){
    string id; 
    float lat;
    float lon; 
    Temps start;
    Temps stop; 
    
    ifstream fic;
    string url = "../dataset/cleaners.csv";
    fic.open(url);
    if(!fic){
        cout << " *****  LE FICHIER "<< url <<" EST INTROUVABLE" << endl;
    }

    // list<Capteur>::iterator it = maListeDeCapteur.begin();
    // char * buffer = new char[100];
    string buffer;
    getline(fic, buffer, ';');
    while(!fic.eof()){
        id = buffer; 
        cout <<"BUFFER id: " <<buffer << endl;
        getline(fic, buffer, ';');
        cout <<"BUFFER lat: " <<buffer << endl;
        lat = stof(buffer);
        getline(fic, buffer, ';');
        cout <<"BUFFER lon: " <<buffer << endl;
        lon = stof(buffer);
        getline(fic, buffer, '-');
        start.annee = stoi(buffer);
        getline(fic, buffer, '-');
        start.mois = stoi(buffer);
        getline(fic, buffer, ' ');
        start.mois = stoi(buffer);
        getline(fic, buffer, ':');
        start.heure = stoi(buffer);
        getline(fic, buffer, ':');
        start.min = stoi(buffer);
        getline(fic, buffer, ';');
        start.sec = stoi(buffer);
        cout << start.annee << "/" << start.mois <<  "/" << start.jour <<  "-" << start.heure <<  ":" << start.min << ":" << start.sec<< endl;

        getline(fic, buffer, '-');
        stop.annee = stoi(buffer);
        getline(fic, buffer, '-');
        stop.mois = stoi(buffer);
        getline(fic, buffer, ' ');
        stop.mois = stoi(buffer);
        getline(fic, buffer, ':');
        stop.heure = stoi(buffer);
        getline(fic, buffer, ':');
        stop.min = stoi(buffer);
        getline(fic, buffer, ';');
        stop.sec = stoi(buffer);
        cout << stop.annee << "/" << stop.mois <<  "/" << stop.jour <<  "-" << stop.heure <<  ":" << stop.min << ":" << stop.sec<< endl;


        getline(fic, buffer, ';');
        // cout <<"FIN: " <<buffer << endl;
        // listesSeriesMesures.emplace((    ,   ,   ));
        Nettoyeur nettoyeurARajouter = Nettoyeur(id,lat,lon,start,stop);
        maListeDeNettoyeur.push_back(nettoyeurARajouter);
        // it++;
    }
}


int main(){
    cout << "********* DEBUT INITIALISATION" << endl;
    initialisationNettoyeur();
    cout << "********* DEUXIEME INITIALISATION" <<endl;
    initialiserAttribut();
    cout << "********* FIN INITIALISATION" << endl;
    // assert(1>0);
    return 0;
}