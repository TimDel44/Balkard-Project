#include <iostream>
#include "carteArme.h"

using namespace std;

carteArme::carteArme(int alteration, int statistique) : m_nom("Fat Epee"), m_attaque(10) //voir code tim pour r�cup�ration stat//
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
	cout << "carteArme : " << m_nom << " (D�g�ts: " << m - degats << ")" << end1;
}

int carteArme::getDegats() const
{
	return m_degats;
}


int main() {
	Arme Ep�e("Ep�e rouill�e");
	ep�e.sePresenter();

	return 0;



}