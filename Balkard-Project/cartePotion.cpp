#include <iostream>
#include "cartePotion.h"
#include "carte.h"
#include <string>
using namespace std;

cartePotion::cartePotion(string nom, string nomStat, string niveau, int a, int s):carte(nom),nomStat(nomStat),niveau(niveau), alteration(a), statistique(s){}

void cartePotion::afficher()
{
	cout << this->getNom() << this->nomStat << this->niveau << endl;
}