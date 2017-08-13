#include "Button.hpp"
#include "Utility.hpp"

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

// To TEST
#include <iostream>

namespace GUI
{

Button::Button(const FontHolder& fonts, const TextureHolder& textures)
    : mCallback()
    , mSprite(textures.get(Textures::Buttons))
    , mRectangleBackground()
    , mText("", fonts.get(Fonts::Main), 16)
    , mIsToggle(false)
{
    changeTexture(Normal);

    sf::FloatRect bounds = mSprite.getLocalBounds();
    mText.setPosition(bounds.width / 2.f, bounds.height / 2.f);

    // Set position of rectangle background
    mRectangleBackground.setFillColor(sf::Color::Black);


}

void Button::setCallback(Callback callback)
{
    mCallback = std::move(callback);
}

void Button::setText(const std::string& text)
{
    mText.setString(text);
    centerOrigin(mText);

    sf::Vector2f vectorText(mText.getLocalBounds().width+10.f,mText.getLocalBounds().height+10.f);
    mRectangleBackground.setSize(vectorText);
    centerOrigin(mRectangleBackground);
    mRectangleBackground.setPosition(mText.getPosition().x,mText.getPosition().y+5.f);
}

void Button::setToggle(bool flag)
{
    mIsToggle = flag;
}

bool Button::isSelectable() const
{
    return true;
}

void Button::select()
{
    Component::select();

    changeTexture(Selected);
}

void Button::deselect()
{
    Component::deselect();

    changeTexture(Normal);
}

void Button::activate()
{
    Component::activate();

    // If we are toggle then we should show that the button is pressed and thus "toggled".
    if (mIsToggle)
    {
       changeTexture(Pressed);
    }

    if (mCallback)
    {
        mCallback();
    }

    // If we are not a toggle then deactivate the button since we are just momentarily activated.
    if (!mIsToggle)
    {
        deactivate();
    }
}

void Button::deactivate()
{
    Component::deactivate();

    if (mIsToggle)
    {
        // Reset Textures one depending on if we are selected or not
        if (isSelected())
        {
            changeTexture(Selected);
        }
        else
        {
            changeTexture(Normal);
        }
    }
}

void Button::handleEvent(const sf::Event &event)
{
    if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
    {
        if(isSelected())
        {
            activate();
        }

    }
}

sf::FloatRect Button::getBoundingRect()
{
    return mSprite.getLocalBounds();
}

bool Button::checkColision(sf::Vector2i& position)
{
    // Get the rect of our button
    sf::FloatRect boundsButton  = getBoundingRect();

    sf::Vector2f positionSprite = this->getPosition();

    // If the position was not in our button rect
    if(
            position.x < (positionSprite.x + boundsButton.width) &&
            position.x >  positionSprite.x &&
            position.y < (positionSprite.y + boundsButton.height) &&
            position.y >  positionSprite.y )
    {
        // If we are in the box
        return true;
    }
    else
    {
        // If we not
        return false;
    }
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(mSprite, states);
    target.draw(mRectangleBackground, states);
    target.draw(mText, states);
}

void Button::changeTexture(Type buttonType)
{
    sf::IntRect textureRect(0, 50*buttonType, 200, 50);
    mSprite.setTextureRect(textureRect);
}


}   // End of namespace
