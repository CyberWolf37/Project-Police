#include "SbireManager.hpp"

// Manage Sbires

SbireManager::SbireManager(SceneNode &sceneGraph)
    :mSceneGraph(sceneGraph)
    ,mTextureSbire()
    ,mStackSbire()
{

}

void SbireManager::createSbire(Category_Sbires::ID category, sf::Vector2i& position)
{
    // create object sbire
    //SbirePtr sbireStack(new Sbires(mTextureSbire,category));
    SbirePtr sbireScene(new Sbires(mTextureSbire,category));

    //sbireStack->setPosition(static_cast<sf::Vector2f>(position));
    sbireScene->setPosition(static_cast<sf::Vector2f>(position));

    // push in the stack
    //mStackSbire.push_back(std::move(sbireStack));

    // push in the scene graph
    mSceneGraph.attachChild(std::move(sbireScene));
}

void SbireManager::setTexture(sf::Texture &texture)
{
    mTextureSbire = texture;
}

sf::Texture &SbireManager::getTexture()
{
    return mTextureSbire;
}

SbireManager::SbireStack &SbireManager::getSbireStack()
{
    return mStackSbire;
}

void SbireManager::update(sf::Time dt)
{
    // Do nothing for now
}

void SbireManager::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    /*for(auto& child : mStackSbire)
    {
        child->draw(target,states);
    }*/
}
