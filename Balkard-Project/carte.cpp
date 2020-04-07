#include <iostream>
#include <string>
#include "carte.h"

using namespace std;

carte::carte(string nom)
{
	this->nom = nom;
}

void carte::afficher() 
{
	/*cout << "	-------------------" << endl;
	printf("	| nom : %-9d |\n", this->getNom().c_str());
	cout << "	-------------------" << endl;
	printf("	| %-15d |\n");
	printf("	| %-15d |\n");
	printf("	| %-15d |\n");
	printf("	| %-15d |\n");
	printf("	| %-15d |\n");
	printf("	| %-15d |\n");
	printf("	| %-15d |\n");
	cout << "	-------------------" << endl;/**/
}

carte::~carte(){}