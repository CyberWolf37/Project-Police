#ifndef SPRITENODE_H
#define SPRITENODE_H

#include "SceneNode.hpp"
#include <iostream>

#include "SFML/Graphics/Sprite.hpp"


class SpriteNode : public SceneNode
{

public:
    explicit                SpriteNode(const sf::Texture& texture);
                            SpriteNode(const sf::Texture& texture, const sf::IntRect& textureRect);
                            SpriteNode(const sf::Texture& texture, const sf::IntRect& textureRect, const sf::Vector2f& position);
private:
    virtual void            drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    void                    tellMe();
private:
    sf::Sprite              mSprite;
};

#endif // SPRITENODE_H
