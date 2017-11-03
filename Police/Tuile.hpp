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
    explicit                            Tuile(unsigned int& count, sf::Vector2u &pixSize, sf::Sprite& sprite, Category::Layers layerCategory = Category::Layers::None , TuileState::ID tuileCategory = TuileState::ID::None);
    ~Tuile();

    virtual void                        draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void                        drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void                        handleEvent(const sf::Event& event, const sf::Vector2i& positionMouse);

    const sf::Vector2u&                 getPixSize() const;

    bool                                isActive() const;
    void                                deactivate();
    void                                setActivate();

    bool                                isSelected() const;
    void                                deSelect();
    void                                Select();

    TuileState::ID                      getTuileCategory() const;
    void                                setTuileCategory(TuileState::ID id);

    const unsigned int                  getCount()const;
    void                                setCount(unsigned int& count);

    const sf::Sprite&                   getSprite() const;
    void                                setSprite(sf::Sprite& sprite);

    const sf::IntRect                   getRectBounds();

private:

    TuileState::ID                  mTuileCategory;
    const sf::Vector2u              mPixSize;
    sf::Sprite                      mSprite;
    unsigned int                    mCount;

    bool                            mIsActive;
    bool                            mIsSelected;


};

#endif // TUILE_H
