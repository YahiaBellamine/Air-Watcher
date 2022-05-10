using namespace std;
#include <iostream>

#include "Utilisateur.h"

int main()
{
    Utilisateur *monUtilisateur = new Utilisateur("aymane", "mdp");
    cout << monUtilisateur->getIdentifiantUtilisateur() << endl;
    cout << monUtilisateur->getMotDePasse() << endl;

    return 0;
}
