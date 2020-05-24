/**
    Objet "DataItem" qui représente un objet dans la partie (objet de l'inventaire)
*/
#ifndef DEF_DATAITEM
#define DEF_DATAITEM

#include <iostream>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>

using namespace std;

class C_DataItem{
    public:
        C_DataItem();
        ~C_DataItem();
        void setModificationType(int); /// Permet de définir le type de modification // 0 -> Ajouter/Retirer // 1 -> Remplacer
        void setType(int); /// Permet de définir le type de l'item
        void setValue(int); /// Permet de définir la valeur de l'item
        int getModificationType(void); /// Permet d'obtenir le type de modification
        int getType(void); /// Permet d'obtenir le type de l'item
        int getValue(void); /// Permet d'obtenir la valeur de l'item
    private:
        // Classe amie
        friend class boost::serialization::access;
        // Méthodes
        template<class Archive>
        void serialize(Archive& ar, const unsigned int version){
            ar & BOOST_SERIALIZATION_NVP(modificationType) & BOOST_SERIALIZATION_NVP(typeI) & BOOST_SERIALIZATION_NVP(valueI);

        }
        // Attributs
        int modificationType;
        int typeI;
        int valueI;
};

#endif // DEF_DATAITEM
