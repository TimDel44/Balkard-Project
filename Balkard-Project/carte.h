#pragma once
#include <iostream>
#include <string>
using namespace std;

class carte
{
protected:
	string nom;

public:
	string getNom() { return this->nom; }
	string setNom(std::string nom) { this->nom = nom; }

	carte(string nom);

	virtual void afficher();
	virtual ~carte();
};

