#pragma once
#include <iostream>
#include "carte.h"
#include <string>
using namespace std;

class carteArgent : public carte
{
private:
	int valeur;

public:
	int getValeur() { return this->valeur; }
	int setValeur(int valeur) { this->valeur = valeur; }

	carteArgent(string nom, int valeur);
	virtual void afficher();



};

/*dans le main : 
	srand(time(NULL));
    int valeur = rand() % 90 + 10;
	carte_argent->afficher();
*/