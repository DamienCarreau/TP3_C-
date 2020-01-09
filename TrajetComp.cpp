/*************************************************************************
                   Classe TrajetComp : décrit un trajet composé
                             -------------------
    début                : 22/11/2019
    copyright            : (C) 2019 par J.HUE, D.CARREAU
    e-mail               : jerome.hue@insa-lyon.fr / damien.carreau@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TrajetComp> (fichier TrajetComp.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetComp.h"
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
	void TrajetComp::afficher()
	// Algorithme :
	//--- Parcourt le tableau de sous trajets et appelle leurs méthodes afficher()
	{
		cout << "Trajet composé | De " << villeDepart << " à " << villeArr << " en " << nbTrajets << " trajet(s) : " << endl;
		for (int i =0; i<nbTrajets; i++)
		{
			cout << i+1 << " : ";
			sousTrajets[i]->afficher();
		}
	}//--- fin de afficher

	void TrajetComp::sauvegarde(ofstream & flux)
	{
		if(nbTrajets > 0){
			sousTrajets[0]->sauvegarde(flux);
			for(int i = 1; i < nbTrajets; i++){
				flux << ";";
				sousTrajets[i]->sauvegarde(flux);
			}
		}
	}	

	void TrajetComp::addTrajet(Trajet* tr)
	//Algorithme :
	//--- Vérifie si le départ du trajet en paramètre est identique
	//à l'arrivée du dernier des sous-trajets
	//--- Ajoute le trajet si c'est le cas
	{
		if (strcmp(tr->getDep(), villeArr)==0 || nbTrajets==0)
		{
		//cout << "ajout d'un trajet à l'indice " << nbTrajets << endl;
			sousTrajets[nbTrajets] = tr;
			//villeDepart = sousTrajets[0]->getDep();
			//villeArr = tr->getArr();
			strcpy(villeDepart, sousTrajets[0]->getDep());
			strcpy(villeArr, tr->getArr());
			strcpy(type, "comp");
			++nbTrajets;
		}
		else
		{
			cout << "Ajout invalide, les villes ne correspondent pas : "<< nbTrajets << endl;
		}
	}//------ fin de addTrajet

	void TrajetComp::creerTrajetComp(int nb)
	//Algorithme :
	//Répète nb fois :
	//- Lis le choix donnée en entrée
	//- Appelle la méthode de création de trajet correspondante
	//- Ajoute le nouveau trajet dans le tableau (de pointeurs) de sous-trajets

	{

		for(int i=0; i<nb; i++)
		{
			cout << "Créer un trajet simple (1) ou un trajet composé (2) : " <<endl;
			char choix= '0';
			while(choix!= '1' && choix != '2'){
			cin >> choix;
				if(choix!='1' && choix!='2')
				{
					cout << "Choix Invalide ! " << endl;
				}
			}
			if(choix == '1')
			{
				Trajet* T = creerTrajetSimple();
				addTrajet(T);
				this->afficher();
			}
			else if (choix =='2')
			{
				cout << "De combien de trajets est composé ce trajet ?" << endl;
				int n;
				cin >> n;
				this->creerTrajetComp(n);

			}

		}

	}//------fin de creerTrajetComp


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

TrajetComp::TrajetComp()
{

	#ifdef MAP
    	cout << "Appel au constructeur sans arguments  de <TrajetComp>" << endl;
	#endif
	Trajet();
	sousTrajets = new Trajet*[50];
	nbTrajets = 0;
	return;
} //Fin du constructeur par défaut sans paramètre

TrajetComp::TrajetComp (const char* s1,const  char* s2, Trajet** mt ):Trajet(s1, s2,"comp")
{
    #ifdef MAP
    cout << "Appel au constructeur de <TrajetComp>" << endl;
    #endif
	sousTrajets = new Trajet*[50];
	sousTrajets = mt;


} //----- Fin de TrajetComp (constructeur par défaut avec paramètres)


TrajetComp::~TrajetComp( )
{
    #ifdef MAP
    		cout << "Appel au destructeur de <TrajetComp>" << endl;
	#endif
	for(int i=0; i<nbTrajets; i++)
	{
		delete sousTrajets[i];
	}
	delete [] sousTrajets;


} //----- Fin de ~TrajetComp, destructeur de TrajetComp

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
