#pragma once
#ifndef DEF_ARME
#define DEF_ARME
#endif // !DEF_ARME

#include <iostream>
#include <string>
#include "Equipement.h"" 
class carteArme : public Equipement
{
private:
    int alteration;
    int statistique;
 
    // constructeur général équipement, penser à récupérer noms et encombrement??//
public:''

    int getAlteration() { return this->alteration; }
    int getStatistique() { return this->statistique; }
    void setAlteration(int alteration) { this->alteration = alteration; }
    void setStatistique(int statistique) { this->statistique = statistique; }
    void afficher();
    void changer(std::string nom, int degats);
    carteArme(int alteration, int statistique);
    carteArme(std::string nom, int degats)
};

#endif