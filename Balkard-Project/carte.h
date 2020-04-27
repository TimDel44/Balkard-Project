#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;

class carte
{
protected:
	string nom;
	int alteration;
	int statistique;
	int cost;
	sf::Font* fontCarte;
	sf::Texture* textureCarte;
public:
	string getNom() { return this->nom; }
	void setNom(string nom) { this->nom = nom; }
	sf::Texture* getTextureCarte() { return this->textureCarte; }
	sf::Font* getFontCarte() { return this->fontCarte; }

	carte(string nom);

	virtual void afficher();
	virtual void sfafficher(sf::RenderWindow* window, int,int);
	virtual int getAlteration() { return this->alteration; }
	virtual int getStatistique() { return this->statistique; }
	virtual int getCost() { return this->cost; }
	virtual void sfCreationCarte(sf::RectangleShape& cardHead, sf::RectangleShape& cardBody);
	virtual void syntaxeCarte(sf::Text& text);
	virtual void setOrigine(sf::Text& text);
	~carte();
};

