#ifndef COMPONENT_H
#define COMPONENT_H

#include "SFML/System/NonCopyable.hpp"
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Transformable.hpp"

#include "SceneNode.hpp"

#include <memory>

namespace sf
{
        class Event;
}

namespace GUI
{

class Component : public SceneNode
{
public:

    typedef std::shared_ptr<Component> Ptr;

public:
    Component();
    virtual                     ~Component();

    virtual bool                isSelectable() const = 0;
    bool                        isSelected() const;
    virtual void                select();
    virtual void                deselect();

    virtual bool                isActive() const;
    virtual void                activate();
    virtual void                deactivate();

    virtual bool                checkColision(sf::Vector2i& position);

private:
    bool                        mIsSelected;
    bool                        mIsActive;
};

}   // End of namespace

#endif // COMPONENT_H
