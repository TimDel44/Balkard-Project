#include "joueur.h"
#include "personnage.h"
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
#include <ctime>

joueur::joueur(personnage* perso) {
	this->actif = 1;
	this->persoVivant = 1;
	this->perso = perso;
	this->argent = 0;
}

void joueur::afficherJoueur() {
	cout << this->perso->personnage::getNom() << endl;
}

void joueur::joueurCombat(joueur* cible) {
	while (this->perso->personnage::getVie() > 0 and cible->perso->personnage::getVie() > 0) {

		this->perso->afficher();

		printf("\n---------------------------------------------\n");

		cible->perso->afficher();


		this->initierCombat(cible);

		printf("\n\n\n");
	}

	printf("\n\n\n");

	this->perso->afficher();

	printf("\n------------------------------------------------------\n");

	cible->perso->afficher();
}
void joueur::attaquer(joueur* cible) {
	int jetAttaque = rand() % 7;
	cout << "\n" << this->perso->getNom() << " se prepare a attaquer !\n" << endl;
	Sleep(5000);
	cout << this->perso->getNom() << " a fait un jet d'attaque de " << jetAttaque << endl;
	int jetCritique = rand() % 101;
	if (jetAttaque != 0) {
		if (jetCritique > 89) {
			cout << "\n" << this->perso->getNom() << " a fait un fait un coup critique !" << endl;
			cible->subir(this->perso->getAttaque() * 1.25 + jetAttaque * 1.25);
		}
		else {
			cible->subir(this->perso->getAttaque() + jetAttaque);
		}
	}
	else
	{
		cout << this->perso->getNom() << " a rate son attaque !" << endl;
	}
}

void joueur::subir(int degats) {
	int jetEsquive = rand() % 7;
	cout << "\n" << this->perso->getNom() << " a fait un jet d'esquive de " << jetEsquive << endl;
	if (jetEsquive + this->perso->getEsquive() < degats) {
		this->perso->setVie((this->perso->getVie() - degats));
		printf("%s a subis %d points de degats !", this->perso->getNom().c_str(), degats);
		//cout << this->nom << " a subis " << degats << ' points de degats !' << endl;
		//int vieActuelle = this->perso->getVie();
	}
	else {
		cout << this->perso->getNom() << " a esquive l'attaque !" << endl;
	}
}

int joueur::jetInitierCombat() {
	int jetInitiative = rand() % 7;
	cout << "\n" << this->perso->getNom() << " a fait un jet d'initiative de " << jetInitiative << endl;
	return jetInitiative + this->perso->getInitiative();
}

void joueur::initierCombat(joueur* cible) {
	if (this->jetInitierCombat() > cible->jetInitierCombat()) {
		this->attaquer(cible);
		cible->attaquer(this);
	}
	else {
		cible->attaquer(this);
		this->attaquer(cible);
	}

}