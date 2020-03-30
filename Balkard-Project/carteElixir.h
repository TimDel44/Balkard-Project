#pragma once
#include <iostream>
#include "carte.h"

class carteElixir : public carte
{
private:
    int alteration;
    int statistique;

public:

    int getAlteration() { return this->alteration; }
    int getStatistique() { return this->statistique; }
    void setAlteration(int alteration) { this->alteration = alteration; }
    void setStatistique(int statistique) { this->statistique = statistique; }

    carteElixir(int alteration, int statistique);
};
