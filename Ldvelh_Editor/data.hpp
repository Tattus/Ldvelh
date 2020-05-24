/**
    Objet "Data" qui repr�sente une entr�e
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
        C_Data(int, string); /// Constructeur avec param�tres -> num�ro, text
        ~C_Data();
        void setDataNum(int); /// Permet de d�finir le num�ro de l'entr�e
        void setDataText(string); /// Permet de d�finir le texte de l'entr�e
        void addChoice(C_DataChoice); /// Permet d'ajouter un choix � l'entr�e
        void changeChoice(C_DataChoice, int); /// Permet de modifier un choix de l'entr�e
        void eraseChoice(void); /// Permet d'effacer l'entr�e
        void addItem(C_DataItem); /// Permet d'ajouter un item � l'entr�e
        void changeItem(C_DataItem, int); /// Modifier un item
        void eraseItem(void); /// Effacer un item
        void descrData(vector<C_Item>); /// Descriptif de l'entr�e dans sa totalit�e
        void showText(void); /// Affiche le texte de l'entr�e
        void format(string); /// Affiche le texte entr� en param�tre avec le formatage d�fini dans la fonction (80 caract�res de large. Tabulation = 8 caract�res)
        vector<C_DataItem> getItemModification(void); /// Renvoi la valeur de getItemModification() d�crit dans dataItem.hpp
        vector<C_DataChoice> getChoice(void); /// Renvoi la valeur de getChoice() d�crit dans dataChoice.hpp
    private:
        // Classe amie
        friend class boost::serialization::access; /// Lance le jeu (pour le lecteur)
        // M�thodes
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
