

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
// Xxx::Méthode ( vectore des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
#include "../Model/Mesure.h"
#include "../Model/Capteur.h"
#include "../Model/SerieMesures.h"
#include "../Controller/ActionQualiteAir.h"
#include "../Controller/ActionCapteur.h"
#include <math.h>
#include <iterator>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool TestUnit::Test1()
{
    bool test1 = false;
    bool test2 = false;
    bool test3 = false;

    cout << ".. Test 1 : Moyenne de la qualité de l'air sur une zone " << endl;
    cout << endl
         << "..... Etape 1 : calcul de la moyenne de capteurs" << endl;

    Mesure m1 = Mesure(1.0, "SO2");
    Mesure m2 = Mesure(5.0, "O3");
    Mesure m3 = Mesure(20.0, "NO2");
    Mesure m4 = Mesure(50.0, "PM10");
    Capteur cap = Capteur("1", 0.5, 0.5);
    SerieMesures sm1 = SerieMesures(Temps(10, 0, 0, 0, 0, 0));
    sm1.ajouterMesure(m1);
    sm1.ajouterMesure(m2);
    sm1.ajouterMesure(m3);
    sm1.ajouterMesure(m4);
    cap.ajouterSerieMesures(sm1);

    Mesure m5 = Mesure(2.0, "SO2");
    Mesure m6 = Mesure(15.0, "O3");
    Mesure m7 = Mesure(30.0, "NO2");
    Mesure m8 = Mesure(50.1, "PM10");
    Capteur cap2 = Capteur("2", 0.5, 0.5);
    SerieMesures sm2 = SerieMesures(Temps(0, 0, 0, 0, 0, 0));

    sm2.ajouterMesure(m5);
    sm2.ajouterMesure(m6);
    sm2.ajouterMesure(m7);
    sm2.ajouterMesure(m8);
    cap2.ajouterSerieMesures(sm2);

    vector<Capteur> testMoyenneAireCap;
    testMoyenneAireCap.push_back(cap);
    testMoyenneAireCap.push_back(cap2);
    float *moyenneTest = ActionQualiteAir::moyenneQualiteAir(0.5, 0.5, 100, testMoyenneAireCap, Temps(0, 0, 0, 0, 0, 0));
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

    cout << endl
         << "..... Etape 2 : vérification de la fonctionnalité de zone" << endl;

    cap2.setLatitudeCapteur(5.5);
    cap2.setLongitudeCapteur(5.5);
    vector<Capteur> testMoyenneAireCap2;
    testMoyenneAireCap2.push_back(cap);
    testMoyenneAireCap2.push_back(cap2);

    float *moyenneTest2 = ActionQualiteAir::moyenneQualiteAir(0.5, 0.5, 5, testMoyenneAireCap2, Temps(0, 0, 0, 0, 0, 0));
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
    cout << endl
         << "..... Etape 3 : vérification de la fonctionnalité de temps" << endl;

    vector<Capteur> testMoyenneAireCap3;
    testMoyenneAireCap3.push_back(cap);
    testMoyenneAireCap3.push_back(cap2);

    float *moyenneTest3 = ActionQualiteAir::moyenneQualiteAir(0.5, 0.5, 100, testMoyenneAireCap3, Temps(5, 0, 0, 0, 0, 0));
    if (moyenneTest3[0] == (float)1.0 && moyenneTest3[1] == (float)5.0 && moyenneTest3[2] == (float)20.0 && moyenneTest3[3] == (float)50.0)
    {
        cout << "...... ETAPE 3 PASSEE" << endl;
        test3 = true;
    }
    else
    {
        cout << "...... /!\\ ETAPE 3 NON PASSEE /!\\" << endl;
        test3 = false;
    }

    bool testGeneral = (test1 && test2 && test3);
    if (testGeneral)
    {
        cout << endl
             << ".. TEST 1 PASSE" << endl;
    }
    else
    {
        cout << endl
             << ".. /!\\ TEST 1 NON PASSE /!\\" << endl;
    }
    return testGeneral;
}

bool TestUnit::Test2()
{
    bool test1, testGeneral;
    cout << ".. Test 2 : Comparer les similarités entre capteurs" << endl;
    cout << endl
         << "..... Etape 1 : Vérification de la bonne exclusion des capteurs non ressemblants" << endl;

    Mesure m1 = Mesure(1.0, "SO2");
    Mesure m2 = Mesure(5.0, "O3");
    Mesure m3 = Mesure(20.0, "NO2");
    Mesure m4 = Mesure(50.0, "PM10");
    Capteur cap = Capteur("1", 0.5, 0.5);
    SerieMesures sm1 = SerieMesures(Temps(10, 0, 0, 0, 0, 0));
    sm1.ajouterMesure(m1);
    sm1.ajouterMesure(m2);
    sm1.ajouterMesure(m3);
    sm1.ajouterMesure(m4);
    cap.ajouterSerieMesures(sm1);

    Mesure m5 = Mesure(2.0, "SO2");
    Mesure m6 = Mesure(8.0, "O3");
    Mesure m7 = Mesure(26.0, "NO2");
    Mesure m8 = Mesure(48.1, "PM10");
    Capteur cap2 = Capteur("2", 0.5, 0.5);
    SerieMesures sm2 = SerieMesures(Temps(0, 0, 0, 0, 0, 0));

    sm2.ajouterMesure(m5);
    sm2.ajouterMesure(m6);
    sm2.ajouterMesure(m7);
    sm2.ajouterMesure(m8);
    cap2.ajouterSerieMesures(sm2);

    Mesure m9 = Mesure(6.0, "SO2");
    Mesure m10 = Mesure(14.0, "O3");
    Mesure m11 = Mesure(35.0, "NO2");
    Mesure m12 = Mesure(48.1, "PM10");
    Capteur cap3 = Capteur("3", 0.5, 0.5);
    SerieMesures sm3 = SerieMesures(Temps(0, 0, 0, 0, 0, 0));

    sm3.ajouterMesure(m9);
    sm3.ajouterMesure(m10);
    sm3.ajouterMesure(m11);
    sm3.ajouterMesure(m12);
    cap3.ajouterSerieMesures(sm3);

    vector<Capteur> testMoyenneAireCap;
    testMoyenneAireCap.push_back(cap2);
    testMoyenneAireCap.push_back(cap3);
    vector<SerieMesures> testMoyenneAireSerie;
    testMoyenneAireSerie.push_back(sm1);
    testMoyenneAireSerie.push_back(sm2);
    testMoyenneAireSerie.push_back(sm3);
    vector<Capteur> resultat1 = ActionCapteur::comparerCapteur(cap, testMoyenneAireCap, testMoyenneAireSerie);
    cout << endl
         << resultat1.size() << endl;
    if (resultat1.size() == 1 && resultat1.begin()->getIdCapteur() == "1")
    {
        cout << "...... ETAPE 1 PASSEE" << endl;
        test1 = true;
    }
    else
    {
        cout << "...... /!\\ ETAPE 1 NON PASSEE /!\\" << endl;
        test1 = false;
    }

    // cout << endl << "..... Etape 2 : vérification de la fonctionnalité de zone" << endl;

    testGeneral = test1;
    if (testGeneral)
    {
        cout << endl
             << ".. TEST 1 PASSE" << endl;
    }
    else
    {
        cout << endl
             << ".. /!\\ TEST 1 NON PASSE /!\\" << endl;
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
    bool test1 = Test1();
    cout << endl
         << endl
         << " --->TEST 2 : ";
    bool test2 = Test2();

    return (test1 && test2);
}