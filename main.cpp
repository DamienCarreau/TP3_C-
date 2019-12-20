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
	for(;;)
	{
		cout<< "Bonjour, que voulez vous faire : \n     (1) Créer un trajet\n     (2) Afficher le catalogue\n     (3) Chercher un trajet\n     (4) Chargement d'un catalogue\n     (5) Sauvegarde du Catalogue\n     (6) Quitter" << endl;
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
		else if(choix == '4')
		{
			string name;
			cout << "Entrez votre nom de fichier" << endl;
			cin >> name;
			cout << "Appel du chargement"<< endl;
		}
		else if(choix == '5')
		{
			string name;
			cout << "Entrer votre nom de fichier" << endl;
			cin >> name;
			cout << "Appel de la sauvegarde" <<endl;
		}
		else if(choix == '6')
		{	
			break;
		}
	
	}
	cout << "Au revoir !" << endl;
}
