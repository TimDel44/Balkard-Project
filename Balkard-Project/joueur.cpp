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
		this->perso->setVie((this->perso->getVie() - (degats - this->perso->getDefense()/2)));
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
	/*cout << "Joueur 1, voici vos cartes :" << endl;
	for (int i = 0; i < this->main.size(); i++) { this->main[i]->afficher(); }
	string pause;
	cin >> pause;
	cout << "Joueur 2, voici vos cartes :" << endl;
	for (int i = 0; i < cible->main.size(); i++) { cible->main[i]->afficher(); }
	cin >> pause;*/
	if (this->possedeRituel == 1) {

		cout << "\n jouez une carte Rituel" << endl;
		//>> cin

	}
	cout << "\n fin du tour" << endl;
	Sleep(5000);
}
void joueur::debutDeCombat(joueur* cible, Deck* deck) {
	cout << "Starting Phase" << endl;
	this->perso->setPA(3);
	cible->perso->setPA(3);
	this->joueurPiocher(deck);
	cible->joueurPiocher(deck);
	cout << "Joueur 1, voici vos cartes :" << endl;
	//for(int i = 0; i < this->main.size(); i++) {	this->main[i]->afficher();   }
	this->joueurJouerCarte(cible, deck);
	cout << "Joueur 2, voici vos cartes :" << endl;
	//for (int i = 0; i < cible->main.size(); i++) { cible->main[i]->afficher(); }
	cible->joueurJouerCarte(cible, deck);
		if (this->possedeItem == 1) {

			cout << "\n jouez une carte Item" << endl;
			//>> cin

		}
}
void joueur::joueurJouerCarte(joueur* cible, Deck* deck) {
	int choix;
	if (this->main.size() != 0) {
		while (this->perso->getPA() != 0) {
			for (int i = 0; i < this->main.size(); i++) { this->main[i]->afficher(); }
			cout << "choisissez une carte a jouer" << endl;
			cin >> choix;
			while (choix > main.size()) {
				cout << "choisissez un nombre valide" << endl;
				cin >> choix;
			}
			joueurActiverCarte(cible, deck, choix);
			this->main.erase(main.begin() + choix - 1);
			this->perso->setPA(this->perso->getPA() - 1);
			cout << "il vous reste : " << this->perso->getPA() << " PA" << endl;
		}
	}
	this->main.clear();
}

void joueur::joueurActiverCarte(joueur* cible, Deck* deck, int choix) {
	if (this->main[choix-1]->getStatistique() == 0) {
		this->perso->setVie(this->perso->getVie() + this->main[choix-1]->getAlteration() * 10);
		cout << "vous vous etes soigne de " << this->main[choix - 1]->getAlteration()*10 << " Points de vie !" << endl;
	}else if (this->main[choix - 1]->getStatistique() == 1) {
		this->perso->setAttaque(this->perso->getAttaque() + this->main[choix - 1]->getAlteration() * 5);
		cout << "vous boostez votre attaque de " << this->main[choix - 1]->getAlteration() * 5 << " !" << endl;
	}else if (this->main[choix - 1]->getStatistique() == 2) {
		this->perso->setDefense(this->perso->getDefense() + this->main[choix - 1]->getAlteration() * 5);
		cout << "vous augmentez votre defense de " << this->main[choix - 1]->getAlteration() * 5 << " !" << endl;
	}else if (this->main[choix - 1]->getStatistique() == 3) {
		this->perso->setEsquive(this->perso->getEsquive() + this->main[choix - 1]->getAlteration() * 5);
		cout << "vous gagnez " << this->main[choix - 1]->getAlteration() * 5 << " points d'esquive !" << endl;
	}else if (this->main[choix - 1]->getStatistique() == 4) {
		this->perso->setPerception(this->perso->getPerception() + this->main[choix - 1]->getAlteration() - 2);
		cout << "vous gagnez " << this->main[choix - 1]->getAlteration() - 2 << " points d'esquive !" << endl;
	}else if (this->main[choix - 1]->getStatistique() == 6) {
		this->perso->setPA(this->perso->getPA() + this->main[choix - 1]->getAlteration() * 1);
		cout << "vous obtenez " << this->main[choix - 1]->getAlteration() * 1 << " PA supplémentaire(s) !" << endl;
	}
}

void joueur::joueurPiocher(Deck* deck){
	
	for (int i = 0; i < 4; i++) {
		if (deck->getCarte().size() > 4) {
			this->main.push_back(deck->getCarte()[i]); /*deck->getCarte().size() - (1 + i)*/
			//deck->getCarte().erase(deck->getPioche().begin());
			deck->suppCarte();
		}
		else {
			cout << "Il n\'y a plus de cartes !" << endl;
		}
		//deck->pioche();
	/*for (i = 0; i < deck->getPioche().size(); i++) {
		deck->getPioche().operator[](i)->afficher();
	}*/
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

