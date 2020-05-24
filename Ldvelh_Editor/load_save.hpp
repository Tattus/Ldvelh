/**
    Fonctions de sauvegarde et chargement du jeu
*/
#ifndef DEF_LOADSAVE
#define DEF_LOADSAVE

#include <iostream>
#include <fstream>
#include <vector>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
#include "data.hpp"
#include "item.hpp"
#include "game.hpp"

using namespace std;

bool saveGame(vector<C_Game>, string, bool); /// Sauvegarde le jeu - Retourne False si le fichier existe déjà.
vector<C_Game> loadGame(string, bool*); /// Charge le jeu
void listeGameFiles(void); /// Liste les fichier de jeux

#endif // DEF_LOADSAVE
