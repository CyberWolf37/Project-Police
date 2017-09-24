#include "TextureHolding.hpp"

TextureHolding::TextureHolding()
    : Texture()
    , m_TuileMap(new std::map<unsigned int, Ptr>)
{

}

TextureHolding::TextureHolding(const sf::Texture &copy)
    : Texture(copy)
    , m_TuileMap(new std::map<unsigned int, Ptr>)
{

}

void TextureHolding::split(sf::Vector2u &pix)
{
    // Get world number of tile
    size_t countX = this->getSize().x / pix.x;
    size_t countY = this->getSize().y / pix.y;

    // Counter to split tile
    unsigned int counter = 0;

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
                sf::Sprite sprite (*this,index);
                Ptr tuile(new Tuile(counter,pix,sprite));

                // Insert in a map
                (*m_TuileMap)[counter] = std::move(tuile);
            }
            else
            {
                // On ajoute pix sur X
                index.left += pix.x;

                // Add in sprite
                sf::Sprite sprite (*this,index);
                Ptr tuile(new Tuile(counter, pix, sprite));

                // Insert in map
                (*m_TuileMap)[counter] = std::move(tuile);
            }
        }

        // On ajoute pix sur y
        index.top += pix.y;
    }
}

std::map<unsigned int, TextureHolding::Ptr> *TextureHolding::getSplitMap()
{
    return m_TuileMap.get();

}
