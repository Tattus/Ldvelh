#ifndef DEF_SAVE
#define DEF_SAVE

#include <iostream>
#include <fstream>
#include <vector>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/serialization/vector.hpp>
#include "data.hpp"
#include "item.hpp"

using namespace std;

class C_Save{
    public:
        C_Save();
        ~C_Save();
        void setEntry(int);
        void setInventory(vector<C_Item>);
        int getEntry(void);
        vector<C_Item> getInventory(void);
    private:
        // Classe amie
        friend class boost::serialization::access;
        // Méthodes
        template<class Archive>
        void serialize(Archive& ar, const unsigned int version){
            ar & BOOST_SERIALIZATION_NVP(myEntry) & BOOST_SERIALIZATION_NVP(myInventory);

        }
        // Attributs
        int myEntry;
        vector<C_Item> myInventory;
};

#endif // DEF_SAVE
