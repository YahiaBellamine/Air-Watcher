#include <iostream>
#include <ctime>
#include "Mesure.h"
#include "SerieMesures.h"
using namespace std;
int main()
{
    Mesure *m = new Mesure(0.4545);
    cout << m->getValeur() << endl;

    SerieMesures *s = new SerieMesures(time(0));
    s->ajouterMesure(*m);
    cout << s->getMesure(0).getValeur() << endl;
    time_t date = s->getDate();
    cout << ctime(&date) << endl;
}