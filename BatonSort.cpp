#include "BatonSort.h"
#include <string>
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

BatonSort::BatonSort(std::string nom, std::string sortDefense, std::string sortAttaque, int attaque, int gain) : 
	m_nom{nom}, m_sortDefense{sortDefense}, m_sortAttaque{sortAttaque}, m_attaque{attaque}, m_gain{gain} {}

string BatonSort::choisiSortDefense()
{
	int aleatoire{};

	srand(time(nullptr));
	aleatoire = rand() % 2;

	if (aleatoire == 0)
	{
		m_sortDefense = "Gu\x82rison";
	}
	else
	{
		m_sortDefense = "Protection";
	}
	return m_sortDefense;
}

string BatonSort::choisiSortAttaque()
{
	int aleatoire{};

	srand(time(nullptr));
	aleatoire = rand() % 2;

	if (aleatoire == 0)
	{
		m_sortAttaque = "Inc\x82nirateur";
	}
	else
	{
		m_sortAttaque = "Foudre";
	}

	return m_sortAttaque;
}

string BatonSort::lierNomSort(std::string sortDefense, std::string sortAttaque)
{
	m_nom = sortAttaque+"de"+sortDefense;

	return m_nom;
}

int BatonSort::afficherAttaque()
{	
	return m_attaque;
}

int BatonSort::afficherGain()
{
	return m_gain;
}

string BatonSort::afficherSortDefense()
{
	return m_sortDefense;
}

string BatonSort::afficherSortAttaque()
{
	return m_sortAttaque;
}

string BatonSort::afficherNomBaton()
{
	return m_nom;
}






