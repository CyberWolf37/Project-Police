#include "SceneManager.hpp"

SceneManager::SceneManager()
    :mSceneStackObject()
    ,mSceneStackSbires()
    ,mSceneStackTuile()
{

}

void SceneManager::update(sf::Time dt, CommandQueue &commands)
{
    for(size_t i = 0; i < mSceneStackObject.size() ; i++)
    {
        mSceneStackObject[i].update(dt,commands);
    }

    for(size_t i = 0; i < mSceneStackSbires.size() ; i++)
    {
        mSceneStackSbires[i].update(dt,commands);
    }

    for(size_t i = 0; i < mSceneStackTuile.size() ; i++)
    {
        mSceneStackTuile[i].update(dt,commands);
    }
}

void SceneManager::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for(size_t i = 0; i < mSceneStackObject.size() ; i++)
    {
        mSceneStackObject[i].draw(target,states);
    }

    for(size_t i = 0; i < mSceneStackSbires.size() ; i++)
    {
        mSceneStackSbires[i].draw(target,states);
    }

    for(size_t i = 0; i < mSceneStackTuile.size() ; i++)
    {
        mSceneStackTuile[i].draw(target,states);
    }
}

void SceneManager::handleEvent(const sf::Event &event, const sf::Vector2i &positionMouse)
{
    for(size_t i = 0; i < mSceneStackObject.size() ; i++)
    {
        mSceneStackObject[i].handleEvent(event,positionMouse);
    }

    for(size_t i = 0; i < mSceneStackSbires.size() ; i++)
    {
        mSceneStackSbires[i].handleEvent(event,positionMouse);
    }

    for(size_t i = 0; i < mSceneStackTuile.size() ; i++)
    {
        mSceneStackTuile[i].handleEvent(event,positionMouse);
    }
}
