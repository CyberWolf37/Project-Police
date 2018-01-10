#include "MapNode.hpp"

MapGame::MapGame(size_t x, size_t y, const FileHolder &file, const TextureSplite &textureSplit)
    :m_size(x,y)
    ,m_file(file)
    ,m_texture(textureSplit)
    ,m_buildStack()
    ,m_componentStack()
{

}

MapGame::MapGame(sf::Vector2i size, IOFile::File &file, Textures &textureSplit)
    :m_size(size)
    ,m_file(file)
    ,m_texture(textureSplit)
    ,m_buildStack()
    ,m_componentStack()
{

}

bool MapGame::insertObject(PtrBuild objectBuild)
{
    if(m_buildStack.push_back(objectBuild))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool MapGame::insertObject(PtrComponent objectComponent)
{
    if(m_componentStack.push_back(objectComponent))
    {
        return true;
    }
    else
    {
        return false;
    }
}

MapGame::vBuild &MapGame::findObject(sf::Vector2i &position)
{
    FOREACH(PtrBuild& child, m_buildStack)
    {
        if(child->isActive() && child->checkColision(position))
        {
            return *child;
        }
    }
}

MapGame::vComponent &MapGame::findObject(sf::Vector2i &position)
{
    FOREACH(PtrComponent& child, m_componentStack)
    {
        if(child->isActive() && child->checkColision(position))
        {
            return *child;
        }
    }
}

void MapGame::handleChildrenEvent(const sf::Event &event, const sf::Vector2i &positionMouse)
{
    handleBuildEvent(event, positionMouse);
    handleComponentEvent(event, positionMouse);
}

void MapGame::updateCurrent(sf::Time dt, CommandQueue &commands)
{
    updatechildren(dt,commands);
}

void MapGame::updatechildren(sf::Time dt, CommandQueue &commands)
{
    updateBuild(dt,commands);
    updateComponent(dt,commands);
}

void MapGame::drawChildren(sf::RenderTarget &target, sf::RenderStates states) const
{
    FOREACH (PtrBuild& child, m_buildStack)
    {
        child->draw(target, states);
    }

    FOREACH (PtrComponent& child, m_componentStack)
    {
        child->draw(target, states);
    }
}

void MapGame::handleBuildEvent(const sf::Event &event, const sf::Vector2i &positionMouse)
{
    FOREACH (PtrBuild& child, m_buildStack)
    {
        child->handleEvent(event,positionMouse);
    }
}

void MapGame::handleComponentEvent(const sf::Event &event, const sf::Vector2i &positionMouse)
{
    FOREACH (PtrComponent& child, m_componentStack)
    {
        child->handleEvent(event,positionMouse);
    }
}

void MapGame::updateBuild(sf::Time dt, CommandQueue &commands)
{
    FOREACH (Ptr& child, m_buildStack)
    {
        child->handleEvent(dt,commands);
    }
}

void MapGame::updateComponent(sf::Time dt, CommandQueue &commands)
{
    FOREACH (Ptr& child, m_componentStack)
    {
        child->handleEvent(dt,commands);
    }
}
