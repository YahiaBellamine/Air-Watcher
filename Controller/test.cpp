#include <iostream>
using namespace std;
#include "ActionMesure.h"

int main(){
    cout << "****** Debut test initialisation des mesures" << endl;
    ActionMesure() actionMesure;
    list<Mesure> maListe = ActionMesure().initialisationMesure();
    cout << "****** Fin test initialisation des mesures" << endl;
    return 0;
}