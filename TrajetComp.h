/*************************************************************************
                  Classe TrajetComp - décrit un trajet composé
                             -------------------
    début                : 22/11/2019
    copyright            : (C) 2019 par J.HUE, F.HACHIM
    e-mail               : jerome.hue@insa-lyon.fr / faouz.hachim@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetComp> (fichier TrajetComp.h) ----------------
#if ! defined (TRAJETC_H )
#define TRAJETC_H
//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetComp>
// Représente un trajet composé (contient plusieurs trajets qui se suivent)
// Hérite de la classe Trajet et possède en plus un tableau de pointeurs de trajets
//------------------------------------------------------------------------

class TrajetComp : public Trajet
{

public:
//----------------------------------------------------- Méthodes publiques
   
	void afficher();
	//Mode d'emploi :
	//Affiche un trajet composé en affichant un à un ses sous-trajets 

	void addTrajet(Trajet* tr);
	//Mode d'emploi :
	//Ajoute le trajet en paramètre à la fin du tableau en vérifiant
	//d'abord s'il est cohérent avec ce qui est déjà présent

	void creerTrajetComp(int nb);	
	//Mode d'emploi :
	//Crée un trajet composé en demandant les différentes caratèristiques
	//du trajet à l'utilisateur
	//Le nombre de sous-trajet est en paramètre

//------------------------------------------------- Surcharge d'opérateurs
/*
//    Xxx & operator = ( const Xxx & unXxx );
      Mode d'emploi :
    
      Contrat :
    
*/

//-------------------------------------------- Constructeurs - destructeur

	TrajetComp();
	//Mode d'emploi :
	// Construit un trajet composé en initialisant son tableau de (pointeurs de) trajets
 
    	TrajetComp(const char* dep, const char* arr, Trajet** trs);
	//Mode d'emploi :
	//Construit un trajet à partir d'un tableau de pointeurs de trajet et de deux chaines
	//de caractères

	virtual ~TrajetComp ( );
	//Mode d'emploi :
	//Détruit le trajet composé

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
 	Trajet** sousTrajets;
	int nbTrajets;
};

//-------------------------------- Autres définitions dépendantes de <TrajetComp>

#endif // TRAJETC_H

