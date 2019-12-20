/*************************************************************************
                             IO  -  description
                             -------------------
    début                : 2019-2020
    copyright            : (C) 2019-2020 par CARREAU Damien	HUE Jérome
    e-mail               : damien.carreau@insa-lyon.fr	jerome.hue@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <IO> (fichier IO.h) ----------------
#if ! defined ( IO_H )
#define IO_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <IO>
// Regroupe les méthodes de sauvegarde et de chargement du programme
//
//------------------------------------------------------------------------

class IO 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Chargement();
    // Mode d'emploi :
    // Charge le flux du fichier dans le programme
    
    void Sauvegarde();
    // Mode d'emploi :
    // Sauvegarde le catalogue courant dans le fichier


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    IO ( const string name, const char mode);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    virtual ~IO ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------- Méthodes protégées
	ifstream iflux;
	ofstream oflux;

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Ensemble>

#endif // ENSEMBLE_H

