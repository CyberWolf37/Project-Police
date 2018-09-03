#include "Container.hpp"
#include "foreach.hpp"

#include "SFML/Window/Event.hpp"
#include "SFML/Graphics/RenderStates.hpp"
#include "SFML/Graphics/RenderTarget.hpp"

// For test
#include <iostream>

namespace GUI
{

Container::Container(sf::Window& window)
    : mChildren()
    , mSelectedChild(-1)
    , mWindow(window)
{

}

void Container::pack(Ptr object)
{
    mChildren.push_back(std::move(object));
}

void Container::handleEvent(const sf::Event &event, const sf::Vector2f &positionMouse)
{

    //If we pressed Left button on mouse when activate a button
    if ( event.mouseButton.button == sf::Mouse::Left)
    {
        mChildren[mSelectedChild]->handleEvent(event,positionMouse);
    }

    else if (event.MouseMoved)
    {
        //Get the position of mouse
        sf::Vector2i position = sf::Mouse::getPosition(mWindow);

        //Check if children was in position
        if(checkColisionEvent(position) && hasSelection())
        {
            // Deselect all component
            deselectAll();
            // Select the component
            select(mSelectedChild);
        }
        else
        {
            deselectAll();
        }
    }
}

void Container::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    FOREACH(const Ptr& child, mChildren)
            target.draw(*child, states);
}

bool Container::hasSelection() const
{
    return mSelectedChild >= 0;
}

void Container::select(std::size_t index)
{
    if(mChildren[index]->getIsSelected())
    {
        if(hasSelection())
            mChildren[mSelectedChild]->setIsSelected(false);

        mChildren[index]->setIsSelected(true);
        mSelectedChild = index;
    }
}

void Container::selectNext()
{
    if(!hasSelection())
        return;

    // Search next component that is selectable, wrap around if necessary
    int next = mSelectedChild;
    do
        next = (next + 1) % mChildren.size();
    while (!mChildren[next]->isSelectable());

    // Select that component
    select(next);
}

void Container::selectPrevious()
{
    if (!hasSelection())
        return;

    // Search previous component that is selectable, wrap around if necessary
    int prev = mSelectedChild;
    do
        prev = (prev + mChildren.size() - 1) % mChildren.size();
    while(!mChildren[prev]->isSelectable());

    // Select that component
    select(prev);
}

void Container::deselectAll()
{
    FOREACH(const Ptr& child, mChildren)
            child->setIsSelected(false);
}

} // End of namespace GUI
