#include "Deck.h"
#include "carte.h"
#include "cartePotion.h"
#include "carteElixir.h"
#include "carteArgent.h"
#include "carteArme.h"
#include "carteArmure.h"
#include "carteTalisman.h"
#include "carteBotte.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <ctime>

Deck::Deck()
{
    string objet[7] = { "Potion","Elixir","Pieces","Armure","Bottes","Arme","Talisman" };
    string stat[4] = { "Vie", "Attaque", "Defense", "Percep\." };
    string niveau[3] = { "I", "II", "III" };
    string materiauArmure[3] = { "Cuir", "Fer", "Or" };
    string materiauArme[3] = { "Bois","Fer","Or" };
    int a;
    int s;
    int i;
    int b;
    int valeur;
    int nbdecarte;
    this->cartesPioche;
    this->cartes;
    //CARTE POTION
    for (a = 0; a < 2; a++) {
        b = (3 - a);
        for (nbdecarte = 0; nbdecarte < b; nbdecarte++) {
            for (s = 0; s < 4; s++) {
                cartes.push_back(new cartePotion(objet[0], stat[s], niveau[a], a, s));
            }
        }
    }
    //CARTE ELIXIR
    for (a = 0; a < 1; a++) {
        b = 1;
        for (nbdecarte = 0; nbdecarte < b; nbdecarte++) {
            for (s = 0; s < 4; s++) {
                cartes.push_back(new carteElixir(objet[1], stat[s], niveau[a], a, s));
            }
        }
    }
    //CARTE ARGENT
    for (i = 0; i < 14; i++) {
        valeur = rand() % 90 + 10;
        cartes.push_back(new carteArgent(objet[2], valeur));
    }
    //CARTE ARMURE et BOTTE
    for (a = 0; a < 3; a++) {
        b = (3 - a);
        for (nbdecarte = 0; nbdecarte < b; nbdecarte++) {
             cartes.push_back(new carteArmure(objet[3], stat[2], materiauArmure[a], a, 2));
             cartes.push_back(new carteBotte(objet[4], stat[2], materiauArmure[a], a, 2));
        }
    }
    //CARTE ARME
    for (a = 0; a < 3; a++) {
        b = (3 - a);
        for (nbdecarte = 0; nbdecarte < b; nbdecarte++) {
            cartes.push_back(new carteArme(objet[5], stat[1], materiauArme[a], a, 1));
        }
    }
    //CARTE TALISMAN
    for (a = 0; a < 3; a++) {
        b = (3 - a);
        for (nbdecarte = 0; nbdecarte < b; nbdecarte++) {
            cartes.push_back(new carteTalisman(objet[6], "PA", niveau[a], a, 6));
        }
    }
    /*
    for (i = 0; i < cartes.size(); i++) {
        delete cartes[i];
    }
    */
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

