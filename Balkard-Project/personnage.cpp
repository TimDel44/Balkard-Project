#include <iostream>
#include <string>
#include "personnage.h"

using namespace std;

personnage::personnage(string nom)
{
	this->nom = nom;
	this->vie = 50;
	this->attaque = 5;
	this->defense = 5;
	this->esquive = 2;
	this->initiative = 3;
	this->perception = 3;
	this->pa = 3;
}

void personnage::afficher() {
	cout << "-------------------" << endl;
	cout << " nom : " << this->getNom() <<"      " << endl;
	cout << "-------------------" << endl;
	cout << " vie : " << this->vie << "        " << endl;
	cout << " attaque : " << this->attaque << "     " << endl;
	cout << " defense : " << this->defense << "     " << endl;
	cout << " esquive : " << this->esquive << "     " << endl;
	cout << " initiative : " << this->initiative << "  " << endl;
	cout << " perception : " << this->perception << "  " << endl;
	cout << " pa : " << this->pa << "          " << endl;
	cout << "-------------------" << endl;


}
