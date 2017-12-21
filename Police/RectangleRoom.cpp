#include "RectangleRoom.hpp"
#include <typeinfo>

namespace BUILD_OBJECT
{

RectangleRoom::RectangleRoom(TextureHolder& texture,SceneNode& worldScene)
    : Build()
    , mIsSet(false)
    , mIsFirst(false)
    , mBounds()
    , mTexture(texture)
    , mRenderTexture()
    , mPositionBegin()
    , mPositionEnd()
    , mWorldScene(worldScene)
{

}

void RectangleRoom::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
    if(mIsSet)
    {
        // Apply transform of current node
        states.transform *= getTransform();

        // Draw the future of rectangle room

    }
    else if(mIsSet)
    {
        // Apply transform of current node
        states.transform *= getTransform();

    }
}

void RectangleRoom::handleEvent(const sf::Event &event, const sf::Vector2i& positionMouse)
{
    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        mIsFirst    = true;
        mIsSet      = true;
        insertRoom(positionMouse);
    }
    else if(event.type == sf::Event::MouseButtonReleased)
    {
        insertRoom(positionMouse);
        mIsSet      = false;
    }
}

bool RectangleRoom::checkColision(sf::Vector2i &position)
{
    // Do nothing now
}

void RectangleRoom::insertRoom(const sf::Vector2i &position)
{
    // If is the first when we take the position we save it
    if(mIsFirst)
    {
        mPositionBegin = position;
        mIsFirst = false;
    }
    else if(mIsSet && !mIsFirst)
    {
        mPositionEnd = position;

        auto tuile_Begin (getCurrentSceneNode(mPositionBegin));
        auto tuile_End (getCurrentSceneNode(mPositionEnd));

        sf::Vector2f positionNext (tuile_Begin.getPosition() - tuile_End.getPosition());
        positionNext /= 16.f;

        std::vector<SceneNode> stackTuile;
        stackTuile.push_back(tuile_Begin);

        // In Axe X
        if(positionNext.x > 0)
        {
            for(size_t i = 0; i < positionNext.x ; i++)
            {
                stackTuile.push_back(*getCurrentSceneNode(tuile_Begin.getPosition().x + (16 * i)));
                stackTuile.push_Back(*getCurrentSceneNode(tuile_End.getPosition().x - (16 * i)));
            }
        }
        else if(positionNext.x < 0)
        {
            position_idx = positionNext.x *-1;
            for(size_t i = 0; i < position_idx ; i++)
            {
                stackTuile.push_back(*getCurrentSceneNode(tuile_Begin.getPosition().x - (16 * i)));
                stackTuile.push_back(*getCurrentSceneNode(tuile_Begin.getPosition().x + (16 * i)));

            }
        }

        // In Axe Y
        if(positionNext.y > 0)
        {
            for(size_t i = 0; i < positionNext.x ; i++)
            {
                stackTuile.push_back(*getCurrentSceneNode(tuile_Begin.getPosition().y + (16 * i)));
                stackTuile.push_Back(*getCurrentSceneNode(tuile_End.getPosition().y - (16 * i)));
            }
        }
        else if(positionNext.y < 0)
        {
            position_idx = positionNext.x *-1;
            for(size_t i = 0; i < position_idx ; i++)
            {
                stackTuile.push_back(*getCurrentSceneNode(tuile_Begin.getPosition().y - (16 * i)));
                stackTuile.push_back(*getCurrentSceneNode(tuile_Begin.getPosition().y + (16 * i)));
            }
        }

        // Finish with the Tuile End
        stackTuile.push_back(tuile_End);

        for (Tuile& child : stackTuile)
        {
            if(child.getIsActive())
            {
                child.getSprite()->setColor(sf::Color::Blue);
            }
            else
            {
                child.getSprite()->setColor(sf::Color::Red);
            }
        }

    }
}

void RectangleRoom::setRoomTexture()
{


}


} // End of namespace
