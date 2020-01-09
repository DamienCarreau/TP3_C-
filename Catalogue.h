/**************************************************************************
                 Catalogue - décrit un catalogue de trajets
                             -------------------
    début                : 29/11/2019
    copyright            : (C) 2019 par J.HUE, D.CARREAU
    e-mail               : jerome.hue@insa-lyon.fr / damien.carreau@insa-lyon.fr
*************************************************************************/


//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

#include <iostream>
using namespace std;
//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "Catalogue.h"
//------------------------------------------------------------------------
/* Rôle de classe Catalogue :
Représente un catalogue de trajets :
- Possède un tableau dynamique de pointeurs de Trajets
- Possède deux attributs entier : 
	- nbTrajets qui indique le nombre de trajets dans le catalogue
	- siez qui indique la taille du Catalogue (du tableau dynamique de trajets)
- Possibilité de saisir de nouveaux trajets
- Possibilité d'afficher le catalogue
- Possibilité de rechercher un parcours : trouver à partir d'un départ et une
arrivée toutes les possibilités de trajets.	
*/
//-----------------------------------------------------------------------
class Catalogue  
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    
	void afficherCatalogue();
	//Mode d'emploi :
	//Affiche tous les trajets du catalogue

	void sauvegarde(const string name);
	//permet de sauvegarder totalement le catalogue actuel dans un fichier dont le nom est passé en paramètre

	void sauvegarde_type(const string name, int type);
	//permet de sauvegarder tout les trajets du type passé en paramètre du catalogue actuel 
	//dans un fichier dont le nom est passé en paramètre
	// type = 1 ==> trajets simples
	// type = 2 ==> trajets composés

	void sauvegarde_ville(const string name, const char* ville, const int type);
	//permet de sauvegarder les trajets du catalogue actuel dont le depart/arrivé est passé en paramètre
	//dans un fichier dont le nom est passé en paramètre
	//le paramètre type indique si la ville passé en paramètre concerne le depart ou l'arrivé
	
	void sauvegarde_intervalle(const string name, const int a, const int b);
	//permet de sauvegarder du trajet a au trajet b du catalogue actuel 
	//dans un fichier dont le nom est passé en paramètre
	//a et b étant des paramètres de la fonction
	
	void Chargement(const string name);
	
	void Chargement_type(const string name, int type);

	void Chargement_ville(const string name, const char* ville, const int type);
	
	void Chargement_intervalle(const string name, int x, int y);

	void creerTrajet();	
	//Mode d'emploi :
	//Permet de créer un trajet en entrant ces caractèristiques
	//puis de l'ajouter au Catalogue

	void addTrajet(Trajet* t);
	//Mode d'emploi : 
	//Ajoute le trajet en paramètre au Catalogue		


	void rechercherTrajet( char* dep,  char* arr);
	//Mode d'emploi :
	//Permet de rechercher des trajets avec deux chaines de caractères 
	//un départ et une arrivée

//--------------------------------------------------Acceseurs et mutateurs

	
	int getNbTrajets() const
	{
		return this->nbTrajets;
	}//Mode d'emploi : retourne le nombre de trajets dans le catalogue 
	

	int getSize() const
	{
		return this->size;
	}//Mode d'emploi : retourne la taille du Catalogue

	Trajet** getListeTraj() const
	{
		return this->listeTraj;
	}//Mode d'emploi : retourne la liste de trajet sous forme d'un tableau de pointeurs

	void setSize(int n)
	{
		this->size=n;
	}//Mode d'emploi : permet de modifier la taille du catalogue

	void setNull()
	{
		this->listeTraj[this->nbTrajets-1]=NULL;
	}//Mode d'emploi : Met à NULL le dernier trajet

	void setNbTrahets()
	{
		this->nbTrajets--;
	}//Mode d'emploi : permet de réduire le nombre de trajets (après un setNull par exemple)
		
//------------------------------------------------- Surcharge d'opérateurs
	
//	friend ostream & operator << ( ostream & out , const Catalogue & unCatalogue);


//-------------------------------------------- Constructeurs - destructeur
    
	Catalogue (const Catalogue & unCatalogue);
   	Catalogue();
    	virtual ~Catalogue ( );
    

protected:

//----------------------------------------------------- Attributs protégés
	
	Trajet** listeTraj; 	
	int nbTrajets;
	int size;


};

//-------------------------------- Autres définitions dépendantes de <Catalogue>


	void explorer(Catalogue* C,  char* ville, Catalogue*  chemin, char* arr, char** explore, int nb);
	//Mode d'emploi :
	//Explore le catalogue C en affichant les parcours possible pour aller de ville à arr
	//chemin est un catalogue qui sert à l'affichage des parcours
	//explore regroupe les villes déjà traitées
	//nb est le nombre de trajets dans chemin 

#endif // CATALOGUE_H
