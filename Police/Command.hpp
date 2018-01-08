#ifndef COMMAND_H
#define COMMAND_H

// SFML Library
#include "SFML/System/Time.hpp"

// STD Library
#include "functional"
#include "cassert"

// Game Library
#include "category.hpp"

class SceneNode;

struct Command
{
    Command();
    std::function<void(SceneNode&, sf::Time)>   action;
    unsigned int                                category;
};

template <typename GameObject, typename Function>
std::function<void(SceneNode&, sf::Time)> derivedAction(Function fn)
{
    return [=] (SceneNode& node, sf::Time dt)
    {
        // Check if cast is safe
        assert(dynamic_cast<GameObject*>(&node) != nullptr);

        // Downcast node and invoke fonction on it
        fn(static_cast<GameObject&>(node), dt);
    };
}

#endif // COMMAND_H
