#include <iostream>
#include <ctime>
#include "Mesure.h"
#include "SerieMesures.h"
#include "Time.cpp"
using namespace std;
int main()
{
    Mesure *m = new Mesure(0.4545, "O3");
    cout << m->getValeur() << endl;
    Temps tem;
    tem.sec = 0;
    tem.min = 0;
    tem.heure = 0;
    tem.jour = 0;
    tem.mois = 0;
    tem.annee = 0;
    SerieMesures *s = new SerieMesures(tem);
    s->ajouterMesure(*m);
    cout << s->getMesure(0).getValeur() << endl;
    Temps date = s->getDate();
    cout << date.sec << endl;
    cout << m->getAttribut() << endl;
}