#include "Tuile.hpp"

Tuile::Tuile(unsigned int& count, sf::Vector2u &pixSize, std::shared_ptr<sf::Sprite> sprite = std::unique_ptr<sf::Sprite>(new sf::Sprite()), Category::Layers layerCategory, TuileState::ID tuileCategory)
    : SceneNode(layerCategory)
    , mTuileCategory(tuileCategory)
    , mPixSize(pixSize)
    , mSprite(sprite)
    , mIsActive(false)
    , mIsSelected(false)
    , mRect()
    , mCount(count)
{
    // Set Pointeur
    mSprite->setPosition(this->getPosition());

    // Set the rect Position + bounds
    setRect();

}

Tuile::~Tuile()
{
}

void Tuile::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
    // If is active drawing the tuile
    if(mIsActive)
    {
        // Apply Transform of current Node
        states.transform *= getTransform();

        // Draw the Tuile
        target.draw(*mSprite, states);

    }

}

void Tuile::handleEvent(const sf::Event &event)
{
    if(event.type == sf::Event::MouseMoved && mRect.contains(sf::Mouse::getPosition()))
    {
        mIsSelected = true;
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

void Tuile::setRect()
{
    // Set the rect
    mRect.left  = mSprite->getPosition().x;
    mRect.top   = mSprite->getPosition().y;
    mRect.width = mPixSize.x;
    mRect.height= mPixSize.y;
}

const unsigned int Tuile::getCount() const
{
    return mCount;
}

void Tuile::setCount(unsigned int& count)
{
    mCount = count;
}

std::shared_ptr<sf::Sprite> Tuile::getSprite() const
{
    return mSprite;
}

void Tuile::setSprite(std::shared_ptr<sf::Sprite> sprite)
{
    mSprite = sprite;
}
