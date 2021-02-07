/**
    Objet "Game" qui repr�sente un jeu dans le fichier de jeu. Il contient tout les �l�ments d�finit dans le jeu.
*/
#ifndef DEF_GAME
#define DEF_GAME

#include <iostream>
#include <vector>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/serialization/vector.hpp>
#include "data.hpp"
#include "item.hpp"
#include "dataItem.hpp"
#include "dataCondition.hpp"
#include "dataChoice.hpp"
#include "add.hpp"

#define VERSION_BASE "3"
#define VERSION "3.1"

using namespace std;

class C_Game{
    public:
        C_Game();
        ~C_Game();
        void setGameNum(unsigned int); /// D�finit le num�ro du jeu
        void setGameName(string); /// D�finit le nom du jeu
        void setGameAuthor(string); /// D�finit l'auteur du jeu
        unsigned int getGameNum(void); /// Renvoi le num�ro du jeu
        string getGameName(void); /// Renvoi le nom du jeu
        string getGameAuthor(void); /// Renvoi l'auteur du jeu
        void runGame(void); /// Lance le jeu (fonctionnalit� non pr�sente [pas de fonction cr��e � ce jour]
        void editGame(void); /// Lance le mode �dition
        void listItems(void); /// Liste les items du jeu
    private:
        // Classe amie
        friend class boost::serialization::access; /// Lance le jeu (pour le lecteur)
        // M�thodes
        template<class Archive>
        void serialize(Archive& ar, const unsigned int version){
            ar & BOOST_SERIALIZATION_NVP(num) & BOOST_SERIALIZATION_NVP(name) & BOOST_SERIALIZATION_NVP(author)
            & BOOST_SERIALIZATION_NVP(dataTab) & BOOST_SERIALIZATION_NVP(itemTab);

        }
        // Attributs
        unsigned int num;
        string name;
        string author;
        vector<C_Data> dataTab;
        vector<C_Item> itemTab;
};

#endif // DEF_GAME
