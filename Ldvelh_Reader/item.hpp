/**
    Objet "Item" qui repr�sente un objet dans le jeu de mani�re g�n�rique
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
        C_Item(); /// Constructeur par d�faut : (0, "", 0) -> (num�ro de l'item, son nom, son nombre)
        C_Item(int, string, int); /// Constructeur avec param�tres (num�ro de l'item, son nom, son nombre)
        ~C_Item(); /// Destructeur
        void setItem(int, string, int); /// Permet de renseigner : le num�ro de l'item, son nom et son nombre.
        void setItemNum(int); /// Permet de d�finir le num�ro de l'item
        void setItemName(string); /// Permet de d�finir le nom de l'item
        void setItemNumber(int); /// Permet de d�finir le nombre de l'item
        void changeItemNumber(int); /// Permet de modifier le nombre de l'item sous forme de variation (+ ou -)
        void descrItem(void); /// Permet d'afficher le num�ro, le nom et le nombre de l'item
        void getItem(void); /// Permet d'afficher le num�ro et le nom de l'item
        int getItemNum(void); /// Renvoi le num�ro de l'item sous forme d'entier
        string getItemName(void); /// Renvoi le nom de l'item sous forme de string
        int getItemNumber(void); /// Renvoi le nombre de l'item sous forme d'entier
    private:
        // Classe amie
        friend class boost::serialization::access;
        // M�thodes
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
