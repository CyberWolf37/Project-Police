#ifndef BUTTON_H
#define BUTTON_H

#include "Component.hpp"
#include "ResourceIdentifiers.hpp"
#include "ResourceHolder.hpp"

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/RectangleShape.hpp"

#include <vector>
#include <string>
#include <memory>
#include <functional>

namespace GUI
{

class Button : public Component
{
public:
    typedef std::shared_ptr<Button>             Ptr;
    typedef std::function<void()>               Callback;

    enum Type
    {
        Normal,
        Selected,
        Pressed,
        ButtonCount
    };

public:

    Button(const FontHolder& fonts, const TextureHolder& textures);

    void                    setCallback(Callback callback);
    void                    setText(const std::string& text);
    void                    setToggle(bool flag);

    virtual bool            isSelectable() const;
    virtual void            select();
    virtual void            deselect();

    virtual void            activate();
    virtual void            deactivate();

    virtual void            handleEvent(const sf::Event& event, const sf::Vector2i& positionMouse);
    sf::FloatRect           getBoundingRect();
    virtual bool            checkColision(sf::Vector2i& position);

private:
    virtual void            drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void            draw(sf::RenderTarget& target, sf::RenderStates states) const;
            void            changeTexture(Type buttonType);



private:
    Callback                mCallback;
    sf::Sprite              mSprite;
    sf::RectangleShape      mRectangleBackground;
    sf::Text                mText;
    bool                    mIsToggle;
};

}   // End of namespace

#endif // BUTTON_H
