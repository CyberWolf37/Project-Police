#include <SceneNode.hpp>

SceneNode::SceneNode(Category_Layers::Layers category)
    : mChildren()
    , mDefaultCategory(category)
{

}

template <typename Object>
void SceneNode::attachChild(Ptr child)
{
    mChildren.push_back(std::move(child));
}

template <typename Object>
SceneNode::Ptr SceneNode::detachChild(const SceneNode &node)
{
    auto found = std::find_if(mChildren.begin(), mChildren.end(), [&] (Ptr& p) {return p.get() == &node; });
    assert(found != mChildren.end());

    Ptr result = std::move(*found);
    mChildren.erase(found);
    return result;
}

void SceneNode::update(sf::Time dt, CommandQueue& commands)
{
    updateCurrent(dt, commands);
    updatechildren(dt, commands);
}

void SceneNode::updateCurrent(sf::Time , CommandQueue&)
{
    // Do nothing by default
}

template <typename Object>
void SceneNode::updatechildren(sf::Time dt, CommandQueue& commands)
{            
    FOREACH (Ptr& child, mChildren)
    {
        child->update(dt, commands);
    }
}

void SceneNode::handleEvent(const sf::Event &event, const sf::Vector2i& positionMouse)
{
    handleChildrenEvent(event,positionMouse);
}

template <typename Object>
void SceneNode::handleChildrenEvent(const sf::Event &event, const sf::Vector2i& positionMouse)
{
    FOREACH (Ptr& child, mChildren)
    {
        child->handleEvent(event,positionMouse);
    }
}

void SceneNode::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    // Draw node and children with changed transform
    drawChildren(target, states);
}

template <typename Object>
void SceneNode::drawChildren(sf::RenderTarget &target, sf::RenderStates states) const
{
    FOREACH (const Ptr& child, mChildren)
    {
        child->draw(target, states);
    }
}

sf::Vector2f SceneNode::getWorldPosition() const
{
    return getWorldTransform() * sf::Vector2f();
}

sf::Transform SceneNode::getWorldTransform() const
{
    sf::Transform transform = sf::Transform::Identity;

    for (const SceneNode* node=this; node != nullptr; node = node->mParent)
    {
        transform = node->getTransform() * transform;
    }

    return transform;
}

void SceneNode::onCommand(const Command& command, sf::Time dt)
{
    // Command Current Node, if category matches
    if(command.category & getCategory())
        command.action(*this, dt);

    // Command children
    FOREACH (Ptr& child, mChildren)
    {
        child->onCommand(command, dt);
    }
}

/*template <typename Object>
void SceneNode::checkNodeCollision(SceneNode &node, std::set<Pair> &collisionPairs)
{
    if (this != &node && collision(*this, node) && !isDestroyed() && !node.isDestroyed())
        collisionPairs.insert(std::minmax(this, &node));

    FOREACH(Ptr& child, mChildren)
        child->checkNodeCollision(node, collisionPairs);
}*/

void SceneNode::removeWrecks()
{
    // Remove all children which request so
    auto wreckfieldBegin = std::remove_if(mChildren.begin(), mChildren.end(), std::mem_fn(&SceneNode::isMarkedForRemoval));
    mChildren.erase(wreckfieldBegin, mChildren.end());

    // Call function recursively for all remaining children
    std::for_each(mChildren.begin(), mChildren.end(), std::mem_fn(&SceneNode::removeWrecks));
}

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

bool collision(const SceneNode& lhs, const SceneNode& rhs)
{
    return lhs.getBoundingRect().intersects(rhs.getBoundingRect());
}
