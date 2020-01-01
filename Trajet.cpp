/*************************************************************************
                  Classe Trajet  -  représente un trajet
                             -------------------
    début                : 22/11/2019
    copyright            : (C) 2019 par J.HUE, F.HACHIM
    e-mail               : jerome.hue@insa-lyon.fr / faouz.hachim@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------
//#define MAP
//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <cstring>
//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
	void Trajet::afficher() 
	{
		cout << villeDepart << endl;
		cout << villeArr << endl;
	} //------ Fin de afficher

	void Trajet::sauvegarde(ofstream & flux)
	{
		
	}
	
	void Trajet::setDepp(const char*  dep)
	{
		strcpy(villeDepart, dep);
	} //------ Fin de setDepp

	void Trajet::setArr(const char* arr)
	{
		strcpy(villeArr, arr);
	} //------ Fin de setArr

	char* Trajet::getArr()
	{
		return this->villeArr;
	} //------ Fin de getArr
	
	char* Trajet::getDep()
	{
		return this->villeDepart;
	} //------ fin de getDep

	char* Trajet::getType()
	{
		return this->type;
	}

//------------------------------------------------- Surcharge d'opérateurs
//Xxx & Xxx::operator = ( const Xxx & unXxx )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

Trajet::Trajet()
{
	villeDepart = "";
	villeArr = "";
	type = "";
	#ifdef MAP
		cout << "Appel au constructeur par defaut sans paramètres de <Trajet>" << endl;
	#endif
}//----- Fin de Trajet (constructeur par défaut sans paramètres)


Trajet::Trajet ( const Trajet & unTrajet )
{
	villeDepart = unTrajet.villeDepart;
	villeArr = unTrajet.villeArr;

	#ifdef MAP
    		cout << "Appel au constructeur de copie de <Trajet>" << endl;
	#endif
} //----- Fin de Trajet (constructeur de copie)


Trajet::Trajet (const char* dep, const char* arr, const char* t)
{
	#ifdef MAP
		cout << "Appel au constructeur par défaut avec paramètres de <Trajet>" << endl;
	#endif
	//this->villeDepart =dep;
	//this->villeArr = arr;
	//this->type = t;


	villeDepart = new char[strlen(dep)+1];
	villeArr = new char[strlen(arr)+1];
	type = new char[strlen(t)+1]; 
	strcpy(villeDepart, dep);
	strcpy(villeArr, arr);	
	strcpy(type, t);

} //----- Fin de Trajet (constructeur par défaut)


Trajet::~Trajet()
{

	#ifdef MAP
    		cout << "Appel au destructeur de <Trajet>" << endl;
	#endif
} //----- Fin de ~Trajet

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
