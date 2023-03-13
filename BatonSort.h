#pragma once
#include<string>


class BatonSort
{
private:
	std::string m_nom;
	std::string m_sortDefense{};
	std::string m_sortAttaque{};
	int m_attaque{};
	int m_gain{};


public:
	//constructeur
	BatonSort(std::string nom, std::string sortDefense, std::string sortAttaque, int attaque, int gain);

	//Permet de choisir aléatoirement le sort de défense
	std::string choisiSortDefense();

	//Permet de choisir aléatoirement le sort d'attaque
	std::string choisiSortAttaque();

	//Permet de retourner un string qui est le nom du baton
	std::string lierNomSort(std::string, std::string);

	//Permet de retourner l'attaque qu'effectue le baton
	int afficherAttaque();

	//Permet de retourner le gain qu'apporte le baton
	int afficherGain();

	//Permet de retourner le sort de défense du baton
	std::string afficherSortDefense();

	//Permet de retourner le sort d'attaque du baton
	std::string afficherSortAttaque();

	//Permet de retourner le nom du baton
	std::string afficherNomBaton();
	
};