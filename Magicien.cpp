#include "Magicien.h"
#include "BatonSort.h"
#include <string>
#include <iostream>


using namespace std;

Magicien::Magicien(int vie, int bouclier, int mana, BatonSort baton) : 
	m_vie{ vie }, m_bouclier{ bouclier }, m_mana{mana}, m_baton{baton} {}

bool Magicien::verifierEnVie()
{
	if (m_vie <= 0)
	{
		return false;
	}

	return true;
}



void Magicien::changerBaton()
{
	m_baton.choisiSortAttaque();
	m_baton.choisiSortDefense();
	m_mana = 50;
}

int Magicien::afficherMana()
{
	return m_mana;
}

int Magicien::afficherVie()
{
	return m_vie;
}

void Magicien::ajouterVie()
{
	m_vie += m_baton.afficherGain();
}

void Magicien::ajouterBouclier()
{
	m_bouclier += m_baton.afficherGain();
}

void Magicien::mettreVieMax()
{
	m_vie = 100;
}

void Magicien::mettreBouclierMax()
{
	m_bouclier = 50;
}

int Magicien::afficherBouclier()
{
	return m_bouclier;
}

void Magicien::soustraireMana()
{
	m_mana - 10;
}

void Magicien::soustraireVie()
{
	m_vie -= m_baton.afficherAttaque();
}

void Magicien::soustraireSurplusVie()
{
	int surplus;

	surplus = m_bouclier -= m_baton.afficherAttaque();
	if (surplus < 0)
	{
		surplus = surplus * -surplus - surplus;

		m_vie -= surplus;
	}
}



