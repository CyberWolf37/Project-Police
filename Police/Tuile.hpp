#ifndef TUILE_H
#define TUILE_H

// SFML Library
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/View.hpp"
#include "SFML/Graphics/Transformable.hpp"
#include "SFML/System/Vector2.hpp"

// Core Library
#include "SceneNode.hpp"
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "Utility.hpp"
#include "Position.hpp"

// STD library
#include <memory>

class Tuile
{
public:

    Tuile(sf::Transformable& object);
    ~Tuile();

    void                                handleEvent(const sf::Event& event, const sf::Vector2i& positionMouse);

    const bool&                         getIsActive() const;
    void                                setIsActive(const bool& active);

    const bool&                         getIsSelected() const;
    void                                setIsSelected();


    const sf::IntRect                   getRectBounds() const;
    void                                setRectBounds(const sf::Vector2f& bounds);

private:

    sf::Transformable&                  mObject;
    Position                            mPosition;
    bool                                mIsActive;
    bool                                mIsSelected;




};

#endif // TUILE_H
