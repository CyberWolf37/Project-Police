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
        qDebug() << "Passe 1.1";

    }
    else if(event.type == sf::Event::MouseButtonReleased)
    {
        qDebug() << "Passe 1.2";
        insertRoom(positionMouse);
        mIsSet      = false;
    }
}

bool RectangleRoom::checkColision(sf::Vector2i &position)
{
    // Do nothing now
}

bool RectangleRoom::insertRoom(const sf::Vector2i &position)
{
    // If is the first when we take the position we save it
    if(mIsFirst)
    {
        mPositionBegin = position;
        mIsFirst = false;
        return false;
    }
    else if(mIsSet && !mIsFirst)
    {
        mPositionEnd = position;

        SceneNode& tuile_Begin (getCurrentSceneNode(mPositionBegin));
        SceneNode& tuile_End (getCurrentSceneNode(mPositionEnd));

         qDebug() << "Passe 1.3";

        sf::Vector2f positionNext (tuile_Begin.getPosition() - tuile_End.getPosition());
        positionNext /= 16.f;

        std::vector<std::reference_wrapper<SceneNode>> stackTuile;
        stackTuile.push_back(tuile_Begin);

        // In Axe X
        if(positionNext.x > 0)
        {
            for(size_t i = 0; i < positionNext.x ; i++)
            {
                sf::Vector2i _position {static_cast<int>(tuile_Begin.getPosition().x) + (16 * i),static_cast<int>(tuile_Begin.getPosition().y)};
                stackTuile.push_back(getCurrentSceneNode(_position));

                _position.x = static_cast<int>(tuile_End.getPosition().x) - (16 * i);
                _position.y = static_cast<int>(tuile_Begin.getPosition().y);
                stackTuile.push_back(getCurrentSceneNode(_position));
            }
        }
        else if(positionNext.x < 0)
        {
            sf::Vector2i position_idx {static_cast<int>(positionNext.x *-1),positionNext.y};
            for(size_t i = 0; i < position_idx.x ; i++)
            {
                position_idx.x = static_cast<int>(tuile_Begin.getPosition().x) - (16 * i);
                stackTuile.push_back(getCurrentSceneNode(position_idx));
                position_idx.x = static_cast<int>(tuile_Begin.getPosition().x) + (16 * i);
                stackTuile.push_back(getCurrentSceneNode(position_idx));
            }
        }

        // In Axe Y
        if(positionNext.y > 0)
        {
            for(size_t i = 0; i < positionNext.y ; i++)
            {
                sf::Vector2i _position {static_cast<int>(tuile_Begin.getPosition().x),static_cast<int>(tuile_Begin.getPosition().y + (16 * i))};
                stackTuile.push_back(getCurrentSceneNode(_position));

                _position.x = static_cast<int>(tuile_Begin.getPosition().x);
                _position.y = static_cast<int>(tuile_Begin.getPosition().y + (16 * i));
                stackTuile.push_back(getCurrentSceneNode(_position));
            }
        }
        else if(positionNext.y < 0)
        {
            sf::Vector2i position_idx {positionNext.x,static_cast<int>(positionNext.y *-1)};
            for(size_t i = 0; i < position_idx.y ; i++)
            {
                position_idx.y = static_cast<int>(tuile_Begin.getPosition().y - (16 * i));
                stackTuile.push_back(getCurrentSceneNode(position_idx));
                position_idx.y = static_cast<int>(tuile_Begin.getPosition().y + (16 * i));
                stackTuile.push_back(getCurrentSceneNode(position_idx));
            }
        }

        // Finish with the Tuile End
        stackTuile.push_back(tuile_End);



        /*for (SceneNode& child : stackTuile)
        {
            if(child.getIsActive())
            {
                child.getSprite()->setColor(sf::Color::Blue);
            }
            else
            {
                child.getSprite()->setColor(sf::Color::Red);
            }
        }*/
    return true;
    }
}

Tuile &RectangleRoom::getCurrentTuile(const sf::Vector2i &position)
{
    qDebug() << "passe dynamic 1";
    auto& node = getCurrentSceneNode(position);
    qDebug() << "passe dynamic 1.1";
    qDebug() << typeid(node).name();
    if(typeid(node) == typeid(Tuile&))
    {
        qDebug() << "passe dynamic 2.1";
        return dynamic_cast<Tuile&>(node);
        qDebug() << "passe dynamic 2.2";
    }

}

void RectangleRoom::setRoomTexture()
{


}


} // End of namespace
