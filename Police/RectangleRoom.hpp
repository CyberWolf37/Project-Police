#ifndef RECTANGLEROOM_H
#define RECTANGLEROOM_H

// Core Library
#include "build.hpp"
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "Tuile.hpp"

// SFML Library
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RenderTexture.hpp"
#include "SFML/Window/Event.hpp"

namespace BUILD_OBJECT
{
class RectangleRoom : public BUILD_OBJECT::Build
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

    explicit                RectangleRoom(TextureHolder &texture);

    virtual void            drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

    virtual void            handleEvent(const sf::Event& event);

    void                    insertRoom(const sf::Vector2i& position);
    bool                    getCurrentTuile(const sf::Vector2i& position)const;

    void                    setStackTexture();


private:



private:
    bool                    mIsSet;
    bool                    mIsCurrent;
    bool                    mIsFirst;

    TextureHolder&          mTexture;
    TuileMap                mStackTuile;
    sf::RenderTexture       mRenderTexture;

    sf::Vector2i            mPositionBegin;

    sf::IntRect             mBounds;

};

} // END OF NAMESPACE BUILD_OBJECT

#endif // RECTANGLEROOM_H
