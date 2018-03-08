#include "SbireManager.hpp"

// Manage Sbires

SbireManager::SbireManager(SceneNode &sceneGraph, sf::Texture &texture)
    :mSceneGraph(sceneGraph)
    ,mTextureSbire(texture)
    ,mStackSbire()
{
}

void SbireManager::createSbire(Category_Sbires::ID category)
{
    // create object sbire
    SbirePtr sbireStack(new Sbires(mTextureSbire,category));
    SbirePtr sbireScene = sbireStack;

    // push in the stack
    mStackSbire.push_back(std::move(sbireStack));

    // push in the scene graph
    mSceneGraph.attachChild(std::move(sbireScene));
}

void SbireManager::update(sf::Time dt)
{

}
