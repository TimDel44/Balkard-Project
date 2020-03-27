#include "carteArgent.h"
#include <iostream>

using namespace std;

carteArgent::carteArgent(int valeur) {
	this->valeur = valeur;
}

void carteArgent::afficher() {
	cout << "--------------------" << endl;
	cout << "   Carte Argent !   " << endl;
	cout << "--------------------" << endl;
	cout << "     Valeur : " << this->getValeur() << "    " << endl;
	cout << "--------------------" << endl;



}