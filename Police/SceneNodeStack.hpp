#ifndef SCENENODESTACK_HPP
#define SCENENODESTACK_HPP

// GAME Library
#include "SceneNode.hpp"
#include "Foreach.hpp"
#include "Command.hpp"
#include "CommandQueue.hpp"

// SFML Library
#include "SFML/System/NonCopyable.hpp"
#include "SFML/System/Time.hpp"
#include "SFML/Graphics/Transformable.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Window.hpp"
#include "SFML/Graphics/View.hpp"

// STD library
#include <vector>
#include <set>
#include <memory>
#include <utility>
#include <algorithm>
#include <cassert>
#include <cmath>

// Test Debug
#include <QDebug>

class SceneNodeStack : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{

public:

    typedef std::unique_ptr<SceneNode> Ptr;

public:

                            SceneNodeStack();

    void                    attachChild(Ptr child);
    Ptr                     detachChild(const SceneNode& node);

    virtual void            handleEvent(const sf::Event& event, const sf::Vector2i& positionMouse);
    virtual void            handleChildrenEvent(const sf::Event& event, const sf::Vector2i& positionMouse);

    void                    update(sf::Time dt, CommandQueue &commands);

    void					checkSceneCollision(SceneNode& sceneGraph, std::set<Pair>& collisionPairs);
    void					checkNodeCollision(SceneNode& node, std::set<Pair>& collisionPairs);

private:

    virtual void            update(sf::Time dt, CommandQueue &commands);
    virtual void            updateCurrent(sf::Time dt, CommandQueue &commands);
    virtual void            updatechildren(sf::Time dt, CommandQueue &commands);

    virtual void            draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void            drawCurrent (sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void            drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;


};

#endif // SCENENODESTACK_HPP
