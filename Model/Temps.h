#ifndef TEMPS_H
#define TEMPS_H

struct Temps
{
    int sec;
    int min;
    int heure;
    int jour;
    int mois;
    int annee;

    Temps (int s=0, int m=0, int h=0, int j=0, int ms=0, int a=0) : sec(s), min(m), heure(h), jour(j), mois(ms), annee(a) {}
    
    int difftime(Temps t1, Temps t2){
        int t1_sec = t1.sec+t1.min*60+t1.heure*3600+t1.jour*24*3600+t1.mois*31*24*3600+t1.annee*12*31*24*3600;
        int t2_sec = t2.sec+t2.min*60+t2.heure*3600+t2.jour*24*3600+t2.mois*31*24*3600+t2.annee*12*31*24*3600;
        if(t1_sec < t2_sec)
            return -1;
        else if (t1_sec > t2_sec)
            return 1;
        else    
            return 0;
    }
};

#endif // TEMPS_H