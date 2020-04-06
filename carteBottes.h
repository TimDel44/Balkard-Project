#pragma once
#include <iostream>
class carteBottes
{
private:
    int alteration;
    int statistique;

public:

    int getAlteration() { return this->alteration; }
    int getStatistique() { return this->statistique; }
    void setAlteration(int alteration) { this->alteration = alteration; }
    void setStatistique(int statistique) { this->statistique = statistique; }

    carteBottes(int alteration, int statistique);

};
