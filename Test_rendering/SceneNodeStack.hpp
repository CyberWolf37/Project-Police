#ifndef SCENENODESTACK_HPP
#define SCENENODESTACK_HPP

// GAME Library
#include "SceneNode.hpp"

// SFML Library
#include "SFML/System/NonCopyable.hpp"
#include "SFML/System/Time.hpp"
#include "SFML/Graphics/Transformable.hpp"
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Window.hpp"
#include "SFML/Graphics/View.hpp"


// STD library
#include <vector>
#include <set>
#include <memory>
#include <utility>

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
};

#endif // SCENENODESTACK_HPP
