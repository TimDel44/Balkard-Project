#pragma once
#include <iostream>
#include "carte.h"
#include <string>
using namespace std;

class carteRituel : public carte
{
private:
    int alteration;
    int statistique;
    string noms[7] = { "Force int�rieure", "D�charge", "Concentration", "Armure d'acier", "D�chainement", "Jour de chance", "Acc�leration" };
public:

    carteRituel(string nom, int a, int s);
    int getAlteration() { return this->alteration; }
    int getStatistique() { return this->statistique; }
    void setAlteration(int a) { this->alteration = a; }
    void setStatistique(int s) { this->statistique = s; }
    virtual void afficher();

};