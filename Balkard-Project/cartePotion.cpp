#include <iostream>
#include "cartePotion.h"
#include "carte.h"
#include <string>
using namespace std;

cartePotion::cartePotion(string nom, string nomStat, string niveau, int a, int s):carte(nom),nomStat(nomStat),niveau(niveau), alteration(a), statistique(s){}

void cartePotion::afficher()
{
	cout << "	-------------------" << endl;
	cout << "	|     " << "Potion"/*this->getNom()*/ << "      |" << endl;
	cout << "	-------------------" << endl;
	printf("	|                 |\n");
	printf("	| stat : %-8s |\n", this->getNomStat().c_str());
	printf("	|                 |\n");
	printf("	| niveau : %-6s |\n", this->getNiveau().c_str());
	printf("	|                 |\n");
	printf("	|                 |\n");
	printf("	|                 |\n");
	cout << "	-------------------" << endl;
	//cout << this->getNom() << this->nomStat << this->niveau << endl;
}