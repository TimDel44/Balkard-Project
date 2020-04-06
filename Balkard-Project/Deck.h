#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "carte.h"
using namespace std;

class Deck
{
private:
	vector<carte*> cartes;
	
public:
	Deck();

	carte* cartesPioche[7];

	void melangerDeck();
	void afficherDeck();
	void pioche();
	void afficherPioche();
};

