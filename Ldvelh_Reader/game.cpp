#include "language.hpp"
#include "game.hpp"

C_Game::C_Game()
{
    num = 0;
    name = "";
    author = "";
}

C_Game::~C_Game()
{

}

void C_Game::setGameNum(unsigned int gameNum)
{
    num = gameNum;
}

void C_Game::setGameName(string gameName)
{
    name = gameName;
}

void C_Game::setGameAuthor(string gameAuthor)
{
    author = gameAuthor;
}

unsigned int C_Game::getGameNum(void)
{
    return num;
}

string C_Game::getGameName(void)
{
    return name;
}

string C_Game::getGameAuthor(void)
{
    return author;
}

void C_Game::runMenu(void)
{
    bool stay = true;
    int choice = 0;
    bool choiceBis = false;
    string fileName;
    C_Save sauvegarde;
    sauvegarde.setInventory(itemTab);

    while(stay)
    {
        cout << "********************************************" << endl;
        #ifdef FR
            cout << name << " par " << author << endl;
            cout << "Que faire ?" << endl;
            cout << "1 - Nouvelle partie"<< endl;
            cout << "2 - Charger une partie" << endl;
            cout << "3 - Quitter" << endl;
        #endif
        #ifdef ENG
            cout << name << " by " << author << endl;
            cout << "Wat to do ?" << endl;
            cout << "1 - New game"<< endl;
            cout << "2 - Load game" << endl;
            cout << "3 - Leave" << endl;
        #endif
        #ifdef ESP
            cout << name << " par " << author << endl;
            cout << "¿Qué quieres hacer?" << endl;
            cout << "1 - Nuevo juego"<< endl;
            cout << "2 - Cargar un juego" << endl;
            cout << "3 - Salir" << endl;
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
                    cout << "Indiquer le fichier de sauvegarde" << endl;
                #endif
                #ifdef ENG
                    cout << "Indicate the save file" << endl;
                #endif
                #ifdef ESP
                    cout << "Indica el archivo de respaldo" << endl;
                #endif
                cin.ignore();
                getline(cin, fileName);
                if (saveVerifExist(fileName))
                {
                    #ifdef FR
                        cout << "Le fichier existe déjà. Le remplacer ?" << endl;
                        cout << "0 - Non" << endl;
                        cout << "1 - Oui" << endl;
                    #endif
                    #ifdef ENG
                        cout << "Already existing file. Replace it ?" << endl;
                        cout << "0 - No" << endl;
                        cout << "1 - Yes" << endl;
                    #endif
                    #ifdef ESP
                        cout << "Archivo ya existente. ¿Reemplazarlo?" << endl;
                        cout << "0 - No" << endl;
                        cout << "1 - Si" << endl;
                    #endif
                    cin >> choiceBis;
                    if(cin.fail())
                    {
                        choiceBis = false;
                    }
                    if (choiceBis)
                    {
                        start(sauvegarde, fileName, false);
                    }
                       else
                    {
                        break;
                    }
                }
                else
                {
                    start(sauvegarde, fileName, false);
                }
                break;
            case 2:
                while (stay)
                {
                    listeGameSaves();
                    #ifdef FR
                        cout << "Indiquer le fichier de sauvegarde" << endl;
                    #endif
                    #ifdef ENG
                        cout << "Indicate the save file" << endl;
                    #endif
                    #ifdef ESP
                        cout << "Indica el archivo de respaldo" << endl;
                    #endif
                    cin.ignore();
                    getline(cin, fileName);
                    sauvegarde = load(fileName, &stay);
                }
                start(sauvegarde, fileName, true);
                break;
            case 3:
                stay = false;
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
}

void C_Game::start(C_Save sauvegarde, string fileName, bool loadedGame)
{
    int nextEntry;
    bool boucle = true;
    bool menu = false;

    nextEntry = playEntry(&sauvegarde, sauvegarde.getEntry(), loadedGame);
    do
    {
        if (nextEntry >= (int)dataTab.size())
        {
            #ifdef FR
                cout << "Une erreur est survenue." << endl;
            #endif
            #ifdef ENG
                cout << "An error has occurred." << endl;
            #endif
            #ifdef ESP
                cout << "Se ha producido un error." << endl;
            #endif
            boucle = false;
        }
        else if (nextEntry > 0)
        {
            sauvegarde.setEntry(nextEntry);
            nextEntry = playEntry(&sauvegarde, sauvegarde.getEntry(), menu);
            menu = false;
        }
        else if (nextEntry == 0)
        {
            nextEntry = playEntry(&sauvegarde, 0, menu);
            menu = true;
        }
        else if (nextEntry == -1)
        {
            showInventory(sauvegarde);
            nextEntry = playEntry(&sauvegarde, 0, menu);
            menu = true;
        }
        else if (nextEntry == -2)
        {
            save(sauvegarde, fileName);
            #ifdef FR
                cout << "Sauvegarde effectuée !" << endl;
            #endif
            #ifdef ENG
                cout << "Save done !" << endl;
            #endif
            #ifdef ESP
                cout << "¡Partida guardada!" << endl;
            #endif
            nextEntry = playEntry(&sauvegarde, 0, menu);
            menu = true;
        }
        else if (nextEntry == -3)
        {
            nextEntry = playEntry(&sauvegarde, sauvegarde.getEntry(), menu);
            menu = true;
        }
        else if (nextEntry == -4)
        {
            boucle = false;
        }
        else
        {
            #ifdef FR
                cout << "Une erreur est survenue." << endl;
            #endif
            #ifdef ENG
                cout << "An error has occurred." << endl;
            #endif
            #ifdef ESP
                cout << "Se ha producido un error." << endl;
            #endif
            boucle = false;
        }
    } while(boucle);
}

int C_Game::playEntry(C_Save *sauvegarde, int entry, bool menu)
{
    bool fail = false;
    bool condition = true;
    unsigned int choice;
    vector<int> choiceShow;
    int conditionType = 0;
    int modificationType = 0;
    int modification = 0;
    int nextEntry;
    vector<C_Item> inventoryTemp;
    inventoryTemp = sauvegarde->getInventory();
    cout << "********************************************" << endl;
    dataTab[entry].showText();

    /// Modifications d'objets
    if (!menu)
    {
        if (dataTab[entry].getItemModification().size() != 0)
        {
            for (unsigned int i = 0 ; i < dataTab[entry].getItemModification().size() ; i++)
            {
                modification = inventoryTemp[dataTab[entry].getItemModification()[i].getType()].getItemNumber();
                modificationType = dataTab[entry].getItemModification()[i].getModificationType();
                switch (modificationType)
                {
                    case 0:
                        modification += dataTab[entry].getItemModification()[i].getValue();
                        inventoryTemp[dataTab[entry].getItemModification()[i].getType()].setItemNumber(modification);
                        sauvegarde->setInventory(inventoryTemp);
                        break;
                    case 1:
                        inventoryTemp[dataTab[entry].getItemModification()[i].getType()].setItemNumber(dataTab[entry].getItemModification()[i].getValue());
                        sauvegarde->setInventory(inventoryTemp);
                        break;
                    default:
                        break;
                }
            }
        }
    }

    /// Choix
    if (dataTab[entry].getChoice().size() != 0)
    {
        cout << "*****" << endl;
        for (unsigned int i = 0 ; i < dataTab[entry].getChoice().size() ; i++)
        {
            condition = true;
            for (unsigned int j = 0 ; j < dataTab[entry].getChoice()[i].getSizeCondition() ; j++)
            {
                conditionType = dataTab[entry].getChoice()[i].getCondition(j).getCondition();
                switch (conditionType)
                {
                    case 0:
                        if (inventoryTemp[dataTab[entry].getChoice()[i].getCondition(j).getTypeItem()].getItemNumber() != dataTab[entry].getChoice()[i].getCondition(j).getValue())
                        {
                            condition = false;
                        }
                        break;
                    case 1:
                        if (inventoryTemp[dataTab[entry].getChoice()[i].getCondition(j).getTypeItem()].getItemNumber() == dataTab[entry].getChoice()[i].getCondition(j).getValue())
                        {
                            condition = false;
                        }
                        break;
                    case 2:
                        if (inventoryTemp[dataTab[entry].getChoice()[i].getCondition(j).getTypeItem()].getItemNumber() < dataTab[entry].getChoice()[i].getCondition(j).getValue())
                        {
                            condition = false;
                        }
                        break;
                    case 3:
                        if (inventoryTemp[dataTab[entry].getChoice()[i].getCondition(j).getTypeItem()].getItemNumber() <= dataTab[entry].getChoice()[i].getCondition(j).getValue())
                        {
                            condition = false;
                        }
                        break;
                    case 4:
                        if (inventoryTemp[dataTab[entry].getChoice()[i].getCondition(j).getTypeItem()].getItemNumber() > dataTab[entry].getChoice()[i].getCondition(j).getValue())
                        {
                            condition = false;
                        }
                        break;
                    case 5:
                        if (inventoryTemp[dataTab[entry].getChoice()[i].getCondition(j).getTypeItem()].getItemNumber() >= dataTab[entry].getChoice()[i].getCondition(j).getValue())
                        {
                            condition = false;
                        }
                        break;
                    default:
                        #ifdef FR
                            cout << "Une erreur est survenue." << endl;
                        #endif
                        #ifdef ENG
                            cout << "An error has occurred." << endl;
                        #endif
                        #ifdef ESP
                            cout << "Se ha producido un error." << endl;
                        #endif
                        return -4;
                        break;
                }
            }
            if (condition)
            {
                choiceShow.push_back(i);
            }
        }
        for (unsigned int i = 0 ; i < choiceShow.size(); i++)
        {
            stringstream stringTemp;
            stringTemp << i + 1 << " - " << dataTab[entry].getChoice()[choiceShow[i]].getTextChoice();
            dataTab[entry].format(stringTemp.str());
        }
        do
        {
            cout << "***" << endl;
            cin >> choice;
            if(cin.fail() || choice > choiceShow.size())
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
        } while(fail);

        if (choice == 0)
        {
            return 0;
        }
        else
        {
            nextEntry = dataTab[entry].getChoice()[choiceShow[choice - 1]].getDestChoice();
        }

        if (dataTab[entry].getChoice()[choiceShow[choice - 1]].getSizeModification() != 0)
        {
            for (unsigned int i = 0 ; i < dataTab[entry].getChoice()[choiceShow[choice - 1]].getSizeModification() ; i++)
            {
                modification = inventoryTemp[dataTab[entry].getChoice()[choiceShow[choice - 1]].getModification(i).getType()].getItemNumber();
                modificationType = dataTab[entry].getChoice()[choiceShow[choice - 1]].getModification(i).getModificationType();
                switch (modificationType)
                {
                    case 0:
                        modification += dataTab[entry].getChoice()[choiceShow[choice - 1]].getModification(i).getValue();
                        inventoryTemp[dataTab[entry].getChoice()[choiceShow[choice - 1]].getModification(i).getType()].setItemNumber(modification);
                        sauvegarde->setInventory(inventoryTemp);
                        break;
                    case 1:
                        inventoryTemp[dataTab[entry].getChoice()[choiceShow[choice - 1]].getModification(i).getType()].setItemNumber(dataTab[entry].getChoice()[choiceShow[choice - 1]].getModification(i).getValue());
                        sauvegarde->setInventory(inventoryTemp);
                        break;
                    default:
                        break;
                }
            }
        }
    }
    else
    {
        #ifdef FR
            cout << "Une erreur est survenue." << endl;
        #endif
        #ifdef ENG
            cout << "An error has occurred." << endl;
        #endif
        #ifdef ESP
            cout << "Se ha producido un error." << endl;
        #endif
        return -4;
    }
    return nextEntry;
}

void C_Game::showInventory(C_Save sauvegarde)
{
    bool stay = true;
    int choice;
    #ifdef FR
        cout << "*** Inventaire ***" << endl;
    #endif
    #ifdef FR
        cout << "*** Inventory ***" << endl;
    #endif
    #ifdef FR
        cout << "*** Inventario ***" << endl;
    #endif
    for (unsigned int i = 0 ; i < itemTab.size() ; i++)
    {
        if (sauvegarde.getInventory()[i].getItemNumber() > 0)
        {
            cout << "\t" << sauvegarde.getInventory()[i].getItemName() << " -> " << sauvegarde.getInventory()[i].getItemNumber() << endl;
        }
    }
    do
    {
        cout << "*****" << endl;
        #ifdef FR
            cout << "1 - Revenir au menu" << endl;
        #endif
        #ifdef ENG
            cout << "1 - Back to menu" << endl;
        #endif
        #ifdef ESP
            cout << "1 - Volver al menu" << endl;
        #endif
        cin >> choice;
        if(cin.fail() || choice != 1)
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
            choice = 0;
            stay = true;
        }
        else
        {
            stay = false;
        }
    } while(stay);
}
