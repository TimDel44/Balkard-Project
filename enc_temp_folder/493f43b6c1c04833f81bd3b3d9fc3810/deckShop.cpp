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
    //string stat[5] = { "Vie", "Attaque", "Defense", "Esquive"/*,"Percept\."*/ };
    //string niveau[3] = { "I", "II", "III" };
    //string materiauArmure[3] = { "Cuir", "Fer", "Or" };
    //string materiauArme[3] = { "Bois","Fer","Or" };
    int a;
    int s;
    int i;
    int b;
    int c=10;
    string l = "special";
    this->cartes;

    //CARTE ELIXIR
    cartes.push_back(new carteElixir(objet[1], "Graal", l, 4, 0, c));
    cartes.push_back(new carteElixir(objet[1], "Riz Dinde", l, 4, 1, c));
    cartes.push_back(new carteElixir(objet[1], "Evian", l, 0, 0, c));
    cartes.push_back(new carteElixir(objet[1], "Nuka Cola", l, 4, 3, c));

    //CARTE ARMURE et BOTTE
    cartes.push_back(new carteArmure(objet[3], "L'exosquelette", l, 5, 2,c));
    cartes.push_back(new carteArmure(objet[3], "Le scaphandre", l, 3, 2, c));
    cartes.push_back(new carteArmure(objet[3], "Mjolnir MK\.VI", l, 3, 2, c));

    cartes.push_back(new carteBotte(objet[4], "", l, 4, 2,c));

    //CARTE ARME
    cartes.push_back(new carteArme(objet[5], "LE baton", l, 0, 1,c));
    cartes.push_back(new carteArme(objet[5], "Damocles", l, 6, 1, c));
    cartes.push_back(new carteArme(objet[5], "Excalibur", l, 6, 1, c));
}
void deckShop::melangerDeck() {
    random_shuffle(this->cartes.begin(), this->cartes.end());
}

void deckShop::afficherDeck(sf::RenderWindow* window) {
    int i;
    for (i = 0; i < this->cartes.size(); i++) {
        cartes[i]->sfafficher(window, i * 100);
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