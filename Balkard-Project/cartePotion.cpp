#include <iostream>
#include "cartePotion.h"
#include "carte.h"
#include <string>
using namespace std;

cartePotion::cartePotion(string nom, int a, int s):carte(nom), alteration(a), statistique(s){}

void cartePotion::afficher()
{
	cout << " nom : " << this->getNom() << " alte : " << this->alteration << " stat : " << this->statistique << endl;
}