// Balkard-Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

#include "carteElixir.h"
#include "cartePotion.h"
#include "carteSort.h"
#include "carte.h"

#include <cstdlib>
#include <ctime>
#ifdef _WIN32
#include <windows.h>
#endif
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
#include <ctime>

#include "personnage.h"
#include "carteArgent.h"
#include "joueur.h"


using namespace std;

int main()
{

    srand(time(NULL));
    cout << "Bienvenue sur Balkard...\n" << endl;

    string nom;
    cout << "Entrez le nom du joueur\n" << endl;
    cin >> nom;

    personnage* perso1 = new personnage(nom);
    joueur* player1 = new joueur(perso1);
    player1->afficherJoueur();

    personnage* perso2 = new personnage("DHB");

    perso1->combat(perso2);


    return 0;*/
    int a = 0;
    int s = 0;
    vector<carte*> cartes;
    cartes.push_back(new cartePotion("PotionVieII", 2, 1));
    cartes.push_back(new carteElixir("ElixirAttI", 1, 2));
    cartes.push_back(new cartePotion("PotionDefIII", 3, 3));

    cartes[0]->afficher();
    cartes[1]->afficher();
    cartes[2]->afficher();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
