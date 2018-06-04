#ifndef CONTAINER_H
#define CONTAINER_H

#include "ObjectBox.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <vector>
#include <memory>

namespace GUI
{

class Container : public ObjectBox

{
public:
    typedef std::shared_ptr<Container> Ptr;

public:
    Container(sf::Window &window);

    void                            pack(ObjectBox::Ptr object);

    virtual bool                    isSelectable() const;
    virtual void                    handleEvent(const sf::Event &event, const sf::Vector2i& positionMouse);


private:
    virtual void                    drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
    virtual void                    draw(sf::RenderTarget& target, sf::RenderStates states) const;

    bool                            hasSelection() const;
    void                            select(std::size_t index);
    void                            selectNext();
    void                            selectPrevious();
    void                            deselectAll();

    bool                            checkColisionEvent(sf::Vector2i &position);

private:
    std::vector<ObjectBox::Ptr>     mChildren;
    int                             mSelectedChild;
    const sf::Window&               mWindow;
};

}

#endif // CONTAINER_H
