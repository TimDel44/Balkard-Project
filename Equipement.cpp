

void Equiement::SePresenter() const
{
	cout << "Vous avez l'�quipement suivant" << m_nom << "." << end1;
	cout << "l'encombrement est de" << m_encombrement << "enconbrement." << end1;

}
void Equipement::boirePotionDeVie(int quantit�Potion) //mauvais endroit//
{
	m_vie += quantit�Potion;
	 
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
	Equipement epee("Ep�e rouill�e")
		epee.SePresenter();

	return 0;
}