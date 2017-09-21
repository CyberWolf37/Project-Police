#include "IOFile.hpp"
#include <string>


IOFile::IOFile()
    : mFile(new IOFile::File)
{

}

IOFile::IOFile(const std::string& name)
    : mFile(new IOFile::File)
{
    mFile->nameFile = name;

    if(loadFromFile(mFile->nameFile))
    {
        std::cout << "Fichier ouvert : " << mFile->nameFile << std::endl;
    }
    else
    {
        std::cout << "Problème ouverture du fichier : " << mFile->nameFile << std::endl;
    }

}

IOFile::~IOFile()
{
    // Delete mFile Ptr
    delete mFile;
    mFile = 0;
}

// Read the file text
bool IOFile::readFile()
{
    // Initialise stream for file and char to read the char
    std::ifstream file;
    char chr;

    // Open The file
    file.open(mFile->nameFile, std::ios::in);

    // File Was open
    if(file.is_open())
    {
        // Boucle do While
        do
        {

            // Pick a char
            file.get(chr);

            // And check the char
            switch (chr) {

            case '<':
                {

                // If Balise was detected we read it
                readBalise(file);

                break;
                }

            default:
                break;
            }

        }while ( !file.eof());

        //We close the file because we have done
        file.close();
    }
    else
    {
        return false;
    }
}

// Save the last update of What we done in the file
bool IOFile::saveFile()
{

    // Initialise the stream of file
    std::ofstream file(mFile->nameFile,std::ios::out);

    // We wright in the file with an structure of file
    if(file)
    {
        file << "# This is a map load by IOMap" << "\n\n\n";
        file << "#---------Balises---------" << std::endl;
        writeBalise(file);

        file << "\n\n";
        file << "#---------Layouts---------" << std::endl;
        writeLayout(file);
        file.close();
        return true;
    }
    else
    {
        std::cout << "Problème ouverture du fichier : " << mFile->nameFile << std::endl;
        return false;
    }
}

// Load the file
bool IOFile::loadFromFile(const std::string& name)
{
    // Set the name of file. so we have a file
    mFile->nameFile = name;

    // initialise the stream of file
    std::ifstream file(name,std::ios::in);

    if(file)
    {
        readFile();
        file.close();
        return true;
    }
    else
    {
        return false;
    }
}

// Read the balise detected
void IOFile::readBalise(std::ifstream &file)
{
    // If file was open (normaly it is)
    if(file.is_open())
    {

        // Initalise a object balise, an char and a bool for check parameter
        std::unique_ptr<Balise> balise(new Balise);
        char chr;
        bool isParameter = false;

        // Boucle to check every char in the balise
        do
        {
            // pick a char
            file.get(chr);

            // Check the right way
            if(chr != ':' && chr != '>' && isParameter == false)
            {
                balise->nameBalise += chr;

            }
            else if(chr == ':' )
            {
                isParameter = true;
            }
            else if(chr != '>' && isParameter == true)
            {
                balise->nameParameter += chr;
            }

        }while(chr != '>');

        if (chr == '>' && balise->nameBalise != "Layout" && balise->nameBalise != "" )
        {
            // Insert of balise in the file object
            mFile->Balises.push_back(std::move(balise));

        }
        else if(balise->nameBalise == "Layout" && chr == '>')
        {

            // Initialise the object layout
            std::unique_ptr<Layout> layout(new Layout);
            // Set the name of layout
            if(balise->nameParameter == "BackGround")
            {
                layout->category = Category::Layers::SceneGroundLayer;
            }
            else if(balise->nameParameter == "Building")
            {
                layout->category = Category::Layers::SceneBuildingLayer;
            }
            else
            {
                layout->category = Category::Layers::None;
            }

            layout->nameLayout = balise->nameParameter;
            // Reset balise we receive
            balise.reset(nullptr);

            // Read the layout
            readLayout(file, layout);
        }
        else
        {
            balise.reset(nullptr);

        }
    }
    else
    {
        std::cout << "Erreur ouverture fichier " << mFile->nameFile << " : IOMap::readBalise" << std::endl;
    }
}

// Read The layout detected
void IOFile::readLayout(std::ifstream& file, std::unique_ptr<Layout>& layout)
{
    if(file.is_open())
    {
        file.ignore(200,'{');
        readNumber(file, layout);
        mFile->Layouts.push_back(std::move(layout));
    }
    else
    {
        std::cout << "Erreur ouverture fichier " << mFile->nameFile << " : IOMap::readLayout" << std::endl;
    }

}

// Read The Number detected
void IOFile::readNumber(std::ifstream& file, std::unique_ptr<Layout>& layout)
{

    // Initialise some of variable to work this function
    std::vector<unsigned int>   number;
    char                        chr;
    std::string                 string;
    bool                        isFinish = false;
    size_t                      countNumber = 0;

    // If Stream was open
    if(file.is_open())
    {

        // Boucle do while
        do
        {

            // Pick a char
            file.get(chr);

            if(chr != ';' && chr != '}' && chr != '\n')
            {
                string += chr;
            }
            else if(chr == ';')
            {
                // We take the string "int" and we cast it on unsigned int
                number.push_back(static_cast<unsigned int>(std::stoi(string,nullptr)));
                countNumber ++;

                // Clear the string for another int
                string.clear();

            }
            else if(chr == '\n')
            {
                // We take the string "int" and we cast it on unsigned int
                number.push_back(static_cast<unsigned int>(std::stoi(string,nullptr)));
                countNumber ++;

                // Clear the string for another int
                string.clear();
            }
            else if(chr == '}')
            {
                // We take the string "int" and we cast it on unsigned int
                number.push_back(static_cast<unsigned int>(std::stoi(string,nullptr)));
                countNumber ++;

                // Clear the string for another int
                string.clear();

                // It's finish because we have }
                isFinish = true;
            }
        }while(!isFinish);

        // Set LayerTile
        layout->layerTile = number;
    }
    else
    {
        std::cout << "Erreur ouverture fichier " << mFile->nameFile << " : IOMap::readNumber" << std::endl;
    }
}

// Wright the balise detected
void IOFile::writeBalise(std::ofstream &file)
{
    if(file.is_open())
    {
        // save Balises
        for(size_t i = 0; i < mFile->Balises.size(); i++)
        {
            file << "<" << mFile->Balises[i]->nameBalise
                 << ":" << mFile->Balises[i]->nameParameter
                 << ">" << std::endl;
        }

    }
    else
    {
        std::cout << "Erreur ouverture fichier " << mFile->nameFile << " : IOMap::readNumber" << std::endl;
    }
}

// Wright The layout detected
void IOFile::writeLayout(std::ofstream &file)
{
    // File is open ?
    if(file.is_open())
    {
        // save Layout
        for(size_t i = 0; i < mFile->Layouts.size(); i++)
        {
            file << "<" << "Layout"
                 << ":" << mFile->Layouts[i]->nameLayout
                 << ">" << std::endl;

            file << "{";

            // Set layout size
            size_t layoutSize = mFile->Layouts[i]->layerTile.size();

            // Counter for line in the file
            size_t counter = 0;

            // Save number of layout
            for(size_t j = 0; j < layoutSize; j++)
            {
                // Take the number
                unsigned int numberRec = mFile->Layouts[i]->layerTile[j];

                // wright the number in the file
                file << numberRec;

                // Increment the counter
                counter++;

                if(j != layoutSize-1 && counter != STD_MANY_NUMBER_LINE)
                {
                    file << ";";
                }
                else if(counter == STD_MANY_NUMBER_LINE)
                {
                    file << std::endl;

                    // Reset the counter
                    counter = 0;

                }
                else if(j == layoutSize-1)
                {
                    file << "}" << std::endl << std::endl;
                }
                else
                {
                    file << std::endl;
                }
            }
        }
    }
    else
    {
        std::cout << "Erreur ouverture fichier " << mFile->nameFile << " : IOMap::readNumber" << std::endl;
    }
}

// Get the file
IOFile::File* IOFile::getFile()
{
    return mFile;
}

//Get the tuile Map
IOFile::MapTuile& IOFile::getTuile(Category::Layers categoryLayer, TuileState::ID tuileCategory, sf::Texture& texture, sf::Vector2u& pix)
{
    // Get world number of tile
    size_t countX = texture.getSize().x / pix.x;
    size_t countY = texture.getSize().y / pix.y;

    // Counter to split tile
    unsigned int counter = 0;
    MapTuile mapTuile;
    std::vector<Tuile> vector;


    // Index
    sf::IntRect index(0,0,pix.x,pix.y);

    // Split the texture
    for(size_t i = 0;i < countY; i++)
    {
        for(size_t j = 0;j < countX; j++ , counter++)
        {
            // si j = 0 on remet à zero l'index
            if(j == 0)
            {
                index.left = 0;

                // Add in Tuile
                sf::Sprite sprite (texture,index);
                Tuile tuile(counter,pix,sprite,categoryLayer);

                // Insert in vector in a map
                vector.push_back(tuile);
            }
            else
            {
                // On ajoute pix sur X
                index.left += pix.x;

                // Add in sprite
                sf::Sprite sprite (texture,index);
                Tuile tuile(counter, pix, sprite, categoryLayer, tuileCategory);

                // Insert in vector
                vector.push_back(std::move(tuile));
            }
        }

        // On ajoute pix sur y
        index.top += pix.y;
    }

    // Set vector in map
    mapTuile[categoryLayer] = vector;

    for(size_t i = 0; i < mFile->Layouts.size(); i++)
    {
        if(mFile->Layouts[i]->category == categoryLayer)
        {
            mFile->Layouts[i]->mapTuile = mapTuile;

            // Return Array
            return mFile->Layouts[i]->mapTuile;
        }
    }
}
