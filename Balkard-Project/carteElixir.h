#pragma once
#include <iostream>
#include "carte.h"
#include <string>
using namespace std;


class carteElixir : public carte
{
private:
    string nomStat;
    string niveau;
    int alteration;
    int statistique;
    int cost;
public:

    carteElixir(string nom, string nomStat, string niveau, int a, int s, int c);
    string getNomStat() { return this->nomStat; }
    void setNomStat(std::string nomStat) { this->nomStat = nomStat; }
    string getNiveau() { return this->niveau; }
    void setNiveau(std::string niveau) { this->niveau = niveau; }
    int getAlteration() { return this->alteration; }
    int getStatistique() { return this->statistique; }
    int getCost() { return this->cost; }
    void setAlteration(int a) { this->alteration = a; }
    void setStatistique(int s) { this->statistique = s; }
    void setCost(int c) { this->cost = c; }
    virtual void afficher();
    virtual void sfafficher(sf::RenderWindow* window, int xpos, int deck/*, int ypos*/);
};
