#pragma once
#include <iostream>
#include "carte.h"

class cartePotion : public carte
{
private:
    int alteration;
    int statistique;

public:
   
    int getAlteration() { return this->alteration; }
    int getStatistique() { return this->statistique; }
    void setAlteration(int alteration) { this->alteration = alteration; }
    void setStatistique(int statistique) { this->statistique = statistique; }

    cartePotion(int alteration, int statistique);

};

