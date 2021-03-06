#pragma once
#include <iostream>
#include "carte.h"
#include <string>
using namespace std;

class carteTalisman : public carte
{
private:
    string nomStat;
    string niveau;
    int alteration;
    int statistique;
public:

    carteTalisman(string nom, string nomStat, string niveau, int a, int s);
    string getNomStat() { return this->nomStat; }
    void setNomStat(std::string nomStat) { this->nomStat = nomStat; }
    string getNiveau() { return this->niveau; }
    void setNiveau(std::string niveau) { this->niveau = niveau; }
    int getAlteration() { return this->alteration; }
    int getStatistique() { return this->statistique; }
    void setAlteration(int a) { this->alteration = a; }
    void setStatistique(int s) { this->statistique = s; }
    virtual void afficher();
    virtual void sfafficher(sf::RenderWindow* window, int xpos/*, int ypos*/);
};