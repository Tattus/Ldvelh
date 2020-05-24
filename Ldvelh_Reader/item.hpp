/**
    Objet "Item" qui représente un objet dans le jeu de manière générique
*/
#ifndef DEF_ITEM
#define DEF_ITEM

#include <iostream>
#include <vector>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>

using namespace std;

class C_Item{
    public:
        C_Item(); /// Constructeur par défaut : (0, "", 0) -> (numéro de l'item, son nom, son nombre)
        C_Item(int, string, int); /// Constructeur avec paramètres (numéro de l'item, son nom, son nombre)
        ~C_Item(); /// Destructeur
        void setItem(int, string, int); /// Permet de renseigner : le numéro de l'item, son nom et son nombre.
        void setItemNum(int); /// Permet de définir le numéro de l'item
        void setItemName(string); /// Permet de définir le nom de l'item
        void setItemNumber(int); /// Permet de définir le nombre de l'item
        void changeItemNumber(int); /// Permet de modifier le nombre de l'item sous forme de variation (+ ou -)
        void descrItem(void); /// Permet d'afficher le numéro, le nom et le nombre de l'item
        void getItem(void); /// Permet d'afficher le numéro et le nom de l'item
        int getItemNum(void); /// Renvoi le numéro de l'item sous forme d'entier
        string getItemName(void); /// Renvoi le nom de l'item sous forme de string
        int getItemNumber(void); /// Renvoi le nombre de l'item sous forme d'entier
    private:
        // Classe amie
        friend class boost::serialization::access;
        // Méthodes
        template<class Archive> /// Archivage Boost Serialize
        void serialize(Archive& ar, const unsigned int version){
            ar & BOOST_SERIALIZATION_NVP(num) & BOOST_SERIALIZATION_NVP(name) & BOOST_SERIALIZATION_NVP(number);
        }
        // Attributs
        int num;
        string name;
        int number;
};

#endif // DEF_ITEM
