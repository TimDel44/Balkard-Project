#pragma once
#include <iostream>
#include "carte.h"
#include <string>
using namespace std;

class carteArgent : public carte
{
private:
	int cost;

public:
	int getCost() { return this->cost; }
	int setCost(int c) { this->cost = c; }

	carteArgent(string nom, int cost);
	virtual void afficher();
	virtual void sfafficher(sf::RenderWindow*, int,int);


};

/*dans le main : 
	srand(time(NULL));
    int valeur = rand() % 90 + 10;
	carte_argent->afficher();
*/