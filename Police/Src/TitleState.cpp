#include <TitleState.hpp>
#include <Utility.hpp>
#include <ResourceHolder.hpp>

#include <SFML/Graphics/RenderWindow.hpp>

// For test
#include <iostream>

TitleState::TitleState(StateStack& stack, Context context)
    : State(stack, context)
    , mText()
    , mShowText(false)
    , mTextEffectTime(sf::Time::Zero)
{
    mBackgroundSprite.setTexture(context.textures->get(Textures::TitleScreen));

    mText.setFont(context.fonts->get(Fonts::Main));
    mText.setString("Press any key to start");
    mText.setCharacterSize(50u);
    mText.setColor(sf::Color::Black);
    centerOrigin(mText);
    mText.setPosition(context.window->getView().getSize() / 2.f);
}

void TitleState::draw()
{
    sf::RenderWindow& window = *getContext().window;
    window.draw(mBackgroundSprite);

    if(mShowText)
    {
        window.draw(mText);
    }
}

bool TitleState::update(sf::Time dt)
{
    mTextEffectTime += dt;
    if(mTextEffectTime >= sf::seconds(1.f))
    {
        mShowText = !mShowText;
        mTextEffectTime = sf::Time::Zero;
    }
    return true;
}

bool TitleState::handleEvent(const sf::Event &event)
{
    // If any key is pressed, trigger the next screen
    if (event.type == sf::Event::KeyReleased)
    {
        requestStackPop();
        requestStackPush(States::Menu);
    }

    return true;
}
