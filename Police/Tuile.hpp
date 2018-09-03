#ifndef TUILE_H
#define TUILE_H

// SFML Library
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/View.hpp"
#include "SFML/Graphics/Transformable.hpp"
#include "SFML/System/Vector2.hpp"

// Core Library
#include "ResourceHolder.hpp"
#include "Utility.hpp"
#include "Position.hpp"
#include "ObjectBox.hpp"

// STD library
#include <memory>

class CommandQueue;

class Tuile : public ObjectBox
{
public:

    typedef std::unique_ptr<Tuile> Ptr;

public:

    Tuile(const std::shared_ptr<sf::Sprite>&  sprite);
    Tuile(const Tuile &copy);
    ~Tuile();

    virtual void                        draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void                        handleEvent(const sf::Event& event, const sf::Vector2f &positionMouse);
    virtual void                        update(sf::Time dt, CommandQueue &commands);

    const std::shared_ptr<sf::Sprite>   getSprite() const;
    void                                setSprite(std::shared_ptr<sf::Sprite> sprite);


private:
    std::shared_ptr<sf::Sprite>         mSprite;
};

#endif // TUILE_H
