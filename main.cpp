#include <iostream>
#include <cstring>
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetComp.h"
#include "Catalogue.h"

#define MAP


using namespace std;
int main()
{
	/*
	//Création d'un trajet
	Trajet t1;
	t1.setDepp("Lyon");
	t1.setArr("Paris");
	t1.afficher();
	

	TrajetSimple t2 = TrajetSimple("Rennes", "Ville2", "Trail");
	 

	//Création d'un trajet simple
	TrajetSimple TS1;
	TS1.setDepp("Besançon");
	TS1.setArr("Pau");
	TS1.setMoyenT("Voiture");
	TS1.afficher();

	//Création d'un trajet Composé
	TrajetComp TC1;
	TrajetSimple t5 = creerTrajetSimple();
	TrajetSimple t6 = creerTrajetSimple();
	TC1.addTrajet(t5);
	TC1.addTrajet(t6);
	*/

	//Création du catalogue
	Catalogue C;
	while(1)
	{
		cout<< "Bonjour, que voulez vous faire : (1) Créer un trajet (2) Afficher le catalogue (3) Chercher un trajet (4) Quitter" << endl;
		char choix= '0';
		cin >> choix;
		if(choix =='1')
		{
			C.creerTrajet();
		}
		else if(choix == '2')
		{
			C.afficherCatalogue();
		}

		else if(choix == '3')
		{
			char* a = new char[128];
			char* b = new char[128];
			cout << "Recherche | Entrez une ville de départ  " << endl;
			cin >> a;
			cout << "Entrez une ville d'arrivée : " << endl;
			cin >> b;

			C.rechercherTrajet(a,b);
			delete []a;
			delete []b;
		}
		else
		{
		/*	for(int i =0; i<C.getNbTrajets(); i++)
			{
				delete (C.getListeTraj()[i]);
			}
		*/
				
			break;
		}
	
	}
	cout << "Au revoir !" << endl;
}
