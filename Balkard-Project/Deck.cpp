#include "Deck.h"
#include "carte.h"
#include "cartePotion.h"
#include "carteElixir.h"
#include <string>
#include <vector>

Deck::Deck()
{
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



    /*for (i = 0; i < cartes.size(); i++) {
        delete cartes[i];
    }*/
}