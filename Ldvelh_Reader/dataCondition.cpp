#include "language.hpp"
#include "dataCondition.hpp"

C_DataCondition::C_DataCondition()
{
    conditionType = 0;
}

C_DataCondition::~C_DataCondition()
{

}

void C_DataCondition::setCondition(int condition)
{
    conditionType = condition;
}

void C_DataCondition::setTypeItem(int typeItem)
{
    itemCondition.setType(typeItem);
}

void C_DataCondition::setValue(int valueCondition)
{
    itemCondition.setValue(valueCondition);
}

int C_DataCondition::getCondition(void)
{
    return conditionType;
}

int C_DataCondition::getTypeItem(void)
{
    return itemCondition.getType();
}

int C_DataCondition::getValue(void)
{
    return itemCondition.getValue();
}
