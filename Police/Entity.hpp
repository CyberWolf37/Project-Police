#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "SceneNode.hpp"


class Entity : public SceneNode
{
public:
    explicit            Entity(int hitpoints);

    int                 getHitPoints() const;

protected:
    virtual void        updateCurrent(sf::Time dt,CommandQueue& commands);

private:
    int                 mHitpoints;
};

#endif // ENTITY_HPP
