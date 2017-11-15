#ifndef TEXTURESPLITER_HPP
#define TEXTURESPLITER_HPP

// SFML Include
#include "SFML/Graphics/Texture.hpp"

// Project Include
#include "Tuile.hpp"

// STD Include
#include <memory>
#include <map>

class TextureSpliter : public sf::Texture
{
public:

    // Typedef
    typedef std::shared_ptr<sf::Sprite> Ptr;
    typedef std::shared_ptr<std::map<unsigned int, Ptr>> MapPtr;

    // Function
    TextureSpliter();
    TextureSpliter(const sf::Texture& copy);
    ~TextureSpliter();

    void        split(sf::Vector2u& pix);
    MapPtr      getSplitMap();

private:

    MapPtr      m_TuileMap;
};

#endif // TEXTUREHOLDING_HPP
