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

    /// Chargement/Nouveau
    string fileName;
    unsigned int choice = 0;
    bool choiceBis = false;

    while (stay)
    {
        #ifdef FR
            cout << "Editeur V" << VERSION << " de Livres Dont Vous êtes Le Héros par Tattus" << endl;
            cout << endl << "Que faire ?" << endl;
            cout << "1 - Charger fichier existant" << endl;
            cout << "2 - Créer nouveau fichier" << endl;
            cout << "3 - Quitter" << endl;
        #endif // FR
        #ifdef ENG
            cout << "Editor V" << VERSION << " of books where you are the Hero by Tattus" << endl;
            cout << endl << "What to do ?" << endl;
            cout << "1 - Load existing file" << endl;
            cout << "2 - Create new file" << endl;
            cout << "3 - Leave" << endl;
        #endif // ENG
        #ifdef ESP
            cout << "Editor V" << VERSION << " de Libros donde eres el héroe por Tattus" << endl;
            cout << endl << "¿Qué quieres hacer?" << endl;
            cout << "1 - Cargar archivo existente " << endl;
            cout << "2 - Crear archivo nuevo" << endl;
            cout << "3 - Salir" << endl;
        #endif // ESP
        cin >> choice;
        if(cin.fail())
        {
            choice = 0;
        }

        switch(choice)
        {
            case 1:
                listeGameFiles();
                #ifdef FR
                    cout << "Indiquer le nom du fichier Jeu" << endl;
                #endif
                #ifdef ENG
                    cout << "Indicate file name" << endl;
                #endif
                #ifdef ESP
                    cout << "Indicar nombre del archivo" << endl;
                #endif
                cin.ignore();
                getline(cin, fileName);
                gameTab = loadGame(fileName, &stay);
                break;
            case 2:
                #ifdef FR
                    cout << "Indiquer le nom du fichier Jeu" << endl;
                #endif
                #ifdef ENG
                    cout << "Indicate file name" << endl;
                #endif
                #ifdef ESP
                    cout << "Indicar nombre del archivo" << endl;
                #endif
                cin.ignore();
                getline(cin, fileName);
                if (!saveGame(gameTab, fileName, false))
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
                        saveGame(gameTab, fileName, true);
                    }
                    else
                    {
                        break;
                    }
                }
                stay = false;
                break;
            case 3:
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
                return 0;
                break;
        }
    }

    /// Environnement de travail
    stay = true;
    C_Game gameTemp;
    while (stay)
    {
        #ifdef FR
            cout << "********************************************" << endl;
            cout << "Editeur V" << VERSION << " de Livres Dont Vous êtes Le Héros par Tattus" << endl;
            cout << "Que faire ?" << endl;
            cout << "1 - Lister les jeux (";
            cout << gameTab.size() << ")" << endl;
            cout << "2 - Charger un jeu" << endl;
            cout << "3 - Créer un nouveau jeu" << endl;
            cout << "4 - Quitter" << endl;
        #endif
        #ifdef ENG
            cout << "********************************************" << endl;
            cout << "Editor V" << VERSION << " of books where you are the Hero by Tattus" << endl;
            cout << "What to do ?" << endl;
            cout << "1 - Show games list (";
            cout << gameTab.size() << ")" << endl;
            cout << "2 - Load game" << endl;
            cout << "3 - Create new game" << endl;
            cout << "4 - Leave" << endl;
        #endif
        #ifdef ESP
            cout << "********************************************" << endl;
            cout << "Editor V" << VERSION << " de Libros donde eres el héroe por Tattus" << endl;
            cout << "¿Qué quieres hacer?" << endl;
            cout << "1 - Mostrar la lista de juegos (";
            cout << gameTab.size() << ")" << endl;
            cout << "2 - Cargar un juego" << endl;
            cout << "3 - Crear un juego nuevo" << endl;
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
                gameTab[choice].editGame();
                saveGame(gameTab, fileName, true);
                break;
            case 3:
                gameTemp.setGameNum(gameTab.size());
                gameTemp.setGameName(setName());
                gameTemp.setGameAuthor(setAuthor());

                gameTab.push_back(gameTemp);
                gameTab[gameTab.size() - 1].editGame();
                saveGame(gameTab, fileName, true);
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
