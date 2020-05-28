/**
    Objet "Game" qui représente un jeu dans le fichier de jeu. Il contient tout les éléments définit dans le jeu.
*/
#ifndef DEF_GAME
#define DEF_GAME

#include <iostream>
#include <sstream>
#include <vector>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/serialization/vector.hpp>
#include "data.hpp"
#include "item.hpp"
#include "dataItem.hpp"
#include "dataCondition.hpp"
#include "dataChoice.hpp"
#include "save.hpp"
#include "load_save_bis.hpp"

#define VERSION_BASE "3"
#define VERSION "3.1"


using namespace std;

class C_Game{
    public:
        C_Game();
        ~C_Game();
        void setGameNum(unsigned int); /// Définit le numéro du jeu
        void setGameName(string); /// Définit le nom du jeu
        void setGameAuthor(string); /// Définit l'auteur du jeu
        unsigned int getGameNum(void); /// Renvoi le numéro du jeu
        string getGameName(void); /// Renvoi le nom du jeu
        string getGameAuthor(void); /// Renvoi l'auteur du jeu
        void runMenu(void); /// Lance le jeu
    private:
        // Classe amie
        friend class boost::serialization::access; /// Lance le jeu (pour le lecteur)
        // Méthodes
        template<class Archive>
        void serialize(Archive& ar, const unsigned int version){
            ar & BOOST_SERIALIZATION_NVP(num) & BOOST_SERIALIZATION_NVP(name) & BOOST_SERIALIZATION_NVP(author)
            & BOOST_SERIALIZATION_NVP(dataTab) & BOOST_SERIALIZATION_NVP(itemTab);

        }
        void start(C_Save, string, bool);
        int playEntry(C_Save*, int, bool);
        void showInventory(C_Save);
        // Attributs
        unsigned int num;
        string name;
        string author;
        vector<C_Data> dataTab;
        vector<C_Item> itemTab;
};

#endif // DEF_GAME
