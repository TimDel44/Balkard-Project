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
#include "Deck.h"
#include "Titre.h"


using namespace std;



int main()
{

    srand(time(NULL));
    cout << " 888888ba  oo                                                                                                 888888ba           dP dP                               dP" << endl;
    cout << " 88    `8b                                                                                                    88    `8b          88 88                               88" << endl;
    cout << " 88aaaa8P' dP .d8888b. 88d888b. dP   .dP .d8888b. 88d888b. dP    dP .d8888b.    .d8888b. dP    dP 88d888b.    88aaaa8P' .d8888b. 88 88  .dP  .d8888b. 88d888b. .d888b88" << endl;
    cout << " 88   `8b. 88 88ooood8 88'  `88 88   d8' 88ooood8 88'  `88 88    88 88ooood8    Y8ooooo. 88    88 88'  `88    88   `8b. 88'  `88 88 88888\"   88\'  `88 88'  `88 88\'  `88" << endl;
    cout << " 88    .88 88 88.  ... 88    88 88 .88'  88.  ... 88    88 88.  .88 88.  ...          88 88.  .88 88          88    .88 88.  .88 88 88  `8b. 88.  .88 88       88.  .88" << endl;
    cout << " 88888888P dP `88888P' dP    dP 8888P'   `88888P' dP    dP `88888P' `88888P'    `88888P' `88888P' dP          88888888P `88888P8 dP dP   `YP `88888P8 dP       `88888P8    88    88    88 "<< endl;
    //new Titre();
    new Deck();
    string nom;
    cout << "Entrez le nom du joueur\n" << endl;
    cin >> nom;

    personnage* perso1 = new personnage(nom);
    joueur* player1 = new joueur(perso1);
    player1->afficherJoueur();
   

    personnage* perso2 = new personnage("DHB");
    joueur* player2 = new joueur(perso2);

    player1->joueurCombat(player2);
    //perso1->combat(perso2);

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
