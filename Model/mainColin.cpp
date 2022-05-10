#include <iostream>
#include "Mesure.h"
using namespace std;
int main()
{
    Mesure *m = new Mesure(0.4545);
    cout << m->getValeur();
}