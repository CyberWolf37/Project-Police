#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

// STD include
#include <map>
#include <memory>
#include <functional>

// SFML include
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/RenderStates.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Graphics/RenderTexture.hpp"

// CORE include
#include "Component.hpp"
#include "ResourceIdentifiers.hpp"
#include "ResourceHolder.hpp"

namespace GUI
{

class ProgressBar : public Component
{

public:

    // enume for check every sprite
    enum Type
    {
        BackStage   = 0,
        Progress    = 1,
        Windowing   = 2,
        CurseurTop  = 3,
        Curseur     = 4,
        TypeCount   = 5,

        Box         = Progress | Windowing | BackStage | Curseur | CurseurTop,
        CurseurBar  = Curseur | CurseurTop,
    };

    // Typdef For map the sprites
    typedef std::map<Type,sf::Sprite> SpritesMap;
    typedef std::shared_ptr<ProgressBar> Ptr;

public:
    ProgressBar(const FontHolder& fonts, const TextureHolder& textures);

    virtual void                handleEvent(const sf::Event& event);
    virtual bool                checkColision(sf::Vector2i &position);
    Type                        checkItem(sf::Vector2i &position);

    void                        setSelectable(bool select);
    virtual bool                isSelectable() const;


    virtual void                select();
    virtual void                deselect();

    sf::FloatRect               getBoundingRect();

    void                        setSprite(const TextureHolder& textures);
    void                        getSprite();

    void                        setValue(size_t value);
    const int                   getValue() const;

    const bool                  isFinish() const;

private:
    virtual void                draw(sf::RenderTarget& target, sf::RenderStates states)const;

private:
    SpritesMap                  mStackSprite;
    sf::RenderTexture           mTextureProgress;
    sf::Text                    mText;
    float                       mValue;

    bool                        mIsFinish;
    bool                        mIsSelectable;
    bool                        mIsCurseurview;
    bool                        mIsPickUp;

};

} // End of namespace

#endif // PROGRESSBAR_H
