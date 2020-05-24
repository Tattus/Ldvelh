/**
    Objet "DataChoice" qui représente un choix dans une entrée
*/
#ifndef DEF_DATACHOICE
#define DEF_DATACHOICE

#include <iostream>
#include <vector>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/serialization/vector.hpp>
#include "dataCondition.hpp"
#include "dataItem.hpp"

using namespace std;

class C_DataChoice{
    public:
        C_DataChoice();
        ~C_DataChoice();
        void setTextChoice(string); /// Permet de définir le texte du choix
        void setDestChoice(int); /// Permet de définir l'entrée destination du choix
        void addConditionChoice(C_DataCondition); /// Permet d'ajouter une condition au choix
        void changeConditionChoice(C_DataCondition, int); /// Permet de changer la condition du choix
        void eraseConditionChoice(void); /// Permet d'effacer la dernière condition du choix
        void addModificationItem(C_DataItem); /// Permet d'ajouter une modification d'item au choix
        void changeModificationItem(C_DataItem, int); /// Permet de modifier une modification d'item du choix
        void eraseModificationItem(void); /// Permet d'effacer la dernière modification d'item du choix
        string getTextChoice(void); /// Permet d'obtenir le texte du choix
        int getDestChoice(void); /// Permet d'obtenir la destination du choix
        unsigned int getSizeCondition(void); /// Permet d'obtenir le nombre de condition du choix
        C_DataCondition getCondition(unsigned int); /// Permet d'obtenir le numéro de la condition
        unsigned int getSizeModification(void); /// Permet d'obtenir le nombre de modification d'item du choix
        C_DataItem getModification(unsigned int); /// Permet d'obtenir le numéro de la modification d'item
    private:
        // Classe amie
        friend class boost::serialization::access;
        // Méthodes
        template<class Archive>
        void serialize(Archive& ar, const unsigned int version){
            ar & BOOST_SERIALIZATION_NVP(choice) & BOOST_SERIALIZATION_NVP(destChoice) & BOOST_SERIALIZATION_NVP(conditionChoice) & BOOST_SERIALIZATION_NVP(modificationItem);

        }
        // Attributs
        string choice;
        int destChoice;
        vector<C_DataCondition> conditionChoice;
        vector<C_DataItem> modificationItem;
};

#endif // DEF_DATACHOICE

