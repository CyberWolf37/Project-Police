#include "Tuile.hpp"

// Debug
#include <QDebug>


Tuile::Tuile()
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
    qDebug() << "Passe Draw";
    // If is active drawing the tuile
    /*if(mIsActive)
    {
        // Apply Transform of current Node
        states.transform *= getTransform();

        // Draw the Tuile
        target.draw(mSprite, states);

    }*/

}

void Tuile::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
    qDebug() << "Passe drawCurrent";
    // If is active drawing the tuile
    /*if(mIsActive)
    {
        // Apply Transform of current Node
        states.transform *= getTransform();

        // Draw the Tuile
        target.draw(mSprite, states);

    }*/
}

void Tuile::handleEvent(const sf::Event &event)
{
    /*
    if(event.type == sf::Event::MouseMoved && mRect.contains(sf::Mouse::getPosition()))
    {
        mIsSelected = true;
    }
    else
    {
        deSelect();
    }*/

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

sf::Sprite& Tuile::getSprite()
{
    return mSprite;
}

void Tuile::setSprite(sf::Sprite& sprite)
{
    mSprite = sprite;
}
