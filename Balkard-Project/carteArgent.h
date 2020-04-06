#pragma once
#include <iostream>
using namespace std;

class carteArgent
{
private:
	int valeur;

public:
	int getValeur() { return this->valeur; }
	int setValeur(int valeur) { this->valeur = valeur; }

	carteArgent(int valeur);
	void afficher();



};

/*dans le main : 
	srand(time(NULL));
    int valeur = rand() % 90 + 10;
	carte_argent->afficher();
*/