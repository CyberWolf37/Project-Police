#ifndef TUILE_H
#define TUILE_H

// SFML Library
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Graphics/RenderTarget.hpp"

// Core Library
#include "SceneNode.hpp"
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"

// STD library
#include <memory>

class Tuile : public SceneNode
{
public:
                                        Tuile();
    explicit                            Tuile(unsigned int& count, sf::Vector2u &pixSize, sf::Sprite& sprite, Category::Layers layerCategory = Category::Layers::None , TuileState::ID tuileCategory = TuileState::ID::None);
    ~Tuile();

    virtual void                        drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void                        handleEvent(const sf::Event& event);

    const sf::Vector2u&                 getPixSize() const;

    bool                                isActive() const;
    void                                deactivate();

    bool                                isSelected() const;
    void                                deSelect();
    void                                Select();

    TuileState::ID                      getTuileCategory() const;
    void                                setTuileCategory(TuileState::ID id);

    const sf::FloatRect                 getRect()const;
    void                                setRect();

    const unsigned int                  getCount()const;
    void                                setCount(unsigned int& count);

    sf::Sprite&                         getSprite()const;
    void                                setSprite(sf::Sprite& sprite);


private:

    TuileState::ID                  mTuileCategory;
    const sf::Vector2u              mPixSize;
    std::shared_ptr<sf::Sprite>     mSprite;
    sf::IntRect                     mRect;
    unsigned int                    mCount;

    bool                            mIsActive;
    bool                            mIsSelected;


};

#endif // TUILE_H
