#include "carteArgent.h"
#include <iostream>
#include "carte.h"
#include <string>
using namespace std;

carteArgent::carteArgent(string nom, int valeur) :carte(nom), valeur(valeur) {}

void carteArgent::afficher() {
	cout << "	-------------------" << endl;
	cout <<"	|   " << "Pieces d\'or"/*this->getNom()*/ << "   |" << endl;
	cout << "	-------------------" << endl;
	printf("	|                 |\n");
	printf("	|                 |\n");
	printf("	|                 |\n");
	printf("	| valeur : %-6d |\n", this->getValeur());
	printf("	|                 |\n");
	printf("	|                 |\n");
	printf("	|                 |\n");
	cout << "	-------------------" << endl;
	//printf("	| nom : %-9d |\n", this->carte::nom.c_str());
	/*cout << "--------------------" << endl;
	cout << "   Carte Argent !   " << endl;
	cout << "--------------------" << endl;
	cout << "     Valeur : " << this->getValeur() << "    " << endl;
	cout << "--------------------" << endl;
	*/
	//cout << this->valeur << " " << this->getNom() << endl;

}