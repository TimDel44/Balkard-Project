#include "cartePotion.h"
#include "carte.h"
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
#include <SFML/Graphics.hpp>

/*void Color(int couleurDuTexte, int couleurDeFond) {
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H, couleurDeFond * 16 + couleurDuTexte);
}*/
using namespace std;

cartePotion::cartePotion(string nom, string nomStat, string niveau, int a, int s, int c):carte(nom),nomStat(nomStat),niveau(niveau), alteration(a), statistique(s), cost(c){}

void cartePotion::afficher()
{
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	cout << "	-------------------" << endl;
	cout << "	|     " << "Potion"/*this->getNom()*/ << "      |" << endl;
	cout << "	-------------------" << endl;
	printf("	|                 |\n");
	printf("	| stat : %-8s |\n", this->getNomStat().c_str());
	printf("	|                 |\n");
	printf("	| niveau : %-6s |\n", this->getNiveau().c_str());
	printf("	|                 |\n");
	printf("	|                 |\n");
	printf("	|                 |\n");
	cout << "	-------------------" << endl;
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	//cout << this->getNom() << this->nomStat << this->niveau << endl;
}

void cartePotion::sfafficher(sf::RenderWindow* window, int xpos, int deck/*, int ypos*/)
{
	sf::RectangleShape cardHead(sf::Vector2f(250.0f, 50.0f));
	sf::RectangleShape cardBody(sf::Vector2f(250.0f, 200.0f));
	carte::sfCreationCarte(cardHead, cardBody);
	sf::Text type;
	sf::Text stat;
	//sf::Text preStat;
	sf::Text niveau;
	sf::Text preNiveau;
	

	type.setString("Potion");
	stat.setString(this->getNomStat());
	//preStat.setString("stat :");
	niveau.setString(this->getNiveau());
	preNiveau.setString("niveau :");



	carte::syntaxeCarte(type);
	type.setCharacterSize(25);
	carte::setOrigine(type);

	//carte::syntaxeCarte(preStat);
	//carte::setOrigine(preStat);
	carte::syntaxeCarte(stat);
	carte::setOrigine(stat);

	carte::syntaxeCarte(preNiveau);
	carte::setOrigine(preNiveau);
	carte::syntaxeCarte(niveau);
	carte::setOrigine(niveau);

	cardHead.setPosition(300.f + xpos, window->getSize().y - 300.f);
	cardBody.setPosition(cardHead.getPosition().x, cardHead.getPosition().y + 142.f);

	type.setPosition(cardHead.getPosition().x, cardHead.getPosition().y + 12.5f);

	stat.setPosition(cardBody.getPosition().x, cardBody.getPosition().y - 30.f);
	//stat.setPosition(preStat.getPosition().x + 50.f, preStat.getPosition().y);

	preNiveau.setPosition(cardBody.getPosition().x, cardBody.getPosition().y + 20.f);
	niveau.setPosition(preNiveau.getPosition().x + 60.f, preNiveau.getPosition().y);

	window->draw(cardHead);
	window->draw(cardBody);

	window->draw(type);
	//window->draw(preStat);
	window->draw(stat);
	window->draw(preNiveau);
	window->draw(niveau);

	if (deck == 1) {
		sf::Text preCost;
		sf::Text cost;
		cost.setString(std::to_string(this->getCost()));
		preCost.setString("prix :");
		carte::syntaxeCarte(preCost);
		carte::setOrigine(preCost);
		carte::syntaxeCarte(cost);
		carte::setOrigine(cost);
		preCost.setPosition(cardBody.getPosition().x, cardBody.getPosition().y + 45.f);
		cost.setPosition(preCost.getPosition().x + 60.f, preCost.getPosition().y);
		window->draw(preCost);
		window->draw(cost);
	}
}

/*void cartePotion::setOrigine(sf::Text* text)
{
	sf::FloatRect textRect = text->getLocalBounds();
	text->setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
}

void cartePotion::syntaxeCarte(sf::Text* text)
{
	sf::Font fontCarte;
	if (!fontCarte.loadFromFile("font/alagard.ttf"))
	{
		// erreur...
	}
	text->setFont(fontCarte);
	text->setFillColor(sf::Color::Black);
	text->setCharacterSize(20);
}*/