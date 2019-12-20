/*************************************************************************
                  TrajetSimple  - décrit un trajet simple
                             -------------------
    début                : 22/11/2019
    copyright            : (C) 2019 par J.HUE, F.HACHIM
    e-mail               : jerome.hue@insa-lyon.fr / faouz.hachim@insa-lyon.fr
*************************************************************************/

//--- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------
#if ! defined (TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H
//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h" 
#include<iostream>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
// Représente un trajt simple (un départ, une arrivée, en une fois)
// Hérite de la classe Trajet et possède en plus un moyen de transport
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques


	void afficher();
	//Mode d'emploi :
	//Affiche un trajet simple en donnant sa ville de départ
	//sa ville d'arrivée et son moyen de transport
	
	void sauvegarde(ofstream & flux);

	void setMoyenT(const char* mt);
	//Mode d'emploi :
	//Change le moyen de transport par mt


//------------------------------------------------- Surcharge d'opérateurs
	

//-------------------------------------------- Constructeurs - destructeur

	//Constructeur par défaut sans paramètres
	TrajetSimple();
	//Mode d'emploi :
	//Construit un trajet simple en initialisant tous
	//ses attributs à ""

	//Constructeur de Copie
	TrajetSimple(const TrajetSimple & unTrajetSimple);	
	//Mode d'emploi :
	//Construit un trajet simple en copiant les attributs du trajet en paramètre    	


	//Constructeur par défaut
	TrajetSimple(const char* dep, const char* arr, const char* mt );
	//Mode d'emploi :
	//Construit un trajet simple à partir de trois chaînes de caractères
	
	//Destructeur
	virtual ~TrajetSimple ();
	//Mode d'emploi :
	//Détruit le trajet simple

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
 	const char* moyenT;
};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

TrajetSimple*  creerTrajetSimple();
//Mode d'emploi :
//Crée un trajet simple en demandant ses attributs à l'utilisateur
//Renvoie le trajet simple créé

#endif // TRAJETSIMPLE_H
