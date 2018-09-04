#include "Entity.hpp"

Entity::Entity(int hitpoints)
    :mHitpoints(hitpoints)
{

}

int Entity::getHitPoints() const
{
    return mHitpoints;
}


void Entity::updateCurrent(sf::Time dt,CommandQueue& commands)
{
    // Do nothing by default
}
