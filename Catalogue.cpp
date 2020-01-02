/*************************************************************************
                 Catalogue - Décrit un catalogue de trajets
                             -------------------
    début                : 29/11/2019
    copyright            : (C) 2019 par J.HUE, F.HACHIM
    e-mail               : jerome.hue@insa-lyon.fr / faouz.hachim@insa-lyon.fr
*************************************************************************/

//-- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//#define MAP

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <vector>
//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetComp.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

	void Catalogue::afficherCatalogue()
	{
		for (int i = 0 ; i < nbTrajets ; i++)
		{
			cout << "Trajet n° : " << i+1 << endl;
			listeTraj[i]->afficher();
			cout << endl;
		}

	}//---------Fin de afficherCatalogue

	void Catalogue::sauvegarde(const string name)
	{
		ofstream flux(name.c_str());
		if(flux)
		{
			for(int i = 0; i < nbTrajets; i++)
			{
				listeTraj[i]->sauvegarde(flux);
				flux << endl;
			}
		}
		else
		{
			cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
		}
	}


	void Catalogue::Chargement(const string name)
	{
		
 		ifstream monflux("testfile.txt");
		if(monflux) 
		{
			int nbTrajets=-1;
			while(!monflux.eof())
			{	
				
				string str;
				getline(monflux, str);
				vector<string> v; 
	  
				stringstream ss(str); 
	  
				while (ss.good()) 
				{ 
					string substr; 
					getline(ss, substr, ';'); 
					v.push_back(substr); 
				} 
	  

				if(v[0] != "")
				{

					//cout << "Trajet n°" << ++nbTrajets<<endl; 		
					//for (size_t i = 0; i < v.size(); i++) 
					//	cout <<  "v[" << i<< "]:"<<  v[i] << endl;
						
				if(v.size()==3)
				{
				char* dep = new char[130];
				char* arr = new char[130];
				char* mt  = new char[130];
				strcpy(dep, v[0].c_str());
				strcpy(arr, v[1].c_str());
				strcpy(mt, v[2].c_str());
				TrajetSimple* t  = new TrajetSimple(dep, arr, mt);
				addTrajet(t);
				cout << "Trajet Inséré" << endl;
				delete [] dep;
				delete [] arr;
				delete [] mt;
				}
				else if (v.size()>3)
				{
					TrajetComp* TC = new TrajetComp();
					for(int i = 0; i<v.size()/3; i++)
					{
							
						char* dep = new char[130];
						char* arr = new char[130];
						char* mt  = new char[130];
						strcpy(dep, v[0+3*i].c_str());
						strcpy(arr, v[1+3*i].c_str());
						strcpy(mt, v[2+3*i].c_str());
						TrajetSimple* t  = new TrajetSimple(dep, arr, mt);
						TC->addTrajet(t);	
					}
					addTrajet(TC);
					cout << "Trajet Inséré" << endl;
				}
				}

			}
				
		} 
		else 
		{	
			cout << "ERREUR: Impossible d'ouvrir le fichier." <<endl;
		}	
		monflux.close();

	}

	
	void Catalogue::Chargement_type(const string name, int type)
	{
		
 		ifstream monflux("testfile.txt");
		if(monflux)
		{	
			int nbTrajets=-1;	
			while(!monflux.eof())
			{	
				string str;
				getline(monflux, str);
				vector<string> v; 
				stringstream ss(str); 
	  
				while (ss.good()) { 
					string substr; 
					getline(ss, substr, ';'); 
					v.push_back(substr); 
				} 
	  
				//cout << "Taile : " << v.size() << endl;

				if(v[0] != "")
				{

					//cout << "Trajet n°" << ++nbTrajets<<endl; 		
					//for (size_t i = 0; i < v.size(); i++) 
					//cout <<  "v[" << i<< "]:"<<  v[i] << endl;
						
				if(v.size()==3 && type==1)
				{
				char* dep = new char[130];
				char* arr = new char[130];
				char* mt  = new char[130];
				strcpy(dep, v[0].c_str());
				strcpy(arr, v[1].c_str());
				strcpy(mt, v[2].c_str());
				TrajetSimple* t  = new TrajetSimple(dep, arr, mt);
				addTrajet(t);
				cout << "Trajet Inséré" << endl;
				//+ Deletes
				}
				else if (v.size()>3 && type==2)
				{
					TrajetComp* TC = new TrajetComp();
					for(int i = 0; i<v.size()/3; i++)
					{
							
						char* dep = new char[130];
						char* arr = new char[130];
						char* mt  = new char[130];
						strcpy(dep, v[0+3*i].c_str());
						strcpy(arr, v[1+3*i].c_str());
						strcpy(mt, v[2+3*i].c_str());
						TrajetSimple* t  = new TrajetSimple(dep, arr, mt);
						TC->addTrajet(t);	
					}
					addTrajet(TC);
					cout << "Trajet Inséré" << endl;
				}
				}
			}	
		}
		else
		{
			cout << "ERREUR: Impossible d'ouvrir le fichier." <<endl;
		}
		monflux.close();
	}

		
	void Catalogue::Chargement_intervalle(const string name, int x, int y)
	{
		
 		ifstream monflux("testfile.txt");
		if(monflux)
		{	
			int nbTrajets=0;	
			while(!monflux.eof())
			{	
				string str;
				getline(monflux, str);
				vector<string> v; 
				stringstream ss(str); 
	  
				while (ss.good()) { 
					string substr; 
					getline(ss, substr, ';'); 
					v.push_back(substr); 
				} 
	  

				if(v[0] != "")
				{
					++nbTrajets;
					//cout << "Trajet n°" << nbTrajets<<endl; 		
					//for (size_t i = 0; i < v.size(); i++) 
					//cout <<  "v[" << i<< "]:"<<  v[i] << endl;
						
				if(v.size()==3 && nbTrajets >= x && nbTrajets <= y)
				{
				char* dep = new char[130];
				char* arr = new char[130];
				char* mt  = new char[130];
				strcpy(dep, v[0].c_str());
				strcpy(arr, v[1].c_str());
				strcpy(mt, v[2].c_str());
				TrajetSimple* t  = new TrajetSimple(dep, arr, mt);
				addTrajet(t);
				cout << "Trajet Inséré" << endl;
				//+ Deletes
				}
				else if (v.size()>3 && nbTrajets >= x && nbTrajets <= y)
				{
					TrajetComp* TC = new TrajetComp();
					for(int i = 0; i<v.size()/3; i++)
					{
							
						char* dep = new char[130];
						char* arr = new char[130];
						char* mt  = new char[130];
						strcpy(dep, v[0+3*i].c_str());
						strcpy(arr, v[1+3*i].c_str());
						strcpy(mt, v[2+3*i].c_str());
						TrajetSimple* t  = new TrajetSimple(dep, arr, mt);
						TC->addTrajet(t);	
					}
					addTrajet(TC);
					cout << "Trajet Inséré" << endl;
				}
				}
			}	
		}
		else
		{
			cout << "ERREUR: Impossible d'ouvrir le fichier." <<endl;
		}
		monflux.close();
	}


	void Catalogue::sauvegarde_type(const string name, int type)
	{
		
		ofstream flux(name.c_str());
		if(flux)
		{
			for(int i = 0; i < nbTrajets; i++)
			{
				if(type == 1 && strcmp(listeTraj[i]->getType(),"simple") == 0)
				{
					listeTraj[i]->sauvegarde(flux);
					flux << endl;
				}
				else if (type == 2 && strcmp(listeTraj[i]->getType(),"comp") == 0)
				{
					listeTraj[i]->sauvegarde(flux);
					flux << endl;
				}
			}
			cout << "Catalogue sauvegardé" << endl;
		}
		else
		{
			cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
		}
	}

	void Catalogue::sauvegarde_ville(const string name, const char* ville,const int type)
	{
		ofstream flux(name.c_str());
		if(flux)
		{
			for(int i = 0; i <nbTrajets; i++)
			{
				if(type == 1 && strcmp(listeTraj[i]->getDep(),ville) == 0){
					listeTraj[i]->sauvegarde(flux);
					flux << endl;
				}else if(type == 2 && strcmp(listeTraj[i]->getArr(),ville) == 0){
					listeTraj[i]->sauvegarde(flux);
					flux << endl;
				}
			}
			cout << "Catalogue sauvegardé" << endl;
		}
		else
		{
			cout << "ERREUR: Impossible d'ouvrir le fichier." <<endl;
		}
	}
		
	void Catalogue::Chargement_ville(const string name, const char* ville, const int type)
	{
		
		ifstream monflux("testfile.txt");
		if(monflux)
		{
			int nbTrajets=-1;
			
			while(!monflux.eof())
			{	
				string str;
				getline(monflux, str);
				vector<string> v; 
				stringstream ss(str); 
	  
				while (ss.good()) { 
					string substr; 
					getline(ss, substr, ';'); 
					v.push_back(substr); 
				} 
	  

				if(v[0] != "")
				{

					//cout << "Trajet n°" << ++nbTrajets<<endl; 		
					//for (size_t i = 0; i < v.size(); i++) 
					//cout <<  "v[" << i<< "]:"<<  v[i] << endl;
						
				if(v.size()==3 && strcmp(v[type-1].c_str(),ville)==0 )
				{
				char* dep = new char[130];
				char* arr = new char[130];
				char* mt  = new char[130];
				strcpy(dep, v[0].c_str());
				strcpy(arr, v[1].c_str());
				strcpy(mt, v[2].c_str());
				TrajetSimple* t  = new TrajetSimple(dep, arr, mt);
				addTrajet(t);
				cout << "Trajet Inséré" << endl;	
				delete [] dep;
				delete [] arr;
				delete [] mt;
				}
				else if (v.size()>3 && ( (strcmp(v[0].c_str(),ville)==0 && type==1) || (strcmp(v[v.size()-2].c_str(), ville)==0 && type==2) ) )
				{
					TrajetComp* TC = new TrajetComp();
					for(int i = 0; i<v.size()/3; i++)
					{
							
						char* dep = new char[130];
						char* arr = new char[130];
						char* mt  = new char[130];
						strcpy(dep, v[0+3*i].c_str());
						strcpy(arr, v[1+3*i].c_str());
						strcpy(mt, v[2+3*i].c_str());
						TrajetSimple* t  = new TrajetSimple(dep, arr, mt);
						TC->addTrajet(t);	
					}
					
					addTrajet(TC);
					cout << "Trajet Inséré" << endl;
				}

				}
					
			}
		} 
		else 
		{
			cout << "ERREUR: Impossible d'ouvrir le fichier." <<endl;	
		}	
	}




	void Catalogue::addTrajet(Trajet* t)
	//Algorithme :
	//-Vérifie si le tableau est plein, si c'est le cas, on double la taille du tableau
	//-Ajoute le trajet en paramètre à la fin du tableau
	{

		//Doublement du tableau si celui-ci est rempli
		if(nbTrajets == size)
		{

			#ifdef MAP
				cout << "Duplication de la taille du tableau" << endl;
			#endif

			Trajet** mem = new Trajet*[size*2];
			for(int i=0; i<size; i++)
			{
				mem[i]=listeTraj[i];
			}


			delete [] (listeTraj);
			listeTraj = new Trajet*[size*2];
			for(int i=0; i<size;i++)
			{
				Trajet* t  = mem[i];
				listeTraj[i] = t;
			}
			delete[] mem;
			size = size*2;
		}
		listeTraj[nbTrajets] = t;
		++nbTrajets;
	}//---------Fin de addTrajet


	void Catalogue::creerTrajet()
	// Algorithme :
	//-Lis en entrée saisie
	//-Appelle la méthode création trajet qu'il faut en fonction du choix
	//-Ajoute le trajet créé à la fin de listeTraj
	{

		cout << "Création d'un trajet simple (1) ou composé (2)" << endl;
		char rep = '0';

		while(rep!= '1' && rep != '2')
		{
			cin >> rep;
			if(rep!='1' && rep!='2')
			{
				cout << "Choix Invalide ! " << endl;
			}
		}

		if(rep == '1')
		{
			Trajet* t = creerTrajetSimple();
			this->addTrajet(t);
		}
		else if (rep == '2')
		{

			cout << "Création d'un trajet composé : " << endl;
			cout << "Entrez le nombre de trajet;" << endl;
			int nb;
			cin >> nb;
			TrajetComp*  T = new TrajetComp;
			T->creerTrajetComp(nb);
			this->addTrajet(T);

		}
		else
		{
			cout << "Réponse invalide" << endl;
		}

	}//----------Fin de creerTrajet


	void Catalogue::rechercherTrajet( char* dep, char* arr)
	//Algorithme :
	//- Initialise un catalogue chemin
	//- Initialise un tableau de chaines de caractères explore qui contient les noms des villes déjà traitées
	//- Appelle la fonction explorer
	{
		Catalogue* chemin = new Catalogue;
		char** explore = new char*[50];
		explorer(this, dep, chemin, arr, explore, 0);
	        delete []explore;
		delete chemin;
	}//------------Fin de rechercherTrajet

	void explorer(Catalogue* C, char* ville, Catalogue* chemin, char* arr, char** explore, int nb)
	//  Parcoursen profondeur : Explore tous les chemins possibles de manière récursive.
	// Pour chaque sommet, il marque le sommet actuel et
	// prend le premier voisin jusqu'à ce que tous les voisins soient marqués.
	{
		int nbTrajets = C->getNbTrajets();
		Trajet** listeTraj = C->getListeTraj();


		explore[nb] = ville;++nb;

		for(int i =0; i<nbTrajets; i++)
		{
			chemin->addTrajet(listeTraj[i]);
			if( strcmp(listeTraj[i]->getArr(), arr)==0 && strcmp(ville, listeTraj[i]->getDep())==0)
			{
				cout << "------ Trajet possible ------" << endl;
				chemin->afficherCatalogue();
				cout << endl;
			}
			else if (strcmp(ville, listeTraj[i]->getDep())==0)
			{
				int e=0;
				for(int j=0; j<nb; j++)
				{
					if(strcmp(explore[j], listeTraj[i]->getArr())==0)
					{
						++e;
					}
				}
				if(e==0)
				{

					explorer(C, (char *) listeTraj[i]->getArr(), chemin, arr, explore, nb);
				}
			}


			chemin->setNull();
			chemin->setNbTrahets();
		}
	}//------------------Fin de explorer



//------------------------------------------------- Surcharge d'opérateurs

//Surchage d'opérateur, plus utilisée car remplacée par une méthod affichée
/*
ostream & operator << (ostream & out , const Catalogue & unCatalogue)
{
	int nbTrajets = unCatalogue.nbTrajets;
	cout << "Affichage du Catalogue" << endl;
	for(int i=0; i<nbTrajets; ++i)
	{
		cout << "Trajet n°" << i << endl;
		Trajet t  = *(unCatalogue.getListeTraj()[i]);
		t.afficher();
		cout << "\n";
	}
	return out;
}
*/
//-------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue ( const Catalogue & unCatalogue )
	{
	    #ifdef MAP
    			cout << "Appel au constructeur de copie de <Catalogue>" << endl;
		#endif
		size = unCatalogue.getSize();
		nbTrajets = unCatalogue.getNbTrajets();
		listeTraj = new Trajet*[size];
		for(int i = 0; i < nbTrajets; i=i+1)
		{
			listeTraj[i] = unCatalogue.getListeTraj()[i];
		}
	} //----- Fin de Catalogue (constructeur de copie)


Catalogue::Catalogue ()
{
    #ifdef MAP
    cout << "Appel au constructeur par défaut de <Catalogue>" << endl;
    #endif
	size = 2;
	listeTraj = new Trajet*[size];
	nbTrajets = 0;
} //----- Fin de Catalaogue (constructeur sans paramètre)


Catalogue::~Catalogue ( )

{
    #ifdef MAP
    		cout << "Appel au destructeur de <Catalogue>" << endl;
	#endif
	for(int i =0; i<nbTrajets; i++)
	{
			delete (listeTraj[i]);
	}
	delete [] (listeTraj);
} //----- Fin de ~Catalogue
