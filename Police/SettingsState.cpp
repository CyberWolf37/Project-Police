#include <SettingsState.hpp>
#include <Utility.hpp>
#include <ResourceHolder.hpp>

#include <SFML/Graphics/RenderWindow.hpp>

// For test
#include <iostream>

SettingsState::SettingsState(StateStack& stack, Context context)
    : State(stack, context)
{
    mBackgroundSprite.setTexture(context.textures->get(Textures::TitleScreen));
}

void SettingsState::draw()
{
    sf::RenderWindow& window = *getContext().window;
    window.draw(mBackgroundSprite);
}

bool SettingsState::update(sf::Time dt)
{
}

bool SettingsState::handleEvent(const sf::Event &event)
{
    // If any key is pressed, trigger the next screen
    if (event.type == sf::Event::MouseLeft)
    {
        requestStackPop();
    }

    return true;
}
