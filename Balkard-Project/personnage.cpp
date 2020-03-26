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
	printf("| nom : %-9s |\n", this->nom.c_str());
	//cout << "| nom : " << this->getNom() << endl;
	cout << "-------------------" << endl;
	printf("| vie : %-9d |\n", this->vie); //11
	printf("| attaque : %-5d |\n", this->attaque); //7
	printf("| defense : %-5d |\n", this->defense); //7
	printf("| esquive : %-5d |\n",this->esquive); //7
	printf("| initiative : %-2d |\n", this->initiative); //4
	printf("| perception : %-2d |\n", this->perception); //4
	printf("| pa : %-10d |\n", this->pa); //12
	cout << "-------------------" << endl;
}
