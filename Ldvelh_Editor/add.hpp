/**
    Fonctions de l'�diteur pour ajouter et modifier des entr�es, etc
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

string setName(void); /// Fonction qui permet de d�finir le nom du jeu, renvoi le nom sous un type string
string setAuthor(void); /// Fonction qui permet de d�finir l'auteur du jeu, renvoi le nom sous un type string
C_Data addEntries(vector<C_Data>, vector<C_Item>); /// Fonction qui permet d'ajouter une entr�e
C_Data changeEntries(C_Data, vector<C_Item>); /// Fonction qui permet de modifier une entr�e
C_Item addItem(vector<C_Item>); /// Fonction qui permet d'ajouter un objet
C_Item changeItem(C_Item); /// Fonction qui permet de modifier un objet

#endif // DEF_ADD
