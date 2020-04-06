#pragma once
#include <iostream>
#include "carte.h"
#include <string>
using namespace std;


class carteElixir : public carte
{
private:
    int alteration;
    int statistique;
public:

    carteElixir(string nom, int a, int s);
    int getAlteration() { return this->alteration; }
    int getStatistique() { return this->statistique; }
    void setAlteration(int a) { this->alteration = a; }
    void setStatistique(int s) { this->statistique = s; }
    virtual void afficher();

};
