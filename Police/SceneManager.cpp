#include "SceneManager.hpp"

SceneManager::SceneManager()
    :mSceneStack()
{
    // init Scene Node
    loadScene();
}

void SceneManager::update(sf::Time dt, CommandQueue &commands)
{
    for(size_t i = 0; i < mSceneStack.size() ; i++)
    {
        mSceneStack[i].update(dt,commands);
    }
}

void SceneManager::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for(size_t i = 0; i < mSceneStack.size() ; i++)
    {
        mSceneStack[i].draw(target,states);
    }
}

void SceneManager::handleEvent(const sf::Event &event, const sf::Vector2i &positionMouse)
{
    for(size_t i = 0; i < mSceneStack.size() ; i++)
    {
        mSceneStack[i].handleEvent(event,positionMouse);
    }
}

SceneManager::PtrSceneNode SceneManager::getSceneNode(Category_Layers::Layers id)
{
    std::unique_ptr<SceneNode<auto>> ptrCpy (*mSceneStack[id]);
    return std::move(ptrCpy);
}

void SceneManager::loadScene()
{
    // Initialise SceneManager
    mSceneStack[Category_Layers::SceneGroundLayer]      = SceneNode<ObjectBox>(Category_Layers::SceneGroundLayer);
    mSceneStack[Category_Layers::SceneBuildingLayer]    = SceneNode<ObjectBox>(Category_Layers::SceneBuildingLayer);
    mSceneStack[Category_Layers::SceneObjectLayer]      = SceneNode<ObjectBox>(Category_Layers::SceneObjectLayer);
    mSceneStack[Category_Layers::SceneSbiresLayer]      = SceneNode<Sbires>(Category_Layers::SceneSbiresLayer);
    mSceneStack[Category_Layers::SceneNone]             = SceneNode<ObjectBox>(Category_Layers::SceneNone);
}

bool SceneManager::collision(const SceneNode &lhs, const SceneNode &rhs)
{

}

