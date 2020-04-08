#include "carteRituel.h"
#include <iostream>
#include "carte.h"
#include <string>
using namespace std;

carteRituel::carteRituel(string nom, int a, int s) :carte(nom), alteration(a), statistique(s) {}

void carteRituel::afficher()
{
	cout << " nom : " << this->getNom() << " alte : " << this->alteration << " stat : " << this->statistique << endl;
}