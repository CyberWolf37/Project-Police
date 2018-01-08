#include "SceneNodeStack.hpp"

SceneNodeStack::SceneNodeStack()
{

}

void SceneNodeStack::attachChild(Ptr child)
{
    child->mParent = this;
    mChildren.push_back(std::move(child));

}

SceneNodeStack::Ptr SceneNodeStack::detachChild(const SceneNode &node)
{
    auto found = std::find_if(mChildren.begin(), mChildren.end(), [&] (Ptr& p) {return p.get() == &node; });
    assert(found != mChildren.end());

    Ptr result = std::move(*found);
    result->mParent = nullptr;
    mChildren.erase(found);
    return result;
}

void SceneNodeStack::handleEvent(const sf::Event &event, const sf::Vector2i& positionMouse)
{
    handleChildrenEvent(event,positionMouse);

    // Do nothing after that
}

void SceneNodeStack::handleChildrenEvent(const sf::Event &event, const sf::Vector2i& positionMouse)
{
    FOREACH (Ptr& child, mChildren)
    {
        child->handleEvent(event,positionMouse);
    }
}

void SceneNodeStack::update(sf::Time dt, CommandQueue& commands)
{
    updateCurrent(dt, commands);
    updatechildren(dt, commands);
}

void SceneNodeStack::updateCurrent(sf::Time , CommandQueue& commands)
{
    // Do nothing by default
}

void SceneNodeStack::updatechildren(sf::Time dt, CommandQueue& commands)
{
    FOREACH (Ptr& child, mChildren)
    {
        child->update(dt, commands);
    }
}

void SceneNodeStack::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    // Apply transform of current node
    states.transform *= getTransform();

    // Draw node and children with changed transform
    drawCurrent(target, states);
    drawChildren(target, states);
}

void SceneNodeStack::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
    // Do nothing by default
}

void SceneNodeStack::drawChildren(sf::RenderTarget &target, sf::RenderStates states) const
{
    FOREACH (const Ptr& child, mChildren)
    {
        child->draw(target, states);
    }
}
