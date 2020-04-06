#include "carteArgent.h"
#include <iostream>
#include "carte.h"
#include <string>
using namespace std;

carteArgent::carteArgent(string nom, int valeur) :carte(nom), valeur(valeur) {}

void carteArgent::afficher() {
	/*cout << "--------------------" << endl;
	cout << "   Carte Argent !   " << endl;
	cout << "--------------------" << endl;
	cout << "     Valeur : " << this->getValeur() << "    " << endl;
	cout << "--------------------" << endl;
	*/
	cout << this->valeur << " " << this->getNom() << endl;

}