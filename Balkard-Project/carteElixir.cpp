#include <iostream>
#include "carteElixir.h"
#include "carte.h"
#include <string>
using namespace std;

carteElixir::carteElixir(string nom, string nomStat, string niveau, int a, int s) :carte(nom),nomStat(nomStat), niveau(niveau), alteration(a), statistique(s) {}

void carteElixir::afficher()
{
	cout << "" << this->getNom() << "" << this->nomStat << "" << this->niveau << endl;
}