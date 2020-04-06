#include <iostream>
#include "cartePotion.h"
#include "carte.h"
#include <string>
using namespace std;

cartePotion::cartePotion(string nom, string nomStat, string niveau, int a, int s):carte(nom), alteration(a), statistique(s){}

void cartePotion::afficher()
{
	cout << " nom" << this->getNom() << this->nomStat << this->niveau << endl;
}