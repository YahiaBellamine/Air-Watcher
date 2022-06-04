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
        cout << " *****  LE FICHIER EST INTROUVABLE" << endl;
    }
    char * buffer = new char[100];
    while(!fic.eof()){
        
        fic.getline(buffer,100, ';'); 
        fic.getline(buffer,100, ';');  
        fic.getline(buffer,100, ';');  
        float valeurMesure = stof(buffer);
        fic.getline(buffer,100, ';');  
        string idMesure = buffer;
        Mesure nouvelleMesure = Mesure (valeurMesure, idMesure);
        toutesLesMesures.insert (it,nouvelleMesure);
        it++;
    }
    fic.close();
    return toutesLesMesures;
}
//------------------------------------------------- Surcharge d'opérateurs



//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées