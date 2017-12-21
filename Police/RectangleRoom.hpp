#ifndef RECTANGLEROOM_H
#define RECTANGLEROOM_H

// Core Library
#include "build.hpp"
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "Tuile.hpp"
#include "Foreach.hpp"

// SFML Library
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RenderTexture.hpp"
#include "SFML/Window/Event.hpp"

namespace BUILD_OBJECT
{
class RectangleRoom : public Build
{

public:

    // Enum for the tuile we use for drawing
    enum TypeTuile
    {
        TopLeft,
        TopRight,
        MiddleFront,
        MiddleSide,
        BottomLeft,
        BottomRight,
    };

    // Enum for the type we build
    enum TypeBuild
    {
        Chamber,
        TypeCount,
    };

    typedef std::map<RectangleRoom::TypeTuile,Tuile> TuileMap;

public:

    explicit                RectangleRoom(TextureHolder &texture,SceneNode& worldScene);

    virtual void            drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

    virtual void            handleEvent(const sf::Event& event, const sf::Vector2i& positionMouse);

    virtual bool            checkColision(sf::Vector2i& position);

    void                    insertRoom(const sf::Vector2i& position);


private:
    void                    setRoomTexture();

private:
    bool                    mIsSet;
    bool                    mIsFirst;

    TextureHolder&          mTexture;
    TuileMap                mStackTuile;
    sf::RenderTexture       mRenderTexture;

    sf::Vector2i            mPositionBegin;
    sf::Vector2i            mPositionEnd;
    SceneNode&              mWorldScene;

    sf::IntRect             mBounds;

};

} // END OF NAMESPACE BUILD_OBJECT

#endif // RECTANGLEROOM_H
