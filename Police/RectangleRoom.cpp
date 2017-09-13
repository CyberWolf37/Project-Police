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
    , mStackSprite()
{

    // Set Textures
    setStackTexture();

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

void RectangleRoom::setStackTexture()
{
    // For TopLeft
    sf::IntRect rectTopLeft (0,0,64,64);
    sf::Sprite  topLeftSprite (mTexture.get(Textures::TileSetBuild), rectTopLeft);

    // For TopRight
    sf::IntRect rectTopRight (64,0,64,64);
    sf::Sprite  topRightSprite (mTexture.get(Textures::TileSetBuild), rectTopRight);

    // For BottomLeft
    sf::IntRect rectBottomLeft (0,64,64,64);
    sf::Sprite  bottomLeftSprite (mTexture.get(Textures::TileSetBuild), rectBottomLeft);

    // For BottomRight
    sf::IntRect rectBottomRight (64,64,64,64);
    sf::Sprite  bottomRightSprite (mTexture.get(Textures::TileSetBuild), rectBottomRight);

    // For MiddleSide
    sf::IntRect rectMiddleSide (0,128,64,64);
    sf::Sprite  middleSideSprite (mTexture.get(Textures::TileSetBuild), rectMiddleSide);

    // For MiddleFront
    sf::IntRect rectMiddleFront (128,128,64,64);
    sf::Sprite  middleFrontSprite (mTexture.get(Textures::TileSetBuild), rectMiddleFront);

    // Stack all Sprite in a map
    mStackSprite[TopLeft]           = topLeftSprite;
    mStackSprite[TopRight]          = topRightSprite;
    mStackSprite[MiddleFront]       = middleFrontSprite;
    mStackSprite[MiddleSide]        = middleSideSprite;
    mStackSprite[BottomLeft]        = bottomLeftSprite;
    mStackSprite[BottomRight]       = bottomRightSprite;

}



} // End of namespace
