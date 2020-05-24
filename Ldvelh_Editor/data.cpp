#include "language.hpp"
#include "data.hpp"

C_Data::C_Data()
{
    num = 0;
    text = "";
}

C_Data::C_Data(int dataNum, string datatext)
{
    num = dataNum;
    text = datatext;
}

C_Data::~C_Data()
{

}

void C_Data::setDataNum(int dataNum)
{
    num = dataNum;
}

void C_Data::setDataText(string dataText)
{
    text = dataText;
}

void C_Data::addChoice(C_DataChoice choice)
{
    dataChoice.push_back(choice);
}

void C_Data::changeChoice(C_DataChoice choice, int choiceNum)
{
    dataChoice[choiceNum] = choice;
}

void C_Data::eraseChoice(void)
{
    dataChoice.pop_back();
}

void C_Data::addItem(C_DataItem item)
{
    itemModification.push_back(item);
}

void C_Data::changeItem(C_DataItem item, int itemNum)
{
    itemModification[itemNum] = item;
}

void C_Data::eraseItem(void)
{
    itemModification.pop_back();
}

void C_Data::descrData(vector<C_Item> itemTab)
{
    #ifdef FR
        cout << "Entrée numéro " << num << " : " << endl;
    #endif
    #ifdef ENG
        cout << "Entry number " << num << " : " << endl;
    #endif
    #ifdef ESP
        cout << "Entrada número " << num << " : " << endl;
    #endif
    cout << endl;
    showText();

    if (itemModification.size() != 0)
    {
        cout << endl;
        cout << "*****" << endl;
        #ifdef FR
            cout << "Objets modifiés par l'entrée : " << endl;
        #endif
        #ifdef ENG
            cout << "Objects changed by the entry : " << endl;
        #endif
        #ifdef ESP
            cout << "Objetos cambiados par la entrada : " << endl;
        #endif
        for (unsigned int i = 0 ; i < itemModification.size() ; i++)
        {
            cout << "\t_ " << i << " -> " << itemTab[itemModification[i].getType()].getItemName() << " : ";
            if (itemModification[i].getModificationType() == 0)
            {
                #ifdef FR
                    cout << "Valeur modifiée de ";
                #endif
                #ifdef ENG
                    cout << "Value changed by ";
                #endif
                #ifdef ESP
                    cout << "Valor cambiado de ";
                #endif
            }
            else
            {
                #ifdef FR
                    cout << "Valeur remplacée par ";
                #endif
                #ifdef ENG
                    cout << "Value replace by ";
                #endif
                #ifdef ESP
                    cout << "Valor reemplazado por ";
                #endif
            }
            cout << itemModification[i].getValue() << endl;
        }
    }

    if (dataChoice.size() != 0)
    {
        for (unsigned int i = 0 ; i < dataChoice.size() ; i++)
        {
            cout << endl;
            cout << "*****" << endl;
            #ifdef FR
                cout << "Choix numéro " << i + 1 << " : " << endl;
            #endif
            #ifdef ENG
                cout << "Choice number " << i + 1 << " : " << endl;
            #endif
            #ifdef ESP
                cout << "Opción número " << i + 1 << " : " << endl;
            #endif
            cout << endl;
            format(dataChoice[i].getTextChoice());
            cout << endl;
            #ifdef FR
                cout << "Destination du choix " << i + 1 << " : " << dataChoice[i].getDestChoice() << endl;
            #endif
            #ifdef ENG
                cout << "Destination of this choice " << i + 1 << " : " << dataChoice[i].getDestChoice() << endl;
            #endif
            #ifdef ESP
                cout << "Destino de la opción " << i + 1 << " : " << dataChoice[i].getDestChoice() << endl;
            #endif
            if (dataChoice[i].getSizeCondition() != 0)
            {
                cout << endl;
                #ifdef FR
                    cout << "Conditions du choix :" << endl;
                #endif
                #ifdef ENG
                    cout << "Conditions of this choice :" << endl;
                #endif
                #ifdef ESP
                    cout << "Condiciones de la opción :" << endl;
                #endif
                for (unsigned int j = 0 ; j < dataChoice[i].getSizeCondition() ; j++)
                {
                    cout << "\t_ " << j << " -> " << itemTab[dataChoice[i].getCondition(j).getTypeItem()].getItemName();
                    switch(dataChoice[i].getCondition(j).getCondition())
                    {
                        case 0:
                            cout << " = ";
                            break;
                        case 1:
                            cout << " != ";
                            break;
                        case 2:
                            cout << " >= ";
                            break;
                        case 3:
                            cout << " > ";
                            break;
                        case 4:
                            cout << " <= ";
                            break;
                        case 5:
                            cout << " < ";
                            break;
                        default:
                            break;
                    }
                    cout << dataChoice[i].getCondition(j).getValue() << endl;
                }
            }
            if (dataChoice[i].getSizeModification() != 0)
            {
                cout << endl;
                #ifdef FR
                    cout << "Objets modifiés par le choix : " << endl;
                #endif
                #ifdef ENG
                    cout << "Objects changed by this choice : " << endl;
                #endif
                #ifdef ESP
                    cout << "Objetos cambiados par la opción : " << endl;
                #endif
                for (unsigned int j = 0 ; j < dataChoice[i].getSizeModification() ; j++)
                {
                    cout << "\t_ " << j << " -> " << itemTab[dataChoice[i].getModification(j).getType()].getItemName() << " : ";
                    if (dataChoice[i].getModification(j).getModificationType() == 0)
                    {
                        #ifdef FR
                            cout << "Valeur modifiée de ";
                        #endif
                        #ifdef ENG
                            cout << "Value changed by ";
                        #endif
                        #ifdef ESP
                            cout << "Valor cambiado de ";
                        #endif
                    }
                    else
                    {
                        #ifdef FR
                            cout << "Valeur remplacée par ";
                        #endif
                        #ifdef ENG
                            cout << "Value replace by ";
                        #endif
                        #ifdef ESP
                            cout << "Valor reemplazado por ";
                        #endif
                    }
                    cout << dataChoice[i].getModification(j).getValue() << endl;
                }
            }
        }
    }
}

void C_Data::showText(void)
{
    vector<string> paragraphe;

    string textLeft = text;
    while (textLeft.find("\n") != string::npos)
    {
        paragraphe.push_back(textLeft.substr(0, textLeft.find("\n")));
        textLeft = textLeft.substr(textLeft.find("\n") + 1);
    }
    paragraphe.push_back(textLeft.substr(0));

    for (unsigned int i = 0 ; i < paragraphe.size() ; i++)
    {
        format(paragraphe[i]);
        cout << endl;
    }
}

void C_Data::format(string stringToFormat)
{
    string textLeft = stringToFormat;
    string line;
    size_t lenght = 0;
    size_t posStart = 0;

    while(textLeft.size() >= 80)
    {
        if (textLeft.at(0) == '\t')
        {
            line = textLeft.substr(0, 72); // Tabulation fait 8 caractères de long.
        }
        else
        {
            line = textLeft.substr(0, 80);
        }
        lenght = line.find_last_of(" ");
        cout << stringToFormat.substr(posStart, lenght) << endl;
        posStart += lenght + 1;
        textLeft = stringToFormat.substr(posStart);

    }
    cout << textLeft << endl;
}

vector<C_DataItem> C_Data::getItemModification(void)
{
    return itemModification;
}

vector<C_DataChoice> C_Data::getChoice(void)
{
    return dataChoice;
}
