#include "Deck.h"
#include "carte.h"
#include "cartePotion.h"
#include "carteElixir.h"
#include "carteArgent.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <ctime>

Deck::Deck()
{
    string objet[3] = { "Potion","Elixir","Pieces" };
    string stat[4] = { "Vie", "Attaque", "Defense", "Percep\." };
    string niveau[3] = { "I", "II", "III" };
    int a;
    int s;
    int i;
    int b;
    int valeur;
    int nbdecarte;
    this->cartesPioche;
    this->cartes;
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

    for (i = 0; i < 14; i++) {
        valeur = rand() % 90 + 10;
        cartes.push_back(new carteArgent(objet[2], valeur));
    }

    /*for (i = 0; i < cartes.size(); i++) {
        delete cartes[i];
    }*/
}

void Deck::melangerDeck() {
    random_shuffle(this->cartes.begin(), this->cartes.end());
}

void Deck::afficherDeck() {
    int i;
    for (i = 0; i < this->cartes.size(); i++) {
        cartes[i]->afficher();
    }
    cartes.size();
    cout << endl;
}
void Deck::suppCarte() {
    this->cartes.erase(cartes.begin());
}
/*void Deck::pioche() {
    this->cartesPioche.clear();
   // this->cartesPioche;
    for (int i = 0; i < 4; i++) {
        this->cartesPioche.push_back(cartes[cartes.size()-(1+i)]);
        this->cartes.pop_back();
    }
}*/
void Deck::checkTaille() {
   cout << this->cartes.size() << endl;
}
/*void Deck::afficherPioche() {
    int i;
    for (i = 0; i < 7; i++) {
        cartesPioche[i]->afficher();
    }
}*/
