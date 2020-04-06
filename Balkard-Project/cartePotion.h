#pragma once
#include <iostream>
#include "carte.h"
#include <string>
using namespace std;

class cartePotion : public carte
{
private:
    int alteration;
    int statistique;

public:
   
   /* int getAlteration() { return this->alteration; }
    int getStatistique() { return this->statistique; }
    void setAlteration(int alteration) { this->alteration = alteration; }
    void setStatistique(int statistique) { this->statistique = statistique; }
    */
    cartePotion(string nom, int a, int s);

};

