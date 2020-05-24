#include "language.hpp"
#include "load_save.hpp"

vector<C_Game> loadGame(string fileName, bool *loadError)
{
    vector<C_Game> gameTab;
    fileName = fileName + ".game" + VERSION_BASE + "v";
    ifstream myFile(fileName.c_str());
    if (myFile.is_open())
    {
        {
            boost::archive::xml_iarchive ia(myFile);
            ia >> BOOST_SERIALIZATION_NVP(gameTab);
        }

        myFile.close();
        *loadError = false;
    }
    else
    {
        #ifdef FR
            cout << "Le fichier " << fileName << " est introuvable" << endl;
        #endif
        #ifdef ENG
            cout << "The file " << fileName << " could not found" << endl;
        #endif
        #ifdef ESP
            cout << "El archivo " << fileName << " no se pudo encontrar" << endl;
        #endif
        *loadError = true;
    }

    return gameTab;
}

void listeGameFiles(void)
{
    boost::filesystem::path p(".");
    stringstream entryText;
    entryText.str("");
    string textTemp = ".game";
    textTemp = textTemp + VERSION_BASE + "v";

    cout << endl;
    if(boost::filesystem::is_directory(p))
    {
        #ifdef FR
            cout << "Liste des fichiers de jeux :" << endl;
        #endif
        #ifdef ENG
            cout << "Files games list :" << endl;
        #endif
        #ifdef ESP
            cout << "Lista de archivos del juegos :" << endl;
        #endif

        for(auto& entry : boost::make_iterator_range(boost::filesystem::directory_iterator(p), {}))
        {
            entryText << entry;
            if (entryText.str().rfind(textTemp) != string::npos)
            {
                entryText.str(entryText.str().substr(3, entryText.str().size() - 11));

                cout << " - " << entryText.str() << endl;
            }
            entryText.str("");
        }
    }
    cout << endl;
}
