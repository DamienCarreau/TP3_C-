/*************************************************************************
                    Classe Trajet  - Représente un trajet
                             -------------------
    début                : 22/11/2019
    copyright            : (C) 2019 par J.HUE, D.CARREAU
    e-mail               : jerome.hue@insa-lyon.fr / damien.carreau@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

#include <fstream>
using namespace std;
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
/*
Implémente la classe Trajet, dont hériterons les classes TrajetSimple et
TrajetComp
Elle possède deux attributs représentants une ville de départ et une ville
d'arrivée.
*/

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    	virtual void afficher();
	//Mode d'emploi :
	//Affiche un trajet en donnant sa ville de départ et celle d'arrivée
	//Virtual car Trajet est parent de TrajetSimple et TrajetComp
	
	virtual void sauvegarde(ofstream & flux);
//--------------------------------------------------Accesseurs et mutateurs

    	void setDepp(const char*  dep);
	//Mode d'emploi :
	//Change la ville de départ par dep

	void setArr(const char*  arr);
	//Mode d'emploi :
	//Change la ville d'arrivée par arr

	char* getArr();
	//Mode d'emploi :
	//Retourne la ville d'arrivée du trajet

	char* getDep();
	//Mode d'emploi :
	//Retourne la ville de départ du trajet
		
	char* getType();

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
	Trajet();
	//Mode d'emploi :
	//Construit un trajet en initialisant ses attributs à ""

	Trajet ( const Trajet & unTrajet );
	//Mode d'emploi (constructeur de copie) :
	//Construit un trajet en copiant les attributs du trajet en paramètre

	Trajet(const char* dep, const char* arr, const char* t);
	//Mode d'emploi :
	//Construit un trajet à l'aide de deux chaines de caractères

	virtual ~Trajet ( );
	//Mode d'emploi :
	//Détruit un trajet
//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	char* villeDepart;
	char* villeArr;
	char* type;
};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJET_H
