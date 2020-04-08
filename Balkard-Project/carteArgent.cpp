#include "carteArgent.h"

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
/*void Color(int couleurDuTexte, int couleurDeFond) {
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H, couleurDeFond * 16 + couleurDuTexte);
}*/

carteArgent::carteArgent(string nom, int valeur) :carte(nom), valeur(valeur) {}

void carteArgent::afficher() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	cout << "	-------------------" << endl;
	cout <<"	|   " << "Pieces d\'or"/*this->getNom()*/ << "   |" << endl;
	cout << "	-------------------" << endl;
	printf("	|                 |\n");
	printf("	|                 |\n");
	printf("	|                 |\n");
	printf("	| valeur : %-6d |\n", this->getValeur());
	printf("	|                 |\n");
	printf("	|                 |\n");
	printf("	|                 |\n");
	cout << "	-------------------" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	//printf("	| nom : %-9d |\n", this->carte::nom.c_str());
	/*cout << "--------------------" << endl;
	cout << "   Carte Argent !   " << endl;
	cout << "--------------------" << endl;
	cout << "     Valeur : " << this->getValeur() << "    " << endl;
	cout << "--------------------" << endl;
	*/
	//cout << this->valeur << " " << this->getNom() << endl;

}