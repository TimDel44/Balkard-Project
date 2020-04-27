#pragma once
#include <iostream>
#include "carte.h"
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;

class carteSort : public carte
{
private:
    string nomStat;
    string niveau;
    int alteration;
    int statistique;
    int cost;
public:

    carteSort(string nom, string nomStat, string niveau, int a, int s, int c);
    string getNomStat() { return this->nomStat; }
    string setNomStat(std::string nomStat) { this->nomStat = nomStat; }

    string getNiveau() { return this->niveau; }
    string setNiveau(std::string niveau) { this->niveau = niveau; }

    virtual int getAlteration() { return this->alteration; }
    virtual int getStatistique() { return this->statistique; }
    virtual int getCost() { return this->cost; }
    void setAlteration() { this->alteration = alteration; }
    void setStatistique() { this->statistique = statistique; }
    void setCost() { this->cost = cost; }
    virtual void afficher();
    virtual void sfafficher(sf::RenderWindow*, int, int/*, int*/);
    //virtual void setOrigine(sf::Text text);
    //virtual void syntaxeCarte(sf::Text text);
};
