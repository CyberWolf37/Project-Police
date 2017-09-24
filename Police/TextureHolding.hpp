#ifndef TEXTUREHOLDER_HPP
#define TEXTUREHOLDER_HPP

// SFML Include
#include "SFML/Graphics/Texture.hpp"

// Project Include
#include "Tuile.hpp"

// STD Include
#include <memory>
#include <map>


class TextureHolding : public sf::Texture
{
public:

    // Typedef
    typedef std::shared_ptr<Tuile> Ptr;
    typedef std::unique_ptr<std::map<unsigned int, Ptr>> MapPtr;

    // Function
    TextureHolding();
    TextureHolding(const Texture& copy);

    void                            split(sf::Vector2u& pix);
    std::map<unsigned int, Ptr>*    getSplitMap();



private:

    MapPtr      m_TuileMap;
};

#endif // TEXTUREHOLDER_HPP
