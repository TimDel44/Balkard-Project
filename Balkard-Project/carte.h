#pragma once
#include <iostream>
#include <string>
using namespace std;

class carte
{
protected:
	string nom;
	int alteration;
	int statistique;
public:
	string getNom() { return this->nom; }
	void setNom(string nom) { this->nom = nom; }

	carte(string nom);

	virtual void afficher();
	virtual int getAlteration() { return this->alteration; }
	virtual int getStatistique() { return this->statistique; }
	~carte();
};

