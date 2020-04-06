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
	cout << " nom : " << this->getNom() << endl;
}

carte::~carte(){}