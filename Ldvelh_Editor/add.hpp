/**
    Fonctions de l'éditeur pour ajouter et modifier des entrées, etc
*/
#ifndef DEF_ADD
#define DEF_ADD

#include <iostream>
#include <vector>
#include "item.hpp"
#include "dataCondition.hpp"
#include "dataItem.hpp"
#include "dataChoice.hpp"
#include "data.hpp"

using namespace std;

string setName(void); /// Fonction qui permet de définir le nom du jeu, renvoi le nom sous un type string
string setAuthor(void); /// Fonction qui permet de définir l'auteur du jeu, renvoi le nom sous un type string
C_Data addEntries(vector<C_Data>, vector<C_Item>); /// Fonction qui permet d'ajouter une entrée
C_Data changeEntries(C_Data, vector<C_Item>); /// Fonction qui permet de modifier une entrée
C_Item addItem(vector<C_Item>); /// Fonction qui permet d'ajouter un objet
C_Item changeItem(C_Item); /// Fonction qui permet de modifier un objet

#endif // DEF_ADD
