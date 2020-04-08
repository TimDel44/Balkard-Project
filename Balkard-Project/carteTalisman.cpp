#include "carteTalisman.h"
#include "carte.h"

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#ifdef _WIN32
#include <windows.h>
#endif
#include <algorithm>
#include <iomanip>
#include <stdlib.h>

using namespace std;

carteTalisman::carteTalisman(string nom, string nomStat, string niveau, int a, int s) :carte(nom), nomStat(nomStat), niveau(niveau), alteration(a), statistique(s) {}

void carteTalisman::afficher()
{
	//cout << this->getNom() << this->nomStat << this->niveau << endl;
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	cout << "	-------------------" << endl;
	cout << "	|     " << "Talisman"/*this->getNom()*/ << "    |" << endl;
	cout << "	-------------------" << endl;
	printf("	|                 |\n");
	printf("	| stat : %-8s |\n", this->getNomStat().c_str());
	printf("	|                 |\n");
	printf("	| niveau : %-6s |\n", this->getNiveau().c_str());
	printf("	|                 |\n");
	printf("	|                 |\n");
	printf("	|                 |\n");
	cout << "	-------------------" << endl;
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
}