#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP

// Core Library
#include "SceneNode.hpp"
#include "CommandQueue.hpp"
#include "Category.hpp"

// SFML Library
#include "SFML/System/Time.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/RenderStates.hpp"

// STD Library
#include <map>
#include <memory>


class SceneManager
{
public:
    typedef std::map<SceneNode, Category_Layers::SceneNone> MapScene;

public:
    SceneManager();

    void                    update(sf::Time dt, CommandQueue &commands);
    void                    draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void                    handleEvent(const sf::Event& event, const sf::Vector2i& positionMouse);

private:
    void                    loadScene();
    bool                    collision(const SceneNode& lhs, const SceneNode& rhs);

private:
    MapScene                mSceneStack;
};

#endif // SCENEMANAGER_HPP
