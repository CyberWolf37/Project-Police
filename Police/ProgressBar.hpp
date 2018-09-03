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
#include "ObjectBox.hpp"
#include "ResourceIdentifiers.hpp"
#include "ResourceHolder.hpp"

namespace GUI
{

class ProgressBar : public ObjectBox
{

public:

    enum Type
    {
        BackStage,
        Progress,
        Windowing,
        CurseurTop,
        Curseur
    };

    // Typdef For map the sprites
    typedef std::map<Type,sf::Sprite> SpritesMap;
    typedef std::shared_ptr<ProgressBar> Ptr;

public:
    ProgressBar(const FontHolder& fonts, const TextureHolder& textures);

    virtual void                handleEvent(const sf::Event& event, const sf::Vector2i& positionMouse);
    virtual void                draw(sf::RenderTarget& target, sf::RenderStates states)const;

    void                        setSprite(const TextureHolder& textures);
    void                        getSprite() const;

    void                        setValue(size_t value);
    const int                   getValue() const;

    const bool                  isFinish() const;

private:
    SpritesMap                  mStackSprite;
    sf::RenderTexture           mTextureProgress;
    sf::Text                    mText;
    float                       mValue;

    bool                        mIsFinish;
    bool                        mIsSelectable;
    bool                        mIsCurseurview;

};

} // End of namespace

#endif // PROGRESSBAR_H
