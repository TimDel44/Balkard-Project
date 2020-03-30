#pragma once
#include <iostream>
#include <string>
using namespace std;

class carte
{
private:
	string nom;

public:
	string getNom() { return this->nom; }
	string setNom(std::string nom) { this->nom = nom; }

	nom(string nom);

	void afficher();
};

