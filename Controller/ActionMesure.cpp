#include <iostream>
#include <cstring>
#include <fstream>
#include <istream>

//------------------------------------------------------ Include personnel
#include "ActionMesure.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
list<Mesure> initialisationMesure(){
    list<Mesure> toutesLesMesures; 
    list<Mesure>::iterator it;
    it = toutesLesMesures.begin();
    ifstream fic;
    fic.open("../dataset/measurements.csv");
    if(!fic){
        cout << " *****  LE FICHIER EST INTROUVABLE"
    }
    char * buffer = new char[100];
    while(!monfic.eof()){
        
        monfic.getline(buffer,100, ';'); 
        monfic.getline(buffer,100, ';');  
        monfic.getline(buffer,100, ';');  
        float valeurMesure = stof(buffer);
        monfic.getline(buffer,100, ';');  
        string idMesure = buffer;
        Mesure nouvelleMesure = new Mesure (valeurMesure, idMesure);
        toutesLesMesures.insert (it,nouvelleMesure);
        it++;
    }
    fic.close();
}
//------------------------------------------------- Surcharge d'opérateurs



//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées