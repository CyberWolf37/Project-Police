#ifndef OBJECT_ONE_HPP
#define OBJECT_ONE_HPP

#include "object.hpp"
#include "iostream"


class Object_one : public Object
{
public:
    Object_one();

    virtual void            handleEvent(const sf::Event& event, const sf::Vector2i& positionMouse){}
    virtual void            update(sf::Time dt){}
    virtual void            draw(sf::RenderTarget& target, sf::RenderStates states) const {}

public:
    void                    tellMe();
};

#endif // OBJECT_ONE_HPP
