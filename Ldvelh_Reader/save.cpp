#include "language.hpp"
#include "save.hpp"

C_Save::C_Save()
{
    myEntry = 1;
}

C_Save::~C_Save()
{

}

void C_Save::setEntry(int entry)
{
    myEntry = entry;
}

void C_Save::setInventory(vector<C_Item> inventory)
{
    myInventory = inventory;
}

int C_Save::getEntry(void)
{
    return myEntry;
}

vector<C_Item> C_Save::getInventory(void)
{
    return myInventory;
}
