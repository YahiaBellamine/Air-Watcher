#include "Temps.h"

Temps::Temps (int s, int m, int h, int j, int ms, int a)
{
    annee = a;
    mois = ms;
    jour = j;
    heure = h;
    min = m;
    sec = s;
}

int Temps::difftime(Temps t1, Temps t2)
    {
        int t1_sec = t1.sec + t1.min * 60 + t1.heure * 3600 + t1.jour * 24 * 3600 + t1.mois * 31 * 24 * 3600 + t1.annee * 12 * 31 * 24 * 3600;
        int t2_sec = t2.sec + t2.min * 60 + t2.heure * 3600 + t2.jour * 24 * 3600 + t2.mois * 31 * 24 * 3600 + t2.annee * 12 * 31 * 24 * 3600;
        if (t1_sec < t2_sec)
            return -1;
        else if (t1_sec > t2_sec)
            return 1;
        else
            return 0;
    }

ostream & operator<< (ostream & os, const Temps & date)
{
    os << date.jour << "/" << date.mois << "/" << date.annee << " " << date.heure << ":" << date.min << ":" << date.sec;
    return os;
}