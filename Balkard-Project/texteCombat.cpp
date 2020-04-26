#include "texteCombat.h"


texteCombat::texteCombat() {
	this->fontCombat = new sf::Font;
	if (!this->fontCombat->loadFromFile("font/alagard.ttf"))
	{
		// erreur...
	}
}


void texteCombat::syntaxeCartetxt(sf::Text& text)
{
	text.setFont(*this->fontCombat);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(25);
}

// Permet de set l'origine du texte à son milieu
void texteCombat::setOriginetxt(sf::Text& text)
{
	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
}

void texteCombat::setOriginetxtBRESOM(sf::Text& text)
{
	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
}


void texteCombat::preparationAtkTxt(joueur* player, sf::RenderWindow* window) {
	sf::Text playerName;
	sf::Text flavorText;
	playerName.setString(player->getPerso()->getNom());
	flavorText.setString("se prepare a attaquer !");
	syntaxeCartetxt(playerName);
	syntaxeCartetxt(flavorText);
	setOriginetxt(playerName);
	setOriginetxt(flavorText);
	flavorText.setPosition(window->getSize().x / 5, 150.f);
	playerName.setPosition(flavorText.getPosition().x - 200.f, flavorText.getPosition().y);
	window->draw(flavorText);
	window->draw(playerName);
	window->display();
}

void texteCombat::jetAtkTxt(joueur* player, sf::RenderWindow* window, int jetAttaque) {
	sf::Text playerName;
	sf::Text flavorText;
	sf::Text jet;
	playerName.setString(player->getPerso()->getNom());
	flavorText.setString("fait un jet d'attaque de");
	jet.setString(std::to_string(jetAttaque));
	syntaxeCartetxt(playerName);
	syntaxeCartetxt(flavorText);
	syntaxeCartetxt(jet);
	setOriginetxt(playerName);
	setOriginetxt(flavorText);
	setOriginetxt(jet);
	flavorText.setPosition(window->getSize().x / 5, 200.f);
	playerName.setPosition(flavorText.getPosition().x - 200.f, flavorText.getPosition().y);
	jet.setPosition(flavorText.getPosition().x + 175.f, flavorText.getPosition().y);
	window->draw(flavorText);
	window->draw(playerName);
	window->draw(jet);
	window->display();
}
void texteCombat::atkCritTxt(joueur* player, sf::RenderWindow* window) {
	sf::Text playerName;
	sf::Text flavorText;
	playerName.setString(player->getPerso()->getNom());
	flavorText.setString("fait un fait un coup critique !");
	syntaxeCartetxt(playerName);
	syntaxeCartetxt(flavorText);
	setOriginetxt(playerName);
	setOriginetxt(flavorText);
	flavorText.setPosition(window->getSize().x / 5, 250.f);
	playerName.setPosition(flavorText.getPosition().x - 200.f, flavorText.getPosition().y);
	window->draw(flavorText);
	window->draw(playerName);
	window->display();
}
void texteCombat::atkFailTxt(joueur* player, sf::RenderWindow* window) {
	sf::Text playerName;
	sf::Text flavorText;
	playerName.setString(player->getPerso()->getNom());
	flavorText.setString("rate son attaque !");
	syntaxeCartetxt(playerName);
	syntaxeCartetxt(flavorText);
	setOriginetxt(playerName);
	setOriginetxt(flavorText);
	flavorText.setPosition(window->getSize().x / 5, 250.f);
	playerName.setPosition(flavorText.getPosition().x - 200.f, flavorText.getPosition().y);
	window->draw(flavorText);
	window->draw(playerName);
	window->display();
}
void texteCombat::jetEsquiveTxt(joueur* player, sf::RenderWindow* window, int jetEsquive) {
	sf::Text playerName;
	sf::Text flavorText;
	sf::Text jet;
	playerName.setString(player->getPerso()->getNom());
	flavorText.setString("fait un jet d'esquive de");
	jet.setString(std::to_string(jetEsquive));
	syntaxeCartetxt(playerName);
	syntaxeCartetxt(flavorText);
	syntaxeCartetxt(jet);
	setOriginetxt(playerName);
	setOriginetxt(flavorText);
	setOriginetxt(jet);
	flavorText.setPosition(window->getSize().x / 5, 300.f);
	playerName.setPosition(flavorText.getPosition().x - 200.f, flavorText.getPosition().y);
	//playerName.setPosition(window->getSize().x / 10, 300.f);
	//flavorText.setPosition(playerName.getPosition().x + 300.f, playerName.getPosition().y);
	jet.setPosition(flavorText.getPosition().x + 175.f, flavorText.getPosition().y);
	window->draw(flavorText);
	window->draw(playerName);
	window->draw(jet);
	window->display();
}
void texteCombat::esquiveTxt(joueur* player, sf::RenderWindow* window) {
	sf::Text playerName;
	sf::Text flavorText;
	playerName.setString(player->getPerso()->getNom());
	flavorText.setString("esquive l'attaque !");
	syntaxeCartetxt(playerName);
	syntaxeCartetxt(flavorText);
	setOriginetxt(playerName);
	setOriginetxt(flavorText);
	flavorText.setPosition(window->getSize().x / 5, 350.f);
	playerName.setPosition(flavorText.getPosition().x - 200.f, flavorText.getPosition().y);
	window->draw(flavorText);
	window->draw(playerName);
	window->display();
}
void texteCombat::jetInitiaTxt(joueur* player, sf::RenderWindow* window, int jetInitiative) {
	sf::Text playerName;
	sf::Text flavorText;
	sf::Text jet;
	playerName.setString(player->getPerso()->getNom());
	flavorText.setString("fait un jet d'initiative de");
	jet.setString(std::to_string(jetInitiative));
	syntaxeCartetxt(playerName);
	syntaxeCartetxt(flavorText);
	syntaxeCartetxt(jet);
	setOriginetxt(playerName);
	setOriginetxt(flavorText);
	setOriginetxt(jet);
	flavorText.setPosition(window->getSize().x / 5, 100.f);
	playerName.setPosition(flavorText.getPosition().x - 200.f, flavorText.getPosition().y);
	jet.setPosition(flavorText.getPosition().x + 175.f, flavorText.getPosition().y);
	window->draw(flavorText);
	window->draw(playerName);
	window->draw(jet);
	window->display();
}
void texteCombat::shopTxt(joueur* player, sf::RenderWindow* window) {
	sf::Text playerName;
	sf::Text flavorText;
	playerName.setString(player->getPerso()->getNom());
	flavorText.setString(", Bienvenue dans mon magasin");
	syntaxeCartetxt(playerName);
	syntaxeCartetxt(flavorText);
	setOriginetxt(playerName);
	setOriginetxt(flavorText);
	flavorText.setPosition(window->getSize().x / 5, 100.f);
	playerName.setPosition(flavorText.getPosition().x - 200.f, flavorText.getPosition().y);
	window->draw(flavorText);
	window->draw(playerName);
	window->display();
}