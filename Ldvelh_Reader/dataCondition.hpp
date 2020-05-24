/**
    Objet "DataCondition" qui représente une condition dans une entrée. Actuellement les conditions se font sur des objets de l'inventaire
*/
#ifndef DEF_DATACONDITION
#define DEF_DATACONDITION

#include <iostream>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include "dataItem.hpp"

using namespace std;

class C_DataCondition{
    public:
        C_DataCondition();
        ~C_DataCondition();
        void setCondition(int); /// Permet de définir l'opérateur de la condition : 0 -> = / 1 -> != / 2 -> >= / 3 ->  > / 4 -> <= / 5 -> <
        void setTypeItem(int); /// Permet de définir l'item utilisé pour la condition
        void setValue(int); /// Permet de définir la valeur de la condition
        int getCondition(void); /// Permet d'obtenir l'opérateur de la condition
        int getTypeItem(void); /// Permet d'obtenir l'item utilisé pour la confition
        int getValue(void); /// Permet d'obtenir la valeur de la condition
    private:
        // Classe amie
        friend class boost::serialization::access;
        // Méthodes
        template<class Archive>
        void serialize(Archive& ar, const unsigned int version){
            ar & BOOST_SERIALIZATION_NVP(conditionType) & BOOST_SERIALIZATION_NVP(itemCondition);

        }
        // Attributs
        int conditionType;
        C_DataItem itemCondition;
};

#endif // DEF_DATACONDITION
