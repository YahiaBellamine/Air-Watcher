#ifndef TEMPS_H
#define TEMPS_H
#include <iostream>
using namespace std;

class Temps
{
    public:

        Temps(int s = 0, int m = 0, int h = 0, int j = 0, int ms = 0, int a = 0);
        friend ostream & operator<< (ostream & os, const Temps & date);
        static int difftime(Temps t1, Temps t2);

        int sec;
        int min;
        int heure;
        int jour;
        int mois;
        int annee;
};

#endif // TEMPS_H