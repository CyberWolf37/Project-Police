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
    void                        insert(std::unique_ptr<SceneNode<Object>>& item, Category_Layers::Layers category);

private:
    /*template <typename Object>
    bool                        collision(const SceneNode<Object>& lhs, const SceneNode<Object>& rhs);*/

private:
    std::map<Category_Layers::Layers, std::unique_ptr<NodeObject>>   mSceneStackObject;
    std::map<Category_Layers::Layers, std::unique_ptr<NodeSbire>>    mSceneStackSbires;
    std::map<Category_Layers::Layers, std::unique_ptr<NodeTuile>>    mSceneStackTuile;
};

template <typename Object>
void SceneManager::insert(std::unique_ptr<SceneNode<Object>>& item, Category_Layers::Layers category)
{
    // Insert and check success
    if(typeid(Object) == typeid(ObjectBox))
    {
        auto inserted = mSceneStackObject.insert(std::make_pair(category, std::move(item)));
        assert(inserted.second);
    }
    else if(typeid(Object) == typeid(Sbires))
    {
        auto inserted = mSceneStackSbires.insert(std::make_pair(category, std::move(item)));
        assert(inserted.second);
    }
    else if(typeid(Object) == typeid(Tuile))
    {
        auto inserted = mSceneStackSbires.insert(std::make_pair(category, std::move(item)));
        assert(inserted.second);
    }
    else
    {
        qDebug() << "Fail to insert Object in is stack ...";
    }

}

#endif // SCENEMANAGER_HPP
