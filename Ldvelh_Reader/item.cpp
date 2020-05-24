#include "language.hpp"
#include "item.hpp"

C_Item::C_Item()
{
    num = 0;
    name = "";
    number = 0;
}

C_Item::C_Item(int itemNum, string itemName, int itemNumber)
{
    num = itemNum;
    name = itemName;
    number = itemNumber;
}

C_Item::~C_Item()
{

}

void C_Item::setItem(int itemNum, string itemName, int itemNumber)
{
    num = itemNum;
    name = itemName;
    number = itemNumber;
}

void C_Item::setItemNum(int itemNum)
{
    num = itemNum;
}

void C_Item::setItemName(string itemName)
{
    name = itemName;
}

void C_Item::setItemNumber(int itemNumber)
{
    number = itemNumber;
}

void C_Item::changeItemNumber(int itemNumberVariation)
{
    number += itemNumberVariation;
}

void C_Item::descrItem(void)
{
    #ifdef FR
        cout << "Objet numéro " << num << " : " << name << endl;
        cout << "Quantité par défaut : " << number << endl;
    #endif
    #ifdef ENG
        cout << "Object number " << num << " : " << name << endl;
        cout << "Default quantity : " << number << endl;
    #endif
    #ifdef ESP
        cout << "Objecto número " << num << " : " << name << endl;
        cout << "Cantidad predeterminada : " << number << endl;
    #endif
}

void C_Item::getItem(void)
{
    cout << number << " - " << name << endl;
}

int C_Item::getItemNum(void)
{
    return num;
}

string C_Item::getItemName(void)
{
    return name;
}

int C_Item::getItemNumber(void)
{
    return number;
}
