#include <iostream>
#include <cstring>
#include <string>
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetComp.h"
#include "Catalogue.h"

#define MAP


using namespace std;
int main()
{
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
			int choice;
			cout << "     (1) Chargement total\n     (2) Chargement selon le type\n     (3) Chargement selon une ville\n";
			cin >> choice;
			if(choice == 1)
			{
				C.Chargement(name);
				cout << "Catalogue chargé" <<endl;
			}
			else if (choice == 2)
			{
				cout << "(1) Trajet Simple  (2) TrajetComposés" << endl;
				choice = 0;
				while(choice < 1 || choice > 2){
					cin >> choice;
				}
				C.Chargement_type(name,choice);
			}
			else if(choice == 3)
			{
				
				cout << "(1) Selon ville de départ  (2) Selon ville d'arrivée\n";
				choice = 0;
				while(choice > 2 || choice < 1){
					cin >> choice;
				}
				cout << "Entrez le nom de la ville\n";
				char * ville = new char[128];
				cin >> ville;
				C.Chargement_ville(name,ville,choice);
				
			}
			else
			{
				cout << "Erreur saisie\n";
			}
		}
		else if(choix == '5')
		{
			string name;
			cout << "Entrer votre nom de fichier" << endl;
			cin >> name;
			int choice;
			cout << "     (1) Sauvegarde totale\n     (2) Sauvegarde selon le type\n     (3) Sauvegarde selon une ville\n";
			cin >> choice;
			if(choice == 1)
			{
				C.sauvegarde(name);
				cout << "Catalogue sauvegardé" <<endl;
			}
			else if (choice == 2)
			{
				cout << "(1) Trajet Simple  (2) TrajetComposés" << endl;
				choice = 0;
				while(choice < 1 || choice > 2){
					cin >> choice;
				}
				C.sauvegarde_type(name,choice);
			}
			else if(choice == 3)
			{
				cout << "(1) Selon ville de départ  (2) Selon ville d'arrivée\n";
				choice = 0;
				while(choice > 2 || choice < 1){
					cin >> choice;
				}
				cout << "Entrez le nom de la ville\n";
				char * ville = new char[128];
				cin >> ville;
				C.sauvegarde_ville(name,ville,choice);
			}
			else
			{
				cout << "Erreur saisie\n";
			}
		}
		else if(choix == '6')
		{	
			break;
		}
	
	}
	cout << "Au revoir !" << endl;
}
