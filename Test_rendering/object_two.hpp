#ifndef OBJECT_TWO_HPP
#define OBJECT_TWO_HPP

#include "object_one.hpp"


class Object_two : public Object_one
{
public:
    Object_two();

    virtual void            handleEvent(const sf::Event& event, const sf::Vector2i& positionMouse){}
    virtual void            update(sf::Time dt){}
    virtual void            draw(sf::RenderTarget& target, sf::RenderStates states) const {}

    virtual void            hello();
};

#endif // OBJECT_TWO_HPP
