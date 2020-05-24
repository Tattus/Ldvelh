#include "language.hpp"
#include "dataChoice.hpp"

C_DataChoice::C_DataChoice()
{
    choice = "";
    destChoice = 0;
}

C_DataChoice::~C_DataChoice()
{

}

void C_DataChoice::setTextChoice(string textChoice)
{
    choice = textChoice;
}

void C_DataChoice::setDestChoice(int destination)
{
    destChoice = destination;
}

void C_DataChoice::addConditionChoice(C_DataCondition condition)
{
    conditionChoice.push_back(condition);
}

void C_DataChoice::changeConditionChoice(C_DataCondition condition, int numModif)
{
    conditionChoice[numModif] = condition;
}

void C_DataChoice::eraseConditionChoice(void)
{
    conditionChoice.pop_back();
}

void C_DataChoice::addModificationItem(C_DataItem modification)
{
    modificationItem.push_back(modification);
}

void C_DataChoice::changeModificationItem(C_DataItem modification, int numModif)
{
    modificationItem[numModif] = modification;
}

void C_DataChoice::eraseModificationItem(void)
{
    modificationItem.pop_back();
}

string C_DataChoice::getTextChoice(void)
{
    return choice;
}

int C_DataChoice::getDestChoice(void)
{
    return destChoice;
}

unsigned int C_DataChoice::getSizeCondition(void)
{
    return conditionChoice.size();
}

C_DataCondition C_DataChoice::getCondition(unsigned int number)
{
    C_DataCondition conditionError;

    if (conditionChoice.size() != 0)
    {
        if (number >= 0 && number < conditionChoice.size())
        {
            return conditionChoice[number];
        }
    }

    return conditionError;
}

unsigned int C_DataChoice::getSizeModification(void)
{
    return modificationItem.size();
}

C_DataItem C_DataChoice::getModification(unsigned int number)
{
    C_DataItem modificationError;

    if (modificationItem.size() != 0)
    {
        if (number >= 0 && number < modificationItem.size())
        {
            return modificationItem[number];
        }
    }

    return modificationError;
}
