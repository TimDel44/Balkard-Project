#include "carteArgent.h"
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
#include <sstream>

using namespace std;
/*void Color(int couleurDuTexte, int couleurDeFond) {
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H, couleurDeFond * 16 + couleurDuTexte);
}*/

carteArgent::carteArgent(string nom, int c) :carte(nom), cost(c) {}

void carteArgent::afficher() {
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	cout << "	-------------------" << endl;
	cout <<"	|   " << "Pieces d\'or"/*this->getNom()*/ << "   |" << endl;
	cout << "	-------------------" << endl;
	printf("	|                 |\n");
	printf("	|                 |\n");
	printf("	|                 |\n");
	printf("	| valeur : %-6d |\n", this->getCost());
	printf("	|                 |\n");
	printf("	|                 |\n");
	printf("	|                 |\n");
	cout << "	-------------------" << endl;
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	//printf("	| nom : %-9d |\n", this->carte::nom.c_str());
	/*cout << "--------------------" << endl;
	cout << "   Carte Argent !   " << endl;
	cout << "--------------------" << endl;
	cout << "     Valeur : " << this->getValeur() << "    " << endl;
	cout << "--------------------" << endl;
	*/
	//cout << this->valeur << " " << this->getNom() << endl;

}
void carteArgent::sfafficher(sf::RenderWindow* window, int xpos,int deck/*, int ypos*/)
{
	sf::RectangleShape cardHead(sf::Vector2f(250.0f, 50.0f));
	sf::RectangleShape cardBody(sf::Vector2f(250.0f, 200.0f));
	carte::sfCreationCarte(cardHead, cardBody);
	sf::Text type;
	//sf::Text stat;
	//sf::Text preStat;
	sf::Text niveau;
	sf::Text preNiveau;

	ostringstream a;
	a << this->getCost();

	type.setString("Argent");
	//stat.setString(this->getValeur());
	//preStat.setString("stat :");
	niveau.setString(a.str());
	preNiveau.setString("BalkCoin");

	carte::syntaxeCarte(type);
	type.setCharacterSize(25);
	carte::setOrigine(type);

	//carte::syntaxeCarte(preStat);
	//carte::setOrigine(preStat);
	//carte::syntaxeCarte(stat);
	//carte::setOrigine(stat);

	carte::syntaxeCarte(preNiveau);
	carte::setOrigine(preNiveau);
	carte::syntaxeCarte(niveau);
	carte::setOrigine(niveau);

	cardHead.setPosition(300.f + xpos, window->getSize().y - 300.f);
	cardBody.setPosition(cardHead.getPosition().x, cardHead.getPosition().y + 142.f);

	type.setPosition(cardHead.getPosition().x, cardHead.getPosition().y + 12.5f);

	//stat.setPosition(cardBody.getPosition().x, cardBody.getPosition().y - 30.f);
	//stat.setPosition(preStat.getPosition().x + 50.f, preStat.getPosition().y);

	preNiveau.setPosition(cardBody.getPosition().x, cardBody.getPosition().y + 20.f);
	niveau.setPosition(preNiveau.getPosition().x + 60.f, preNiveau.getPosition().y);

	window->draw(cardHead);
	window->draw(cardBody);

	window->draw(type);
	//window->draw(preStat);
	//window->draw(stat);
	window->draw(preNiveau);
	window->draw(niveau);
}