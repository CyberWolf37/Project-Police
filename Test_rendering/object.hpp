#ifndef OBJECT_HPP
#define OBJECT_HPP

// SFML Library
#include "SFML/System/NonCopyable.hpp"
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Transformable.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Graphics/RenderStates.hpp"
#include "SFML/Graphics/RenderTarget.hpp"

// STD Library
#include <typeinfo>
#include <iostream>
#include <string>


class Object : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
public:

    Object();

    virtual void            handleEvent(const sf::Event& event, const sf::Vector2i& positionMouse) = 0;
    virtual void            update(sf::Time dt) = 0;
    virtual void            draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

    virtual const bool&     isActive() const;
    virtual void            getType();

private:
    bool                    m_isActive;
    sf::IntRect             m_bounds;

};

#endif // OBJECT_HPP
