#ifndef IOFILE_H
#define IOFILE_H

// Category
#include "Category.hpp"

// Core Library
#include "Tuile.hpp"
#include "ResourceHolder.hpp"

// Sfml library
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

// STD librarary
#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <memory>
#include <map>

// Option standard
#define STD_NAME_FILE "test.txt"
#define STD_MANY_NUMBER_LINE 100


class IOFile
{

// Structure of IOFile
public:
    typedef std::map<Category::Layers,std::vector<std::shared_ptr<Tuile>>> MapTuile;

    struct Layout
    {
        std::string                 nameLayout;
        std::vector<unsigned int>   layerTile;
        Category::Layers            category;
        MapTuile                    mapTuile;
    };
    struct Balise
    {
        std::string         nameBalise;
        std::string         nameParameter;
    };

    struct File
    {
        std::string                             nameFile;
        std::vector<std::unique_ptr<Layout>>    Layouts;
        std::vector<std::unique_ptr<Balise>>    Balises;
    };



// Main Function
public:
    IOFile();
    IOFile(std::string& name);
    ~IOFile();

    bool            readFile();

    bool            saveFile();

    bool            loadFromFile(std::string& name);

    File*           getFile();

    std::shared_ptr<MapTuile> getTuile(Category::Layers categoryLayer, TuileState::ID tuileCategory, sf::Texture& texture, sf::Vector2u& pix);


// Private function read and wright
private:
    void            readBalise(std::ifstream& file);
    void            readLayout(std::ifstream& file, std::unique_ptr<Layout> &layout);
    void            readNumber(std::ifstream& file, std::unique_ptr<Layout> &layout);

    void            writeBalise(std::ofstream& file);
    void            writeLayout(std::ofstream& file);

// Atribute of file
private:
    File*           mFile;
};

#endif // IOFILE_H
