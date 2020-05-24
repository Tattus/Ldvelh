/**
    Fonctions de sauvegarde et chargement de la partie
*/
#ifndef DEF_LOADSAVEBIS
#define DEF_LOADSAVEBIS

#include <iostream>
#include <fstream>
#include <vector>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
#include "save.hpp"
#include "game.hpp"


using namespace std;

bool saveVerifExist(string); /// Vérifie si le fichier de sauvegarde existe déjà - Retourne False si le fichier existe déjà.
void save(C_Save, string); /// Sauvegarde la partie - Retourne False si le fichier existe déjà.
C_Save load(string, bool*); /// Charge la partie
void listeGameSaves(void); /// Liste les fichier de sauvegardes

#endif // DEF_LOADSAVEBIS
