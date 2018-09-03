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
    typedef std::shared_ptr<ObjectBox> Ptr;

public:

    Container(sf::Window &window);

    void                            pack(Ptr object);

    virtual void                    handleEvent(const sf::Event &event, const sf::Vector2f &positionMouse);
    virtual void                    draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:

    bool                            hasSelection() const;
    void                            select(std::size_t index);
    void                            selectNext();
    void                            selectPrevious();
    void                            deselectAll();

    bool                            checkColisionEvent(sf::Vector2i &position);

private:

    std::vector<Ptr>                mChildren;
    int                             mSelectedChild;
    const sf::Window&               mWindow;
};

}

#endif // CONTAINER_H
