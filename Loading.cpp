#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <limits>
#include <vector>
#include <list>
#include <map>
#include "Model/SerieMesures.h"
#include "Model/Temps.h"
#include "Model/Mesure.h"
#include "Model/Attribut.h"
#include "Model/Capteur.h"
#include "Model/Fournisseur.h"
#include "Model/IndividuPrive.h"
#include "Controller/ActionNettoyeur.h"
#include "Controller/ActionQualiteAir.h"
#include "Controller/ActionCapteur.h"

static list<SerieMesures> listeSeriesMesures;
static list<Attribut> listeAttributs;
static map<string, Capteur> listeCapteursIntermediaires;

static map<string, Capteur> listeCapteurs;
static list<Nettoyeur> listeNettoyeurs;
static map<string, Fournisseur> listeFournisseurs;
static map<string, IndividuPrive> listeUtilisateurs;

void loadMeasurements()
{
    ifstream fic("./dataset/measurements.csv");
    if (!fic)
    {
        cout << " ERREUR D'OUVERTURE DU FICHIER ! " << endl;
    }
    string tmp1, tmp2;
    string idCapteur;
    Temps date;
    Mesure mesure;
    while (!fic.eof())
    {
        getline(fic, tmp1, '/');
        date.jour = stoi(tmp1);
        getline(fic, tmp1, '/');
        date.mois = stoi(tmp1);
        getline(fic, tmp1, ' ');
        date.annee = stoi(tmp1);
        getline(fic, tmp1, ':');
        date.heure = stoi(tmp1);
        getline(fic, tmp1, ';');
        date.min = stoi(tmp1);
        getline(fic, idCapteur, ';');
        SerieMesures serieMesures(date);
        getline(fic, tmp1, ';');
        getline(fic, tmp2, '\n');
        mesure = Mesure(stof(tmp2), tmp1);
        serieMesures.ajouterMesure(mesure);
        fic.ignore(numeric_limits<streamsize>::max(), ';');
        fic.ignore(numeric_limits<streamsize>::max(), ';');
        getline(fic, tmp1, ';');
        getline(fic, tmp2, '\n');
        mesure = Mesure(stof(tmp2), tmp1);
        serieMesures.ajouterMesure(mesure);
        fic.ignore(numeric_limits<streamsize>::max(), ';');
        fic.ignore(numeric_limits<streamsize>::max(), ';');
        getline(fic, tmp1, ';');
        getline(fic, tmp2, '\n');
        mesure = Mesure(stof(tmp2), tmp1);
        serieMesures.ajouterMesure(mesure);
        fic.ignore(numeric_limits<streamsize>::max(), ';');
        fic.ignore(numeric_limits<streamsize>::max(), ';');
        getline(fic, tmp1, ';');
        getline(fic, tmp2, '\n');
        mesure = Mesure(stof(tmp2), tmp1);
        serieMesures.ajouterMesure(mesure);
        listeSeriesMesures.push_back(serieMesures);
        Capteur capteur = listeCapteursIntermediaires.find(idCapteur)->second;
        capteur.ajouterSerieMesures(serieMesures);
        listeCapteurs.insert(pair<string, Capteur>(idCapteur, capteur));
        /* cout << listeSeriesMesures.back().getListeMesures().begin()->getValeur() << endl;
        cout << "Date : " << listeSeriesMesures.back().getDate();
        cout << "Id capteur : " << listeSeriesMesures.back().getCapteur() << endl;
        cout << "Mesures : " << endl;
        for (vector<Mesure>::iterator it = listeSeriesMesures.back().getListeMesures().begin() ; it != listeSeriesMesures.back().getListeMesures().end() ; ++it )
        {
            cout << "(" << it->getAttribut() << ") " << it->getValeur() << " ;" << endl;
        }
        cout << listeSeriesMesures.back().getListeMesures().begin()->getValeur() << endl; */
    }
}

void loadSensors()
{
    ifstream fic;

    fic.open("./dataset/sensors.csv");
    if (!fic)
    {
        cout << " ***  LE FICHIER EST INTROUVABLE" << endl;
    }

    // list<Capteur>::iterator it = maListeDeCapteur.begin();
    // char * buffer = new char[100];
    string id, lat, lon;
    while (!fic.eof())
    {
        getline(fic, id, ';');
        getline(fic, lat, ';');
        getline(fic, lon, ';');
        fic.ignore(1, '\n');
        Capteur capteur(id, stof(lat), stof(lon));
        listeCapteursIntermediaires.insert(pair<string, Capteur>(id, capteur));
        // it++;
    }
}

void loadAttributes()
{
    ifstream fic("./dataset/attributes.csv");
    if (!fic)
    {
        cout << " ERREUR D'OUVERTURE DU FICHIER ! " << endl;
    }
    string id, unite, description;
    while (!fic.eof())
    {
        getline(fic, id, ';');
        getline(fic, unite, ';');
        getline(fic, description, ';');
        Attribut attribut(id, unite, description);
        listeAttributs.push_back(attribut);
    }
}

void loadProviders()
{
    ifstream fic("./dataset/providers.csv");
    if (!fic)
    {
        cout << " ERREUR D'OUVERTURE DU FICHIER ! " << endl;
    }
    string idFournisseur, idNettoyeur;
    while (!fic.eof())
    {
        getline(fic, idFournisseur, ';');
        getline(fic, idNettoyeur, ';');
        fic.ignore(1, '\n');
        Fournisseur fournisseur(idFournisseur);
        listeFournisseurs.insert(pair<string, Fournisseur>(idNettoyeur, fournisseur));
    }
}

void loadCleaners()
{
    ifstream fic("./dataset/cleaners.csv");
    if (!fic)
    {
        cout << " ERREUR D'OUVERTURE DU FICHIER ! " << endl;
    }
    string id, lat, lon, tmp;
    Temps tDeb, tFin;
    while (!fic.eof())
    {
        getline(fic, id, ';');
        getline(fic, lat, ';');
        getline(fic, lon, ';');

        getline(fic, tmp, '-');
        tDeb.annee = stoi(tmp);
        getline(fic, tmp, '-');
        tDeb.mois = stoi(tmp);
        getline(fic, tmp, ' ');
        tDeb.jour = stoi(tmp);
        getline(fic, tmp, ':');
        tDeb.heure = stoi(tmp);
        getline(fic, tmp, ':');
        tDeb.min = stoi(tmp);
        getline(fic, tmp, ';');
        tDeb.sec = stoi(tmp);

        getline(fic, tmp, '-');
        tFin.annee = stoi(tmp);
        getline(fic, tmp, '-');
        tFin.mois = stoi(tmp);
        getline(fic, tmp, ' ');
        tFin.jour = stoi(tmp);
        getline(fic, tmp, ':');
        tFin.heure = stoi(tmp);
        getline(fic, tmp, ':');
        tFin.min = stoi(tmp);
        getline(fic, tmp, ';');
        tFin.sec = stoi(tmp);
        fic.ignore(1, '\n');

        Fournisseur f = listeFournisseurs.find(id)->second;
        Nettoyeur nettoyeur(id, stof(lat), stof(lon), tDeb, tFin, &f);
        f.ajouterNettoyeur(nettoyeur);
        listeNettoyeurs.push_back(nettoyeur);
    }
}

void loadUsers()
{
    ifstream fic("./dataset/users.csv");
    if (!fic)
    {
        cout << " ERREUR D'OUVERTURE DU FICHIER ! " << endl;
    }
    string idUser, idCapteur;
    while (!fic.eof())
    {
        getline(fic, idUser, ';');
        getline(fic, idCapteur, ';');
        fic.ignore(1, '\n');
        IndividuPrive user(idUser);
        Capteur capteur = listeCapteurs.find(idCapteur)->second;
        user.ajouterCapteur(capteur);
        listeUtilisateurs.insert(pair<string, IndividuPrive>(idUser, user));
    }
}

int main()
{
    cout << "****** Debut test initialisation des capteurs" << endl;
    loadSensors();
    cout << "****** Fin test initialisation des capteurs" << endl;
    cout << "****** Debut test initialisation des mesures" << endl;
    loadMeasurements();
    cout << "****** Fin test initialisation des mesures" << endl;
    cout << "****** Debut test initialisation des fournisseurs" << endl;
    loadProviders();
    cout << "****** Fin test initialisation des fournisseurs" << endl;
    cout << "****** Debut test initialisation des nettoyeurs" << endl;
    loadCleaners();
    cout << "****** Fin test initialisation des nettoyeurs" << endl;
    cout << "****** Debut test initialisation des attributs" << endl;
    loadAttributes();
    cout << "****** Fin test initialisation des attributs" << endl;
    cout << "****** Debut test initialisation des utilisateurs" << endl;
    loadUsers();
    cout << "****** Fin test initialisation des utilisateurs" << endl;

    cout << "Veuillez choisir le type de compte auquel vous voulez vous connecter :" << endl;
    cout << "   1. Agence gouvernementale" << endl;
    cout << "   2. Utilisateur privé" << endl;
    cout << "   3. Fournisseur" << endl;
    cout << "" << endl;
    cout << "   0. Se déconnecter" << endl;

    string identifiant;
    int buffer;
    string type;
    scanf("%d", &buffer);
    bool etape1 = true;
    while (etape1)
    {
        if (buffer == 1)
        {
            type = "agenceGouvernementale";
            etape1 = false;
        }
        else if (buffer == 2)
        {
            type = "individuPrive";

            etape1 = false;
        }
        else if (buffer == 3)
        {
            type = "fournisseur";
            etape1 = false;
        }
        else if (buffer == 0)
        {
            return 0;
        }
        else
        {
            printf("/!\\ Requête non reconnue : Sécurité/Comportement non prévu -> quitter l'application\r\n");
            // scanf("%d", &buffer);
            return 0;
        }
    }

    cout << "Veuillez entrer l'identifiant de votre compte" << endl;
    if (type == "agenceGouvernementale")
    {
        cout << "identifiant: 7" << endl;
        scanf("%d", &buffer);
        if (buffer == 7)
        {
            identifiant = "agence";
        }
        else
        {
            printf("/!\\ Identifiant introuvable\r\n");
            return 0;
        }
    }
    else if (type == "individuPrive")
    {
        cout << "identifiant 0 ou 1" << endl;
        scanf("%d", &buffer);
        if (buffer == 0)
        {
            identifiant = "User0";
            // valeur de point arbitraire
            // listeUtilisateurs[identifiant].setNombrePoints(12);
        }
        else if (buffer == 1)
        {
            identifiant = "User1";
            // valeur de point arbitraire
            // listeUtilisateurs[identifiant].setNombrePoints(25);
        }
        else
        {
            printf("/!\\ Identifiant introuvable\r\n");
            return 0;
        }
    }
    else if (type == "fournisseur")
    {
        cout << "identifiant 0 ou 1" << endl;
        scanf("%d", &buffer);
        if (buffer == 0)
        {
            identifiant = "Provider0";
            // valeur de point arbitraire
        }
        else if (buffer == 1)
        {
            identifiant = "Provider1";
            // valeur de point arbitraire
        }
        else
        {
            printf("/!\\ Identifiant introuvable\r\n");
            return 0;
        }
    }

    bool etape2 = true;
    while (etape2)
    {
        if (type == "agenceGouvernementale")
        {
            type = "agenceGouvernementale";
            cout << "Veuillez choisir parmi les fonctionnalités suivantes :" << endl;
            cout << "" << endl;
            cout << "   1. Demander la moyenne de la qualité de l'air dans une zone géographique, en moyenne sur une période" << endl;
            cout << "   2. Comparer les similarités entre capteurs" << endl;
            cout << "" << endl;
            cout << "   0. Se déconnecter" << endl;
            scanf("\r\n%d", &buffer);
        }
        else if (type == "individuPrive")
        {
            type = "individuPrive";
            cout << "Veuillez choisir parmi les fonctionnalités suivantes :" << endl;
            cout << "" << endl;
            cout << "   1. Connaitre le nombre de points" << endl;
            cout << "   2. Connaitre ses données de capteur personnel" << endl;
            cout << "" << endl;
            cout << "   0. Se déconnecter" << endl;
            scanf("\r\n%d", &buffer);
        }
        else if (type == "fournisseur")
        {
            type = "fournisseur";
            cout << "Veuillez choisir parmi les fonctionnalités suivantes :" << endl;
            cout << "" << endl;
            cout << "   1. Observer l'impact des purificateurs d'air sur la qualité de l'air" << endl;
            cout << "" << endl;
            cout << "   0. Se déconnecter" << endl;
            scanf("\r\n%d", &buffer);
        }
        else if (buffer == 0)
        {
            return 0;
        }
        else
        {
            printf("/!\\ Requête non reconnue : Sécurité/Comportement non prévu -> quitter l'application\r\n");
            // scanf("%d", &buffer);
            return 0;
        }

        if (buffer == 1)
        {
            if (type == "agenceGouvernementale")
            {
                float abscisse, ordonnee, rayon;
                int annee, mois, jour, heure, minute, seconde;
                cout << "      Veuillez choisir l'abscisse du centre de la zone considérée :" << endl;
                scanf("\r\n%f", &abscisse);
                cout << "      Veuillez choisir l'ordonnée du centre de la zone considérée :" << endl;
                scanf("\r\n%f", &ordonnee);
                cout << "      Veuillez choisir le rayon de la zone :" << endl;
                scanf("\r\n%f", &rayon);
                cout << "      Veuillez choisir l'instant depuis lequel vous voulez regarder les mesures :" << endl;
                cout << "      Annee :" << endl;
                scanf("\r\n%d", &annee);
                cout << "      Mois :" << endl;
                scanf("\r\n%d", &mois);
                cout << "      Jour :" << endl;
                scanf("\r\n%d", &jour);
                cout << "      Heure :" << endl;
                scanf("\r\n%d", &heure);
                cout << "      Minute :" << endl;
                scanf("\r\n%d", &minute);
                cout << "      Seconde :" << endl;
                scanf("\r\n%d", &seconde);

                float *resultats = ActionQualiteAir::moyenneQualiteAir((abscisse), (ordonnee), (rayon), listeCapteurs, Temps((seconde), (minute), (heure), (jour), (mois), (annee)));
                cout << "      La moyenne de la qualité de l'air sur la zone de centre (" << abscisse << "," << ordonnee << ") de rayon " << rayon << " depuis le " << jour << "/" << mois << "/" << annee << " à " << heure << "h" << minute << "m" << seconde << "s est : " << endl;
                cout << "     SO2 : " << resultats[0] << ", O3 : " << resultats[1] << ", NO2 : " << resultats[2] << ", PM10 : " << resultats[3] << endl;
            }
            else if (type == "individuPrive")
            {
                if (identifiant == "User0")
                {
                    cout << "\nNombre de points : " << listeUtilisateurs["User0"].getNombrePoints() << "\n"
                         << endl;
                }
                else if (identifiant == "User1")
                {
                    cout << "\nNombre de points : " << listeUtilisateurs["User1"].getNombrePoints() << "\n"
                         << endl;
                }
                else
                {
                    cout << "\nNombre de points : " << 0 << "\n"
                         << endl;
                }
            }
            else if (type == "fournisseur")
            {
                string idNettoyeurSelectionne;
                float impactNettoyeur = 0.0;
                for (pair<string, Fournisseur> f : listeFournisseurs)
                {
                    if (f.second.getIdFournisseur() == identifiant)
                    {
                        idNettoyeurSelectionne = f.first;
                    }
                }
                for (Nettoyeur n : listeNettoyeurs)
                {
                    if (n.getIdNettoyeur() == idNettoyeurSelectionne)
                    {
                        impactNettoyeur = ActionNettoyeur::evaluerImpactNettoyeur(n, listeCapteurs, listeNettoyeurs);
                    }
                }

                cout << "      L'impact est de : " << impactNettoyeur << endl;
            }
        }
        else if (buffer == 2)
        {
            if (type == "agenceGouvernementale")
            {
                string idCapteurCompare;
                cout << "      Choisissez l'ID du capteur à comparer :" << endl;
                cin >> idCapteurCompare;
                Capteur cap = listeCapteurs[(idCapteurCompare)];
                cout << "CAPTEUR : " << cap << endl;
                cout << "MESURES : " << cap.getSeriesMesures().at(0) << endl;
                vector<Capteur> resultats = ActionCapteur::comparerCapteur(cap, listeCapteurs);
            }
            else if (type == "individuPrive")
            {
                cout << "      Vos capteurs : " << endl;
                for (Capteur c : listeUtilisateurs[identifiant].getListeCapteurs())
                {
                    cout << c << endl;
                    for (SerieMesures sm : c.getSeriesMesures())
                    {
                        cout << sm << endl;
                    }
                }
            }
            else if (type == "fournisseur")
            {
                printf("/!\\ Requête non reconnue : Sécurité/Comportement non prévu -> quitter l'application\r\n");
                return 0;
            }
        }
        else if (buffer == 3)
        {
            if (type == "agenceGouvernementale")
            {
                // vector<Capteur> resultat = comparerCapteur(Capteur &capteurSelectionne, vector<Capteur> &listeCapteurs)
            }
            else if (type == "individuPrive")
            {
                printf("/!\\ Requête non reconnue : Sécurité/Comportement non prévu -> quitter l'application\r\n");
                return 0;
            }
            else if (type == "fournisseur")
            {
                printf("/!\\ Requête non reconnue : Sécurité/Comportement non prévu -> quitter l'application\r\n");
                return 0;
            }
        }
        else if (buffer == 0)
        {
            return 0;
        }
        else
        {
            printf("/!\\ Requête non reconnue : Sécurité/Comportement non prévu -> quitter l'application\r\n");
            // scanf("%d", &buffer);
            return 0;
        }
    }

    return 0;
}