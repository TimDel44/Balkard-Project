#pragma once
#include <iostream>
class carteTalisman
{
private:
    int alteration;
    int statistique;
    int m_mana;
public:

    int getAlteration() { return this->alteration; }
    int getStatistique() { return this->statistique; }
    void setAlteration(int alteration) { this->alteration = alteration; }
    void setStatistique(int statistique) { this->statistique = statistique; }
    void ProtectionSorts() const;
    carteTalisman(int alteration, int statistique);

};
