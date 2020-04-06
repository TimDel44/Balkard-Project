#include "joueur.h"
#include "personnage.h"
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

joueur::joueur(personnage* perso) {
	this->actif = 1;
	this->persoVivant = 1;
	this->perso = perso;
	this->argent = 0;
}

void joueur::afficherJoueur() {
	cout << this->perso->personnage::getNom() << endl;
}