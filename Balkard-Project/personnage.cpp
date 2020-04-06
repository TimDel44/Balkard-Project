#include <iostream>
#include <string>
#include "personnage.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#ifdef _WIN32
#include <windows.h>
#endif
#include <algorithm>
#include <iomanip>
#include <random>
#include "joueur.h"

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
	cout << "	-------------------" << endl;
	printf("	| nom : %-9s |\n", this->nom.c_str());
	cout << "	-------------------" << endl;
	printf("	| vie : %-9d |\n", this->vie); //11
	printf("	| attaque : %-5d |\n", this->attaque); //7
	printf("	| defense : %-5d |\n", this->defense); //7
	printf("	| esquive : %-5d |\n",this->esquive); //7
	printf("	| initiative : %-2d |\n", this->initiative); //4
	printf("	| perception : %-2d |\n", this->perception); //4
	printf("	| pa : %-10d |\n", this->pa); //12
	cout << "	-------------------" << endl;
	//cout << "| nom : " << this->getNom() << endl;
}

/*void personnage::attaquer(joueur* cible) {
	int jetAttaque = rand() % 7;
	cout << "\n" << this->nom << " se prepare a attaquer !\n" << endl;
	Sleep(5000);
	cout << this->nom << " a fait un jet d'attaque de " << jetAttaque << endl;
	int jetCritique = rand() % 101;
	if (jetAttaque != 0) {
		if (jetCritique > 89) {
			cout << "\n" << this->nom << " a fait un fait un coup critique ! Degats doubles !" << endl;
			cible->subir(this->attaque*1.25 + jetAttaque*1.25);
		}
		else {
			cible->subir(this->attaque + jetAttaque);
		}
	}
	else
	{
		cout << this->nom << " a rate son attaque !" << endl;
	}
}

void personnage::subir(int degats) {
	int jetEsquive = rand() % 7;
	cout << "\n" << this->nom << " a fait un jet d'esquive de " << jetEsquive << endl;
	if (jetEsquive + this->esquive < degats) {
		this->vie -= degats;
		printf("%s a subis %d points de degats !", this->nom.c_str(), degats);
		//cout << this->nom << " a subis " << degats << ' points de degats !' << endl;
	}
	else {
		cout << this->nom << " a esquive l'attaque !" << endl;
	}
}

int personnage::jetInitierCombat() {
	int jetInitiative = rand() % 7;
	cout << "\n" << this->nom << " a fait un jet d'initiative de " << jetInitiative << endl;
	return jetInitiative + this->initiative;
}

void personnage::initierCombat(joueur* cible) {	
	if (this->jetInitierCombat() > cible->jetInitierCombat() ) {
		this->attaquer(cible);
		cible->attaquer(this);
	}
	else {
		cible->attaquer(this);
		this->attaquer(cible);
	}

}

void personnage::combat(personnage* cible) {
	while(this->vie > 0 and cible->vie>0) {

		this->afficher();

		printf("\n---------------------------------------------\n");

		cible->afficher();


		this->initierCombat(cible);

		printf("\n\n\n");
	}

	printf("\n\n\n");

	this->afficher();

	printf("\n------------------------------------------------------\n");

	cible->afficher();
}*/