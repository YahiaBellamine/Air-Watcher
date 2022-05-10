#include <iostream>
#include "Mesure.h"
#include "SerieMesures.h"
using namespace std;
int main()
{
    Mesure *m = new Mesure(0.4545);
    cout << m->getValeur() << endl;

    SerieMesures *s = new SerieMesures();
    s->ajouterMesure(*m);
    cout << s->getMesure(0).getValeur() << endl;
}