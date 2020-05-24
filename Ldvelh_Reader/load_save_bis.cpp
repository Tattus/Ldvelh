#include "language.hpp"
#include "load_save_bis.hpp"

bool saveVerifExist(string fileName)
{
    fileName = fileName + ".sav" + VERSION_BASE + "v";

    if (boost::filesystem::exists(fileName))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void save(C_Save sauvegarde, string fileName)
{
    fileName = fileName + ".sav" + VERSION_BASE + "v";

    ofstream myFile(fileName.c_str());
    {
        boost::archive::xml_oarchive oa(myFile);
        oa << BOOST_SERIALIZATION_NVP(sauvegarde);
    }

    myFile.close();
}

C_Save load(string fileName, bool *loadError)
{
    C_Save sauvegarde;
    fileName = fileName + ".sav" + VERSION_BASE + "v";
    ifstream myFile(fileName.c_str());
    if (myFile.is_open())
    {
        {
            boost::archive::xml_iarchive ia(myFile);
            ia >> BOOST_SERIALIZATION_NVP(sauvegarde);
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

    return sauvegarde;
}

void listeGameSaves(void)
{
    boost::filesystem::path p(".");
    stringstream entryText;
    entryText.str("");
    string textTemp = ".sav";
    textTemp = textTemp + VERSION_BASE + "v";

    cout << endl;
    if(boost::filesystem::is_directory(p))
    {
        #ifdef FR
            cout << "Liste des fichiers de sauvegarde :" << endl;
        #endif
        #ifdef ENG
            cout << "Save files list :" << endl;
        #endif
        #ifdef ESP
            cout << "Lista de archivos de respaldo :" << endl;
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
