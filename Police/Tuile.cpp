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
    , mIsActive(copy.isActive())
    , mIsSelected(copy.isSelected())
{

}

Tuile::Tuile(unsigned int& count, sf::Vector2u &pixSize, sf::Sprite& sprite, Category::Layers layerCategory, TuileState::ID tuileCategory)
    : SceneNode(layerCategory)
    , mTuileCategory(tuileCategory)
    , mPixSize(pixSize)
    , mSprite(sprite)
    , mIsActive(true)
    , mIsSelected(false)
    , mCount(count)
{

}

Tuile::~Tuile()
{
}

void Tuile::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    // If is active drawing the tuile
    if(mIsActive)
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

void Tuile::handleEvent(const sf::Event &event, const sf::Window &window, const sf::View &view)
{
    if(event.type == sf::Event::MouseMoved)
    {
        // take the real position in the world
        sf::Vector2i positionView = static_cast<sf::Vector2i>(view.getCenter()) - (static_cast<sf::Vector2i>(view.getSize()) / 2);
        sf::Vector2i positionMouse = sf::Mouse::getPosition(window) + positionView;

        // Check if in this tuile we have the mouse
        if(this->getRectBounds().contains(positionMouse))
        {
            mIsSelected = true;
            mSprite.setColor(sf::Color(255, 255, 255, 128));
        }
    }
    else
    {
        deSelect();
    }

}

const sf::Vector2u& Tuile::getPixSize() const
{
    return mPixSize;
}

bool Tuile::isActive() const
{
    return mIsActive;
}

void Tuile::deactivate()
{
    mIsActive = false;
}

bool Tuile::isSelected() const
{
    return mIsSelected;
}

void Tuile::deSelect()
{
    mIsSelected = false;
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
