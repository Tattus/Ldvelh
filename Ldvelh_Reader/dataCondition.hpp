/**
    Objet "DataCondition" qui repr�sente une condition dans une entr�e. Actuellement les conditions se font sur des objets de l'inventaire
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
        void setCondition(int); /// Permet de d�finir l'op�rateur de la condition : 0 -> = / 1 -> != / 2 -> >= / 3 ->  > / 4 -> <= / 5 -> <
        void setTypeItem(int); /// Permet de d�finir l'item utilis� pour la condition
        void setValue(int); /// Permet de d�finir la valeur de la condition
        int getCondition(void); /// Permet d'obtenir l'op�rateur de la condition
        int getTypeItem(void); /// Permet d'obtenir l'item utilis� pour la confition
        int getValue(void); /// Permet d'obtenir la valeur de la condition
    private:
        // Classe amie
        friend class boost::serialization::access;
        // M�thodes
        template<class Archive>
        void serialize(Archive& ar, const unsigned int version){
            ar & BOOST_SERIALIZATION_NVP(conditionType) & BOOST_SERIALIZATION_NVP(itemCondition);

        }
        // Attributs
        int conditionType;
        C_DataItem itemCondition;
};

#endif // DEF_DATACONDITION
