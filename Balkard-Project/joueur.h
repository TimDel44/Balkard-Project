#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#ifdef _WIN32
#include <windows.h>
#endif
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
#include <ctime>
#include "personnage.h"
#include "Deck.h"
using namespace std;

class joueur
{
private:

	int actif;
	int persoVivant;
	personnage* perso;
	int argent;
	vector<carte*> main;
	
public:

	int getActif() { return this->actif; }
	int getPersoVivant() { return this->persoVivant; }
	int getArgent() { return this->argent; }

	int setArgent() { this->argent = argent; }
	int setActif() { this->actif = actif; }
	int setPersoVivant() { this->persoVivant = persoVivant; }
	int setPersonnage(personnage* perso) { this->perso = perso; }

	joueur(personnage* perso);
	void afficherJoueur();
	void joueurCombat(joueur* cible);
	void attaquer(joueur*);
	void subir(int degats);
	int jetInitierCombat();
	void initierCombat(joueur*);

	void choisirCarte();
	void afficherMain();
};
