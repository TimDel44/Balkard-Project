#include <iostream>
#include "cartePotion.h"
#include "carte.h"
#include <string>
using namespace std;

cartePotion::cartePotion(string nom, int a, int s):carte(nom), alteration(a), statistique(s)
{
	/*carte(nom);
	this->alteration = alteration;
	this->statistique = statistique;
	*/
}