#include <iostream>
#include "carteArme.h"

using namespace std;

carteArme::carteArme(int alteration, int statistique) : m_nom("Fat Epee"), m_attaque(10) //voir code tim pour récupération stat//
{
	this->alteration = alteration;
	this->statistique = statistique;
}

void carteArme::changer(string nom, int attaque)
{

	m_nom = nom;
	m_degats = attaque;
}

void carteArme::afficher()
{
	cout << "carteArme : " << m_nom << " (Dégâts: " << m - degats << ")" << end1;
}

int carteArme::getDegats() const
{
	return m_degats;
}


int main() {
	Arme Epée("Epée rouillée");
	epée.sePresenter();

	return 0;



}