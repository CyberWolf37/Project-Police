#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP

// Core Library
#include "SceneNode.hpp"
#include "CommandQueue.hpp"
#include "Category.hpp"
#include "Foreach.hpp"
#include "ObjectBox.hpp"
#include "ResourceIdentifiers.hpp"
#include "Tuile.hpp"

// SFML Library
#include "SFML/System/Time.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/RenderStates.hpp"

// STD Library
#include <map>
#include <vector>
#include <memory>
#include <QDebug>


class SceneManager
{
public:
    SceneManager();

    void                        update(sf::Time dt, CommandQueue &commands);
    void                        draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void                        handleEvent(const sf::Event& event, const sf::Vector2i& positionMouse);

    template <typename Object>
    void                        insert(std::unique_ptr<Object> item);

private:
    /*template <typename Object>
    bool                        collision(const SceneNode<Object>& lhs, const SceneNode<Object>& rhs);*/

private:
    NodeObject   mSceneStackObject;
    NodeSbire    mSceneStackSbires;
    NodeTuile    mSceneStackTuile;
};

template <typename Object>
void SceneManager::insert(std::unique_ptr<Object> item)
{
    // Insert and check success
    if(typeid(Object) == typeid(ObjectBox))
    {
        mSceneStackObject.attachChild(std::move(item));
    }
    else if(typeid(Object) == typeid(Sbires))
    {
        //mSceneStackSbires.attachChild(std::move(item));
    }
    else if(typeid(Object) == typeid(Tuile))
    {
        mSceneStackTuile.attachChild(std::move(item));
    }
    else
    {
        qDebug() << "Fail to insert Object in is stack ...";
    }

}

#endif // SCENEMANAGER_HPP
