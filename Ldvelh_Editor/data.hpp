/**
    Objet "Data" qui représente une entrée
*/
#ifndef DEF_DATA
#define DEF_DATA

#include <iostream>
#include <vector>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/serialization/vector.hpp>
#include "item.hpp"
#include "dataItem.hpp"
#include "dataCondition.hpp"
#include "dataChoice.hpp"


using namespace std;

class C_Data{
    public:
        C_Data();
        C_Data(int, string); /// Constructeur avec paramètres -> numéro, text
        ~C_Data();
        void setDataNum(int); /// Permet de définir le numéro de l'entrée
        void setDataText(string); /// Permet de définir le texte de l'entrée
        void addChoice(C_DataChoice); /// Permet d'ajouter un choix à l'entrée
        void changeChoice(C_DataChoice, int); /// Permet de modifier un choix de l'entrée
        void eraseChoice(void); /// Permet d'effacer l'entrée
        void addItem(C_DataItem); /// Permet d'ajouter un item à l'entrée
        void changeItem(C_DataItem, int); /// Modifier un item
        void eraseItem(void); /// Effacer un item
        void descrData(vector<C_Item>); /// Descriptif de l'entrée dans sa totalitée
        void showText(void); /// Affiche le texte de l'entrée
        void format(string); /// Affiche le texte entré en paramètre avec le formatage défini dans la fonction (80 caractères de large. Tabulation = 8 caractères)
        vector<C_DataItem> getItemModification(void); /// Renvoi la valeur de getItemModification() décrit dans dataItem.hpp
        vector<C_DataChoice> getChoice(void); /// Renvoi la valeur de getChoice() décrit dans dataChoice.hpp
    private:
        // Classe amie
        friend class boost::serialization::access; /// Lance le jeu (pour le lecteur)
        // Méthodes
        template<class Archive>
        void serialize(Archive& ar, const unsigned int version){
            ar & BOOST_SERIALIZATION_NVP(num) & BOOST_SERIALIZATION_NVP(text)
            & BOOST_SERIALIZATION_NVP(itemModification) & BOOST_SERIALIZATION_NVP(dataChoice);

        }
        // Attributs
        int num;
        string text;
        vector<C_DataItem> itemModification;
        vector<C_DataChoice> dataChoice;
};

#endif // DEF_DATA
