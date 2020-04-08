#pragma once
#include <iostream>
#include "carte.h"
#include <string>
using namespace std;

class cartePotion : public carte
{
private:
    string nomStat;
    string niveau;
    int alteration;
    int statistique;
public:
   
    cartePotion(string nom, string nomStat, string niveau, int a, int s);
    string getNomStat() { return this->nomStat; }
    string setNomStat(std::string nomStat) { this->nomStat = nomStat; }

    string getNiveau() { return this->niveau; }
    string setNiveau(std::string niveau) { this->niveau = niveau; }

    virtual int getAlteration() { return this->alteration; }
    virtual int getStatistique() { return this->statistique; }
    void setAlteration() { this->alteration = alteration; }
    void setStatistique() { this->statistique = statistique; }
    virtual void afficher();

};

