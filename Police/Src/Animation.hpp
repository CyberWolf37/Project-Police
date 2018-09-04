#ifndef ANIMATION_H
#define ANIMATION_H

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/System/Time.hpp"
#include "SFML/Graphics/Texture.hpp"

class Animation : public sf::Drawable, public sf::Transformable
{
public:
    Animation();
    explicit                    Animation(const sf::Texture& texture);

    void                        loadFromFile(const std::string& filename);

    void                        setTexture(const sf::Texture& texture);
    const sf::Texture*          getTexture() const;

    void                        setFrameSize(sf::Vector2i frameSize);
    sf::Vector2i                getFrameSize() const;

    void                        setIndex(sf::Vector2i index);
    sf::Vector2i                getIndex() const;

    void                        setNumFrames(std::size_t numFrames);
    std::size_t                 getNumFrames() const;

    void                        setDuration(sf::Time duration);
    sf::Time                    getDuration() const;

    void                        setRepeating(bool flag);
    bool                        isRepeating() const;

    void                        setReverse(bool flag);
    bool                        isReverse() const;

    void                        restart();
    bool                        isFinished() const;

    sf::FloatRect               getLocalBounds() const;
    sf::FloatRect               getGlobalBounds() const;

    void                        update(sf::Time dt);

public:
    void                        draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    sf::Sprite                  mSprite;
    sf::Texture                 mTexture;
    sf::Vector2i                mIndexSprite;
    sf::Vector2i                mFrameSize;
    std::size_t                 mNumFrames;
    std::size_t                 mCurrentFrame;
    sf::Time                    mDuration;
    sf::Time                    mElapsedTime;
    bool                        mRepeat;
    bool                        mReverse;
    bool                        mReturn;
};

#endif // ANIMATION_H
