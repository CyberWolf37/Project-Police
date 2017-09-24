#ifndef TEXTUREHOLDER_HPP
#define TEXTUREHOLDER_HPP

// SFML Include
#include "SFML/Graphics/Texture.hpp"

// Project Include
#include "Tuile.hpp"

// STD Include
#include <memory>
#include <map>


class TextureHolder : public sf::Texture
{
public:

    // Typedef
    typedef std::shared_ptr<Tuile> Ptr;
    typedef std::unique_ptr<std::map<unsigned int, Ptr>> MapPtr;

    // Function
    TextureHolder();
    TextureHolder(const Texture& copy);

    void        split(sf::Vector2u& pix);
    MapPtr*     getTuileMap();



private:

    MapPtr      m_TuileMap;
};

#endif // TEXTUREHOLDER_HPP
