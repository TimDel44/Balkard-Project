#pragma once
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
#include "personnage.h"
#include "Deck.h"
#include "deckShop.h"
//#include "miseEnPage.h"
#include <SFML/Graphics.hpp>
using namespace std;

class joueur
{
private:

	int actif;
	int persoVivant;
	personnage* perso;
	int argent;
	int possedeSort;
	int possedeRituel;
	int possedeItem;
	vector<carte*> main;
	vector<carte*> shop;
	sf::Font* fontJoueur;
  
public:

	int getActif() { return this->actif; }
	int getPersoVivant() { return this->persoVivant; }
	int getArgent() { return this->argent; }
	int getPossedeSort() { return this->possedeSort; }
	int getPossedeRituel() { return this->possedeRituel; }
	int getPossedeItem() { return this->possedeSort; }
	vector<carte*> getMain() { return this->main; }
	vector<carte*> getShop() { return this->shop; }
	personnage* getPerso() { return this->perso;  }
	sf::Font* getFontJoueur() { return this->fontJoueur; }

	void setArgent(int argent) { this->argent = argent; }
	void setActif() { this->actif = actif; }
	void setPersoVivant() { this->persoVivant = persoVivant; }
	void setPersonnage(personnage* perso) { this->perso = perso; }
	void setPossedeSort() { this->possedeSort = possedeSort; }
	void setPossedeRituel() { this->possedeRituel = possedeRituel; }
	void setPossedeItem() { this->possedeItem = possedeItem; }

	joueur(personnage* perso);
	void afficherJoueur();
	void joueurCombat(joueur* cible, Deck*, deckShop*, sf::RenderWindow*);
	void attaquer(joueur*, sf::RenderWindow*);
	void subir(int degats, sf::RenderWindow*);
	int jetInitierCombat(sf::RenderWindow*);
	void initierCombat(joueur*, Deck*, sf::RenderWindow*);

	void clear();
	void finDeCombat(joueur*, Deck*, sf::RenderWindow*);
	void debutDeCombat(joueur*, Deck*, sf::RenderWindow*);

	void joueurPiocher(Deck* deck);
	void joueurJouerCarte(joueur*, Deck*, sf::RenderWindow*);
	void joueurActiverCarte(joueur*, Deck*, int);
	//Méthode non retenu de choix de carte
	//void choisirCarte();
	//void afficherMain();

	void shopping(joueur*, deckShop*,sf::RenderWindow*);
	void joueurShop(deckShop* deckshop);
	void joueurAcheterCarte(joueur*, deckShop*, sf::RenderWindow*);
	void joueurActiverCarteShop(joueur*, deckShop*, int);

	void syntaxeCarte(sf::Text& text);
	void setOrigine(sf::Text& text);
	void affichageJoueur(joueur* player, int xpos, int ypos, sf::RenderWindow*);
	void affichagePlateau(joueur* player2, sf::RenderWindow*);
	//int fChoix();

	void reset(joueur*);
};
