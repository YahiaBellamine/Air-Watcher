#include <iostream>
using namespace std;
#include <cstring>
#include <fstream>
#include <istream>
#include <list>
#include "./Model/Temps.h"
#include "./Model/Capteur.h"






static list<Capteur> maListeDeCapteur; 
// g++ -o main main.cpp Model/Capteur.cpp
void initialisationCapteur(){
    string id; 
    float lat;
    float lon; 
    
    ifstream fic;
    
    fic.open("./dataset/sensors.csv");
    if(!fic){
        cout << " *****  LE FICHIER EST INTROUVABLE" << endl;
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
        getline(fic, buffer, ';');
        // cout <<"FIN: " <<buffer << endl;
        Capteur capteurARajoute = Capteur(id,lat,lon);
        maListeDeCapteur.push_back(capteurARajoute);
        // it++;
    }
}









void initialiserAirWatcher(){
    cout << "** debut initialisation capteurs " << endl;
    initialisationCapteur();
    cout << "** fin initialisation capteurs " << endl;

    // cout << "** debut initialisation capteurs " << endl;
    // initialisationCapteur();
    // cout << "** fin initialisation capteurs " << endl;
}

int main(){
    cout << "********* DEBUT INITIALISATION" << endl;
    initialiserAirWatcher();
    cout << "********* FIN INITIALISATION" << endl;
    return 0;
}