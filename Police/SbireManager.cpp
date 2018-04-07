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
    SbirePtr sbireScene(new Sbires(mTextureSbire,category));

    //sbireStack->setPosition(static_cast<sf::Vector2f>(position));
    sbireScene->setPosition(static_cast<sf::Vector2f>(position));
    sbireScene->setCategory(Category::Layers::SceneSbiresLayer);

    SbirePtr sbireStack = sbireScene;

    // push in the stack
    mStackSbire.push_back(std::move(sbireStack));

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
