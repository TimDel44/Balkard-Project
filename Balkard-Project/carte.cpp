#include <iostream>
#include <string>
#include "carte.h"
#include <SFML/Graphics.hpp>

using namespace std;

carte::carte(string nom)
{
	this->nom = nom;
	this->fontCarte = new sf::Font;
	if (!this->fontCarte->loadFromFile("font/alagard.ttf"))
	{
		// erreur...
	}
}

void carte::afficher() 
{
	/*
	cout << "	-------------------" << endl;
	printf("	| nom : %-9d |\n", this->getNom().c_str());
	cout << "	-------------------" << endl;
	printf("	| %-15d |\n");
	printf("	| %-15d |\n");
	printf("	| %-15d |\n");
	printf("	| %-15d |\n");
	printf("	| %-15d |\n");
	printf("	| %-15d |\n");
	printf("	| %-15d |\n");
	cout << "	-------------------" << endl;
	*/
}
void carte::sfafficher(sf::RenderWindow*, int) {}

void carte::sfCreationCarte(sf::RectangleShape &cardHead, sf::RectangleShape &cardBody) 
{
	cardHead.setFillColor(sf::Color(154, 142, 127));
	cardBody.setFillColor(sf::Color(154, 142, 127));
	cardHead.setOutlineThickness(3.f);
	cardHead.setOutlineColor(sf::Color(104, 92, 77));
	cardBody.setOutlineThickness(3.f);
	cardBody.setOutlineColor(sf::Color(104, 92, 77));

	cardHead.setOrigin(125.f, 12.5f);
	cardBody.setOrigin(125.f, 100.f);
}

//Permet de set un font, une couleur et une size
void carte::syntaxeCarte(sf::Text& text)
{
	text.setFont(*this->fontCarte);
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(20);
}

// Permet de set l'origine du texte à son milieu
void carte::setOrigine(sf::Text& text)
{
	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
}


carte::~carte(){}