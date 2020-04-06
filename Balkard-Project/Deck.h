#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "carte.h"
using namespace std;

class Deck
{
public:
	Deck();

	carte* getCarte() { return this->cartes; }
	carte* setCarte(carte* cartes) { this->cartes = cartes; }

	void melangerDeck();
};

