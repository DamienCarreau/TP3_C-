/*************************************************************************
              Classe TrajetSimple  - décrit un trajet simple
                             -------------------
    début                : 22/11/2019
    copyright            : (C) 2019 par J.HUE, F.HACHIM
    e-mail               : jerome.hue@insa-lyon.fr / faouz.hachim@insa-lyon.fr
*************************************************************************/

//-Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ----

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <cstring>
//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"
#include "Trajet.h"
//------------------------------------------------------------- Constantes
//#define MAP
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

	void TrajetSimple::afficher()
	{
		cout << "Départ : " << villeDepart << " | Arrivée : " << villeArr << " | Moyen de Transport : " << moyenT << endl;
	}//----fin de afficher

	void TrajetSimple::sauvegarde(ofstream & flux)
	{
		flux << villeDepart << " " << villeArr << " " << moyenT;
	}//------fin de sauvegarde

	void TrajetSimple::setMoyenT(const char* mt)
	{
		moyenT = mt;
	}//----fin de setMoyenT

	TrajetSimple*  creerTrajetSimple()
	//Algorithme :
	//Lis 3 chaines de caractères sur l'entrée
	//Appelle le constructeur TrajetSimple avec ces 3 chaines
	{
		char*  dep = new char[128];
		char*  arr = new char[128];
		char*  mt  = new char[128];
		cout << "Entrez une ville de départ " << endl;
		cin >> dep;
		cout << "Entrez une ville d'arrivée " << endl;
		cin >> arr;
		cout << "Entrez un moyen de transport " << endl;
		cin >> mt;		

		return new TrajetSimple(dep, arr, mt);
	}//---fin de creerTrajetSimple


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple()
{
    #ifdef MAP
   		 cout << "Appel au constructeur par défaut sans paramètres de <TrajetSimple>" << endl;
	#endif
	Trajet();
	moyenT = " ";

}//-- fin du constructeur par défaut sans paramètre


TrajetSimple::TrajetSimple(const TrajetSimple & unTrajetSimple) : Trajet(unTrajetSimple), moyenT(unTrajetSimple.moyenT)
{

	#ifdef MAP
   		 cout << "Appel au constructeur par copie de <TrajetSimple>" << endl;
	#endif
}//---fin du constructeur par copie



TrajetSimple::TrajetSimple (const char* s1,const  char* s2,const  char* mt ): Trajet(s1,s2,"simple"), moyenT(mt)
{
	#ifdef MAP
   		 cout << "Appel au constructeur de <TrajetSimple>" << endl;
	#endif
} //--- fin du constructeur par défaut avec paramètres

TrajetSimple::~TrajetSimple ()
{
    #ifdef MAP
    		cout << "Appel au destructeur de <TrajetSimple>" << endl;
	#endif
	delete [] villeDepart;
	delete [] villeArr;
	delete [] moyenT;

} //--- fin du destructeur

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
