#include "RectangleRoom.hpp"

namespace BUILD_OBJECT
{

RectangleRoom::RectangleRoom(TextureHolder &texture)
    : Build()
    , mIsSet(false)
    , mIsCurrent(false)
    , mIsFirst(false)
    , mBounds()
    , mTexture(texture)
    , mRenderTexture()
    , mPositionBegin()
{

}

void RectangleRoom::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
    if(mIsCurrent)
    {
        // Apply transform of current node
        states.transform *= getTransform();
    }
    else if(mIsSet)
    {
        // Apply transform of current node
        states.transform *= getTransform();

    }
}

void RectangleRoom::handleEvent(const sf::Event &event)
{
    if(mIsCurrent && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {

        insertRoom(sf::Mouse::getPosition());
    }
}

void RectangleRoom::insertRoom(const sf::Vector2i &position)
{
    // If is the first when we take the position we save it
    if(mIsFirst)
    {
        mPositionBegin = position;
        mIsFirst = false;
    }

    // we


}

bool RectangleRoom::getCurrentTuile(const sf::Vector2i &position) const
{

}


} // End of namespace
