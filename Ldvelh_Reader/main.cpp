#define WINDOWS_USED

#include <iostream>
#include <vector>
#ifdef WINDOWS_USED
    #include <windows.h> // Pour la fonction SetConsoleOutputCp()
#endif // WINDOWS_USED
#include "language.hpp"
#include "load_save.hpp"
#include "game.hpp"

using namespace std;

int main()
{
    #ifdef WINDOWS_USED
        SetConsoleOutputCP(1252);
        SetConsoleCP(1252);
    #endif // WINDOWS_USED
    bool stay = true;

    vector<C_Game> gameTab;

    /// Chargement
    string fileName;
    unsigned int choice = 0;

    while (stay)
    {
        #ifdef FR
            cout << "Lecteur V" << VERSION << " de Livres Dont Vous êtes Le Héros par Tattus" << endl;
            cout << endl << "Indiquer le fichier de jeu" << endl;
        #endif
        #ifdef ENG
            cout << "Reader V" << VERSION << " of books where you are the Hero by Tattus" << endl;
            cout << endl << "Indicate game file" << endl;
        #endif
        #ifdef ESP
            cout << "Lector V" << VERSION << " de Libros donde eres el héroe por Tattus" << endl;
            cout << endl << "Indicar el archivo del juego" << endl;
        #endif
        listeGameFiles();
        getline(cin, fileName);
        gameTab = loadGame(fileName, &stay);
    }

    /// Menu
    stay = true;
    C_Game gameTemp;
    while (stay)
    {
        cout << "********************************************" << endl;
        #ifdef FR
            cout << "Lecteur V" << VERSION << " de Livres Dont Vous êtes Le Héros par Tattus" << endl;
            cout << "Que faire ?" << endl;
            cout << "1 - Lister les jeux (";
            cout << gameTab.size() << ")" << endl;
            cout << "2 - Charger un jeu" << endl;
            cout << "3 - Documentation" << endl;
            cout << "4 - Quitter" << endl;
        #endif
        #ifdef ENG
            cout << "Reader V" << VERSION << " of books where you are the Hero by Tattus" << endl;
            cout << "What to do ?" << endl;
            cout << "1 - Show games list (";
            cout << gameTab.size() << ")" << endl;
            cout << "2 - Load game" << endl;
            cout << "3 - Documentation" << endl;
            cout << "4 - Leave" << endl;
        #endif
        #ifdef ESP
            cout << "Lector V" << VERSION << " de Libros donde eres el héroe por Tattus" << endl;
            cout << "¿Qué quieres hacer?" << endl;
            cout << "1 - Mostrar la lista de juegos (";
            cout << gameTab.size() << ")" << endl;
            cout << "2 - Cargar un juego" << endl;
            cout << "3 - documentación" << endl;
            cout << "4 - Salir" << endl;
        #endif
        cin >> choice;
        if(cin.fail())
        {
            choice = 0;
        }

        switch(choice)
        {
            case 1:
                cout << "***" << endl;
                if (gameTab.size() > 0)
                {
                    for (unsigned int i = 0 ; i < gameTab.size() ; i++)
                    {
                        cout << i << " -> " << gameTab[i].getGameName() << endl;
                    }
                }
                break;
            case 2:
                #ifdef FR
                    cout << "Indiquer le numéro du jeu" << endl;
                #endif
                #ifdef ENG
                    cout << "Indicate game number" << endl;
                #endif
                #ifdef ESP
                    cout << "Indicar el número del juego" << endl;
                #endif
                cin >> choice;
                if(cin.fail() || choice >= gameTab.size())
                {
                    choice = 0;
                }
                gameTab[choice].runMenu();
                break;
            case 3:
                #ifdef FR
                    cout << "Choisir 0 en jeu pour se rendre au menu" << endl;
                #endif
                #ifdef ENG
                    cout << "Type 0 in game to go to menu" << endl;
                #endif
                #ifdef ESP
                    cout << "Escribe 0 en el juego para ir al menú" << endl;
                #endif
                break;
            case 4:
                return 0;
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

    return 0;
}
