#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "carte.h"
using namespace std;

class deckShop
{
private:
	vector<carte*> cartes;
public:
	deckShop();

	vector<carte*> getCarte() { return this->cartes; }

	void melangerDeck();
	void afficherDeck(sf::RenderWindow*);
	void checkTaille();
	void suppCarte();

};