#include "Tuile.hpp"

// Debug
#include <QDebug>


Tuile::Tuile()
{

}

Tuile::Tuile(const Tuile &copy)
    : mTuileCategory(copy.getTuileCategory())
    , mSprite(copy.getSprite())
{
    setActivate(false);
    setSelected(false);
}

Tuile::~Tuile()
{
}

void Tuile::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    // If is active drawing the tuile
    if(isActive())
    {
        // Apply Transform of current Node
        states.transform *= getTransform();

        // Draw the Tuile
        target.draw(*mSprite, states);
    }

}

void Tuile::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{

}

void Tuile::handleEvent(const sf::Event &event, const sf::Vector2i& positionMouse)
{
    if(!isActive())
    {
        return;
    }

    if(event.type == sf::Event::MouseMoved)
    {
        // Check if in this tuile we have the mouse
        if(this->getRectBounds().contains(positionMouse))
        {
            setSelected(true);
        }
    }
    else
    {
        setSelected(false);
    }

}

TuileState::ID Tuile::getTuileCategory() const
{
    return mTuileCategory;
}

void Tuile::setTuileCategory(TuileState::ID id)
{
    mTuileCategory = id;
}

const std::shared_ptr<sf::Sprite> Tuile::getSprite() const
{
    return mSprite;
}

void Tuile::setSprite(std::shared_ptr<sf::Sprite> sprite)
{
    mSprite = sprite;
}

const bool &Tuile::getIsActive() const
{
    return mIsActive;
}

const sf::IntRect Tuile::getRectBounds()
{
    sf::IntRect result(mSprite->getGlobalBounds());

    result.left = this->getPosition().x;
    result.top  = this->getPosition().y;

    return result;

}
