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

void deck() {
    string objet[2] = { "Potion","Elixir" };
    string stat[4] = { "Vie", "Attaque", "Defense", "Perception" };
    string niveau[3] = { "I", "II", "III" };

    int a;
    int s;
    int i;
    int b;
    //int valeur = rand() % 90 + 10;
    int nbdecarte;
    vector<carte*> cartes;
    for (a = 0; a < 2; a++) {
        b = (3 - a);
        for (nbdecarte = 0; nbdecarte < b; nbdecarte++) {
            for (s = 0; s < 4; s++) {
                cartes.push_back(new cartePotion(objet[0], stat[s], niveau[a], a, s));
            }
        }
    }
    for (a = 0; a < 1; a++) {
        b = 1;
        for (nbdecarte = 0; nbdecarte < b; nbdecarte++) {
            for (s = 0; s < 4; s++) {
                cartes.push_back(new carteElixir(objet[1], stat[s], niveau[a], a, s));
            }
        }
    }

    for (i = 0; i < cartes.size(); i++) {
        cartes[i]->afficher();
    }

    b = cartes.size();
    cout << b;



    /*for (i = 0; i < cartes.size(); i++) {
        delete cartes[i];
    }*/
}

int main()
{

    srand(time(NULL));
    cout << "Bienvenue sur Balkard...\n" << endl;
    deck();
    /*string nom;
    cout << "Entrez le nom du joueur\n" << endl;
    cin >> nom;

    personnage* perso1 = new personnage(nom);
    joueur* player1 = new joueur(perso1);
    player1->afficherJoueur();

    personnage* perso2 = new personnage("DHB");

    perso1->combat(perso2);
    */
    
    
    
    return 0;
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
