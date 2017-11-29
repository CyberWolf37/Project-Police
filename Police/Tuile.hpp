#ifndef TUILE_H
#define TUILE_H

// SFML Library
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/View.hpp"

// Core Library
#include "SceneNode.hpp"
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "Utility.hpp"

// STD library
#include <memory>

class Tuile : public SceneNode
{
public:
                                        Tuile();
                                        Tuile(const Tuile &copy);
    explicit                            Tuile(std::shared_ptr<sf::Sprite>  sprite, Category::Layers layerCategory = Category::Layers::None , TuileState::ID tuileCategory = TuileState::ID::None);
    ~Tuile();

    virtual void                        draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void                        drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void                        handleEvent(const sf::Event& event, const sf::Vector2i& positionMouse);

    TuileState::ID                      getTuileCategory() const;
    void                                setTuileCategory(TuileState::ID id);


    const std::shared_ptr<sf::Sprite>   getSprite() const;
    void                                setSprite(std::shared_ptr<sf::Sprite> sprite);

    const bool&                         getIsActive() const;

    const sf::IntRect                   getRectBounds();

private:

    TuileState::ID                      mTuileCategory;
    std::shared_ptr<sf::Sprite>         mSprite;

    bool                                mIsActive;
    bool                                mIsSelected;


};

#endif // TUILE_H
