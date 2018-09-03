// Game Library
#include "MenuState.hpp"
#include "Button.hpp"
#include "ProgressBar.hpp"
#include "Utility.hpp"
#include "ResourceHolder.hpp"

// SFML Library
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/View.hpp"

// Std Library
#include <iostream>

// Debug
#include <QDebug>

MenuState::MenuState(StateStack& stack, Context context)
    : State(stack, context)
    , mGuiContainer(*context.window)
    , mAnimation(context.textures->get(Textures::PoliceAnimation))
{
    sf::Texture& texture = context.textures->get(Textures::TitleScreen);
    mBackgroundSprite.setTexture(texture);

    auto playButton = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
    playButton->setPosition(100,500);
    playButton->setText("Play");
    playButton->setCallback([this] ()
    {
        //requestStackPop();
        //requestStackPush(States::Game);
    });

    auto settingsButton = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
    settingsButton->setPosition(100,550);
    settingsButton->setText("Settings");
    settingsButton->setCallback([this] ()
    {
        requestStackPush(States::Settings);
    });

    auto exitButton = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
    exitButton->setPosition(100,600);
    exitButton->setText("Exit");
    exitButton->setCallback ([this] ()
    {
        requestStackPop();
    });

    mGuiContainer.pack(playButton);
    mGuiContainer.pack(settingsButton);
    mGuiContainer.pack(exitButton);
}

void MenuState::draw()
{
    sf::RenderWindow& window = *getContext().window;
    window.setView(window.getDefaultView());
    window.draw(mBackgroundSprite);
    window.draw(mGuiContainer);
    window.draw(mAnimation);

}

bool MenuState::update(sf::Time dt)
{
    mAnimation.update(dt);
    return true;
}

bool MenuState::handleEvent(const sf::Event &event)
{   
    sf::Vector2f position(0.f,0.f);
    mGuiContainer.handleEvent(event,position);
    return false;
}
