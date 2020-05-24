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

void C_Game::editGame(void)
{
    bool stay = true;
    int choice = 0;

    while(stay)
    {
        cout << "********************************************" << endl;
        #ifdef FR
            cout << "Editeur V" << VERSION << " par Tattus : " << endl;
            cout << name << " par " << author << endl;
            cout << "Que faire ?" << endl;
            cout << "1 - Ajouter une entrée (";
            cout << dataTab.size() << ")" << endl;
            cout << "2 - Editer une entrée (";
            cout << dataTab.size() << ")" << endl;
            cout << "3 - Ajouter un objet (";
            cout << itemTab.size() << ")" << endl;
            cout << "4 - Editer un objet (";
            cout << itemTab.size() << ")" << endl;
            cout << "5 - Lister les objets (";
            cout << itemTab.size() << ")" << endl;
            cout << "6 - Documentation" << endl;
            cout << "7 - Sauvegarder et quitter" << endl;
        #endif
        #ifdef ENG
            cout << "Editor V" << VERSION << " by Tattus : " << endl;
            cout << name << " by " << author << endl;
            cout << "What to do ?" << endl;
            cout << "1 - Add entry (";
            cout << dataTab.size() << ")" << endl;
            cout << "2 - Edit entry (";
            cout << dataTab.size() << ")" << endl;
            cout << "3 - Add object (";
            cout << itemTab.size() << ")" << endl;
            cout << "4 - Edit object (";
            cout << itemTab.size() << ")" << endl;
            cout << "5 - List objects (";
            cout << itemTab.size() << ")" << endl;
            cout << "6 - Documentation" << endl;
            cout << "7 - Save and leave" << endl;
        #endif
        #ifdef ESP
            cout << "Editor V" << VERSION << " por Tattus : " << endl;
            cout << name << " por " << author << endl;
            cout << "¿ Qué quieres hacer ?" << endl;
            cout << "1 - Añadir una entrada (";
            cout << dataTab.size() << ")" << endl;
            cout << "2 - Editar una entrada (";
            cout << dataTab.size() << ")" << endl;
            cout << "3 - Añadir un objeto (";
            cout << itemTab.size() << ")" << endl;
            cout << "4 - Editar un objeto (";
            cout << itemTab.size() << ")" << endl;
            cout << "5 - Listar los objetos (";
            cout << itemTab.size() << ")" << endl;
            cout << "6 - Documentación" << endl;
            cout << "7 - Salvar y salir" << endl;
        #endif
        cin >> choice;
        if(cin.fail())
        {
            choice = 0;
        }
        bool boucle = true;

        switch(choice)
        {
            case 1:
                while(boucle)
                {
                    dataTab.push_back(addEntries(dataTab, itemTab));
                    #ifdef FR
                        cout << "Ajouter une nouvelle entrée ?" << endl;
                        cout << "1 - Oui" << endl;
                        cout << "2 - Non" << endl;
                    #endif
                    #ifdef ENG
                        cout << "Add new entry ?" << endl;
                        cout << "1 - Yes" << endl;
                        cout << "2 - No" << endl;
                    #endif
                    #ifdef ESP
                        cout << "¿ Añadir una nueva entrada ?" << endl;
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
                            break;
                        case 2:
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
                break;
            case 2:
                while(boucle)
                {
                    unsigned int dataNum = 0;
                    #ifdef FR
                        cout << "Indiquer le numéro de l'entrée" << endl;
                    #endif
                    #ifdef ENG
                        cout << "Indicate entry number" << endl;
                    #endif
                    #ifdef ESP
                        cout << "Indicar el número de la entrada" << endl;
                    #endif
                    cin >> dataNum;
                    if(cin.fail() || dataNum >= dataTab.size())
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
                    }
                    else
                    {
                        dataTab[dataNum] = changeEntries(dataTab[dataNum], itemTab);
                    }
                    #ifdef FR
                        cout << "Editer une autre entrée ?" << endl;
                        cout << "1 - Oui" << endl;
                        cout << "2 - Non" << endl;
                    #endif
                    #ifdef ENG
                        cout << "Edit another entry ?" << endl;
                        cout << "1 - Yes" << endl;
                        cout << "2 - No" << endl;
                    #endif
                    #ifdef ESP
                        cout << "¿ Editar otra entrada ?" << endl;
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
                            break;
                        case 2:
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
                break;
            case 3:
                while(boucle)
                {
                    itemTab.push_back(addItem(itemTab));
                    #ifdef FR
                        cout << "Ajouter un nouvel objet ?" << endl;
                        cout << "1 - Oui" << endl;
                        cout << "2 - Non" << endl;
                    #endif
                    #ifdef ENG
                        cout << "Add new object ?" << endl;
                        cout << "1 - Yes" << endl;
                        cout << "2 - No" << endl;
                    #endif
                    #ifdef ESP
                        cout << "¿ Añadir un nuevo objeto ?" << endl;
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
                            break;
                        case 2:
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
                break;
            case 4:
                while(boucle)
                {
                    unsigned int itemNum = 0;
                    #ifdef FR
                        cout << "Indiquer le numéro de l'objet" << endl;
                    #endif
                    #ifdef ENG
                        cout << "Indicate object number" << endl;
                    #endif
                    #ifdef ESP
                        cout << "Indicar el número del objeto" << endl;
                    #endif
                    cin >> itemNum;
                    if(cin.fail() || itemNum >= itemTab.size())
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
                    }
                    else
                    {
                        itemTab[itemNum] = changeItem(itemTab[itemNum]);
                    }
                    #ifdef FR
                        cout << "Editer un autre objet ?" << endl;
                        cout << "1 - Oui" << endl;
                        cout << "2 - Non" << endl;
                    #endif
                    #ifdef ENG
                        cout << "Edit another object ?" << endl;
                        cout << "1 - Yes" << endl;
                        cout << "2 - No" << endl;
                    #endif
                    #ifdef ESP
                        cout << "¿ Editar otro objeto ?" << endl;
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
                            break;
                        case 2:
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
                break;
            case 5:
                listItems();
                break;
            case 6:
                #ifdef FR
                    cout << "********************************************" << endl;
                    cout << "***** Types de modification d'objet :" << endl;
                    cout << "\t0 -> Ajouter / Retirer" << endl;
                    cout << "\t1 -> Remplacer" << endl;
                    cout << "********************************************" << endl;
                    cout << "***** Types de conditions :" << endl;
                    cout << "\t0 -> =" << endl;
                    cout << "\t1 -> !=" << endl;
                    cout << "\t2 -> >=" << endl;
                    cout << "\t3 -> >" << endl;
                    cout << "\t4 -> <=" << endl;
                    cout << "\t5 -> <" << endl;
                    cout << "********************************************" << endl;
                    cout << "***** Entrées spéciales :" << endl;
                    cout << "\t0 -> Menu" << endl;
                    cout << "\t1 -> Début de partie" << endl;
                    cout << "\t-4 -> Fin de partie" << endl;
                    cout << "********************************************" << endl;
                    cout << "***** Entrées spéciales du menu :" << endl;
                    cout << "\t-1 -> Inventaire" << endl;
                    cout << "\t-2 -> Sauvegarder" << endl;
                    cout << "\t-3 -> Retour au jeu" << endl;
                    cout << "\t-4 -> Quitter le jeu" << endl;
                #endif
                #ifdef ENG
                    cout << "********************************************" << endl;
                    cout << "***** Object's modification types :" << endl;
                    cout << "\t0 -> Add / Remove" << endl;
                    cout << "\t1 -> Replace" << endl;
                    cout << "********************************************" << endl;
                    cout << "***** Conditions's types :" << endl;
                    cout << "\t0 -> =" << endl;
                    cout << "\t1 -> !=" << endl;
                    cout << "\t2 -> >=" << endl;
                    cout << "\t3 -> >" << endl;
                    cout << "\t4 -> <=" << endl;
                    cout << "\t5 -> <" << endl;
                    cout << "********************************************" << endl;
                    cout << "***** Specials entries :" << endl;
                    cout << "\t0 -> Menu" << endl;
                    cout << "\t1 -> Start game entry" << endl;
                    cout << "\t-4 -> End game entry" << endl;
                    cout << "********************************************" << endl;
                    cout << "***** Menu's specials entries :" << endl;
                    cout << "\t-1 -> Inventory" << endl;
                    cout << "\t-2 -> Save" << endl;
                    cout << "\t-3 -> Back to game" << endl;
                    cout << "\t-4 -> Leave game" << endl;
                #endif
                #ifdef ESP
                    cout << "********************************************" << endl;
                    cout << "***** Types de modification d'objet :" << endl;
                    cout << "\t0 -> Añadir / Eliminar" << endl;
                    cout << "\t1 -> Reemplazar" << endl;
                    cout << "********************************************" << endl;
                    cout << "***** Typos de condiciones :" << endl;
                    cout << "\t0 -> =" << endl;
                    cout << "\t1 -> !=" << endl;
                    cout << "\t2 -> >=" << endl;
                    cout << "\t3 -> >" << endl;
                    cout << "\t4 -> <=" << endl;
                    cout << "\t5 -> <" << endl;
                    cout << "********************************************" << endl;
                    cout << "***** Entradas especiales :" << endl;
                    cout << "\t0 -> Menú" << endl;
                    cout << "\t1 -> Comienza el juego" << endl;
                    cout << "\t-4 -> Juego terminado" << endl;
                    cout << "********************************************" << endl;
                    cout << "***** Entradas especiales del menú :" << endl;
                    cout << "\t-1 -> Inventario" << endl;
                    cout << "\t-2 -> Salvar" << endl;
                    cout << "\t-3 -> Volver al juego" << endl;
                    cout << "\t-4 -> Salir el juego" << endl;
                #endif
                break;
            case 7:
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

void C_Game::listItems(void)
{
    unsigned int i;

    cout << endl;
    #ifdef FR
        cout << "Liste des objets du jeu :" << endl;
    #endif
    #ifdef ENG
        cout << "Game's objects list :" << endl;
    #endif
    #ifdef ESP
        cout << "Lista de objetos del juego :" << endl;
    #endif

    for (i = 0 ; i < itemTab.size() ; i++)
    {
        cout << itemTab[i].getItemNum() << " - " << itemTab[i].getItemName() << endl;
    }

    cout << endl;
}
