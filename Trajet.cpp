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
	
	void Trajet::setDepp(const char*  dep)
	{
		villeDepart = dep;
	} //------ Fin de setDepp

	void Trajet::setArr(const char* arr)
	{
		villeArr = arr;
	} //------ Fin de setArr

	const char* Trajet::getArr()
	{
		return this->villeArr;
	} //------ Fin de getArr
	
	const char* Trajet::getDep()
	{
		return this->villeDepart;
	} //------ fin de getDep

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


Trajet::Trajet (const char* dep, const char* arr)
{
	#ifdef MAP
		cout << "Appel au constructeur par défaut avec paramètres de <Trajet>" << endl;
	#endif
	this->villeDepart =dep;
	this->villeArr = arr;
} //----- Fin de Trajet (constructeur par défaut)


Trajet::~Trajet()
{

	#ifdef MAP
    		cout << "Appel au destructeur de <Trajet>" << endl;
	#endif
} //----- Fin de ~Trajet

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

