#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "joueur.h"
class miseEnPage
{
private:
	sf::RenderWindow* window;
	sf::Font* fontTitre;
	sf::Font* fontHead;
public :
	miseEnPage();
	sf::Font* getFontTitre() { return this->fontTitre; }
	sf::RenderWindow* getWindow() { return this->window; }

	void affichageNom(std::string);
	void Titre();
	//void affichageJoueur(joueur*, int, int);
	void setOrigine(sf::Text&);
	void syntaxeCarte(sf::Text&);
	//void affichagePlateau(joueur*, joueur*);
};

