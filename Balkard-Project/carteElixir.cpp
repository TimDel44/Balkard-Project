#include <iostream>
#include "carteElixir.h"
#include "carte.h"
#include <string>
using namespace std;

carteElixir::carteElixir(string nom, int a, int s) :carte(nom), alteration(a), statistique(s) {}

void carteElixir::afficher()
{
	cout << " nom : " << this->getNom() << " alte : " << this->alteration << " stat : " << this->statistique << endl;
}