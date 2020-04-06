

void Equiement::SePresenter() const
{
	cout << "Vous avez l'équipement suivant" << m_nom << "." << end1;
	cout << "l'encombrement est de" << m_encombrement << "enconbrement." << end1;

}
void Equipement::boirePotionDeVie(int quantitéPotion) //mauvais endroit//
{
	m_vie += quantitéPotion;
	 
	if (m_vie > 100)
	{
		m_vie = 100;
	}
}
//modifier le changer arme//
void Equipement::changerEquipement(string nomNouvelEquipement, int stats nouvelEquipement)
{
	m_equipement.changer(nomNouvelEquipement, degatsNouvelEquipement);
}




int main()
{
	Equipement epee("Epée rouillée")
		epee.SePresenter();

	return 0;
}