// Balkard-Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#ifdef _WIN32
#include <windows.h>
#endif
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
#include "personnage.h"


using namespace std;

int main()
{
    cout << "Bienvenue sur Balkard...\n" << endl;

    string nom;
    cout << "Entrez le nom du joueur\n" << endl;
    cin >> nom;

    personnage* player1 = new personnage(nom);

    personnage* player2 = new personnage("DHB");

    for (int i = 0; i < 10; i++) {

        player1->afficher();

        printf("\n------------------------------------------------------------------------\n");

        player2->afficher();


        player1->attaquer(player2);

        printf("\n\n\n");

        player1->afficher();

        printf("\n------------------------------------------------------------------------\n");

        player2->afficher();


        player2->attaquer(player1);

        printf("\n\n\n");

        player1->afficher();

        printf("\n------------------------------------------------------------------------\n");

        player2->afficher();
    }


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
