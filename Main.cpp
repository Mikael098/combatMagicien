#include <iostream>
#include <string>
#include "BatonSort.h"
#include "Magicien.h"

using namespace std;

int main()
{
    int quiCommence;
    int choixDebutManche{};
    int surplus;

    BatonSort baton{"","","",0,0};

    //Création baton joueur et joueur
    string sortDefense = baton.choisiSortDefense();
    string sortAttaque = baton.choisiSortAttaque();
    string sortLier = baton.lierNomSort( sortDefense, sortAttaque );
    BatonSort batonJoueur{ sortLier, sortDefense, sortAttaque, 20, 10 };
    Magicien magicienJoueur{ 50, 0, 50, batonJoueur };

    //Création baton robot et robot
    sortDefense = baton.choisiSortDefense();
    sortAttaque = baton.choisiSortAttaque();
    sortLier = baton.lierNomSort( sortDefense, sortAttaque );
    BatonSort batonRobot{ sortLier, sortDefense, sortAttaque, 10, 5 };
    Magicien magicienRobot{ 50, 0, 50, batonRobot };

    while (magicienJoueur.verifierEnVie()==true && magicienRobot.verifierEnVie()==true)
    {
        //srand(time(nullptr));
        //quiCommence = rand() % 2;
        //cout << quiCommence;
        quiCommence = 0;

        //si 0 le joueur commence, sinon c'est le robot
        if (quiCommence == 0)
        {
            cout << "\nVotre attaque est de: " << batonJoueur.afficherAttaque();
            cout << "\nVotre regain est de: " << batonJoueur.afficherGain();
            cout << "\nVotre sort d'attaque est : " << batonJoueur.afficherSortAttaque();
            cout << "\nVotre sort de défense est: " << batonJoueur.afficherSortDefense();
            cout << "\nVous commencer en premier";
            cout << "\nVous pouvez sois attaquer l'enemi avec votre sort d'attaque(1), ou vous pouvez changer de baton(2)";
            cin >> choixDebutManche;
            cin.clear();

            if (choixDebutManche == 1)
            {
                if (magicienJoueur.afficherMana() >= 10)
                {
                    if (batonJoueur.afficherSortAttaque() == "Incinérateur")
                    {
                        if (magicienRobot.afficherBouclier() == 0)
                        {
                            magicienRobot.soustraireVie();
                        }
                        else
                        {
                            magicienRobot.soustraireSurplusVie();
                        }
                    }
                    else
                    {
                        magicienRobot.soustraireVie();
                    }
                }
                else
                {
                    cout << "\nVous n'avez pas assez de mana";
                }
                magicienJoueur.soustraireMana();









                //defendre robot
                if (batonRobot.afficherSortDefense() == "Guérison")
                {
                    if (batonJoueur.afficherSortAttaque() == "Incinérateur")
                    {
                        if (magicienRobot.afficherVie() < 100)
                        {
                            magicienRobot.ajouterVie();
                        }
                        else
                        {
                            magicienRobot.mettreVieMax();
                        }
                    }
                }
                else
                {
                    if (batonJoueur.afficherSortAttaque() == "Foudre")
                    {
                        if (magicienRobot.afficherBouclier() < 50)
                        {
                            magicienRobot.ajouterBouclier();
                        }
                        else
                        {
                            magicienRobot.mettreBouclierMax();
                        }
                    }
                }
            }
            else if (choixDebutManche == 2)
            {
                magicienJoueur.changerBaton();
            }
        }
        else
        {
            if (magicienRobot.afficherMana() >= 10)
            {
                if (magicienRobot.afficherMana() >= 10)
                {
                    if (batonRobot.afficherSortAttaque() == "Incinérateur")
                    {
                        if (magicienJoueur.afficherBouclier() == 0)
                        {
                            magicienJoueur.soustraireVie();
                        }
                        else
                        {
                            magicienJoueur.soustraireSurplusVie();
                        }
                    }
                    else
                    {
                        magicienJoueur.soustraireVie();
                    }
                }
                else
                {
                    cout << "\nVous n'avez pas assez de mana";
                }
                magicienRobot.soustraireMana();


                //defendre joueur


                if (batonJoueur.afficherSortDefense() == "Guérison")
                {
                    if (batonRobot.afficherSortAttaque() == "Incinérateur")
                    {
                        if (magicienJoueur.afficherVie() < 100)
                        {
                            magicienJoueur.ajouterVie();
                        }
                        else
                        {
                            magicienJoueur.mettreVieMax();
                        }
                    }
                }
                else
                {
                    if (batonRobot.afficherSortAttaque() == "Foudre")
                    {
                        if (magicienJoueur.afficherBouclier() < 50)
                        {
                            magicienJoueur.ajouterBouclier();
                        }
                        else
                        {
                            magicienJoueur.mettreBouclierMax();
                        }
                    }
                }
            }
            else
            {
                magicienRobot.changerBaton();
            }
        }
        cout << "\nVotre vie est de: " << magicienJoueur.afficherVie();
        cout << "\nVotre bouclier est de: " << magicienJoueur.afficherBouclier();
        cout << "\nVotre mana est de: " << magicienJoueur.afficherMana();

        cout << "\nLa vie du robot est de: " << magicienRobot.afficherVie();
        cout << "\nLe bouclier du robot est de: " << magicienRobot.afficherBouclier();
        cout << "\nLe mana du bouclier est de: " << magicienRobot.afficherMana();
    }
}

