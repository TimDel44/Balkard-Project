#pragma once
#include <SFML/Graphics.hpp>
#include "joueur.h"
class texteCombat
{
private :
	sf::Font* fontCombat;

public :
	texteCombat();
	sf::Font* getFontCombat() { return this->fontCombat; }
	void syntaxeCartetxt(sf::Text& text);
	void setOriginetxt(sf::Text& text);
	void preparationAtkTxt(joueur*, sf::RenderWindow*);
	//void atkTxt(joueur*, sf::RenderWindow*);
	void jetAtkTxt(joueur*, sf::RenderWindow*, int);
	void atkCritTxt(joueur*, sf::RenderWindow*);
	void atkFailTxt(joueur*, sf::RenderWindow*);
	void jetEsquiveTxt(joueur*, sf::RenderWindow*, int);
	void esquiveTxt(joueur*, sf::RenderWindow*);
	void jetInitiaTxt(joueur*, sf::RenderWindow*, int);

	void setOriginetxtBRESOM(sf::Text& text);

};

