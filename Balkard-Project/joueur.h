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
	int possedeSort;
	int possedeRituel;
	int possedeItem;
	vector<carte*> main;
  
public:

	int getActif() { return this->actif; }
	int getPersoVivant() { return this->persoVivant; }
	int getArgent() { return this->argent; }
	int getPossedeSort() { return this->possedeSort; }
	int getPossedeRituel() { return this->possedeRituel; }
	int getPossedeItem() { return this->possedeSort; }

	void setArgent() { this->argent = argent; }
	void setActif() { this->actif = actif; }
	void setPersoVivant() { this->persoVivant = persoVivant; }
	void setPersonnage(personnage* perso) { this->perso = perso; }
	void setPossedeSort() { this->possedeSort = possedeSort; }
	void setPossedeRituel() { this->possedeRituel = possedeRituel; }
	void setPossedeItem() { this->possedeItem = possedeItem; }

	joueur(personnage* perso);
	void afficherJoueur();
	void joueurCombat(joueur* cible);
	void attaquer(joueur*);
	void subir(int degats);
	int jetInitierCombat();
	void initierCombat(joueur*);

	void clear();
	void finDeCombat(joueur*);
	void debutDeCombat(joueur*);


	void choisirCarte();
	void afficherMain();

};
