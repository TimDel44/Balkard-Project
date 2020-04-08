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
#include "Deck.h"
#include "carte.h"

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

void joueur::joueurCombat(joueur* cible, Deck* deck) {
	while (this->perso->personnage::getVie() > 0 and cible->perso->personnage::getVie() > 0) {

		this->perso->afficher();

		printf("\n					   ---------------------------------------------\n");

		cible->perso->afficher();


		this->initierCombat(cible, deck);

		printf("\n\n\n");
		system("cls");
	}

	printf("\n\n\n");

	this->perso->afficher();

	printf("\n					   ------------------------------------------------------\n");

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

void joueur::initierCombat(joueur* cible, Deck* deck) {
	debutDeCombat(cible, deck);
	if (this->jetInitierCombat() > cible->jetInitierCombat()) {
		this->attaquer(cible);
		cible->attaquer(this);
		finDeCombat(cible, deck);
	}
	else {
		cible->attaquer(this);
		this->attaquer(cible);
		finDeCombat(cible, deck);
	}
}

void joueur::finDeCombat(joueur* cible, Deck* deck) {
	cout << "\n End Phase" << endl;
	cout << "Joueur 1, voici vos cartes :" << endl;
	for (int i = 0; i < this->main.size(); i++) { this->main[i]->afficher(); }
	string pause;
	cin >> pause;
	cout << "Joueur 2, voici vos cartes :" << endl;
	for (int i = 0; i < cible->main.size(); i++) { cible->main[i]->afficher(); }
	cin >> pause;
	if (this->possedeRituel == 1) {

		cout << "\n jouez une carte Rituel" << endl;
		//>> cin

	}
	cout << "\n fin du tour" << endl;
	Sleep(5000);
}
void joueur::debutDeCombat(joueur* cible, Deck* deck) {
	cout << "Starting Phase" << endl;
	this->joueurPiocher(deck);
	cible->joueurPiocher(deck);
	cout << "Joueur 1, voici vos cartes :" << endl;
	for(int i = 0; i < this->main.size(); i++) {	this->main[i]->afficher();   }
	this->joueurJouerCarte(cible, deck);
	string pause;
	cin >> pause;
	cout << "Joueur 2, voici vos cartes :" << endl;
	for (int i = 0; i < cible->main.size(); i++) { cible->main[i]->afficher(); }
	string pause1;
	cin >> pause1;
		if (this->possedeItem == 1) {

			cout << "\n jouez une carte Item" << endl;
			//>> cin

		}
}
void joueur::joueurJouerCarte(joueur* cible, Deck* deck) {
	int choix;
	cout << "choisissez une carte � jouer" << endl;
	cin >> choix;
	//this->main.erase(choix);
	
}
void joueur::joueurPiocher(Deck* deck){
	/*
	deck->pioche();
	for (i = 0; i < deck->getPioche().size(); i++) {
		deck->getPioche().operator[](i)->afficher();
	}
	*/
	for (int i = 0; i < 4; i++) {
		this->main.push_back(deck->getCarte()[i/*deck->getCarte().size() - (1 + i)*/]);
		//deck->getCarte().erase(deck->getPioche().begin());
		deck->suppCarte();
		//this->main[i]->afficher();    <---- afficher la main (mettre main[main.size()]
	}
	/*
	vector<carte*> main2(deck->getPioche().begin(), deck->getPioche().end());
	this->main.push_back(deck->getPioche().begin(), deck->getPioche().end());
	for (i = 0; i < this->main.size(); i++) {
		main[i]->afficher();
	}
	//cout <<" "<< this->main << endl;
	*/
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

