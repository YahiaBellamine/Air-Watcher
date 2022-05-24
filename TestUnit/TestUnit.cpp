/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Xxx> (fichier Xxx.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TestUnit.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// Xxx::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
#include "../Model/Mesure.h"
#include "../Model/Capteur.h"
#include "../Model/SerieMesures.h"
#include "../Controller/ActionQualiteAir.h"
#include <math.h>
#include <iterator>
#include <algorithm>
#include <string>
#include <list>
using namespace std;

bool TestUnit::Test1()
{
    bool test1 = false;
    bool test2 = false;
    bool test3 = false;

    cout << ".. Test 1 : Moyenne de la qualité de l'air sur une zone " << endl;
    cout << "..... Etape 1 : calcul de la moyenne de capteurs" << endl;

    Mesure *m1 = new Mesure(1.0, "SO2");
    Mesure *m2 = new Mesure(5.0, "O3");
    Mesure *m3 = new Mesure(20.0, "NO2");
    Mesure *m4 = new Mesure(50.0, "PM10");
    Capteur *cap = new Capteur(1, 0.5, 0.5);
    SerieMesures *sm1 = new SerieMesures(cap, Temps(0, 0, 0, 0, 0, 0));
    sm1->ajouterMesure(m1);
    sm1->ajouterMesure(m2);
    sm1->ajouterMesure(m3);
    sm1->ajouterMesure(m4);

    Mesure *m5 = new Mesure(2.0, "SO2");
    Mesure *m6 = new Mesure(15.0, "O3");
    Mesure *m7 = new Mesure(30.0, "NO2");
    Mesure *m8 = new Mesure(50.1, "PM10");
    Capteur *cap2 = new Capteur(2, 0.5, 0.5);
    SerieMesures *sm2 = new SerieMesures(cap2, Temps(0, 0, 0, 0, 0, 0));
    sm2->ajouterMesure(m5);
    sm2->ajouterMesure(m6);
    sm2->ajouterMesure(m7);
    sm2->ajouterMesure(m8);

    list<SerieMesures> *testMoyenneAireSerie = new list<SerieMesures>;
    testMoyenneAireSerie->insert(testMoyenneAireSerie->begin(), *sm1);
    testMoyenneAireSerie->insert(testMoyenneAireSerie->begin(), *sm2);
    list<Capteur> *testMoyenneAireCap = new list<Capteur>;
    testMoyenneAireCap->insert(testMoyenneAireCap->begin(), *cap);
    testMoyenneAireCap->insert(testMoyenneAireCap->begin(), *cap2);
    float *moyenneTest = ActionQualiteAir::moyenneQualiteAir(0.5, 0.5, 100, testMoyenneAireSerie, testMoyenneAireCap, Temps(0, 0, 0, 0, 0, 0));
    if (moyenneTest[0] == (float)1.5 && moyenneTest[1] == (float)10 && moyenneTest[2] == (float)25 && moyenneTest[3] == (float)50.05)
    {
        cout << "...... ETAPE 1 PASSEE" << endl;
        test1 = true;
    }
    else
    {
        cout << "...... /!\\ ETAPE 1 NON PASSEE /!\\" << endl;
        test1 = false;
    }

    cout << "..... Etape 2 : vérification de la fonctionnalité de zone" << endl;
    Mesure *m9 = new Mesure(30.0, "SO2");
    Mesure *m10 = new Mesure(30.0, "O3");
    Mesure *m11 = new Mesure(30.0, "NO2");
    Mesure *m12 = new Mesure(30.0, "PM10");
    Capteur *cap3 = new Capteur(3, 5.5, 5.5);
    SerieMesures *sm3 = new SerieMesures(cap3, Temps(0, 0, 0, 0, 0, 0));
    sm3->ajouterMesure(m9);
    sm3->ajouterMesure(m10);
    sm3->ajouterMesure(m11);
    sm3->ajouterMesure(m12);

    Mesure *m13 = new Mesure(1.0, "SO2");
    Mesure *m14 = new Mesure(5.0, "O3");
    Mesure *m15 = new Mesure(20.0, "NO2");
    Mesure *m16 = new Mesure(50.0, "PM10");
    Capteur *cap4 = new Capteur(1, 0.5, 0.5);
    SerieMesures *sm4 = new SerieMesures(cap4, Temps(0, 0, 0, 0, 0, 0));
    sm4->ajouterMesure(m13);
    sm4->ajouterMesure(m14);
    sm4->ajouterMesure(m15);
    sm4->ajouterMesure(m16);

    list<SerieMesures> *testMoyenneAireSerie2 = new list<SerieMesures>;
    testMoyenneAireSerie2->insert(testMoyenneAireSerie2->begin(), *sm4);
    testMoyenneAireSerie2->insert(testMoyenneAireSerie2->begin(), *sm3);
    list<Capteur> *testMoyenneAireCap2 = new list<Capteur>;
    testMoyenneAireCap2->insert(testMoyenneAireCap2->begin(), *cap4);
    testMoyenneAireCap2->insert(testMoyenneAireCap2->begin(), *cap3);

    float *moyenneTest2 = ActionQualiteAir::moyenneQualiteAir(0.5, 0.5, 5, testMoyenneAireSerie2, testMoyenneAireCap2, Temps(0, 0, 0, 0, 0, 0));
    cout << moyenneTest2[0] << " : " << moyenneTest2[1] << " : " << moyenneTest2[2] << " : " << moyenneTest2[3] << endl;
    if (moyenneTest2[0] == (float)1.0 && moyenneTest2[1] == (float)5.0 && moyenneTest2[2] == (float)20.0 && moyenneTest2[3] == (float)50.0)
    {
        cout << "...... ETAPE 2 PASSEE" << endl;
        test2 = true;
    }
    else
    {
        cout << "...... /!\\ ETAPE 2 NON PASSEE /!\\" << endl;
        test2 = false;
    }
    cout << "..... Etape 3 : vérification de la fonctionnalité de temps" << endl;

    bool testGeneral = (test1 && test2 && test3);
    if (testGeneral)
    {
        cout << ".. TEST 1 PASSE" << endl;
    }
    else
    {
        cout << ".. /!\\ TEST 1 NON PASSE /!\\" << endl;
    }
    return testGeneral;
}

bool TestUnit::AllTests()
{
    cout << endl
         << endl
         << "-------- TEST UNITS ----------" << endl
         << endl
         << " --->  TEST 1 : ";
    Test1();
}