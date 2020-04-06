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
    int getAlteration() { return this->alteration; }
    int getStatistique() { return this->statistique; }
    void setAlteration(int a) { this->alteration = a; }
    void setStatistique(int s) { this->statistique = s; }
    virtual void afficher();

};

