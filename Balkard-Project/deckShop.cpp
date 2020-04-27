#include "deckShop.h"
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

deckShop::deckShop()
{
    string objet[7] = { "Potion","Elixir","Pieces","Armure","Bottes","Arme","Talisman" };
    int a;
    int s;
    int i;
    int b;
    int c=40;
    string l = "special";
    this->cartes;
    for (int i = 0; i < 3; i++) {
        //CARTE ELIXIR
        cartes.push_back(new carteElixir(objet[1], "Graal", l, 4, 0, c));
        cartes.push_back(new carteElixir(objet[1], "Green Ice Tea", l, 4, 1, c));
        cartes.push_back(new carteElixir(objet[1], "Evian", l, 0, 0, c));
        cartes.push_back(new carteElixir(objet[1], "Nuka Cola", l, 2, 3, c));
        cartes.push_back(new carteElixir(objet[1], "Shrek's juice", l, 5, 2, c));

        //CARTE ARMURE et BOTTE
        cartes.push_back(new carteArmure(objet[3], "L'exosquelette", l, 5, 2, c));
        cartes.push_back(new carteArmure(objet[3], "Le scaphandre", l, 3, 2, c));
        cartes.push_back(new carteArmure(objet[3], "Mjolnir MK\.VI", l, 3, 2, c));

        cartes.push_back(new carteBotte(objet[4], "Tongs", l, 0, 2, c));

        //CARTE ARME
        cartes.push_back(new carteArme(objet[5], "LE baton", l, 0, 1, c));
        cartes.push_back(new carteArme(objet[5], "Damocles", l, 5, 1, c));
        cartes.push_back(new carteArme(objet[5], "Excalibur", l, 6, 1, c));
        cartes.push_back(new carteArme(objet[5], "Le tesson du Capitaine", l, 2, 1, c));
        cartes.push_back(new carteArme(objet[5], "CURSED Magnum", l, -2, 0, c));
    }
}
void deckShop::melangerDeck() {
    random_shuffle(this->cartes.begin(), this->cartes.end());
}

void deckShop::afficherDeck(sf::RenderWindow* window) {
    int i;
    for (i = 0; i < this->cartes.size(); i++) {
        cartes[i]->sfafficher(window, i * 100,0);
    }
    cartes.size();
    cout << endl;
}
void deckShop::suppCarte() {
    this->cartes.erase(cartes.begin());
}
void deckShop::checkTaille() {
    cout << this->cartes.size() << endl;
}