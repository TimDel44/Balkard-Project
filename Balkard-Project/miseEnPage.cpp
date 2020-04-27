#include "miseEnPage.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
//#include "joueur.h"
#include "personnage.h"

miseEnPage::miseEnPage() {
    this->window = new sf::RenderWindow(sf::VideoMode(1600, 900), "Balkard-Project", sf::Style::Close | sf::Style::Titlebar);
    sf::Image icon;
    if (!icon.loadFromFile("logo.png")) { /*error*/ }
    this->window->setIcon(186, 194, icon.getPixelsPtr());
    this->fontTitre = new sf::Font;
    if (!this->fontTitre->loadFromFile("font/alagard.ttf"))
    {
        // erreur...
    }

    this->fontHead = new sf::Font;
    if (!this->fontHead->loadFromFile("font/PIXEL___.ttf"))
    {
        // erreur...
    }
}


/*void miseEnPage::affichagePlateau(joueur* player1, joueur* player2)
{
    sf::RectangleShape separateur(sf::Vector2f(this->window->getSize().x / 2, 5.f));
    separateur.setOrigin(this->window->getSize().x / 4, 2.5f);
    separateur.setPosition(this->window->getSize().x / 2, this->window->getSize().y / 2);
    separateur.setFillColor(sf::Color(104, 92, 77));

    this->window->draw(separateur);

    affichageJoueur(player1, this->window->getSize().x / 2, separateur.getPosition().y - 300.f);
    affichageJoueur(player2, this->window->getSize().x / 2, separateur.getPosition().y + 100.f);
}*/

void miseEnPage::affichageNom(std::string nom) {
    sf::Text name;

    name.setFont(*this->fontHead);
    name.setCharacterSize(24);
    //name.setStyle(sf::Text::Bold | sf::Text::Underlined);
    name.setFillColor(sf::Color::Red);
    name.setString(nom);

    this->window->draw(name);

}

void miseEnPage::Titre() {
    sf::Text titre;
    sf::Text titre2;
    sf::Text titre3;

    titre.setFont(*this->fontTitre);
    titre.setCharacterSize(80);
    titre.setStyle(sf::Text::Bold);
    titre.setFillColor(sf::Color::Red);
    titre.setString("Bienvenue sur Balkard");
    sf::FloatRect textRect = titre.getLocalBounds();
    titre.setOrigin(textRect.left + textRect.width / 2.0f,
        textRect.top + textRect.height / 2.0f);
    titre.setPosition(sf::Vector2f(this->window->getSize().x / 2.0f, this->window->getSize().y / 3.0f));

    titre2.setFont(*this->fontTitre);
    titre2.setCharacterSize(32);
    //titre2.setStyle(sf::Text::Bold);
    titre2.setFillColor(sf::Color::White);
    titre2.setString("Appuyez sur entree pour continuer");
    sf::FloatRect textRect2 = titre2.getLocalBounds();
    titre2.setOrigin(textRect2.left + textRect2.width / 2.0f,
        textRect2.top + textRect2.height / 2.0f);
    titre2.setPosition(sf::Vector2f(window->getSize().x / 2.0f , window->getSize().y / 2.0f + window->getSize().y / 5.0f));

    titre3.setFont(*this->fontTitre);
    titre3.setCharacterSize(24);
    //titre2.setStyle(sf::Text::Bold);
    titre3.setFillColor(sf::Color::White);
    titre3.setString("Projet realise par Timothee Delamare et Theophile Farvacque");
    sf::FloatRect textRect3 = titre3.getLocalBounds();
    titre3.setOrigin(textRect3.left + textRect3.width / 2.0f,
        textRect3.top + textRect3.height / 2.0f);
    titre3.setPosition(sf::Vector2f(window->getSize().x / 2.0f, window->getSize().y / 2.0f + 1.5f));
  /*titre.move(5.0f, 0.0f);
    if (titre.getPosition().x > this->window->getSize().x) {
        titre.setPosition(0.f, titre.getPosition().y);
    }*/
    
    this->window->draw(titre);
    this->window->draw(titre2);
    this->window->draw(titre3);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
        this->window->clear();
    }
}

/*void miseEnPage::affichageJoueur(joueur* player, int xpos, int ypos)
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

    this->window->draw(playercardHead);
    this->window->draw(playercardBody);

    this->window->draw(nom);
    this->window->draw(preVie);
    this->window->draw(vie);
    this->window->draw(preAtk);
    this->window->draw(attaque);
    this->window->draw(preDef);
    this->window->draw(defense);
    this->window->draw(preEsq);
    this->window->draw(esquive);
    this->window->draw(preInitia);
    this->window->draw(initiative);
    this->window->draw(prePerc);
    this->window->draw(perception);
    this->window->draw(prePa);
    this->window->draw(pa);
    

}*/


//Permet de set un font, une couleur et une size
void miseEnPage::syntaxeCarte(sf::Text &text)
{
    text.setFont(*this->fontTitre);
    text.setFillColor(sf::Color::Black);
    text.setCharacterSize(20);
}

// Permet de set l'origine du texte à son milieu
void miseEnPage::setOrigine(sf::Text &text)
{
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f,
        textRect.top + textRect.height / 2.0f);
}




/*sf::FloatRect textRect = text.getLocalBounds();
text.setOrigin(textRect.left + textRect.width/2.0f,
               textRect.top  + textRect.height/2.0f);
text.setPosition(sf::Vector2f(SCRWIDTH/2.0f,SCRHEIGHT/2.0f));*/