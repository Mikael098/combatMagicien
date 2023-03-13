#pragma once

#include "BatonSort.h"
#include <string>

using namespace std;

class Magicien
{
private:
	int m_vie{};
	int m_bouclier{};
	int m_mana{};
	BatonSort m_baton;

public:
	// Constructeur
	Magicien(int vie, int bouclier, int mana, BatonSort baton);

	//Vérifie s'il reste des points de vie
	bool verifierEnVie();

	//Permet de remplir le mana et de choisir aléatoirement un neauveau sort de chaque type
	void changerBaton();

	//Permet d'afficher le mana 
	int afficherMana();

	//Permet d'afficher la vie du magicien
	int afficherVie();

	//Permet d'ajouter de la vie au magicien
	void ajouterVie();

	//Permet d'ajouter du bouclier au magicien
	void ajouterBouclier();

	//Permet de mettre la vie au maximum au magicien
	void mettreVieMax();

	//Permet de mettre le bouclier au maximum
	void mettreBouclierMax();

	//Permet d'afficher le bouclier du magicien
	int afficherBouclier();

	//Permet de soustraire du manan au magicien
	void soustraireMana();

	//Permet de soustraire le surplus de vie du magicien
	void soustraireSurplusVie();

	//Permet de soustraire de la vie au magicien
	void soustraireVie();
};