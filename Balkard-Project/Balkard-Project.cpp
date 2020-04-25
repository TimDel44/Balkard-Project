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
#include <SFML/Graphics.hpp>
#include <sstream>

#include "carteElixir.h"
#include "cartePotion.h"
#include "carteSort.h"
#include "carteRituel.h"
#include "carte.h"

#include "personnage.h"
#include "carteArgent.h"
#include "joueur.h"
#include "Deck.h"
#include "Titre.h"
#include "graphics.h"
#include "miseEnPage.h"

using namespace std;

/*void Color(int couleurDuTexte, int couleurDeFond) {
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, couleurDeFond * 16 + couleurDuTexte);
}
*/
int main()
{
    srand(time(NULL));

    Deck* deck = new Deck;
    deck->melangerDeck();
    string nom = "DHB";

    personnage* perso1 = new personnage(nom);
    joueur* player1 = new joueur(perso1);
    personnage* perso2 = new personnage("Big \'E\'");
    joueur* player2 = new joueur(perso2);
    //-------------------------------------------------------------*/
    //sf::RenderWindow window(sf::VideoMode(1000, 800), "Balkard-Project", sf::Style::Close | sf::Style::Titlebar);
    miseEnPage* mep = new miseEnPage();

    while (mep->getWindow()->isOpen())
    {
        sf::Event evnt;
        while (mep->getWindow()->pollEvent(evnt))
        {
            switch (evnt.type)
            {
            case sf::Event::Closed:
                mep->getWindow()->close();
                break;
                case sf::Event::TextEntered:
                    if (evnt.text.unicode < 128) {
                        printf("%c", evnt.text.unicode);
                    }
            }
        }
        mep->getWindow()->clear();

        while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
        {
            sf::Event evnt;
            while (mep->getWindow()->pollEvent(evnt))
            {
                switch (evnt.type)
                {
                case sf::Event::Closed:
                    mep->getWindow()->close();
                    break;
                    //case sf::Event::TextEntered:
                    //    if (evnt.text.unicode < 128) {
                    //        printf("%c", evnt.text.unicode);
                    //    }
                }
            }
            mep->getWindow()->clear();
            mep->Titre();
            mep->getWindow()->display();
        }
        // <- mettre une animation de disparition pour l'écran de titre
        mep->getWindow()->clear();
        //mep->affichagePlateau(player1, player2);
        player1->joueurCombat(player2, deck, mep->getWindow());
        //mep->getWindow()->clear();
   //     deck->afficherDeck(mep->getWindow());
        //mep->affichageNom(window, nom);
        //window.draw(playercard);
        //mep->getWindow()->display();
        //player1->joueurCombat(player2, deck, mep->getWindow());
        Sleep(5000);
    }

}
/*    srand(time(NULL));

    cout << " 888888ba  oo                                                                                                 888888ba           dP dP                               dP" << endl;
    cout << " 88    `8b                                                                                                    88    `8b          88 88                               88" << endl;
    cout << " 88aaaa8P' dP .d8888b. 88d888b. dP   .dP .d8888b. 88d888b. dP    dP .d8888b.    .d8888b. dP    dP 88d888b.    88aaaa8P' .d8888b. 88 88  .dP  .d8888b. 88d888b. .d888b88" << endl;
    cout << " 88   `8b. 88 88ooood8 88'  `88 88   d8' 88ooood8 88'  `88 88    88 88ooood8    Y8ooooo. 88    88 88'  `88    88   `8b. 88'  `88 88 88888\"   88\'  `88 88'  `88 88\'  `88" << endl;
    cout << " 88    .88 88 88.  ... 88    88 88 .88'  88.  ... 88    88 88.  .88 88.  ...          88 88.  .88 88          88    .88 88.  .88 88 88  `8b. 88.  .88 88       88.  .88" << endl;
    cout << " 88888888P dP `88888P' dP    dP 8888P'   `88888P' dP    dP `88888P' `88888P'    `88888P' `88888P' dP          88888888P `88888P8 dP dP   `YP `88888P8 dP       `88888P8    88    88    88 "<< endl;
    //new Titre();
    Deck* deck= new Deck;
    deck->melangerDeck();
    //deck->afficherDeck();
    //deck->pioche();
    //deck->afficherPioche();

    string nom;
    cout << "\n\n\n\n\n\nEntrez le nom du joueur 1\n" << endl;
    cin >> nom;
    system("cls");

    personnage* perso1 = new personnage(nom);
    joueur* player1 = new joueur(perso1);
    
    //player1->choisirCarte();
    //player1->afficherMain();
 

   
    string nom2;
    cout << "\n\n\n\n\n\nEntrez le nom du joueur 2\n" << endl;
    cin >> nom2;
    system("cls");
    personnage* perso2 = new personnage(nom2"Big \'E\'");
    joueur* player2 = new joueur(perso2);

    //string pause;
    //cin >> pause;
    player1->joueurCombat(player2, deck);

    return 0;
}
*/