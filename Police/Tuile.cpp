#include "Tuile.hpp"

// Debug
#include <QDebug>


Tuile::Tuile()
{

}

Tuile::Tuile(const std::shared_ptr<sf::Sprite>& sprite)
    : mSprite(*sprite)
{

}

Tuile::Tuile(const Tuile &copy)
    : mSprite(copy.getSprite())
{
    setIsActive(false);
    setIsSelected(false);
}

Tuile::~Tuile()
{
}

void Tuile::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    // Draw the mother class
    Tuile::draw(target,states);

    // If is active drawing the tuile
    if(getIsActive())
    {
        // Apply Transform of current Node
        states.transform *= getTransform();

        // Draw the Tuile
        target.draw(*mSprite, states);
    }

}

const std::shared_ptr<sf::Sprite> Tuile::getSprite() const
{
    return mSprite;
}

void Tuile::setSprite(std::shared_ptr<sf::Sprite> sprite)
{
    mSprite = sprite;
}
