#include "language.hpp"
#include "add.hpp"

string setName(void)
{
    string name;
    #ifdef FR
        cout << "Indiquer le nom du jeu" << endl;
    #endif
    #ifdef ENG
        cout << "Indicate game name" << endl;
    #endif
    #ifdef ESP
        cout << "Indicar nombre del juego" << endl;
    #endif
    cin.ignore();
    getline(cin, name);

    return name;
}

string setAuthor(void)
{
    string author;
    #ifdef FR
        cout << "Indiquer l'auteur du jeu" << endl;
    #endif
    #ifdef ENG
        cout << "Indicate the author of the game" << endl;
    #endif
    #ifdef ESP
        cout << "Indicar autor del juego" << endl;
    #endif
    getline(cin, author);

    return author;
}

C_Data addEntries(vector<C_Data> dataTab, vector<C_Item> itemTab)
{
    bool fail = false;
    bool next = true;
    int intData;
    unsigned int intDataStrictPos;
    string stringData;
    string stringDataTotal;
    C_Data data;
    data.setDataNum(dataTab.size());
    int choice;

    cout << "********************************************" << endl;
    #ifdef FR
        cout << "Inserer le texte :" << endl;
    #endif
    #ifdef ENG
        cout << "insert text" << endl;
    #endif
    #ifdef ESP
        cout << "Insertar el texto" << endl;
    #endif
    cin.ignore();
    getline(cin, stringData);
    stringDataTotal += stringData;

    while(next)
    {
        #ifdef FR
            cout << "Ajouter un paragraphe ?" << endl;
            cout << "1 - Oui" << endl;
            cout << "2 - Non" << endl;
        #endif
        #ifdef ENG
            cout << "Add paragraph ?" << endl;
            cout << "1 - Yes" << endl;
            cout << "2 - No" << endl;
        #endif
        #ifdef ESP
            cout << "¿ Añadar un párrafo ?" << endl;
            cout << "1 - Si" << endl;
            cout << "2 - No" << endl;
        #endif
        cin >> choice;
        if(cin.fail())
        {
            choice = 0;
        }
        switch(choice)
        {
            case 1:
                stringDataTotal += "\n";
                cout << "********************************************" << endl;
                #ifdef FR
                    cout << "Inserer le texte :" << endl;
                #endif
                #ifdef ENG
                    cout << "insert text" << endl;
                #endif
                #ifdef ESP
                    cout << "Insertar el texto" << endl;
                #endif
                cin.ignore();
                getline(cin, stringData);
                stringDataTotal += stringData;
                next = true;
                break;
            case 2:
                next = false;
                break;
            default:
                #ifdef FR
                    cout << "Valeur entrée incorrecte" << endl;
                #endif
                #ifdef ENG
                    cout << "Value incorrect" << endl;
                #endif
                #ifdef ESP
                    cout << "Valor incorrecto" << endl;
                #endif
                break;
        }
    }
    data.setDataText(stringDataTotal);

    next = true;
    while(next)
    {
        C_DataItem dataItem;
        #ifdef FR
            cout << "Ajouter un objet à modifier ?" << endl;
            cout << "1 - Oui" << endl;
            cout << "2 - Non" << endl;
            cout << "3 - Lister les objets" << endl;
            cout << "4 - Lister les types de modifications" << endl;
        #endif
        #ifdef ENG
            cout << "Aff an object to change ?" << endl;
            cout << "1 - Yes" << endl;
            cout << "2 - No" << endl;
            cout << "3 - List objects" << endl;
            cout << "4 - List types of changes" << endl;
        #endif
        #ifdef ESP
            cout << "Añadar un objeto para cambiar ?" << endl;
            cout << "1 - Si" << endl;
            cout << "2 - No" << endl;
            cout << "3 - Listar los objetos" << endl;
            cout << "4 - Listar los typos de cambios" << endl;
        #endif
        cin >> choice;
        if(cin.fail())
        {
            choice = 0;
        }

        switch(choice)
        {
            case 1:
                #ifdef FR
                    cout << "Type de la modification :" << endl;
                #endif
                #ifdef ENG
                    cout << "Type of change" << endl;
                #endif
                #ifdef ESP
                    cout << "Typo del cambio" << endl;
                #endif
                do
                {
                    cin >> intDataStrictPos;
                    if(cin.fail() || intDataStrictPos > 1)
                    {
                        #ifdef FR
                            cout << "Valeur entrée incorrecte" << endl;
                        #endif
                        #ifdef ENG
                            cout << "Value incorrect" << endl;
                        #endif
                        #ifdef ESP
                            cout << "Valor incorrecto" << endl;
                        #endif
                        fail = true;
                    }
                    else
                    {
                        fail = false;
                    }
                } while (fail);
                dataItem.setModificationType(intDataStrictPos);

                #ifdef FR
                    cout << "Numéro de l'objet à modifier :" << endl;
                #endif
                #ifdef ENG
                    cout << "Number of the object to modify :" << endl;
                #endif
                #ifdef ESP
                    cout << "Número del objeto a modificar :" << endl;
                #endif
                do
                {
                    cin >> intDataStrictPos;
                    if(cin.fail() || intDataStrictPos >= itemTab.size())
                    {
                        #ifdef FR
                            cout << "Valeur entrée incorrecte" << endl;
                        #endif
                        #ifdef ENG
                            cout << "Value incorrect" << endl;
                        #endif
                        #ifdef ESP
                            cout << "Valor incorrecto" << endl;
                        #endif
                        fail = true;
                    }
                    else
                    {
                        fail = false;
                    }
                } while (fail);
                dataItem.setType(intDataStrictPos);

                #ifdef FR
                    cout << "Montant de la modification :" << endl;
                #endif
                #ifdef ENG
                    cout << "Modification amount" << endl;
                #endif
                #ifdef ESP
                    cout << "Cantidad de modificación" << endl;
                #endif
                do
                {
                    cin >> intData;
                    if(cin.fail())
                    {
                        #ifdef FR
                            cout << "Valeur entrée incorrecte" << endl;
                        #endif
                        #ifdef ENG
                            cout << "Value incorrect" << endl;
                        #endif
                        #ifdef ESP
                            cout << "Valor incorrecto" << endl;
                        #endif
                        fail = true;
                    }
                    else
                    {
                        fail = false;
                    }
                } while (fail);

                dataItem.setValue(intData);

                data.addItem(dataItem);
                break;
            case 2:
                next = false;
                break;
            case 3:
                #ifdef FR
                    cout << "Liste des objets du jeu :" << endl;
                #endif
                #ifdef ENG
                    cout << "Game's objects list :" << endl;
                #endif
                #ifdef ESP
                    cout << "Lista de objetos del juego :" << endl;
                #endif

                for (unsigned i = 0 ; i < itemTab.size() ; i++)
                {
                    cout << itemTab[i].getItemNum() << " - " << itemTab[i].getItemName() << endl;
                }
                cout << "********************************************" << endl;
                break;
            case 4:
                #ifdef FR
                    cout << "\t0 -> Ajouter / Retirer" << endl;
                    cout << "\t1 -> Remplacer" << endl;
                #endif
                #ifdef ENG
                    cout << "\t0 -> Add / Remove" << endl;
                    cout << "\t1 -> Replace" << endl;
                #endif
                #ifdef ESP
                    cout << "\t0 -> Añadir / Eliminar" << endl;
                    cout << "\t1 -> Reemplazar" << endl;
                #endif
                cout << "********************************************" << endl;
                break;
            default:
                #ifdef FR
                    cout << "Valeur entrée incorrecte" << endl;
                #endif
                #ifdef ENG
                    cout << "Value incorrect" << endl;
                #endif
                #ifdef ESP
                    cout << "Valor incorrecto" << endl;
                #endif
                break;
        }
    }

    next = true;
    while(next)
    {
        C_DataChoice dataChoice;
        C_DataCondition dataCondition;
        C_DataItem itemChoiceModification;
        #ifdef FR
            cout << "Ajouter un choix ?" << endl;
            cout << "1 - Oui" << endl;
            cout << "2 - Non" << endl;
        #endif
        #ifdef ENG
            cout << "Add a choice ?" << endl;
            cout << "1 - Yes" << endl;
            cout << "2 - No" << endl;
        #endif
        #ifdef ESP
            cout << "Añadar una opción ?" << endl;
            cout << "1 - Si" << endl;
            cout << "2 - No" << endl;
        #endif
        cin >> choice;
        if(cin.fail())
        {
            choice = 0;
        }

        switch(choice)
        {
            case 1:
                #ifdef FR
                    cout << "Texte du choix :" << endl;
                #endif
                #ifdef ENG
                    cout << "Choice text" << endl;
                #endif
                #ifdef ESP
                    cout << "Texto de la opción" << endl;
                #endif
                cin.ignore();
                getline(cin, stringData);
                dataChoice.setTextChoice(stringData);

                #ifdef FR
                    cout << "Destination du choix :" << endl;
                #endif
                #ifdef ENG
                    cout << "Choice destination" << endl;
                #endif
                #ifdef ESP
                    cout << "Destino de la opción" << endl;
                #endif
                do
                {
                    cin >> intData;
                    if(cin.fail())
                    {
                        #ifdef FR
                            cout << "Valeur entrée incorrecte" << endl;
                        #endif
                        #ifdef ENG
                            cout << "Value incorrect" << endl;
                        #endif
                        #ifdef ESP
                            cout << "Valor incorrecto" << endl;
                        #endif
                        fail = true;
                    }
                    else
                    {
                        fail = false;
                    }
                } while (fail);
                dataChoice.setDestChoice(intData);

                while (next)
                {
                    #ifdef FR
                        cout << "Ajouter une modification d'objet à ce choix ?" << endl;
                        cout << "1 - Oui" << endl;
                        cout << "2 - Non" << endl;
                        cout << "3 - Lister les objets" << endl;
                        cout << "4 - Lister les types de modifications" << endl;
                    #endif
                    #ifdef ENG
                        cout << "Add a change to an object at this choice ?" << endl;
                        cout << "1 - Yes" << endl;
                        cout << "2 - No" << endl;
                        cout << "3 - List objects" << endl;
                        cout << "4 - List types of changes" << endl;
                    #endif
                    #ifdef ESP
                        cout << "Añadar una modificación de objeto a esta opción ?" << endl;
                        cout << "1 - Si" << endl;
                        cout << "2 - No" << endl;
                        cout << "3 - Listar los objetos" << endl;
                        cout << "4 - Listar los typos de cambios" << endl;
                    #endif
                    cin >> choice;
                    if(cin.fail())
                    {
                        choice = 0;
                    }
                    switch(choice)
                    {
                        case 1:
                            #ifdef FR
                                cout << "Type de la modification :" << endl;
                            #endif
                            #ifdef ENG
                                cout << "Type of change" << endl;
                            #endif
                            #ifdef ESP
                                cout << "Typo del cambio" << endl;
                            #endif
                            do
                            {
                                cin >> intDataStrictPos;
                                if(cin.fail() || intDataStrictPos > 1)
                                {
                                    #ifdef FR
                                        cout << "Valeur entrée incorrecte" << endl;
                                    #endif
                                    #ifdef ENG
                                        cout << "Value incorrect" << endl;
                                    #endif
                                    #ifdef ESP
                                        cout << "Valor incorrecto" << endl;
                                    #endif
                                    fail = true;
                                }
                                else
                                {
                                    fail = false;
                                }
                            } while (fail);
                            itemChoiceModification.setModificationType(intDataStrictPos);

                            #ifdef FR
                                cout << "Type de l'objet à modifier :" << endl;
                            #endif
                            #ifdef ENG
                                cout << "Object's type to change :" << endl;
                            #endif
                            #ifdef ESP
                                cout << "Typo del objeto a cambiar :" << endl;
                            #endif
                            do
                            {
                                cin >> intDataStrictPos;
                                if(cin.fail() || intDataStrictPos >= itemTab.size())
                                {
                                    #ifdef FR
                                        cout << "Valeur entrée incorrecte" << endl;
                                    #endif
                                    #ifdef ENG
                                        cout << "Value incorrect" << endl;
                                    #endif
                                    #ifdef ESP
                                        cout << "Valor incorrecto" << endl;
                                    #endif
                                    fail = true;
                                }
                                else
                                {
                                    fail = false;
                                }
                            } while (fail);
                            itemChoiceModification.setType(intDataStrictPos);

                            #ifdef FR
                                cout << "Valeur de la modification :" << endl;
                            #endif
                            #ifdef ENG
                                cout << "Change value :" << endl;
                            #endif
                            #ifdef ESP
                                cout << "Valor del cambio :" << endl;
                            #endif
                            do
                            {
                                cin >> intData;
                                if(cin.fail())
                                {
                                    #ifdef FR
                                        cout << "Valeur entrée incorrecte" << endl;
                                    #endif
                                    #ifdef ENG
                                        cout << "Value incorrect" << endl;
                                    #endif
                                    #ifdef ESP
                                        cout << "Valor incorrecto" << endl;
                                    #endif
                                    fail = true;
                                }
                                else
                                {
                                    fail = false;
                                }
                            } while (fail);
                            itemChoiceModification.setValue(intData);

                            dataChoice.addModificationItem(itemChoiceModification);
                            break;
                        case 2:
                            next = false;
                            break;
                        case 3:
                            #ifdef FR
                                cout << "Liste des objets du jeu :" << endl;
                            #endif
                            #ifdef ENG
                                cout << "Game's objects list :" << endl;
                            #endif
                            #ifdef ESP
                                cout << "Lista de objetos del juego :" << endl;
                            #endif

                            for (unsigned i = 0 ; i < itemTab.size() ; i++)
                            {
                                cout << itemTab[i].getItemNum() << " - " << itemTab[i].getItemName() << endl;
                            }
                            cout << "********************************************" << endl;
                            break;
                        case 4:
                            #ifdef FR
                                cout << "\t0 -> Ajouter / Retirer" << endl;
                                cout << "\t1 -> Remplacer" << endl;
                            #endif
                            #ifdef ENG
                                cout << "\t0 -> Add / Remove" << endl;
                                cout << "\t1 -> Replace" << endl;
                            #endif
                            #ifdef ESP
                                cout << "\t0 -> Añadir / Eliminar" << endl;
                                cout << "\t1 -> Reemplazar" << endl;
                            #endif
                            cout << "********************************************" << endl;
                            break;
                        default:
                            #ifdef FR
                                cout << "Valeur entrée incorrecte" << endl;
                            #endif
                            #ifdef ENG
                                cout << "Value incorrect" << endl;
                            #endif
                            #ifdef ESP
                                cout << "Valor incorrecto" << endl;
                            #endif
                            break;
                    }
                }
                next = true;

                while (next)
                {
                    #ifdef FR
                        cout << "Ajouter une condition à ce choix ?" << endl;
                        cout << "1 - Oui" << endl;
                        cout << "2 - Non" << endl;
                        cout << "3 - Lister les objets" << endl;
                        cout << "4 - Lister les types de conditions" << endl;
                    #endif
                    #ifdef ENG
                        cout << "Add condition to this change ?" << endl;
                        cout << "1 - Yes" << endl;
                        cout << "2 - No" << endl;
                        cout << "3 - List objects" << endl;
                        cout << "4 - List types of changes" << endl;
                    #endif
                    #ifdef ESP
                        cout << "Añadar una condición a este cambio ?" << endl;
                        cout << "1 - Si" << endl;
                        cout << "2 - No" << endl;
                        cout << "3 - Listar los objetos" << endl;
                        cout << "4 - Listar los typos de condiciónes" << endl;
                    #endif
                    cin >> choice;
                    if(cin.fail())
                    {
                        choice = 0;
                    }
                    switch(choice)
                    {
                        case 1:
                            #ifdef FR
                                cout << "Type de la condition :" << endl;
                            #endif
                            #ifdef ENG
                                cout << "Change type :" << endl;
                            #endif
                            #ifdef ESP
                                cout << "Typo del cambio :" << endl;
                            #endif
                            do
                            {
                                cin >> intDataStrictPos;
                                if(cin.fail() || intDataStrictPos > 5)
                                {
                                    #ifdef FR
                                        cout << "Valeur entrée incorrecte" << endl;
                                    #endif
                                    #ifdef ENG
                                        cout << "Value incorrect" << endl;
                                    #endif
                                    #ifdef ESP
                                        cout << "Valor incorrecto" << endl;
                                    #endif
                                    fail = true;
                                }
                                else
                                {
                                    fail = false;
                                }
                            } while (fail);
                            dataCondition.setCondition(intDataStrictPos);

                            #ifdef FR
                                cout << "Type de l'objet de la condition :" << endl;
                            #endif
                            #ifdef ENG
                                cout << "Object's type of the change :" << endl;
                            #endif
                            #ifdef ESP
                                cout << "Typo del objeto del cambio :" << endl;
                            #endif
                            do
                            {
                                cin >> intDataStrictPos;
                                if(cin.fail() || intDataStrictPos >= itemTab.size())
                                {
                                    #ifdef FR
                                        cout << "Valeur entrée incorrecte" << endl;
                                    #endif
                                    #ifdef ENG
                                        cout << "Value incorrect" << endl;
                                    #endif
                                    #ifdef ESP
                                        cout << "Valor incorrecto" << endl;
                                    #endif
                                    fail = true;
                                }
                                else
                                {
                                    fail = false;
                                }
                            } while (fail);
                            dataCondition.setTypeItem(intDataStrictPos);

                            #ifdef FR
                                cout << "Valeur de la condition :" << endl;
                            #endif
                            #ifdef ENG
                                cout << "Condition value :" << endl;
                            #endif
                            #ifdef ESP
                                cout << "Valor de la condición :" << endl;
                            #endif
                            do
                            {
                                cin >> intData;
                                if(cin.fail())
                                {
                                    #ifdef FR
                                        cout << "Valeur entrée incorrecte" << endl;
                                    #endif
                                    #ifdef ENG
                                        cout << "Value incorrect" << endl;
                                    #endif
                                    #ifdef ESP
                                        cout << "Valor incorrecto" << endl;
                                    #endif
                                    fail = true;
                                }
                                else
                                {
                                    fail = false;
                                }
                            } while (fail);
                            dataCondition.setValue(intData);

                            dataChoice.addConditionChoice(dataCondition);
                            break;
                        case 2:
                            next = false;
                            break;
                        case 3:
                            #ifdef FR
                                cout << "Liste des objets du jeu :" << endl;
                            #endif
                            #ifdef ENG
                                cout << "Game's objects list :" << endl;
                            #endif
                            #ifdef ESP
                                cout << "Lista de objetos del juego :" << endl;
                            #endif

                            for (unsigned i = 0 ; i < itemTab.size() ; i++)
                            {
                                cout << itemTab[i].getItemNum() << " - " << itemTab[i].getItemName() << endl;
                            }
                            cout << "********************************************" << endl;
                            break;
                        case 4:
                            cout << "\t0 -> =" << endl;
                            cout << "\t1 -> !=" << endl;
                            cout << "\t2 -> >=" << endl;
                            cout << "\t3 -> >" << endl;
                            cout << "\t4 -> <=" << endl;
                            cout << "\t5 -> <" << endl;
                            cout << "********************************************" << endl;
                            break;
                        default:
                            #ifdef FR
                                cout << "Valeur entrée incorrecte" << endl;
                            #endif
                            #ifdef ENG
                                cout << "Value incorrect" << endl;
                            #endif
                            #ifdef ESP
                                cout << "Valor incorrecto" << endl;
                            #endif
                            break;
                    }
                }
                next = true;

                data.addChoice(dataChoice);
                break;
            case 2:
                next = false;
                break;
            default:
                #ifdef FR
                    cout << "Valeur entrée incorrecte" << endl;
                #endif
                #ifdef ENG
                    cout << "Value incorrect" << endl;
                #endif
                #ifdef ESP
                    cout << "Valor incorrecto" << endl;
                #endif
                break;
        }
    }

    return data;
}

C_Data changeEntries(C_Data data, vector<C_Item> itemTab)
{
    bool fail = false;
    bool boucle = true;
    bool next = true;
    unsigned int choice;
    unsigned int numModif;
    unsigned int numModifBis;
    int intData;
    unsigned int intDataStrictPos;
    string stringData;
    string stringDataTotal;
    C_DataItem dataItem;
    C_DataChoice dataChoice;
    C_DataCondition dataCondition;
    while (boucle)
    {
        cout << "********************************************" << endl;
        data.descrData(itemTab);
        cout << "********************************************" << endl;
        #ifdef FR
            cout << "Que changer ?" << endl;
            cout << "1 - Texte" << endl;
            cout << "2 - Ajouter une modification d'objet" << endl;
            cout << "3 - Editer une modification d'objet" << endl;
            cout << "4 - Supprimer la dernière modification d'objet" << endl;
            cout << "5 - Ajouter un choix" << endl;
            cout << "6 - Editer un choix" << endl;
            cout << "7 - Supprimer le dernier choix" << endl;
            cout << "8 - Rien" << endl;
        #endif
        #ifdef ENG
            cout << "What to modify ?" << endl;
            cout << "1 - Text" << endl;
            cout << "2 - Add object change" << endl;
            cout << "3 - Edit object change" << endl;
            cout << "4 - Delete last object change" << endl;
            cout << "5 - add choice" << endl;
            cout << "6 - Edit choice" << endl;
            cout << "7 - Delete last choice" << endl;
            cout << "8 - Nothing" << endl;
        #endif
        #ifdef ESP
            cout << "¿ Que cambiar ?" << endl;
            cout << "1 - Texto" << endl;
            cout << "2 - Añadar un cambio de objeto" << endl;
            cout << "3 - Editar un cambio de objeto" << endl;
            cout << "4 - Eliminar el último  cambio de objeto" << endl;
            cout << "5 - Añadar una opción" << endl;
            cout << "6 - Editar una opción" << endl;
            cout << "7 - Eliminar la última opción" << endl;
            cout << "8 - Nada" << endl;
        #endif
        cin >> choice;
        if(cin.fail())
        {
            choice = 0;
        }
        switch(choice)
        {
            case 1:
                cout << "********************************************" << endl;
                #ifdef FR
                    cout << "Inserer le texte :" << endl;
                #endif
                #ifdef ENG
                    cout << "Insert text :" << endl;
                #endif
                #ifdef ESP
                    cout << "Insertar texto :" << endl;
                #endif
                cin.ignore();
                getline(cin, stringData);
                stringDataTotal += stringData;

                while(next)
                {
                    #ifdef FR
                        cout << "Ajouter un paragraphe ?" << endl;
                        cout << "1 - Oui" << endl;
                        cout << "2 - Non" << endl;
                    #endif
                    #ifdef ENG
                        cout << "Add paragraph ?" << endl;
                        cout << "1 - Yes" << endl;
                        cout << "2 - No" << endl;
                    #endif
                    #ifdef ESP
                        cout << "¿ Añadar un párrafo ?" << endl;
                        cout << "1 - Si" << endl;
                        cout << "2 - No" << endl;
                    #endif
                    cin >> choice;
                    if(cin.fail())
                    {
                        choice = 0;
                    }
                    switch(choice)
                    {
                        case 1:
                            stringDataTotal += "\n";
                            cout << "********************************************" << endl;
                            #ifdef FR
                                cout << "Inserer le texte :" << endl;
                            #endif
                            #ifdef ENG
                                cout << "Insert text :" << endl;
                            #endif
                            #ifdef ESP
                                cout << "Insertar texto :" << endl;
                            #endif
                            cin.ignore();
                            getline(cin, stringData);
                            stringDataTotal += stringData;
                            next = true;
                            break;
                        case 2:
                            next = false;
                            break;
                        default:
                            #ifdef FR
                                cout << "Valeur entrée incorrecte" << endl;
                            #endif
                            #ifdef ENG
                                cout << "Value incorrect" << endl;
                            #endif
                            #ifdef ESP
                                cout << "Valor incorrecto" << endl;
                            #endif
                            break;
                    }
                }
                data.setDataText(stringDataTotal);
                break;
            case 2:
                do
                {
                    cout << "***" << endl;
                    #ifdef FR
                        cout << "Que faire ?" << endl;
                        cout << "1 - Ajouter" << endl;
                        cout << "2 - Lister les objets" << endl;
                        cout << "3 - Lister les types de conditions" << endl;
                    #endif
                    #ifdef ENG
                        cout << "What to do ?" << endl;
                        cout << "1 - Add" << endl;
                        cout << "2 - List objects" << endl;
                        cout << "3 - List types of changes" << endl;
                    #endif
                    #ifdef ESP
                        cout << "¿ Qué quieres hacer ?" << endl;
                        cout << "1 - Añadar" << endl;
                        cout << "2 - Listar los objetos" << endl;
                        cout << "3 - Listar los typos de cambios" << endl;
                    #endif
                    cin >> choice;
                    if(cin.fail())
                    {
                        choice = 0;
                    }

                    switch(choice)
                    {
                        case 1:
                            #ifdef FR
                                cout << "Type de la modification :" << endl;
                            #endif
                            #ifdef ENG
                                cout << "Type of change" << endl;
                            #endif
                            #ifdef ESP
                                cout << "Typo del cambio" << endl;
                            #endif
                            do
                            {
                                cin >> intDataStrictPos;
                                if(cin.fail() || intDataStrictPos > 1)
                                {
                                    #ifdef FR
                                        cout << "Valeur entrée incorrecte" << endl;
                                    #endif
                                    #ifdef ENG
                                        cout << "Value incorrect" << endl;
                                    #endif
                                    #ifdef ESP
                                        cout << "Valor incorrecto" << endl;
                                    #endif
                                    fail = true;
                                }
                                else
                                {
                                    fail = false;
                                }
                            } while (fail);
                            dataItem.setModificationType(intDataStrictPos);

                            #ifdef FR
                                cout << "Numéro de l'objet à modifier :" << endl;
                            #endif
                            #ifdef ENG
                                cout << "Number of the object to modify :" << endl;
                            #endif
                            #ifdef ESP
                                cout << "Número del objeto a modificar :" << endl;
                            #endif
                            do
                            {
                                cin >> intDataStrictPos;
                                if(cin.fail() || intDataStrictPos >= itemTab.size())
                                {
                                    #ifdef FR
                                        cout << "Valeur entrée incorrecte" << endl;
                                    #endif
                                    #ifdef ENG
                                        cout << "Value incorrect" << endl;
                                    #endif
                                    #ifdef ESP
                                        cout << "Valor incorrecto" << endl;
                                    #endif
                                    fail = true;
                                }
                                else
                                {
                                    fail = false;
                                }
                            } while (fail);
                            dataItem.setType(intDataStrictPos);

                            #ifdef FR
                                cout << "Montant de la modification :" << endl;
                            #endif
                            #ifdef ENG
                                cout << "Modification amount" << endl;
                            #endif
                            #ifdef ESP
                                cout << "Cantidad de modificación" << endl;
                            #endif
                            do
                            {
                                cin >> intData;
                                if(cin.fail())
                                {
                                    #ifdef FR
                                        cout << "Valeur entrée incorrecte" << endl;
                                    #endif
                                    #ifdef ENG
                                        cout << "Value incorrect" << endl;
                                    #endif
                                    #ifdef ESP
                                        cout << "Valor incorrecto" << endl;
                                    #endif
                                    fail = true;
                                }
                                else
                                {
                                    fail = false;
                                }
                            } while (fail);

                            dataItem.setValue(intData);
                            fail = false;
                            break;
                        case 2:
                            #ifdef FR
                                cout << "Liste des objets du jeu :" << endl;
                            #endif
                            #ifdef ENG
                                cout << "Game's objects list :" << endl;
                            #endif
                            #ifdef ESP
                                cout << "Lista de objetos del juego :" << endl;
                            #endif

                            for (unsigned i = 0 ; i < itemTab.size() ; i++)
                            {
                                cout << itemTab[i].getItemNum() << " - " << itemTab[i].getItemName() << endl;
                            }
                            cout << "********************************************" << endl;
                            break;
                        case 3:
                            #ifdef FR
                                cout << "\t0 -> Ajouter / Retirer" << endl;
                                cout << "\t1 -> Remplacer" << endl;
                            #endif
                            #ifdef ENG
                                cout << "\t0 -> Add / Remove" << endl;
                                cout << "\t1 -> Replace" << endl;
                            #endif
                            #ifdef ESP
                                cout << "\t0 -> Añadir / Eliminar" << endl;
                                cout << "\t1 -> Reemplazar" << endl;
                            #endif
                            cout << "********************************************" << endl;
                            break;
                        default:
                            #ifdef FR
                                cout << "Valeur entrée incorrecte" << endl;
                            #endif
                            #ifdef ENG
                                cout << "Value incorrect" << endl;
                            #endif
                            #ifdef ESP
                                cout << "Valor incorrecto" << endl;
                            #endif
                            break;
                    }
                } while(fail);
                data.addItem(dataItem);
                break;
            case 3:
                if (data.getItemModification().size() != 0)
                {
                    #ifdef FR
                        cout << "Inserer le numéro de la modification :" << endl;
                    #endif
                    #ifdef ENG
                        cout << "Insert change number :" << endl;
                    #endif
                    #ifdef ESP
                        cout << "Insertar el número del cambio :" << endl;
                    #endif
                    do
                    {
                        cin >> numModif;
                        if(cin.fail() || numModif >= data.getItemModification().size())
                        {
                            #ifdef FR
                                cout << "Valeur entrée incorrecte" << endl;
                            #endif
                            #ifdef ENG
                                cout << "Value incorrect" << endl;
                            #endif
                            #ifdef ESP
                                cout << "Valor incorrecto" << endl;
                            #endif
                            fail = true;
                        }
                        else
                        {
                            fail = true;
                            while (fail)
                            {
                                cout << "***" << endl;
                                #ifdef FR
                                    cout << "Que faire ?" << endl;
                                    cout << "1 - Modifier" << endl;
                                    cout << "2 - Lister les objets" << endl;
                                    cout << "3 - Lister les types de conditions" << endl;
                                #endif
                                #ifdef ENG
                                    cout << "What to do ?" << endl;
                                    cout << "1 - Edit" << endl;
                                    cout << "2 - List objects" << endl;
                                    cout << "3 - List types of changes" << endl;
                                #endif
                                #ifdef ESP
                                    cout << "¿ Qué quieres hacer ?" << endl;
                                    cout << "1 - Editar" << endl;
                                    cout << "2 - Listar los objetos" << endl;
                                    cout << "3 - Listar los typos de cambios" << endl;
                                #endif
                                cin >> choice;
                                if(cin.fail())
                                {
                                    choice = 0;
                                }

                                switch(choice)
                                {
                                    case 1:
                                        #ifdef FR
                                            cout << "Type de la modification :" << endl;
                                        #endif
                                        #ifdef ENG
                                            cout << "Type of change" << endl;
                                        #endif
                                        #ifdef ESP
                                            cout << "Typo del cambio" << endl;
                                        #endif
                                        do
                                        {
                                            cin >> intDataStrictPos;
                                            if(cin.fail() || intDataStrictPos > 1)
                                            {
                                                #ifdef FR
                                                    cout << "Valeur entrée incorrecte" << endl;
                                                #endif
                                                #ifdef ENG
                                                    cout << "Value incorrect" << endl;
                                                #endif
                                                #ifdef ESP
                                                    cout << "Valor incorrecto" << endl;
                                                #endif
                                                fail = true;
                                            }
                                            else
                                            {
                                                fail = false;
                                            }
                                        } while (fail);
                                        dataItem.setModificationType(intDataStrictPos);

                                        #ifdef FR
                                            cout << "Numéro de l'objet à modifier :" << endl;
                                        #endif
                                        #ifdef ENG
                                            cout << "Number of the object to modify :" << endl;
                                        #endif
                                        #ifdef ESP
                                            cout << "Número del objeto a modificar :" << endl;
                                        #endif
                                        do
                                        {
                                            cin >> intDataStrictPos;
                                            if(cin.fail() || intDataStrictPos >= itemTab.size())
                                            {
                                                #ifdef FR
                                                    cout << "Valeur entrée incorrecte" << endl;
                                                #endif
                                                #ifdef ENG
                                                    cout << "Value incorrect" << endl;
                                                #endif
                                                #ifdef ESP
                                                    cout << "Valor incorrecto" << endl;
                                                #endif
                                                fail = true;
                                            }
                                            else
                                            {
                                                fail = false;
                                            }
                                        } while (fail);
                                        dataItem.setType(intDataStrictPos);

                                        #ifdef FR
                                            cout << "Montant de la modification :" << endl;
                                        #endif
                                        #ifdef ENG
                                            cout << "Modification amount" << endl;
                                        #endif
                                        #ifdef ESP
                                            cout << "Cantidad de modificación" << endl;
                                        #endif
                                        do
                                        {
                                            cin >> intData;
                                            if(cin.fail())
                                            {
                                                #ifdef FR
                                                    cout << "Valeur entrée incorrecte" << endl;
                                                #endif
                                                #ifdef ENG
                                                    cout << "Value incorrect" << endl;
                                                #endif
                                                #ifdef ESP
                                                    cout << "Valor incorrecto" << endl;
                                                #endif
                                                fail = true;
                                            }
                                            else
                                            {
                                                fail = false;
                                            }
                                        } while (fail);

                                        dataItem.setValue(intData);
                                        break;
                                    case 2:
                                        #ifdef FR
                                            cout << "Liste des objets du jeu :" << endl;
                                        #endif
                                        #ifdef ENG
                                            cout << "Game's objects list :" << endl;
                                        #endif
                                        #ifdef ESP
                                            cout << "Lista de objetos del juego :" << endl;
                                        #endif

                                        for (unsigned i = 0 ; i < itemTab.size() ; i++)
                                        {
                                            cout << itemTab[i].getItemNum() << " - " << itemTab[i].getItemName() << endl;
                                        }
                                        cout << "********************************************" << endl;
                                        break;
                                    case 3:
                                        #ifdef FR
                                            cout << "\t0 -> Ajouter / Retirer" << endl;
                                            cout << "\t1 -> Remplacer" << endl;
                                        #endif
                                        #ifdef ENG
                                            cout << "\t0 -> Add / Remove" << endl;
                                            cout << "\t1 -> Replace" << endl;
                                        #endif
                                        #ifdef ESP
                                            cout << "\t0 -> Añadir / Eliminar" << endl;
                                            cout << "\t1 -> Reemplazar" << endl;
                                        #endif
                                        cout << "********************************************" << endl;
                                        break;
                                    default:
                                        #ifdef FR
                                            cout << "Valeur entrée incorrecte" << endl;
                                        #endif
                                        #ifdef ENG
                                            cout << "Value incorrect" << endl;
                                        #endif
                                        #ifdef ESP
                                            cout << "Valor incorrecto" << endl;
                                        #endif
                                        break;
                                }
                            }
                            fail = false;
                        }
                    } while (fail);
                    data.changeItem(dataItem, numModif);
                }
                else
                {
                    #ifdef FR
                        cout << "Il n'y a pas de modification d'objet à modifier." << endl;
                    #endif
                    #ifdef ENG
                        cout << "There's no change to do." << endl;
                    #endif
                    #ifdef ESP
                        cout << "No se pueden realizar cambios." << endl;
                    #endif
                }
                break;
            case 4:
                if (data.getItemModification().size() == 0)
                {
                    #ifdef FR
                        cout << "Il n'y a rien à supprimer." << endl;
                    #endif
                    #ifdef ENG
                        cout << "There's nothing to delete." << endl;
                    #endif
                    #ifdef ESP
                        cout << "No hay nada que borrar" << endl;
                    #endif
                }
                else
                {
                    data.eraseItem();
                }
                break;
            case 5:
                cout << "***" << endl;
                #ifdef FR
                    cout << "Texte du choix :" << endl;
                #endif
                #ifdef ENG
                    cout << "Choice text" << endl;
                #endif
                #ifdef ESP
                    cout << "Texto de la opción" << endl;
                #endif
                cin.ignore();
                getline(cin, stringData);
                dataChoice.setTextChoice(stringData);

                #ifdef FR
                    cout << "Destination du choix :" << endl;
                #endif
                #ifdef ENG
                    cout << "Choice destination" << endl;
                #endif
                #ifdef ESP
                    cout << "Destino de la opción" << endl;
                #endif
                do
                {
                    cin >> intData;
                    if(cin.fail())
                    {
                        #ifdef FR
                            cout << "Valeur entrée incorrecte" << endl;
                        #endif
                        #ifdef ENG
                            cout << "Value incorrect" << endl;
                        #endif
                        #ifdef ESP
                            cout << "Valor incorrecto" << endl;
                        #endif
                        fail = true;
                    }
                    else
                    {
                        fail = false;
                    }
                } while (fail);
                dataChoice.setDestChoice(intData);

                while (next)
                {
                    #ifdef FR
                        cout << "Ajouter une modification d'objet à ce choix ?" << endl;
                        cout << "1 - Oui" << endl;
                        cout << "2 - Non" << endl;
                        cout << "3 - Lister les objets" << endl;
                        cout << "4 - Lister les types de modifications" << endl;
                    #endif
                    #ifdef ENG
                        cout << "Add a change to an object at this choice ?" << endl;
                        cout << "1 - Yes" << endl;
                        cout << "2 - No" << endl;
                        cout << "3 - List objects" << endl;
                        cout << "4 - List types of changes" << endl;
                    #endif
                    #ifdef ESP
                        cout << "Añadar una modificación de objeto a esta opción ?" << endl;
                        cout << "1 - Si" << endl;
                        cout << "2 - No" << endl;
                        cout << "3 - Listar los objetos" << endl;
                        cout << "4 - Listar los typos de cambios" << endl;
                    #endif
                    cin >> choice;
                    if(cin.fail())
                    {
                        choice = 0;
                    }
                    switch(choice)
                    {
                        case 1:
                            #ifdef FR
                                cout << "Type de la modification :" << endl;
                            #endif
                            #ifdef ENG
                                cout << "Type of change" << endl;
                            #endif
                            #ifdef ESP
                                cout << "Typo del cambio" << endl;
                            #endif
                            do
                            {
                                cin >> intDataStrictPos;
                                if(cin.fail() || intDataStrictPos > 1)
                                {
                                    #ifdef FR
                                        cout << "Valeur entrée incorrecte" << endl;
                                    #endif
                                    #ifdef ENG
                                        cout << "Value incorrect" << endl;
                                    #endif
                                    #ifdef ESP
                                        cout << "Valor incorrecto" << endl;
                                    #endif
                                    fail = true;
                                }
                                else
                                {
                                    fail = false;
                                }
                            } while (fail);
                            dataItem.setModificationType(intDataStrictPos);

                            #ifdef FR
                                cout << "Type de l'objet à modifier :" << endl;
                            #endif
                            #ifdef ENG
                                cout << "Object's type to change :" << endl;
                            #endif
                            #ifdef ESP
                                cout << "Typo del objeto a cambiar :" << endl;
                            #endif
                            do
                            {
                                cin >> intDataStrictPos;
                                if(cin.fail() || intDataStrictPos >= itemTab.size())
                                {
                                    #ifdef FR
                                        cout << "Valeur entrée incorrecte" << endl;
                                    #endif
                                    #ifdef ENG
                                        cout << "Value incorrect" << endl;
                                    #endif
                                    #ifdef ESP
                                        cout << "Valor incorrecto" << endl;
                                    #endif
                                    fail = true;
                                }
                                else
                                {
                                    fail = false;
                                }
                            } while (fail);
                            dataItem.setType(intDataStrictPos);

                            #ifdef FR
                                cout << "Valeur de la modification :" << endl;
                            #endif
                            #ifdef ENG
                                cout << "Change value :" << endl;
                            #endif
                            #ifdef ESP
                                cout << "Valor del cambio :" << endl;
                            #endif
                            do
                            {
                                cin >> intData;
                                if(cin.fail())
                                {
                                    #ifdef FR
                                        cout << "Valeur entrée incorrecte" << endl;
                                    #endif
                                    #ifdef ENG
                                        cout << "Value incorrect" << endl;
                                    #endif
                                    #ifdef ESP
                                        cout << "Valor incorrecto" << endl;
                                    #endif
                                    fail = true;
                                }
                                else
                                {
                                    fail = false;
                                }
                            } while (fail);
                            dataItem.setValue(intData);

                            dataChoice.addModificationItem(dataItem);
                            break;
                        case 2:
                            next = false;
                            break;
                        case 3:
                           #ifdef FR
                                cout << "Liste des objets du jeu :" << endl;
                            #endif
                            #ifdef ENG
                                cout << "Game's objects list :" << endl;
                            #endif
                            #ifdef ESP
                                cout << "Lista de objetos del juego :" << endl;
                            #endif

                            for (unsigned i = 0 ; i < itemTab.size() ; i++)
                            {
                                cout << itemTab[i].getItemNum() << " - " << itemTab[i].getItemName() << endl;
                            }
                            cout << "********************************************" << endl;
                            break;
                        case 4:
                            #ifdef FR
                                cout << "\t0 -> Ajouter / Retirer" << endl;
                                cout << "\t1 -> Remplacer" << endl;
                            #endif
                            #ifdef ENG
                                cout << "\t0 -> Add / Remove" << endl;
                                cout << "\t1 -> Replace" << endl;
                            #endif
                            #ifdef ESP
                                cout << "\t0 -> Añadir / Eliminar" << endl;
                                cout << "\t1 -> Reemplazar" << endl;
                            #endif
                            cout << "********************************************" << endl;
                            break;
                        default:
                            #ifdef FR
                                cout << "Valeur entrée incorrecte" << endl;
                            #endif
                            #ifdef ENG
                                cout << "Value incorrect" << endl;
                            #endif
                            #ifdef ESP
                                cout << "Valor incorrecto" << endl;
                            #endif
                            break;
                    }
                }
                next = true;

                while (next)
                {
                    #ifdef FR
                        cout << "Ajouter une condition à ce choix ?" << endl;
                        cout << "1 - Oui" << endl;
                        cout << "2 - Non" << endl;
                        cout << "3 - Lister les objets" << endl;
                        cout << "4 - Lister les types de conditions" << endl;
                    #endif
                    #ifdef ENG
                        cout << "Add condition to this change ?" << endl;
                        cout << "1 - Yes" << endl;
                        cout << "2 - No" << endl;
                        cout << "3 - List objects" << endl;
                        cout << "4 - List types of changes" << endl;
                    #endif
                    #ifdef ESP
                        cout << "Añadar una condición a este cambio ?" << endl;
                        cout << "1 - Si" << endl;
                        cout << "2 - No" << endl;
                        cout << "3 - Listar los objetos" << endl;
                        cout << "4 - Listar los typos de condiciónes" << endl;
                    #endif
                    cin >> choice;
                    if(cin.fail())
                    {
                        choice = 0;
                    }
                    switch(choice)
                    {
                        case 1:
                            #ifdef FR
                                cout << "Type de la condition :" << endl;
                            #endif
                            #ifdef ENG
                                cout << "Change type :" << endl;
                            #endif
                            #ifdef ESP
                                cout << "Typo del cambio :" << endl;
                            #endif
                            do
                            {
                                cin >> intDataStrictPos;
                                if(cin.fail() || intDataStrictPos > 5)
                                {
                                    #ifdef FR
                                        cout << "Valeur entrée incorrecte" << endl;
                                    #endif
                                    #ifdef ENG
                                        cout << "Value incorrect" << endl;
                                    #endif
                                    #ifdef ESP
                                        cout << "Valor incorrecto" << endl;
                                    #endif
                                    fail = true;
                                }
                                else
                                {
                                    fail = false;
                                }
                            } while (fail);
                            dataCondition.setCondition(intDataStrictPos);

                            #ifdef FR
                                cout << "Type de l'objet de la condition :" << endl;
                            #endif
                            #ifdef ENG
                                cout << "Object's type of the change :" << endl;
                            #endif
                            #ifdef ESP
                                cout << "Typo del objeto del cambio :" << endl;
                            #endif
                            do
                            {
                                cin >> intDataStrictPos;
                                if(cin.fail() || intDataStrictPos >= itemTab.size())
                                {
                                    #ifdef FR
                                        cout << "Valeur entrée incorrecte" << endl;
                                    #endif
                                    #ifdef ENG
                                        cout << "Value incorrect" << endl;
                                    #endif
                                    #ifdef ESP
                                        cout << "Valor incorrecto" << endl;
                                    #endif
                                    fail = true;
                                }
                                else
                                {
                                    fail = false;
                                }
                            } while (fail);
                            dataCondition.setTypeItem(intDataStrictPos);

                            #ifdef FR
                                cout << "Valeur de la condition :" << endl;
                            #endif
                            #ifdef ENG
                                cout << "Condition value :" << endl;
                            #endif
                            #ifdef ESP
                                cout << "Valor de la condición :" << endl;
                            #endif
                            do
                            {
                                cin >> intData;
                                if(cin.fail())
                                {
                                    #ifdef FR
                                        cout << "Valeur entrée incorrecte" << endl;
                                    #endif
                                    #ifdef ENG
                                        cout << "Value incorrect" << endl;
                                    #endif
                                    #ifdef ESP
                                        cout << "Valor incorrecto" << endl;
                                    #endif
                                    fail = true;
                                }
                                else
                                {
                                    fail = false;
                                }
                            } while (fail);
                            dataCondition.setValue(intData);

                            dataChoice.addConditionChoice(dataCondition);
                            break;
                        case 2:
                            next = false;
                            break;
                        case 3:
                            #ifdef FR
                                cout << "Liste des objets du jeu :" << endl;
                            #endif
                            #ifdef ENG
                                cout << "Game's objects list :" << endl;
                            #endif
                            #ifdef ESP
                                cout << "Lista de objetos del juego :" << endl;
                            #endif

                            for (unsigned i = 0 ; i < itemTab.size() ; i++)
                            {
                                cout << itemTab[i].getItemNum() << " - " << itemTab[i].getItemName() << endl;
                            }
                            cout << "********************************************" << endl;
                            break;
                        case 4:
                            cout << "\t0 -> =" << endl;
                            cout << "\t1 -> !=" << endl;
                            cout << "\t2 -> >=" << endl;
                            cout << "\t3 -> >" << endl;
                            cout << "\t4 -> <=" << endl;
                            cout << "\t5 -> <" << endl;
                            cout << "********************************************" << endl;
                            break;
                        default:
                            #ifdef FR
                                cout << "Valeur entrée incorrecte" << endl;
                            #endif
                            #ifdef ENG
                                cout << "Value incorrect" << endl;
                            #endif
                            #ifdef ESP
                                cout << "Valor incorrecto" << endl;
                            #endif
                            break;
                    }
                }
                next = true;

                data.addChoice(dataChoice);
                break;
            case 6:
                if (data.getChoice().size() != 0)
                {
                    #ifdef FR
                        cout << "Inserer le numéro de la modification :" << endl;
                    #endif
                    #ifdef ENG
                        cout << "Insert change number :" << endl;
                    #endif
                    #ifdef ESP
                        cout << "Insertar el número del cambio :" << endl;
                    #endif
                    do
                    {
                        cin >> numModif;
                        if(cin.fail() || numModif == 0 || numModif > data.getChoice().size())
                        {
                            #ifdef FR
                                cout << "Valeur entrée incorrecte" << endl;
                            #endif
                            #ifdef ENG
                                cout << "Value incorrect" << endl;
                            #endif
                            #ifdef ESP
                                cout << "Valor incorrecto" << endl;
                            #endif
                            fail = true;
                        }
                        else
                        {
                            numModif -= 1;
                            fail = true;
                            while (fail)
                            {
                                dataChoice = data.getChoice()[numModif];
                                cout << "********************************************" << endl;
                                cout << dataChoice.getTextChoice() << endl;
                                #ifdef FR
                                    cout << "Destination : " << dataChoice.getDestChoice() << endl;
                                #endif
                                #ifdef ENG
                                    cout << "Destination : " << dataChoice.getDestChoice() << endl;
                                #endif
                                #ifdef ESP
                                    cout << "Destino : " << dataChoice.getDestChoice() << endl;
                                #endif
                                cout << "*****" << endl;
                                if (dataChoice.getSizeCondition() != 0)
                                {
                                    #ifdef FR
                                        cout << "Conditions du choix :" << endl;
                                    #endif
                                    #ifdef ENG
                                        cout << "Conditions of this choice :" << endl;
                                    #endif
                                    #ifdef ESP
                                        cout << "Condiciones de la opción :" << endl;
                                    #endif
                                    for (unsigned int i = 0 ; i < dataChoice.getSizeCondition() ; i++)
                                    {
                                        cout << "\t_ " << i << " -> " << itemTab[dataChoice.getCondition(i).getTypeItem()].getItemName();
                                        switch(dataChoice.getCondition(i).getCondition())
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
                                        cout << dataChoice.getCondition(i).getValue() << endl;
                                    }
                                }
                                if (dataChoice.getSizeModification() != 0)
                                {
                                    cout << "*****" << endl;
                                    #ifdef FR
                                        cout << "Objets modifiés par le choix : " << endl;
                                    #endif
                                    #ifdef ENG
                                        cout << "Objects changed by this choice : " << endl;
                                    #endif
                                    #ifdef ESP
                                        cout << "Objetos cambiados par la opción : " << endl;
                                    #endif
                                    for (unsigned int i = 0 ; i < dataChoice.getSizeModification() ; i++)
                                    {
                                        cout << "\t_ " << i << " -> " << itemTab[dataChoice.getModification(i).getType()].getItemName() << " : ";
                                        if (dataChoice.getModification(i).getModificationType() == 0)
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
                                        cout << dataChoice.getModification(i).getValue() << endl;
                                    }
                                }
                                #ifdef FR
                                    cout << "***" << endl;
                                    cout << "Que faire ?" << endl;
                                    cout << "1 - Changer le texte" << endl;
                                    cout << "2 - Changer la destination" << endl;
                                    cout << "3 - Changer les modifications" << endl;
                                    cout << "4 - Changer les conditions" << endl;
                                    cout << "5 - Retour" << endl;
                                #endif
                                #ifdef ENG
                                    cout << "***" << endl;
                                    cout << "What to do ?" << endl;
                                    cout << "1 - Change text" << endl;
                                    cout << "2 - Change destination" << endl;
                                    cout << "3 - Change modifications" << endl;
                                    cout << "4 - Change conditions" << endl;
                                    cout << "5 - Retour" << endl;
                                #endif
                                #ifdef ESP
                                    cout << "***" << endl;
                                    cout << "¿ Qué quieres hacer ?" << endl;
                                    cout << "1 - Cambiar texto" << endl;
                                    cout << "2 - Cambiar destination" << endl;
                                    cout << "3 - Cambiar cambios" << endl;
                                    cout << "4 - Cambiar condiciones" << endl;
                                    cout << "5 - Retour" << endl;
                                #endif
                                cin >> choice;
                                if(cin.fail())
                                {
                                    choice = 0;
                                }
                                switch(choice)
                                {
                                    case 1:
                                        #ifdef FR
                                            cout << "Texte du choix :" << endl;
                                        #endif
                                        #ifdef ENG
                                            cout << "Choice text" << endl;
                                        #endif
                                        #ifdef ESP
                                            cout << "Texto de la opción" << endl;
                                        #endif
                                        cin.ignore();
                                        getline(cin, stringData);
                                        dataChoice.setTextChoice(stringData);
                                        data.changeChoice(dataChoice, numModif);
                                        break;
                                    case 2:
                                        #ifdef FR
                                            cout << "Destination du choix :" << endl;
                                        #endif
                                        #ifdef ENG
                                            cout << "Choice destination" << endl;
                                        #endif
                                        #ifdef ESP
                                            cout << "Destino de la opción" << endl;
                                        #endif
                                        do
                                        {
                                            cin >> intData;
                                            if(cin.fail())
                                            {
                                                #ifdef FR
                                                    cout << "Valeur entrée incorrecte" << endl;
                                                #endif
                                                #ifdef ENG
                                                    cout << "Value incorrect" << endl;
                                                #endif
                                                #ifdef ESP
                                                    cout << "Valor incorrecto" << endl;
                                                #endif
                                                fail = true;
                                            }
                                            else
                                            {
                                                fail = false;
                                            }
                                        } while (fail);
                                        dataChoice.setDestChoice(intData);
                                        data.changeChoice(dataChoice, numModif);
                                        break;
                                    case 3:
                                        boucle = true;
                                        while (boucle)
                                        {
                                            cout << "***" << endl;
                                            #ifdef FR
                                                cout << "Que faire ?" << endl;
                                                cout << "1 - Ajouter une modification d'objet" << endl;
                                                cout << "2 - Editer une modification d'objet" << endl;
                                                cout << "3 - Supprimer la dernière modification d'objet" << endl;
                                            #endif
                                            #ifdef ENG
                                                cout << "What to do ?" << endl;
                                                cout << "1 - Add object change" << endl;
                                                cout << "2 - Edit object change" << endl;
                                                cout << "3 - Delete last object change" << endl;
                                            #endif
                                            #ifdef ESP
                                                cout << "¿ Qué quieres hacer ?" << endl;
                                                cout << "1 - Añadar un cambio de objeto" << endl;
                                                cout << "2 - Editar un cambio de objeto" << endl;
                                                cout << "3 - Eliminar el último  cambio de objeto" << endl;
                                            #endif
                                            cin >> choice;
                                            if(cin.fail())
                                            {
                                                choice = 0;
                                            }
                                            switch(choice)
                                            {
                                                case 1:
                                                    do
                                                    {
                                                        cout << "***" << endl;
                                                        #ifdef FR
                                                            cout << "Que faire ?" << endl;
                                                            cout << "1 - Ajouter" << endl;
                                                            cout << "2 - Lister les objets" << endl;
                                                            cout << "3 - Lister les types de conditions" << endl;
                                                        #endif
                                                        #ifdef ENG
                                                            cout << "What to do ?" << endl;
                                                            cout << "1 - Add" << endl;
                                                            cout << "2 - List objects" << endl;
                                                            cout << "3 - List types of changes" << endl;
                                                        #endif
                                                        #ifdef ESP
                                                            cout << "¿ Qué quieres hacer ?" << endl;
                                                            cout << "1 - Añadar" << endl;
                                                            cout << "2 - Listar los objetos" << endl;
                                                            cout << "3 - Listar los typos de cambios" << endl;
                                                        #endif
                                                        cin >> choice;
                                                        if(cin.fail())
                                                        {
                                                            choice = 0;
                                                        }

                                                        switch(choice)
                                                        {
                                                            case 1:
                                                                #ifdef FR
                                                                    cout << "Type de la modification :" << endl;
                                                                #endif
                                                                #ifdef ENG
                                                                    cout << "Type of change" << endl;
                                                                #endif
                                                                #ifdef ESP
                                                                    cout << "Typo del cambio" << endl;
                                                                #endif
                                                                do
                                                                {
                                                                    cin >> intDataStrictPos;
                                                                    if(cin.fail() || intDataStrictPos > 1)
                                                                    {
                                                                        #ifdef FR
                                                                            cout << "Valeur entrée incorrecte" << endl;
                                                                        #endif
                                                                        #ifdef ENG
                                                                            cout << "Value incorrect" << endl;
                                                                        #endif
                                                                        #ifdef ESP
                                                                            cout << "Valor incorrecto" << endl;
                                                                        #endif
                                                                        fail = true;
                                                                    }
                                                                    else
                                                                    {
                                                                        fail = false;
                                                                    }
                                                                } while (fail);
                                                                dataItem.setModificationType(intDataStrictPos);

                                                                #ifdef FR
                                                                    cout << "Numéro de l'objet à modifier :" << endl;
                                                                #endif
                                                                #ifdef ENG
                                                                    cout << "Number of the object to modify :" << endl;
                                                                #endif
                                                                #ifdef ESP
                                                                    cout << "Número del objeto a modificar :" << endl;
                                                                #endif
                                                                do
                                                                {
                                                                    cin >> intDataStrictPos;
                                                                    if(cin.fail() || intDataStrictPos >= itemTab.size())
                                                                    {
                                                                        #ifdef FR
                                                                            cout << "Valeur entrée incorrecte" << endl;
                                                                        #endif
                                                                        #ifdef ENG
                                                                            cout << "Value incorrect" << endl;
                                                                        #endif
                                                                        #ifdef ESP
                                                                            cout << "Valor incorrecto" << endl;
                                                                        #endif
                                                                        fail = true;
                                                                    }
                                                                    else
                                                                    {
                                                                        fail = false;
                                                                    }
                                                                } while (fail);
                                                                dataItem.setType(intDataStrictPos);

                                                                #ifdef FR
                                                                    cout << "Montant de la modification :" << endl;
                                                                #endif
                                                                #ifdef ENG
                                                                    cout << "Modification amount" << endl;
                                                                #endif
                                                                #ifdef ESP
                                                                    cout << "Cantidad de modificación" << endl;
                                                                #endif
                                                                do
                                                                {
                                                                    cin >> intData;
                                                                    if(cin.fail())
                                                                    {
                                                                        #ifdef FR
                                                                            cout << "Valeur entrée incorrecte" << endl;
                                                                        #endif
                                                                        #ifdef ENG
                                                                            cout << "Value incorrect" << endl;
                                                                        #endif
                                                                        #ifdef ESP
                                                                            cout << "Valor incorrecto" << endl;
                                                                        #endif
                                                                        fail = true;
                                                                    }
                                                                    else
                                                                    {
                                                                        fail = false;
                                                                    }
                                                                } while (fail);

                                                                dataItem.setValue(intData);
                                                                fail = false;
                                                                break;
                                                            case 2:
                                                                #ifdef FR
                                                                    cout << "Liste des objets du jeu :" << endl;
                                                                #endif
                                                                #ifdef ENG
                                                                    cout << "Game's objects list :" << endl;
                                                                #endif
                                                                #ifdef ESP
                                                                    cout << "Lista de objetos del juego :" << endl;
                                                                #endif

                                                                for (unsigned i = 0 ; i < itemTab.size() ; i++)
                                                                {
                                                                    cout << itemTab[i].getItemNum() << " - " << itemTab[i].getItemName() << endl;
                                                                }
                                                                cout << "********************************************" << endl;
                                                                break;
                                                            case 3:
                                                                #ifdef FR
                                                                    cout << "\t0 -> Ajouter / Retirer" << endl;
                                                                    cout << "\t1 -> Remplacer" << endl;
                                                                #endif
                                                                #ifdef ENG
                                                                    cout << "\t0 -> Add / Remove" << endl;
                                                                    cout << "\t1 -> Replace" << endl;
                                                                #endif
                                                                #ifdef ESP
                                                                    cout << "\t0 -> Añadir / Eliminar" << endl;
                                                                    cout << "\t1 -> Reemplazar" << endl;
                                                                #endif
                                                                cout << "********************************************" << endl;
                                                                break;
                                                            default:
                                                                #ifdef FR
                                                                    cout << "Valeur entrée incorrecte" << endl;
                                                                #endif
                                                                #ifdef ENG
                                                                    cout << "Value incorrect" << endl;
                                                                #endif
                                                                #ifdef ESP
                                                                    cout << "Valor incorrecto" << endl;
                                                                #endif
                                                                break;
                                                        }
                                                    } while(fail);
                                                    dataChoice.addModificationItem(dataItem);
                                                    break;
                                                case 2:
                                                    do
                                                    {
                                                        #ifdef FR
                                                            cout << "Inserer le numéro de la modification :" << endl;
                                                        #endif
                                                        #ifdef ENG
                                                            cout << "Insert change number :" << endl;
                                                        #endif
                                                        #ifdef ESP
                                                            cout << "Insertar el número del cambio :" << endl;
                                                        #endif
                                                        cin >> numModifBis;
                                                        if(cin.fail() || numModifBis >= dataChoice.getSizeModification())
                                                        {
                                                            #ifdef FR
                                                                cout << "Valeur entrée incorrecte" << endl;
                                                            #endif
                                                            #ifdef ENG
                                                                cout << "Value incorrect" << endl;
                                                            #endif
                                                            #ifdef ESP
                                                                cout << "Valor incorrecto" << endl;
                                                            #endif
                                                            fail = true;
                                                        }
                                                        else
                                                        {
                                                            do
                                                            {
                                                                cout << "***" << endl;
                                                                #ifdef FR
                                                                    cout << "Que faire ?" << endl;
                                                                    cout << "1 - Modifier" << endl;
                                                                    cout << "2 - Lister les objets" << endl;
                                                                    cout << "3 - Lister les types de conditions" << endl;
                                                                #endif
                                                                #ifdef ENG
                                                                    cout << "What to do ?" << endl;
                                                                    cout << "1 - Edit" << endl;
                                                                    cout << "2 - List objects" << endl;
                                                                    cout << "3 - List types of changes" << endl;
                                                                #endif
                                                                #ifdef ESP
                                                                    cout << "¿ Qué quieres hacer ?" << endl;
                                                                    cout << "1 - Editar" << endl;
                                                                    cout << "2 - Listar los objetos" << endl;
                                                                    cout << "3 - Listar los typos de cambios" << endl;
                                                                #endif
                                                                cin >> choice;
                                                                if(cin.fail())
                                                                {
                                                                    choice = 0;
                                                                }

                                                                switch(choice)
                                                                {
                                                                    case 1:
                                                                        #ifdef FR
                                                                            cout << "Type de la modification :" << endl;
                                                                        #endif
                                                                        #ifdef ENG
                                                                            cout << "Type of change" << endl;
                                                                        #endif
                                                                        #ifdef ESP
                                                                            cout << "Typo del cambio" << endl;
                                                                        #endif
                                                                        do
                                                                        {
                                                                            cin >> intDataStrictPos;
                                                                            if(cin.fail() || intDataStrictPos > 1)
                                                                            {
                                                                                #ifdef FR
                                                                                    cout << "Valeur entrée incorrecte" << endl;
                                                                                #endif
                                                                                #ifdef ENG
                                                                                    cout << "Value incorrect" << endl;
                                                                                #endif
                                                                                #ifdef ESP
                                                                                    cout << "Valor incorrecto" << endl;
                                                                                #endif
                                                                                fail = true;
                                                                            }
                                                                            else
                                                                            {
                                                                                fail = false;
                                                                            }
                                                                        } while (fail);
                                                                        dataItem.setModificationType(intDataStrictPos);

                                                                        #ifdef FR
                                                                            cout << "Numéro de l'objet à modifier :" << endl;
                                                                        #endif
                                                                        #ifdef ENG
                                                                            cout << "Number of the object to modify :" << endl;
                                                                        #endif
                                                                        #ifdef ESP
                                                                            cout << "Número del objeto a modificar :" << endl;
                                                                        #endif
                                                                        do
                                                                        {
                                                                            cin >> intDataStrictPos;
                                                                            if(cin.fail() || intDataStrictPos >= itemTab.size())
                                                                            {
                                                                                #ifdef FR
                                                                                    cout << "Valeur entrée incorrecte" << endl;
                                                                                #endif
                                                                                #ifdef ENG
                                                                                    cout << "Value incorrect" << endl;
                                                                                #endif
                                                                                #ifdef ESP
                                                                                    cout << "Valor incorrecto" << endl;
                                                                                #endif
                                                                                fail = true;
                                                                            }
                                                                            else
                                                                            {
                                                                                fail = false;
                                                                            }
                                                                        } while (fail);
                                                                        dataItem.setType(intDataStrictPos);

                                                                        #ifdef FR
                                                                            cout << "Montant de la modification :" << endl;
                                                                        #endif
                                                                        #ifdef ENG
                                                                            cout << "Modification amount" << endl;
                                                                        #endif
                                                                        #ifdef ESP
                                                                            cout << "Cantidad de modificación" << endl;
                                                                        #endif
                                                                        do
                                                                        {
                                                                            cin >> intData;
                                                                            if(cin.fail())
                                                                            {
                                                                                #ifdef FR
                                                                                    cout << "Valeur entrée incorrecte" << endl;
                                                                                #endif
                                                                                #ifdef ENG
                                                                                    cout << "Value incorrect" << endl;
                                                                                #endif
                                                                                #ifdef ESP
                                                                                    cout << "Valor incorrecto" << endl;
                                                                                #endif
                                                                                fail = true;
                                                                            }
                                                                            else
                                                                            {
                                                                                fail = false;
                                                                            }
                                                                        } while (fail);

                                                                        dataItem.setValue(intData);
                                                                        fail = false;
                                                                        break;
                                                                    case 2:
                                                                        #ifdef FR
                                                                            cout << "Liste des objets du jeu :" << endl;
                                                                        #endif
                                                                        #ifdef ENG
                                                                            cout << "Game's objects list :" << endl;
                                                                        #endif
                                                                        #ifdef ESP
                                                                            cout << "Lista de objetos del juego :" << endl;
                                                                        #endif

                                                                        for (unsigned i = 0 ; i < itemTab.size() ; i++)
                                                                        {
                                                                            cout << itemTab[i].getItemNum() << " - " << itemTab[i].getItemName() << endl;
                                                                        }
                                                                        cout << "********************************************" << endl;
                                                                        break;
                                                                    case 3:
                                                                        #ifdef FR
                                                                            cout << "\t0 -> Ajouter / Retirer" << endl;
                                                                            cout << "\t1 -> Remplacer" << endl;
                                                                        #endif
                                                                        #ifdef ENG
                                                                            cout << "\t0 -> Add / Remove" << endl;
                                                                            cout << "\t1 -> Replace" << endl;
                                                                        #endif
                                                                        #ifdef ESP
                                                                            cout << "\t0 -> Añadir / Eliminar" << endl;
                                                                            cout << "\t1 -> Reemplazar" << endl;
                                                                        #endif
                                                                        cout << "********************************************" << endl;
                                                                        break;
                                                                    default:
                                                                        #ifdef FR
                                                                            cout << "Valeur entrée incorrecte" << endl;
                                                                        #endif
                                                                        #ifdef ENG
                                                                            cout << "Value incorrect" << endl;
                                                                        #endif
                                                                        #ifdef ESP
                                                                            cout << "Valor incorrecto" << endl;
                                                                        #endif
                                                                        break;
                                                                }
                                                            } while(fail);
                                                            dataChoice.changeModificationItem(dataItem, numModifBis);
                                                            fail = false;
                                                        }
                                                    } while (fail);
                                                    break;
                                                case 3:
                                                    dataChoice.eraseModificationItem();
                                                    break;
                                                default:
                                                    #ifdef FR
                                                        cout << "Valeur entrée incorrecte" << endl;
                                                    #endif
                                                    #ifdef ENG
                                                        cout << "Value incorrect" << endl;
                                                    #endif
                                                    #ifdef ESP
                                                        cout << "Valor incorrecto" << endl;
                                                    #endif
                                                    break;
                                            }
                                        }
                                        data.changeChoice(dataChoice, numModif);
                                        break;
                                    case 4:
                                        boucle = true;
                                        while (boucle)
                                        {
                                            cout << "***" << endl;
                                            #ifdef FR
                                                cout << "Que faire ?" << endl;
                                                cout << "1 - Ajouter une condition" << endl;
                                                cout << "2 - Editer une condition" << endl;
                                                cout << "3 - Supprimer la dernière condition" << endl;
                                            #endif
                                            #ifdef ENG
                                                cout << "What to do ?" << endl;
                                                cout << "1 - Add conditon" << endl;
                                                cout << "2 - Edit condition" << endl;
                                                cout << "3 - Delete last condition" << endl;
                                            #endif
                                            #ifdef ESP
                                                cout << "¿ Qué quieres hacer ?" << endl;
                                                cout << "1 - Añadar condición" << endl;
                                                cout << "2 - Editar condición" << endl;
                                                cout << "3 - Eliminar la última condición" << endl;
                                            #endif
                                            cin >> choice;
                                            if(cin.fail())
                                            {
                                                choice = 0;
                                            }
                                            switch(choice)
                                            {
                                                case 1:
                                                    do
                                                    {
                                                        cout << "***" << endl;
                                                        #ifdef FR
                                                            cout << "Que faire ?" << endl;
                                                            cout << "1 - Ajouter" << endl;
                                                            cout << "2 - Lister les objets" << endl;
                                                            cout << "3 - Lister les types de conditions" << endl;
                                                        #endif
                                                        #ifdef ENG
                                                            cout << "What to do ?" << endl;
                                                            cout << "1 - Add" << endl;
                                                            cout << "2 - List objects" << endl;
                                                            cout << "3 - List types of changes" << endl;
                                                        #endif
                                                        #ifdef ESP
                                                            cout << "¿ Qué quieres hacer ?" << endl;
                                                            cout << "1 - Añadar" << endl;
                                                            cout << "2 - Listar los objetos" << endl;
                                                            cout << "3 - Listar los typos de cambios" << endl;
                                                        #endif
                                                        cin >> choice;
                                                        if(cin.fail())
                                                        {
                                                            choice = 0;
                                                        }

                                                        switch(choice)
                                                        {
                                                            case 1:
                                                                #ifdef FR
                                                                    cout << "Type de la condition :" << endl;
                                                                #endif
                                                                #ifdef ENG
                                                                    cout << "Change type :" << endl;
                                                                #endif
                                                                #ifdef ESP
                                                                    cout << "Typo del cambio :" << endl;
                                                                #endif
                                                                do
                                                                {
                                                                    cin >> intDataStrictPos;
                                                                    if(cin.fail() || intDataStrictPos > 5)
                                                                    {
                                                                        #ifdef FR
                                                                            cout << "Valeur entrée incorrecte" << endl;
                                                                        #endif
                                                                        #ifdef ENG
                                                                            cout << "Value incorrect" << endl;
                                                                        #endif
                                                                        #ifdef ESP
                                                                            cout << "Valor incorrecto" << endl;
                                                                        #endif
                                                                        fail = true;
                                                                    }
                                                                    else
                                                                    {
                                                                        fail = false;
                                                                    }
                                                                } while (fail);
                                                                dataCondition.setCondition(intDataStrictPos);

                                                                #ifdef FR
                                                                    cout << "Type de l'objet de la condition :" << endl;
                                                                #endif
                                                                #ifdef ENG
                                                                    cout << "Object's type of the change :" << endl;
                                                                #endif
                                                                #ifdef ESP
                                                                    cout << "Typo del objeto del cambio :" << endl;
                                                                #endif
                                                                do
                                                                {
                                                                    cin >> intDataStrictPos;
                                                                    if(cin.fail() || intDataStrictPos >= itemTab.size())
                                                                    {
                                                                        #ifdef FR
                                                                            cout << "Valeur entrée incorrecte" << endl;
                                                                        #endif
                                                                        #ifdef ENG
                                                                            cout << "Value incorrect" << endl;
                                                                        #endif
                                                                        #ifdef ESP
                                                                            cout << "Valor incorrecto" << endl;
                                                                        #endif
                                                                        fail = true;
                                                                    }
                                                                    else
                                                                    {
                                                                        fail = false;
                                                                    }
                                                                } while (fail);
                                                                dataCondition.setTypeItem(intDataStrictPos);

                                                                #ifdef FR
                                                                    cout << "Valeur de la condition :" << endl;
                                                                #endif
                                                                #ifdef ENG
                                                                    cout << "Condition value :" << endl;
                                                                #endif
                                                                #ifdef ESP
                                                                    cout << "Valor de la condición :" << endl;
                                                                #endif
                                                                do
                                                                {
                                                                    cin >> intData;
                                                                    if(cin.fail())
                                                                    {
                                                                        #ifdef FR
                                                                            cout << "Valeur entrée incorrecte" << endl;
                                                                        #endif
                                                                        #ifdef ENG
                                                                            cout << "Value incorrect" << endl;
                                                                        #endif
                                                                        #ifdef ESP
                                                                            cout << "Valor incorrecto" << endl;
                                                                        #endif
                                                                        fail = true;
                                                                    }
                                                                    else
                                                                    {
                                                                        fail = false;
                                                                    }
                                                                } while (fail);
                                                                dataCondition.setValue(intData);
                                                                fail = false;
                                                                break;
                                                            case 2:
                                                                #ifdef FR
                                                                    cout << "Liste des objets du jeu :" << endl;
                                                                #endif
                                                                #ifdef ENG
                                                                    cout << "Game's objects list :" << endl;
                                                                #endif
                                                                #ifdef ESP
                                                                    cout << "Lista de objetos del juego :" << endl;
                                                                #endif

                                                                for (unsigned i = 0 ; i < itemTab.size() ; i++)
                                                                {
                                                                    cout << itemTab[i].getItemNum() << " - " << itemTab[i].getItemName() << endl;
                                                                }
                                                                cout << "********************************************" << endl;
                                                                break;
                                                            case 3:
                                                                cout << "\t0 -> =" << endl;
                                                                cout << "\t1 -> !=" << endl;
                                                                cout << "\t2 -> >=" << endl;
                                                                cout << "\t3 -> >" << endl;
                                                                cout << "\t4 -> <=" << endl;
                                                                cout << "\t5 -> <" << endl;
                                                                cout << "********************************************" << endl;
                                                                break;
                                                            default:
                                                                #ifdef FR
                                                                    cout << "Valeur entrée incorrecte" << endl;
                                                                #endif
                                                                #ifdef ENG
                                                                    cout << "Value incorrect" << endl;
                                                                #endif
                                                                #ifdef ESP
                                                                    cout << "Valor incorrecto" << endl;
                                                                #endif
                                                                break;
                                                        }
                                                    } while(fail);
                                                    dataChoice.addConditionChoice(dataCondition);
                                                    break;
                                                case 2:
                                                    do
                                                    {
                                                        #ifdef FR
                                                            cout << "Inserer le numéro de la modification :" << endl;
                                                        #endif
                                                        #ifdef ENG
                                                            cout << "Insert change number :" << endl;
                                                        #endif
                                                        #ifdef ESP
                                                            cout << "Insertar el número del cambio :" << endl;
                                                        #endif
                                                        cin >> numModifBis;
                                                        if(cin.fail() || numModifBis >= dataChoice.getSizeModification())
                                                        {
                                                            #ifdef FR
                                                                cout << "Valeur entrée incorrecte" << endl;
                                                            #endif
                                                            #ifdef ENG
                                                                cout << "Value incorrect" << endl;
                                                            #endif
                                                            #ifdef ESP
                                                                cout << "Valor incorrecto" << endl;
                                                            #endif
                                                            fail = true;
                                                        }
                                                        else
                                                        {
                                                            do
                                                            {
                                                                cout << "***" << endl;
                                                                #ifdef FR
                                                                    cout << "Que faire ?" << endl;
                                                                    cout << "1 - Modifier" << endl;
                                                                    cout << "2 - Lister les objets" << endl;
                                                                    cout << "3 - Lister les types de conditions" << endl;
                                                                #endif
                                                                #ifdef ENG
                                                                    cout << "What to do ?" << endl;
                                                                    cout << "1 - Edit" << endl;
                                                                    cout << "2 - List objects" << endl;
                                                                    cout << "3 - List types of changes" << endl;
                                                                #endif
                                                                #ifdef ESP
                                                                    cout << "¿ Qué quieres hacer ?" << endl;
                                                                    cout << "1 - Editar" << endl;
                                                                    cout << "2 - Listar los objetos" << endl;
                                                                    cout << "3 - Listar los typos de cambios" << endl;
                                                                #endif
                                                                cin >> choice;
                                                                if(cin.fail())
                                                                {
                                                                    choice = 0;
                                                                }

                                                                switch(choice)
                                                                {
                                                                    case 1:
                                                                        #ifdef FR
                                                                            cout << "Type de la condition :" << endl;
                                                                        #endif
                                                                        #ifdef ENG
                                                                            cout << "Change type :" << endl;
                                                                        #endif
                                                                        #ifdef ESP
                                                                            cout << "Typo del cambio :" << endl;
                                                                        #endif
                                                                        do
                                                                        {
                                                                            cin >> intDataStrictPos;
                                                                            if(cin.fail() || intDataStrictPos > 5)
                                                                            {
                                                                                #ifdef FR
                                                                                    cout << "Valeur entrée incorrecte" << endl;
                                                                                #endif
                                                                                #ifdef ENG
                                                                                    cout << "Value incorrect" << endl;
                                                                                #endif
                                                                                #ifdef ESP
                                                                                    cout << "Valor incorrecto" << endl;
                                                                                #endif
                                                                                fail = true;
                                                                            }
                                                                            else
                                                                            {
                                                                                fail = false;
                                                                            }
                                                                        } while (fail);
                                                                        dataCondition.setCondition(intDataStrictPos);

                                                                        #ifdef FR
                                                                            cout << "Type de l'objet de la condition :" << endl;
                                                                        #endif
                                                                        #ifdef ENG
                                                                            cout << "Object's type of the change :" << endl;
                                                                        #endif
                                                                        #ifdef ESP
                                                                            cout << "Typo del objeto del cambio :" << endl;
                                                                        #endif
                                                                        do
                                                                        {
                                                                            cin >> intDataStrictPos;
                                                                            if(cin.fail() || intDataStrictPos >= itemTab.size())
                                                                            {
                                                                                #ifdef FR
                                                                                    cout << "Valeur entrée incorrecte" << endl;
                                                                                #endif
                                                                                #ifdef ENG
                                                                                    cout << "Value incorrect" << endl;
                                                                                #endif
                                                                                #ifdef ESP
                                                                                    cout << "Valor incorrecto" << endl;
                                                                                #endif
                                                                                fail = true;
                                                                            }
                                                                            else
                                                                            {
                                                                                fail = false;
                                                                            }
                                                                        } while (fail);
                                                                        dataCondition.setTypeItem(intDataStrictPos);

                                                                        #ifdef FR
                                                                            cout << "Valeur de la condition :" << endl;
                                                                        #endif
                                                                        #ifdef ENG
                                                                            cout << "Condition value :" << endl;
                                                                        #endif
                                                                        #ifdef ESP
                                                                            cout << "Valor de la condición :" << endl;
                                                                        #endif
                                                                        do
                                                                        {
                                                                            cin >> intData;
                                                                            if(cin.fail())
                                                                            {
                                                                                #ifdef FR
                                                                                    cout << "Valeur entrée incorrecte" << endl;
                                                                                #endif
                                                                                #ifdef ENG
                                                                                    cout << "Value incorrect" << endl;
                                                                                #endif
                                                                                #ifdef ESP
                                                                                    cout << "Valor incorrecto" << endl;
                                                                                #endif
                                                                                fail = true;
                                                                            }
                                                                            else
                                                                            {
                                                                                fail = false;
                                                                            }
                                                                        } while (fail);
                                                                        dataCondition.setValue(intData);
                                                                        fail = false;
                                                                        break;
                                                                    case 2:
                                                                        #ifdef FR
                                                                            cout << "Liste des objets du jeu :" << endl;
                                                                        #endif
                                                                        #ifdef ENG
                                                                            cout << "Game's objects list :" << endl;
                                                                        #endif
                                                                        #ifdef ESP
                                                                            cout << "Lista de objetos del juego :" << endl;
                                                                        #endif

                                                                        for (unsigned i = 0 ; i < itemTab.size() ; i++)
                                                                        {
                                                                            cout << itemTab[i].getItemNum() << " - " << itemTab[i].getItemName() << endl;
                                                                        }
                                                                        cout << "********************************************" << endl;
                                                                        break;
                                                                    case 3:
                                                                        cout << "\t0 -> =" << endl;
                                                                        cout << "\t1 -> !=" << endl;
                                                                        cout << "\t2 -> >=" << endl;
                                                                        cout << "\t3 -> >" << endl;
                                                                        cout << "\t4 -> <=" << endl;
                                                                        cout << "\t5 -> <" << endl;
                                                                        cout << "********************************************" << endl;
                                                                        break;
                                                                    default:
                                                                        #ifdef FR
                                                                            cout << "Valeur entrée incorrecte" << endl;
                                                                        #endif
                                                                        #ifdef ENG
                                                                            cout << "Value incorrect" << endl;
                                                                        #endif
                                                                        #ifdef ESP
                                                                            cout << "Valor incorrecto" << endl;
                                                                        #endif
                                                                        break;
                                                                }
                                                            } while(fail);
                                                            dataChoice.changeConditionChoice(dataCondition, numModifBis);
                                                        }
                                                    } while(fail);
                                                    break;
                                                case 3:
                                                    dataChoice.eraseConditionChoice();
                                                    break;
                                                default:
                                                    #ifdef FR
                                                        cout << "Valeur entrée incorrecte" << endl;
                                                    #endif
                                                    #ifdef ENG
                                                        cout << "Value incorrect" << endl;
                                                    #endif
                                                    #ifdef ESP
                                                        cout << "Valor incorrecto" << endl;
                                                    #endif
                                                    break;
                                            }
                                        }
                                        data.changeChoice(dataChoice, numModif);
                                        break;
                                    case 5:
                                        fail = false;
                                        break;
                                    default:
                                        #ifdef FR
                                            cout << "Valeur entrée incorrecte" << endl;
                                        #endif
                                        #ifdef ENG
                                            cout << "Value incorrect" << endl;
                                        #endif
                                        #ifdef ESP
                                            cout << "Valor incorrecto" << endl;
                                        #endif
                                        break;
                                }
                            }
                            fail = false;
                        }
                    } while (fail);
                    data.changeChoice(dataChoice, numModif);
                }
                else
                {
                    #ifdef FR
                        cout << "Il n'y a pas de modification d'objet à modifier." << endl;
                    #endif
                    #ifdef ENG
                        cout << "There's no change to do." << endl;
                    #endif
                    #ifdef ESP
                        cout << "No se pueden realizar cambios." << endl;
                    #endif
                }
                break;
            case 7:
                if (data.getChoice().size() == 0)
                {
                    #ifdef FR
                        cout << "Il n'y a rien à supprimer." << endl;
                    #endif
                    #ifdef ENG
                        cout << "There's nothing to delete." << endl;
                    #endif
                    #ifdef ESP
                        cout << "No hay nada que borrar" << endl;
                    #endif
                }
                else
                {
                    data.eraseChoice();
                }
                break;
            case 8:
                boucle = false;
                break;
            default:
                #ifdef FR
                    cout << "Valeur entrée incorrecte" << endl;
                #endif
                #ifdef ENG
                    cout << "Value incorrect" << endl;
                #endif
                #ifdef ESP
                    cout << "Valor incorrecto" << endl;
                #endif
                break;
        }
    }

    return data;
}

C_Item addItem(vector<C_Item> itemTab)
{
    bool fail = false;
    int intData;
    string stringData;
    C_Item item;
    item.setItemNum(itemTab.size());
    cout << "********************************************" << endl;
    #ifdef FR
        cout << "Nom de l'objet :" << endl;
    #endif
    #ifdef ENG
        cout << "Object name :" << endl;
    #endif
    #ifdef ESP
        cout << "Nombre del objeto :" << endl;
    #endif
    cin.ignore();
    getline(cin, stringData);
    item.setItemName(stringData);
    #ifdef FR
        cout << "Valeur par défaut :" << endl;
    #endif
    #ifdef ENG
        cout << "Default value :" << endl;
    #endif
    #ifdef ESP
        cout << "Valor por defecto :" << endl;
    #endif
    do
    {
        cin >> intData;
        if(cin.fail())
        {
            #ifdef FR
                cout << "Valeur entrée incorrecte" << endl;
            #endif
            #ifdef ENG
                cout << "Value incorrect" << endl;
            #endif
            #ifdef ESP
                cout << "Valor incorrecto" << endl;
            #endif
            fail = true;
        }
        else
        {
            fail = false;
        }
    } while (fail);
    item.setItemNumber(intData);

    return item;
}

C_Item changeItem(C_Item item)
{
    bool fail = false;
    bool boucle = true;
    unsigned int choice;
    int intData;
    string stringData;
    cout << "********************************************" << endl;
    item.descrItem();
    while (boucle)
    {
        cout << "***" << endl;
        #ifdef FR
            cout << "Que changer ?" << endl;
            cout << "1 - Nom de l'objet" << endl;
            cout << "2 - Valeur par défaut" << endl;
            cout << "3 - Rien" << endl;
        #endif
        #ifdef ENG
            cout << "What to modify ?" << endl;
            cout << "1 - Object name" << endl;
            cout << "2 - Default value" << endl;
            cout << "3 - Nothing" << endl;
        #endif
        #ifdef ESP
            cout << "¿ Que cambiar ?" << endl;
            cout << "1 - Nombre del objeto" << endl;
            cout << "2 - Valor por defecto" << endl;
            cout << "3 - Nada" << endl;
        #endif
        cin >> choice;
        if(cin.fail())
        {
            choice = 0;
        }
        switch(choice)
        {
            case 1:
                #ifdef FR
                    cout << "Nom de l'objet :" << endl;
                #endif
                #ifdef ENG
                    cout << "Object name :" << endl;
                #endif
                #ifdef ESP
                    cout << "Nombre del objeto :" << endl;
                #endif
                cin.ignore();
                getline(cin, stringData);
                item.setItemName(stringData);
                break;
            case 2:
                #ifdef FR
                    cout << "Valeur par défaut :" << endl;
                #endif
                #ifdef ENG
                    cout << "Default value :" << endl;
                #endif
                #ifdef ESP
                    cout << "Valor por defecto :" << endl;
                #endif
                do
                {
                    cin >> intData;
                    if(cin.fail())
                    {
                        #ifdef FR
                            cout << "Valeur entrée incorrecte" << endl;
                        #endif
                        #ifdef ENG
                            cout << "Value incorrect" << endl;
                        #endif
                        #ifdef ESP
                            cout << "Valor incorrecto" << endl;
                        #endif
                        fail = true;
                    }
                    else
                    {
                        fail = false;
                    }
                } while (fail);
                item.setItemNumber(intData);
                break;
            case 3:
                boucle = false;
                break;
            default:
                #ifdef FR
                    cout << "Valeur entrée incorrecte" << endl;
                #endif
                #ifdef ENG
                    cout << "Value incorrect" << endl;
                #endif
                #ifdef ESP
                    cout << "Valor incorrecto" << endl;
                #endif
                break;
        }
    }

    return item;
}
