#ifndef SCENENODE_H
#define SCENENODE_H

// GAME Library
#include "Category.hpp"
#include "Foreach.hpp"

// SFML Library
#include "SFML/System/NonCopyable.hpp"
#include "SFML/System/Time.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Window.hpp"
#include "SFML/Graphics/View.hpp"
#include "SFML/Graphics/RenderStates.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
// STD library
#include <vector>
#include <set>
#include <memory>
#include <utility>
#include <algorithm>
#include <cassert>
#include <cmath>

// Debug
#include <QDebug>

class Command;
class CommandQueue;

template <typename Object>
class SceneNode : private sf::NonCopyable
{

public:
        typedef std::unique_ptr<Object> Ptr;

public:
        explicit                SceneNode(Category_Layers::Layers category = Category_Layers::SceneNone);
        void                    attachChild(Ptr child);
        Ptr                     detachChild(const SceneNode& node);

        void                    update(sf::Time dt, CommandQueue &commands);
        void                    updateCurrent(sf::Time dt, CommandQueue &commands);
        void                    updateChildren(sf::Time dt, CommandQueue &commands);
        sf::Vector2f            getWorldPosition() const;
        sf::Transform           getWorldTransform() const;

public:
        void                    draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void                    drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;
        void                    handleEvent(const sf::Event& event, const sf::Vector2i& positionMouse);
        void                    handleChildrenEvent(const sf::Event& event, const sf::Vector2i& positionMouse);

private:
        std::vector<Ptr>        mChildren;
        Category_Layers::Layers mDefaultCategory;
};

#include <SceneNode.inl>
#endif // SCENENODE_H
