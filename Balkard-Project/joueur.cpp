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
#include "deckShop.h"
#include "carte.h"
#include "texteCombat.h"
//#include "miseEnPage.cpp"
#include <SFML/Graphics.hpp>


joueur::joueur(personnage* perso) {
	this->actif = 1;
	this->persoVivant = 1;
	this->perso = perso;
	this->argent = 20;
	this->possedeRituel = 0;
	this->possedeSort = 0;
	this->possedeItem = 0;

	this->fontJoueur = new sf::Font;
	if (!this->fontJoueur->loadFromFile("font/alagard.ttf"))
	{
		// erreur...
	}
}
//AFFICHAGE JOUEUR
void joueur::afficherJoueur() {
	cout << this->perso->personnage::getNom() << endl;
}
//BOUCLE DE COMBAT
void joueur::joueurCombat(joueur* cible, Deck* deck, deckShop* deckshop, sf::RenderWindow* window) {
	int tour = 1;
	while (this->perso->personnage::getVie() > 0 and cible->perso->personnage::getVie() > 0) {
		
		affichagePlateau(cible, window);
		//this->perso->afficher();

		//printf("\n					   ---------------------------------------------\n");

		//cible->perso->afficher();

		cout << "TOUR " << tour << endl;
		this->initierCombat(cible, deck, window, deckshop, tour);
		tour++;
		printf("\n\n\n");
		system("cls");
	}


	printf("\n\n\n");


	affichagePlateau(cible, window);

	window->clear();
	if (this->perso->personnage::getVie() <= 0 && cible->perso->personnage::getVie() <= 0) {
		cout << "vous vous etes entretuer" << endl;
		this->reset(cible);
	}else if (this->perso->personnage::getVie() <= 0) {
		cout << "vous avez perdu" << endl;
		this->reset(cible);
	//}else if(cible->perso->personnage::getVie() <= 0){
	//	this->reset(cible);
	//	shopping(cible, deckshop, window);
	}
	


	//this->perso->afficher();

	//printf("\n					   ------------------------------------------------------\n");

	//cible->perso->afficher();
}
//ATTAQUE
void joueur::attaquer(joueur* cible, sf::RenderWindow* window) {
	int jetAttaque = rand() % 7;
	texteCombat* txt = new texteCombat;
	window->clear();
	affichageJoueur(this, window->getSize().x / 2, (window->getSize().y / 2) - 300.f, window);
	txt->preparationAtkTxt(this, window);
	cout << "\n" << this->perso->getNom() << " se prepare a attaquer !\n" << endl;

	if (this->possedeSort == 1) {

		cout << "\n jouez une carte Sort" << endl;
		//>> cin

	}
	Sleep(2000);
	cout << this->perso->getNom() << " a fait un jet d'attaque de " << jetAttaque << endl;
	affichageJoueur(this, window->getSize().x / 2, (window->getSize().y / 2) - 300.f, window);
	txt->jetAtkTxt(this, window, jetAttaque);
	Sleep(2000);
	int jetCritique = rand() % 101;
	if (jetAttaque != 0) {
		if (jetCritique > 89) {
			cout << "\n" << this->perso->getNom() << " a fait un fait un coup critique !" << endl;
			affichageJoueur(this, window->getSize().x / 2, (window->getSize().y / 2) - 300.f, window);
			txt->atkCritTxt(this, window);
			Sleep(500);
			cible->subir(this->perso->getAttaque() * 1.25 + jetAttaque * 1.25, window);
		}
		else {
			cible->subir(this->perso->getAttaque() + jetAttaque, window);
		}
	}
	else
	{
		cout << this->perso->getNom() << " a rate son attaque !" << endl;
		affichageJoueur(this, window->getSize().x / 2, (window->getSize().y / 2) - 300.f, window);
		txt->atkFailTxt(this, window);
	}
}
//DEGATS SUBIS
void joueur::subir(int degats, sf::RenderWindow* window) {
	int jetEsquive = rand() % 7;
	texteCombat* txt = new texteCombat;
	cout << "\n" << this->perso->getNom() << " a fait un jet d'esquive de " << jetEsquive << endl;
	affichageJoueur(this, window->getSize().x / 2, (window->getSize().y / 2) - 300.f, window);
	txt->jetEsquiveTxt(this, window, jetEsquive);
	Sleep(2000);
	if (jetEsquive + this->perso->getEsquive() < degats) {
		this->perso->setVie((this->perso->getVie() - (degats - this->perso->getDefense()/4)));
		printf("\n%s a subis %d points de degats !\n", this->perso->getNom().c_str(), (degats - this->perso->getDefense() / 4));
		affichageJoueur(this, window->getSize().x / 2, (window->getSize().y / 2) - 300.f, window); // chaud
		Sleep(1000);
		//cout << this->nom << " a subis " << degats << ' points de degats !' << endl;
		//int vieActuelle = this->perso->getVie(); mista lova lova
	}
	else {
		cout << this->perso->getNom() << " a esquive l'attaque !" << endl;
		affichageJoueur(this, window->getSize().x / 2, (window->getSize().y / 2) - 300.f, window);
		txt->esquiveTxt(this, window);
		Sleep(1000);
	}
}
//JET D'INITIATIVE
int joueur::jetInitierCombat(sf::RenderWindow* window) {
	texteCombat* txt = new texteCombat;
	int jetInitiative = rand() % 7;
	cout << "\n" << this->perso->getNom() << " a fait un jet d'initiative de " << jetInitiative << endl;
	affichageJoueur(this, window->getSize().x / 2, (window->getSize().y / 2) - 300.f, window);
	//txt->jetInitiaTxt(this, window, jetInitiative);
	return jetInitiative + this->perso->getInitiative();
}
//CHOIX DU JOUEUR QUI ATTAQUE EN PREMIER
void joueur::initierCombat(joueur* cible, Deck* deck, sf::RenderWindow* window, deckShop* deckshop, int tour) {
	debutDeCombat(cible, deck, window);
	system("cls");
	this->perso->afficher();

	printf("\n					   ---------------------------------------------\n");

	cible->perso->afficher();
	if (this->jetInitierCombat(window) > cible->jetInitierCombat(window)) {
		this->attaquer(cible, window);
		window->clear();
		cible->attaquer(this, window);
		window->clear();
		finDeCombat(cible, deck, window, deckshop, tour);
	}
	else {
		cible->attaquer(this, window);
		this->attaquer(cible, window);
		finDeCombat(cible, deck, window, deckshop, tour);
	}
}
//FIN DU COMBAT (AFFICHAGE DES JOUEUR ET CARTE RITUEL(pas mis en place))
void joueur::finDeCombat(joueur* cible, Deck* deck,  sf::RenderWindow* window, deckShop* deckshop, int tour) {
	cout << "\n End Phase" << endl;
	//Affichage de la main à la fin du tour
	/*
	cout << "Joueur 1, voici vos cartes :" << endl;
	for (int i = 0; i < this->main.size(); i++) { this->main[i]->afficher(); }
	string pause;
	cin >> pause;
	cout << "Joueur 2, voici vos cartes :" << endl;
	for (int i = 0; i < cible->main.size(); i++) { cible->main[i]->afficher(); }
	cin >> pause;
	*/
	if (this->possedeRituel == 1) {

		cout << "\n jouez une carte Rituel" << endl;
		//>> cin

	}
	cout << "\n fin du tour" << endl;
	this->perso->afficher();

	printf("\n					   ---------------------------------------------\n");

	cible->perso->afficher();
	window->clear();
	if(tour%3 == 0){
		this->shopping(cible, deckshop, window);
		cible->shopping(cible, deckshop, window);
		window->clear();
	}
	//affichagePlateau(cible, window);

	//Sleep(2000);
}
//DEBUT DU COMBAT (PIOCHER ET UTILISER CARTE)
void joueur::debutDeCombat(joueur* cible, Deck* deck, sf::RenderWindow* window) {
	cout << "Starting Phase" << endl;
	this->perso->setPA(3);
	cible->perso->setPA(3);
	this->joueurPiocher(deck);
	cible->joueurPiocher(deck);
	cout << "Joueur 1, voici vos cartes :" << endl;
	//for(int i = 0; i < this->main.size(); i++) {	this->main[i]->afficher();   }
	this->joueurJouerCarte(cible, deck, window);
	window->clear();
	cout << "Joueur 2, voici vos cartes :" << endl;
	//for (int i = 0; i < cible->main.size(); i++) { cible->main[i]->afficher(); }
	cible->joueurJouerCarte(cible, deck, window);
		if (this->possedeItem == 1) {

			cout << "\n jouez une carte Item" << endl;
			//>> cin

		}
		window->clear();
		window->display();
}
//CHOIX DE LA CARTE A JOUER
void joueur::joueurJouerCarte(joueur* cible, Deck* deck, sf::RenderWindow* window) {
	int choix;
		if (this->main.size() != 0) {
				while (this->perso->getPA() != 0) {
					window->clear();
					if (this->main.size() > 5) {
						this->affichageJoueur(this, window->getSize().x / 2, (window->getSize().y / 2 - 300.f), window);
						for (int i = 0; i < this->main.size(); i++) { this->main[i]->sfafficher(window, i * 150); }
					}
					else {
						this->affichageJoueur(this, window->getSize().x / 2, window->getSize().y / 2 - 300.f, window);
						for (int i = 0; i < this->main.size(); i++) { this->main[i]->sfafficher(window, i * 300); }
					}
					window->display();
					cout << "choisissez une carte a jouer" << endl;
					cin >> choix;
					//choix = fChoix();
					
					while (choix > main.size() || choix == 0) {
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

//MISE EN PLACE DES EFFETS DES POTIONS
void joueur::joueurActiverCarte(joueur* cible, Deck* deck, int choix) {
	if (this->main[choix-1]->getNom() == "Sort") {
		if (this->main[choix - 1]->getStatistique() == 0) {
			cible->perso->setVie(cible->perso->getVie() - this->main[choix - 1]->getAlteration() * 10);
			cout << "vous infligez " << this->main[choix - 1]->getAlteration() * 10 << " Points de degats a " <<cible->perso->getNom()<<" !"<< endl;
		}
		else if (this->main[choix - 1]->getStatistique() == 1) {
			cible->perso->setAttaque(cible->perso->getAttaque() - this->main[choix - 1]->getAlteration() * 5);
			cout << "vous baissez l'attaque de " << cible->perso->getNom() << " de " << this->main[choix - 1]->getAlteration() * 5 << " !" << endl;
		}
		else if (this->main[choix - 1]->getStatistique() == 2) {
			cible->perso->setDefense(cible->perso->getDefense() - this->main[choix - 1]->getAlteration() * 5);
			cout << "vous diminuez la defense de " << cible->perso->getNom() << " de " << this->main[choix - 1]->getAlteration() * 5 << " !" << endl;
		}
		else if (this->main[choix - 1]->getStatistique() == 3) {
			cible->perso->setEsquive(cible->perso->getEsquive() - this->main[choix - 1]->getAlteration() * 5);
			cout << cible->perso->getNom() << " perd " << this->main[choix - 1]->getAlteration() * 5 << " points d'esquive !" << endl;
		}
	}
	else if (this->main[choix - 1]->getNom() == "Argent") {
		this->setArgent(this->getArgent() + this->main[choix - 1]->getCost());
		cout << "vous obtenez " << this->main[choix - 1]->getCost() << " BalkCoins !" << endl;
	}
	else {
		if (this->main[choix - 1]->getStatistique() == 0) {
			this->perso->setVie(this->perso->getVie() + this->main[choix - 1]->getAlteration() * 10);
			cout << "vous vous etes soigne de " << this->main[choix - 1]->getAlteration() * 10 << " Points de vie !" << endl;
		}
		else if (this->main[choix - 1]->getStatistique() == 1) {
			this->perso->setAttaque(this->perso->getAttaque() + this->main[choix - 1]->getAlteration() * 5);
			cout << "vous boostez votre attaque de " << this->main[choix - 1]->getAlteration() * 5 << " !" << endl;
		}
		else if (this->main[choix - 1]->getStatistique() == 2) {
			this->perso->setDefense(this->perso->getDefense() + this->main[choix - 1]->getAlteration() * 5);
			cout << "vous augmentez votre defense de " << this->main[choix - 1]->getAlteration() * 5 << " !" << endl;
		}
		else if (this->main[choix - 1]->getStatistique() == 3) {
			this->perso->setEsquive(this->perso->getEsquive() + this->main[choix - 1]->getAlteration() * 5);
			cout << "vous gagnez " << this->main[choix - 1]->getAlteration() * 5 << " points d'esquive !" << endl;
		}
		else if (this->main[choix - 1]->getStatistique() == 4) {
			this->perso->setPerception(this->perso->getPerception() + this->main[choix - 1]->getAlteration() - 2);
			cout << "vous pouvez piocher " << this->perso->getPerception() << " cartes !" << endl;
		}
		else if (this->main[choix - 1]->getStatistique() == 6) {
			this->perso->setPA(this->perso->getPA() + this->main[choix - 1]->getAlteration() * 1);
			cout << "vous obtenez " << this->main[choix - 1]->getAlteration() * 1 << " PA supplémentaire(s) !" << endl;
		}
	}
}

//PIOCHE DES CARTES ET SUPPRESSION DE LA CARTE DANS LE DECK
void joueur::joueurPiocher(Deck* deck){
	
	for (int i = 0; i < this->perso->getPerception(); i++) {
		if (deck->getCarte().size() > 4) {
			this->main.push_back(deck->getCarte()[i]); /*deck->getCarte().size() - (1 + i)*/
			//deck->getCarte().erase(deck->getPioche().begin());
			deck->suppCarte();
		}
		else {
			cout << "Il n\'y a plus de cartes !" << endl;
		}
	//Ancienne méthode utilisant pioche[]
	/*
	deck->pioche();
	for (i = 0; i < deck->getPioche().size(); i++) {
		deck->getPioche().operator[](i)->afficher();
	}
	
		//this->main[i]->afficher();    <---- afficher la main (mettre main[main.size()]
		*/
	}
	//Ancienne méthode utilisant pioche[]
	/*
	vector<carte*> main2(deck->getPioche().begin(), deck->getPioche().end());
	this->main.push_back(deck->getPioche().begin(), deck->getPioche().end());
	for (i = 0; i < this->main.size(); i++) {
		main[i]->afficher();
	}
	//cout <<" "<< this->main << endl;
	*/
}


//CLEAR DE LA MAIN A LA FIN DES TOURS
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

//Choix carte & afficher main modifié
/*
void joueur::choisirCarte() {
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
}
*/

void joueur::affichagePlateau(joueur* player2, sf::RenderWindow* window)
{
	sf::RectangleShape separateur(sf::Vector2f(window->getSize().x / 2, 5.f));
	separateur.setOrigin(window->getSize().x / 4, 2.5f);
	separateur.setPosition(window->getSize().x / 2, window->getSize().y / 2);
	separateur.setFillColor(sf::Color(104, 92, 77));

	window->draw(separateur);

	affichageJoueur(this, window->getSize().x / 2, separateur.getPosition().y - 300.f, window);
	affichageJoueur(player2, window->getSize().x / 2, separateur.getPosition().y + 100.f, window);

	window->display();
	Sleep(3000);
}

void joueur::affichageJoueur(joueur* player, int xpos, int ypos, sf::RenderWindow* window)
{
	sf::RectangleShape playercardHead(sf::Vector2f(250.0f, 50.0f));
	sf::RectangleShape playercardBody(sf::Vector2f(250.0f, 200.0f));

	playercardHead.setFillColor(sf::Color(154, 142, 127));
	playercardBody.setFillColor(sf::Color(154, 142, 127));
	playercardHead.setOutlineThickness(3.f);
	playercardHead.setOutlineColor(sf::Color(104, 92, 77));
	playercardBody.setOutlineThickness(3.f);
	playercardBody.setOutlineColor(sf::Color(104, 92, 77));

	playercardHead.setOrigin(125.f, 12.5f);
	playercardBody.setOrigin(125.f, 100.f);

	playercardHead.setPosition(xpos, ypos);
	playercardBody.setPosition(playercardHead.getPosition().x, playercardHead.getPosition().y + 142.f);


	sf::Text nom;
	sf::Text vie;
	sf::Text preVie;
	sf::Text attaque;
	sf::Text preAtk;
	sf::Text defense;
	sf::Text preDef;
	sf::Text esquive;
	sf::Text preEsq;
	sf::Text initiative;
	sf::Text preInitia;
	sf::Text perception;
	sf::Text prePerc;
	sf::Text pa;
	sf::Text prePa;


	nom.setString(player->getPerso()->getNom());

	syntaxeCarte(nom);
	nom.setCharacterSize(25);
	setOrigine(nom);


	nom.setPosition(playercardHead.getPosition().x, playercardHead.getPosition().y + 12.5f);

	//
	preVie.setString("vie :");
	vie.setString(std::to_string(player->getPerso()->getVie()));
	preAtk.setString("attaque :");
	attaque.setString(std::to_string(player->getPerso()->getAttaque()));
	preDef.setString("defense :");
	defense.setString(std::to_string(player->getPerso()->getDefense()));
	preEsq.setString("esquive :");
	esquive.setString(std::to_string(player->getPerso()->getEsquive()));
	preInitia.setString("initiative :");
	initiative.setString(std::to_string(player->getPerso()->getInitiative()));
	prePerc.setString("perception :");
	perception.setString(std::to_string(player->getPerso()->getPerception()));
	prePa.setString("PA :");
	pa.setString(std::to_string(player->getPerso()->getPA()));

	syntaxeCarte(preVie);
	syntaxeCarte(vie);
	syntaxeCarte(preAtk);
	syntaxeCarte(attaque);
	syntaxeCarte(preDef);
	syntaxeCarte(defense);
	syntaxeCarte(preEsq);
	syntaxeCarte(esquive);
	syntaxeCarte(preInitia);
	syntaxeCarte(initiative);
	syntaxeCarte(prePerc);
	syntaxeCarte(perception);
	syntaxeCarte(prePa);
	syntaxeCarte(pa);

	setOrigine(preVie);
	setOrigine(vie);
	setOrigine(preAtk);
	setOrigine(attaque);
	setOrigine(preDef);
	setOrigine(defense);
	setOrigine(preEsq);
	setOrigine(esquive);
	setOrigine(preInitia);
	setOrigine(initiative);
	setOrigine(prePerc);
	setOrigine(perception);
	setOrigine(prePa);
	setOrigine(pa);


	preVie.setPosition(playercardBody.getPosition().x, playercardBody.getPosition().y - 80.f);
	vie.setPosition(preVie.getPosition().x + 40.f, preVie.getPosition().y);

	preAtk.setPosition(playercardBody.getPosition().x, playercardBody.getPosition().y - 55.f);
	attaque.setPosition(preAtk.getPosition().x + 50.f, preAtk.getPosition().y);

	preDef.setPosition(playercardBody.getPosition().x, playercardBody.getPosition().y - 30.f);
	defense.setPosition(preDef.getPosition().x + 50.f, preDef.getPosition().y);

	preEsq.setPosition(playercardBody.getPosition().x, playercardBody.getPosition().y - 5.f);
	esquive.setPosition(preEsq.getPosition().x + 50.f, preEsq.getPosition().y);

	preInitia.setPosition(playercardBody.getPosition().x, playercardBody.getPosition().y + 20.f);
	initiative.setPosition(preInitia.getPosition().x + 60.f, preInitia.getPosition().y);

	prePerc.setPosition(playercardBody.getPosition().x, playercardBody.getPosition().y + 45.f);
	perception.setPosition(prePerc.getPosition().x + 65.f, prePerc.getPosition().y);

	prePa.setPosition(playercardBody.getPosition().x, playercardBody.getPosition().y + 70.f);
	pa.setPosition(prePa.getPosition().x + 40.f, prePa.getPosition().y);

	window->draw(playercardHead);
	window->draw(playercardBody);

	window->draw(nom);
	window->draw(preVie);
	window->draw(vie);
	window->draw(preAtk);
	window->draw(attaque);
	window->draw(preDef);
	window->draw(defense);
	window->draw(preEsq);
	window->draw(esquive);
	window->draw(preInitia);
	window->draw(initiative);
	window->draw(prePerc);
	window->draw(perception);
	window->draw(prePa);
	window->draw(pa);


}

void joueur::syntaxeCarte(sf::Text& text)
{
	text.setFont(*this->fontJoueur);
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(20);
}

// Permet de set l'origine du texte à son milieu
void joueur::setOrigine(sf::Text& text)
{
	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
}



/*int joueur::fChoix() {
	int choix;
	while (!sf::Keyboard::isKeyPressed) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			choix = 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
			choix = 2;

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
		{
			choix = 3;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
		{
			choix = 4;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
		{
			choix = 5;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
		{
			choix = 6;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
		{
			choix = 7;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
		{
			choix = 8;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
		{
			choix = 9;
		}
	}
	return choix;
}*/

void joueur::shopping(joueur* cible, deckShop* deckshop, sf::RenderWindow* window) {
	window->clear();

	deckshop->checkTaille();
	texteCombat* txt = new texteCombat;
	affichageJoueur(this, window->getSize().x / 2, (window->getSize().y / 2) - 300.f, window);
	txt->shopTxt(this, window);
	this->joueurShop(deckshop);
	this->joueurAcheterCarte(cible, deckshop, window);
	window->display();
}
//CHOIX DE LA CARTE A JOUER
void joueur::joueurAcheterCarte(joueur* cible, deckShop* deckshop, sf::RenderWindow* window) {
	int choix;
	if (this->main.size() != 0) {
		cout << "Bienvenue dans mon magasin" << endl;

		while (this->getArgent() > 9 && this->main.size() > 0) {
			window->clear();
			cout << "Vous avez " << this->getArgent() << " pieces" << endl;

			if (this->main.size() > 5) {
				this->affichageJoueur(this, window->getSize().x / 2, (window->getSize().y / 2 - 300.f), window);
				for (int i = 0; i < this->main.size(); i++) { this->main[i]->sfafficher(window, i * 150); }
			}
			else {
				this->affichageJoueur(this, window->getSize().x / 2, window->getSize().y / 2 - 300.f, window);
				for (int i = 0; i < this->main.size(); i++) { this->main[i]->sfafficher(window, i * 300); }
			}
			window->display();
			cout << "choisissez une carte a acheter ou passez votre chemin" << endl;
			cin >> choix;
			if (choix == 0) {
				cout << "vous decidez de passer votre chemin" << endl;
			}
			else {
				while (choix > main.size()) {
					cout << "choisissez un nombre valide" << endl;
					cin >> choix;
				}
				joueurActiverCarteShop(cible, deckshop, choix);
				this->main.erase(main.begin() + choix - 1);
				cout << "il vous reste : " << this->getArgent() << " BalkCoin" << endl;
			}
			if (this->getArgent() < 10 ) {
				cout << "Vous n'avez plus d'argent, sortez d'ici !" << endl;
			}
			else if (this->main.size() < 1) {
				cout << "Je n'ai plus rien, revenez plus tard" << endl;
			}
		}
	}
	this->main.clear();

}

//MISE EN PLACE DES EFFETS DES POTIONS
void joueur::joueurActiverCarteShop(joueur* cible, deckShop* deckshop, int choix) {
	if (this->main[choix - 1]->getStatistique() == 0) {
		this->perso->setVie(this->perso->getVie() + this->main[choix - 1]->getAlteration() * 10);
		cout << "vous vous etes soigne de " << this->main[choix - 1]->getAlteration() * 10 << " Points de vie !" << endl;
	}
	else if (this->main[choix - 1]->getStatistique() == 1) {
		this->perso->setAttaque(this->perso->getAttaque() + this->main[choix - 1]->getAlteration() * 5);
		cout << "vous boostez votre attaque de " << this->main[choix - 1]->getAlteration() * 5 << " !" << endl;
	}
	else if (this->main[choix - 1]->getStatistique() == 2) {
		this->perso->setDefense(this->perso->getDefense() + this->main[choix - 1]->getAlteration() * 5);
		cout << "vous augmentez votre defense de " << this->main[choix - 1]->getAlteration() * 5 << " !" << endl;
	}
	else if (this->main[choix - 1]->getStatistique() == 3) {
		this->perso->setEsquive(this->perso->getEsquive() + this->main[choix - 1]->getAlteration() * 5);
		cout << "vous gagnez " << this->main[choix - 1]->getAlteration() * 5 << " points d'esquive !" << endl;
	}
	else if (this->main[choix - 1]->getStatistique() == 4) {
		this->perso->setPerception(this->perso->getPerception() + this->main[choix - 1]->getAlteration() - 2);
		cout << "vous pouvez piocher " << this->perso->getPerception() << " cartes !" << endl;
	}
	else if (this->main[choix - 1]->getStatistique() == 6) {
		this->perso->setPA(this->perso->getPA() + this->main[choix - 1]->getAlteration() * 1);
		cout << "vous obtenez " << this->main[choix - 1]->getAlteration() * 1 << " PA supplémentaire(s) !" << endl;
	}
	this->setArgent(this->getArgent() - this->main[choix - 1]->getCost());

}

//PIOCHE DES CARTES ET SUPPRESSION DE LA CARTE DANS LE DECK
void joueur::joueurShop(deckShop* deckshop) {

	for (int i = 0; i < 4; i++) {
		if (deckshop->getCarte().size() > 4) {
			this->main.push_back(deckshop->getCarte()[i]);
			deckshop->suppCarte();
		}
		else {
			cout << "Il n\'y a plus de cartes !" << endl;
		}
	}
}

void joueur::reset(joueur* cible) {
	this->perso->setVie(100);
	this->perso->setAttaque(5);
	this->perso->setDefense(5);
	this->perso->setPerception(4);
	this->perso->setInitiative(3);
	this->perso->setEsquive(2);
	this->perso->setPA(3);
	cible->perso->setVie(100);
	cible->perso->setAttaque(5);
	cible->perso->setDefense(5);
	cible->perso->setPerception(4);
	cible->perso->setInitiative(3);
	cible->perso->setEsquive(2);
	cible->perso->setPA(3);
}