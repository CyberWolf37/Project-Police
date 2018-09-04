#include "SpriteNode.hpp"

#include "SFML/Graphics/RenderTarget.hpp"

SpriteNode::SpriteNode(const sf::Texture& texture)
    :mSprite(texture)
{

}

SpriteNode::SpriteNode(const sf::Texture &texture, const sf::IntRect &textureRect)
    :mSprite(texture, textureRect)
{

}

SpriteNode::SpriteNode(const sf::Texture& texture, const sf::IntRect& textureRect, const sf::Vector2f& position)
    :mSprite(texture, textureRect)
{
    // Set Position of sprite
    mSprite.setPosition(position);
    //tellMe();

}

void SpriteNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mSprite, states);
}

void SpriteNode::tellMe()
{
    std::cout << "Sprite Position : "
              << mSprite.getPosition().x << " ; "
              << mSprite.getPosition().y << " . "
              << " Rect = "
              << mSprite.getTextureRect().left << ";"
              << mSprite.getTextureRect().top << ";"
              << mSprite.getTextureRect().width << ";"
              << mSprite.getTextureRect().height << " ."
              << std::endl;
}
