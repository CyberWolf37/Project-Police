#include "Foreach.hpp"
template <typename Object>
SceneNode<Object>::SceneNode(Category_Layers::Layers category)
    : mChildren()
    , mDefaultCategory(category)
{

}

template <typename Object>
void SceneNode<Object>::attachChild(SceneNode::Ptr child)
{
    mChildren.push_back(std::move(child));
}

template <typename Object>
typename SceneNode<Object>::Ptr SceneNode<Object>::detachChild(const SceneNode &node)
{
    auto found = std::find_if(mChildren.begin(), mChildren.end(), [&] (Ptr& p) {return p.get() == &node; });
    assert(found != mChildren.end());

    Ptr result = std::move(*found);
    mChildren.erase(found);
    return result;
}

template <typename Object>
void SceneNode<Object>::update(sf::Time dt, CommandQueue& commands)
{
    updateCurrent(dt, commands);
    updateChildren(dt, commands);
}

template <typename Object>
void SceneNode<Object>::updateCurrent(sf::Time , CommandQueue&)
{
    // Do nothing by default
}

template <typename Object>
void SceneNode<Object>::updateChildren(sf::Time dt, CommandQueue& commands)
{            
    FOREACH (Ptr& child, mChildren)
    {
        child->update(dt, commands);
    }
}

template <typename Object>
void SceneNode<Object>::handleEvent(const sf::Event &event, const sf::Vector2i& positionMouse)
{
    handleChildrenEvent(event,positionMouse);
}

template <typename Object>
void SceneNode<Object>::handleChildrenEvent(const sf::Event &event, const sf::Vector2i& positionMouse)
{
    FOREACH (Ptr& child, mChildren)
    {
        child->handleEvent(event,positionMouse);
    }
}

template <typename Object>
void SceneNode<Object>::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    // Draw node and children with changed transform
    drawChildren(target, states);
}

template <typename Object>
void SceneNode<Object>::drawChildren(sf::RenderTarget &target, sf::RenderStates states) const
{
    FOREACH (const Ptr& child, mChildren)
    {
        child->draw(target, states);
    }
}

template <typename Object>
sf::Vector2f SceneNode<Object>::getWorldPosition() const
{
    return getWorldTransform() * sf::Vector2f();
}

template <typename Object>
sf::Transform SceneNode<Object>::getWorldTransform() const
{
    sf::Transform transform = sf::Transform::Identity;

    for (const SceneNode* node=this; node != nullptr; node = node->mParent)
    {
        transform = node->getTransform() * transform;
    }

    return transform;
}

/*void SceneNode::onCommand(const Command& command, sf::Time dt)
{
    // Command Current Node, if category matches
    if(command.category & getCategory())
        command.action(*this, dt);

    // Command children
    FOREACH (Ptr& child, mChildren)
    {
        child->onCommand(command, dt);
    }
}*/

/*template <typename Object>
void SceneNode::checkNodeCollision(SceneNode &node, std::set<Pair> &collisionPairs)
{
    if (this != &node && collision(*this, node) && !isDestroyed() && !node.isDestroyed())
        collisionPairs.insert(std::minmax(this, &node));

    FOREACH(Ptr& child, mChildren)
        child->checkNodeCollision(node, collisionPairs);
}*/

/*void SceneNode::removeWrecks()
{
    // Remove all children which request so
    auto wreckfieldBegin = std::remove_if(mChildren.begin(), mChildren.end(), std::mem_fn(&SceneNode::isMarkedForRemoval));
    mChildren.erase(wreckfieldBegin, mChildren.end());

    // Call function recursively for all remaining children
    std::for_each(mChildren.begin(), mChildren.end(), std::mem_fn(&SceneNode::removeWrecks));
}*/

/*void SceneNode::checkTuileChildInCurrentView(const sf::View& view)
{
    sf::Vector2f positionView = view.getCenter() - view.getSize() / 2.f;
    sf::FloatRect boundsView(positionView,view.getSize());

    FOREACH(Ptr& child, mChildren)
    {
        if(boundsView.contains(child->getPosition()))
        {
            child->setActivate(true);
        }
        else
        {
            child->setActivate(false);
        }
    }
}*/

/*template <typename Object>
bool collision(const SceneNode& lhs, const SceneNode& rhs)
{
    return lhs.getBoundingRect().intersects(rhs.getBoundingRect());
}*/
