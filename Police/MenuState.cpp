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

MenuState::MenuState(StateStack& stack, Context context)
    : State(stack, context)
    , mGuiContainer(*context.window)
{
    sf::Texture& texture = context.textures->get(Textures::TitleScreen);
    mBackgroundSprite.setTexture(texture);

    auto playButton = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
    playButton->setPosition(100,500);
    playButton->setText("Play");
    playButton->setCallback([this] ()
    {
        requestStackPop();
        requestStackPush(States::Loading);
    });

    auto testProgressBar = std::make_shared<GUI::ProgressBar>(*context.fonts, *context.textures);
    testProgressBar->setPosition(500,500);
    testProgressBar->setSelectable(true);
    testProgressBar->setValue(50);


    auto settingsButton = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
    settingsButton->setPosition(100,550);
    settingsButton->setText("Settings");
    settingsButton->setCallback([this] ()
    {
        //requestStackPush(States::Settings);
        std::cout << "Nothing by default" << std::endl;
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
    mGuiContainer.pack(testProgressBar);

}

void MenuState::draw()
{
    sf::RenderWindow& window = *getContext().window;
    window.setView(window.getDefaultView());
    window.draw(mBackgroundSprite);
    window.draw(mGuiContainer);

}

bool MenuState::update(sf::Time dt)
{
    return true;
}

bool MenuState::handleEvent(const sf::Event &event)
{
    mGuiContainer.handleEvent(event);
    return false;
}
