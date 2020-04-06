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

using namespace std;

class personnage
{
private :
	string nom;
	int vie;
	int attaque;
	int defense;
	int perception;
	int initiative;
	int esquive;
	int pa;



public :
	string getNom() { return this->nom; }
	int getVie() { return this->vie; }
	int getAttaque() { return this->attaque; }
	int getDefense() { return this->defense; }
	int getPerception() { return this->perception; }
	int getInitiative() { return this->initiative; }
	int getEsquive() { return this->esquive; }
	int getPA() { return this->pa; }

	string setNom(string nom) { this->nom = nom; }
	void setVie(int vie) {this->vie = vie; }
	void setAttaque(int attaque) {this->attaque = attaque; }
	void setDefense(int defense) {this->defense = defense; }
	void setPerception(int perception) {this->perception = perception; }
	void setInitiative(int initiative) {this->initiative = initiative; }
	void setEsquive(int esquive) {this->esquive = esquive; }
	void setPA(int pa) {this->pa = pa; }

	personnage(string nom);
	void afficher();
	//void attaquer(joueur*);
	//void subir(int degats);
	//int jetInitierCombat();
	//void initierCombat(joueur*);
	//void combat(joueur*);
};

