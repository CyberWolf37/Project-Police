#include "Tuile.hpp"

// Debug
#include <QDebug>


Tuile::Tuile()
{

}

Tuile::Tuile(const Tuile &copy)
    : mTuileCategory(copy.getTuileCategory())
    , mPixSize(copy.getPixSize())
    , mSprite(copy.getSprite())
    , mCount(copy.getCount())
{
    setActivate(false);
    setSelected(false);
}

Tuile::Tuile(unsigned int& count, sf::Vector2u &pixSize, sf::Sprite& sprite, Category::Layers layerCategory, TuileState::ID tuileCategory)
    : SceneNode(layerCategory)
    , mTuileCategory(tuileCategory)
    , mPixSize(pixSize)
    , mSprite(sprite)
    , mCount(count)
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
        target.draw(mSprite, states);
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
            mSprite.setColor(sf::Color(255, 255, 255, 128));
        }
    }
    else
    {
        setSelected(false);
    }

}

const sf::Vector2u& Tuile::getPixSize() const
{
    return mPixSize;
}

TuileState::ID Tuile::getTuileCategory() const
{
    return mTuileCategory;
}

void Tuile::setTuileCategory(TuileState::ID id)
{
    mTuileCategory = id;
}


const unsigned int Tuile::getCount() const
{
    return mCount;
}

void Tuile::setCount(unsigned int& count)
{
    mCount = count;
}

const sf::Sprite& Tuile::getSprite() const
{
    return mSprite;
}

void Tuile::setSprite(sf::Sprite& sprite)
{
    mSprite = sprite;
}

const sf::IntRect Tuile::getRectBounds()
{
    sf::IntRect result(mSprite.getGlobalBounds());

    result.left = this->getPosition().x;
    result.top  = this->getPosition().y;

    return result;

}
