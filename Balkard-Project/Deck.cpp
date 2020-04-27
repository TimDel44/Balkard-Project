#include "Deck.h"
#include "carte.h"
#include "cartePotion.h"
#include "carteElixir.h"
#include "carteArgent.h"
#include "carteArme.h"
#include "carteArmure.h"
#include "carteSort.h"
#include "carteBotte.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <ctime>

Deck::Deck()
{
    string objet[7] = { "Potion","Elixir","Argent","Armure","Bottes","Arme","Sort" };
    string stat[5] = { "Vie", "Attaque", "Defense", "Esquive"/*,"Percept\."*/ };
    string niveau[3] = { "I", "II", "III" };
    string materiauArmure[3] = { "Cuir", "Fer", "Or" };
    string materiauArme[3] = { "Bois","Fer","Or" };
    int a;
    int s;
    int i;
    int b;
    int c;
    int nbdecarte;
    this->cartesPioche;
    this->cartes;
    //CARTE POTION
    for (a = 0; a < 3; a++) {
        b = (3 - a);
        for (nbdecarte = 0; nbdecarte < b; nbdecarte++) {
            for (s = 0; s < 4; s++) {
                cartes.push_back(new cartePotion(objet[0], stat[s], niveau[a], a+1, s, 0));
            }
        }
    }
    //CARTE ELIXIR
    for (a = 0; a < 2; a++) {
        b = (2 - a);
        for (nbdecarte = 0; nbdecarte < b; nbdecarte++) {
            for (s = 0; s < 4; s++) {
                cartes.push_back(new carteElixir(objet[1], stat[s], niveau[a], a+3, s, 0));
            }
        }
    }
    //CARTE ARGENT
    
    for (i = 0; i < 14; i++) {
        c = rand() % 90 + 10;
        cartes.push_back(new carteArgent(objet[2], c));
    }
    
    //CARTE ARMURE et BOTTE
    for (a = 0; a < 3; a++) {
        b = (3 - a);
        for (nbdecarte = 0; nbdecarte < b; nbdecarte++) {
             cartes.push_back(new carteArmure(objet[3], stat[2], materiauArmure[a], a+1, 2, 0));
             cartes.push_back(new carteBotte(objet[4], stat[2], materiauArmure[a], a+1, 2, 0));
        }
    }
    //CARTE ARME
    for (a = 0; a < 3; a++) {
        b = (3 - a);
        for (nbdecarte = 0; nbdecarte < b; nbdecarte++) {
            cartes.push_back(new carteArme(objet[5], stat[1], materiauArme[a], a+1, 1, 0));
        }
    }
    //CARTE SORT   
    for (a = 0; a < 3; a++) {
        cartes.push_back(new carteSort(objet[6], "Le feu ca brule", niveau[a], a+1, 0, 0));
        cartes.push_back(new carteSort(objet[6], "L'alcool ca saoule", niveau[a], a + 1, 1, 0));
        cartes.push_back(new carteSort(objet[6], "L'eau ca mouille", niveau[a], a + 1, 2, 0));
        cartes.push_back(new carteSort(objet[6], "L'huile ca glisse", niveau[a], a + 1, 3, 0));
    }
    
    //delete de carte, pas utile
    /*
    for (i = 0; i < cartes.size(); i++) {
        delete cartes[i];
    }
    */
}

void Deck::melangerDeck() {
    random_shuffle(this->cartes.begin(), this->cartes.end());
}

void Deck::afficherDeck(sf::RenderWindow* window) {
    int i;
    for (i = 0; i < this->cartes.size(); i++) {
        cartes[i]->sfafficher(window, i*100,0);
    }
    cartes.size();
    cout << endl;
}
void Deck::suppCarte() {
    this->cartes.erase(cartes.begin());
}
//Ancienne pioche pas gardée
/*
void Deck::pioche() {
    this->cartesPioche.clear();
   // this->cartesPioche;
    for (int i = 0; i < 4; i++) {
        this->cartesPioche.push_back(cartes[cartes.size()-(1+i)]);
        this->cartes.pop_back();
    }
}
*/
void Deck::checkTaille() {
   cout << this->cartes.size() << endl;
}
//Ancien affichage de pioche pas gardé
/*
void Deck::afficherPioche() {
    int i;
    for (i = 0; i < 7; i++) {
        cartesPioche[i]->afficher();
    }
}
*/

