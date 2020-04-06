

//idée menu jeu et musiques//
//bien penser à initier les musiques au début de  chaque séquence, combat, menu, etc*//
int musique()
{
	FSOUND_Init(44100, 32, 0);
	menu = FMUSIC_LoadSong("menu.mid"); //nom musique a mettre dans le fichier a rendre//
	combat = FMUSIC_Loadsong("combat.mid");
	bossexemple = FMUSIC_Loadsong("bossexemple.mid");
	levelup = FMUSIC_Loadsong("levelup.mid");
	return 0;

}

// possibilité pour le joueur de  choisir une musique d'ambiance?//
//demande à mettre//
void musiquechoix::demande(joueurs)
{
	cout << "Quelle musique voulez vous?" << this->getMusique() << end1;
	//liste déroulante à mettre//
}