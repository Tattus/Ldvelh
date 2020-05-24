#include "language.hpp"
#include "dataItem.hpp"

C_DataItem::C_DataItem()
{
    modificationType = 0;
    typeI = 0;
    valueI = 0;
}

C_DataItem::~C_DataItem()
{

}

void C_DataItem::setModificationType(int typeModif)
{
    modificationType = typeModif;
}

void C_DataItem::setType(int typeItem)
{
    typeI = typeItem;
}

void C_DataItem::setValue(int valueItem)
{
    valueI = valueItem;
}

int C_DataItem::getModificationType(void)
{
    return modificationType;
}

int C_DataItem::getType(void)
{
    return typeI;
}

int C_DataItem::getValue(void)
{
    return valueI;
}
