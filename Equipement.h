#pragma once
#ifndef DEF_EQUIPEMENT
#define DEF_EQUIPEMENT


#include <iostream>
#include <string>
#include "Equipement.h""
class Equipement 
{
    public:
     Equipement();
     Equipement(std::string nom);


     void faireConsultation() const; // dans le menu des choix, faire inventaire, pour consultation sous forme de tableau//

    protected:
    int m_encombrement;
    std::string m_nom;
 
};

Equipement::Equipement() : m_encombrement(100), m_nom("Epée rouillée")
{

}
#endif