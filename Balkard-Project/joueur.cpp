#include "joueur.h"
#include "personnage.h"
#include "Deck.h"
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
#include "graphics.h"
#include <ctime>

joueur::joueur(personnage* perso) {
	this->actif = 1;
	this->persoVivant = 1;
	this->perso = perso;
	this->argent = 0;
	this->possedeRituel = 0;
	this->possedeSort = 0;
	this->possedeItem = 0;
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
		system("cls");
	}

	printf("\n\n\n");

	this->perso->afficher();

	printf("\n------------------------------------------------------\n");

	cible->perso->afficher();
}
void joueur::attaquer(joueur* cible) {
	int jetAttaque = rand() % 7;
	cout << "\n" << this->perso->getNom() << " se prepare a attaquer !\n" << endl;
	if (this->possedeSort == 1) {

		cout << "\n jouez une carte Sort" << endl;
		//>> cin

	}
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
	debutDeCombat(cible);
	if (this->jetInitierCombat() > cible->jetInitierCombat()) {
		this->attaquer(cible);
		cible->attaquer(this);
		finDeCombat(cible);
	}
	else {
		cible->attaquer(this);
		this->attaquer(cible);
		finDeCombat(cible);
	}

}

void joueur::finDeCombat(joueur* cible) {
	cout << "\n End Phase" << endl;
	if (this->possedeRituel == 1) {

		cout << "\n jouez une carte Rituel" << endl;
		//>> cin

	}
	cout << "\n fin du tour" << endl;
	Sleep(5000);
}
void joueur::debutDeCombat(joueur* cible) {
	cout << "Starting Phase" << endl;
		if (this->possedeItem == 1) {

			cout << "\n jouez une carte Item" << endl;
			//>> cin

		}
}





void joueur::clear() {
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;
	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
		);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
		);
	SetConsoleCursorPosition(console, topLeft);
}


/*void joueur::choisirCarte() {
	this->cartesPioche;
	this->main;
	int a;
	cin >> a;
	main.push_back(cartesPioche[a]);
}

void joueur::afficherMain() {
	int i;
	for (i = 0; i < main.size(); i++) {
		main[i]->afficher();
	}
}*/

