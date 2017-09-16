#ifndef SCENENODE_H
#define SCENENODE_H

// GAME Library
#include "Category.hpp"

// SFML Library
#include "SFML/System/NonCopyable.hpp"
#include "SFML/System/Time.hpp"
#include "SFML/Graphics/Transformable.hpp"
#include "SFML/Graphics/Drawable.hpp"


// STD library
#include <vector>
#include <set>
#include <memory>
#include <utility>


struct Command;
struct CommandQueue;

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{

public:
        typedef std::unique_ptr<SceneNode> Ptr;
        typedef std::pair<SceneNode*, SceneNode*> Pair;

public:
        explicit                SceneNode(Category::Layers category = Category::None);
        void                    attachChild(Ptr child);
        Ptr                     detachChild(const SceneNode& node);

        void                    update(sf::Time dt, CommandQueue &commands);
        sf::Vector2f            getWorldPosition() const;
        sf::Transform           getWorldTransform() const;

        //void                  onCommand(const Command& command, sf::Time dt);
        virtual unsigned int    getCategory() const;

        void					checkSceneCollision(SceneNode& sceneGraph, std::set<Pair>& collisionPairs);
        void					checkNodeCollision(SceneNode& node, std::set<Pair>& collisionPairs);
        void					removeWrecks();
        virtual sf::IntRect     getBoundingRect() const;
        virtual bool			isMarkedForRemoval() const;
        virtual bool			isDestroyed() const;

private:
        virtual void            updateCurrent(sf::Time dt, CommandQueue& commands);
        void                    updatechildren(sf::Time dt, CommandQueue &commands);

        virtual void            draw(sf::RenderTarget& target, sf::RenderStates states) const;
        virtual void            drawCurrent (sf::RenderTarget& target, sf::RenderStates states) const;
        void                    drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;
        void                    drawBoundingRect(sf::RenderTarget& target, sf::RenderStates states) const;

private:
        std::vector<Ptr>        mChildren;
        SceneNode*              mParent;
        Category::Layers        mDefaultCategory;
};

bool	collision(const SceneNode& lhs, const SceneNode& rhs);
float	distance(const SceneNode& lhs, const SceneNode& rhs);

#endif // SCENENODE_H
