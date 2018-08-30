// GAME Library
#include <Application.hpp>
#include <State.hpp>
#include <Stateidentifiers.hpp>
#include <TitleState.hpp>
//#include <GameState.hpp>
#include <MenuState.hpp>
#include <LoadingState.hpp>
#include <SettingsState.hpp>

// Init Time per frame
const sf::Time Application::TimePerFrame = sf::seconds(1.f/60.f);

Application::Application()
    : mWindow(sf::VideoMode(1280,912), "Police", sf::Style::Close)
    , mTextures()
    , mFonts()
    , mStateStack(State::Context(mWindow, mTextures, mFonts))
{
    mTextures.load(Textures::TitleScreen,"Media/Textures/Title_Screen.png");
    mTextures.load(Textures::Explosion,"Media/Textures/Explosion.png");
    mFonts.load(Fonts::Main, "Media/Font/BreeSerif.ttf");
    mTextures.load(Textures::Buttons,"Media/Textures/ButtonsPolice.png" );
    mTextures.load(Textures::ProgressBar,"Media/Textures/ProgressBar.png");
    mTextures.load(Textures::PoliceAnimation,"Media/Textures/police_sprites.png");

    mWindow.setKeyRepeatEnabled(false);

    registerStates();
    mStateStack.pushState(States::Title);

}

void Application::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (mWindow.isOpen())
    {
        sf::Time dt = clock.restart();
        timeSinceLastUpdate += dt;
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;

            processInput();
            update(TimePerFrame);

            // Check inside this loop because stack might be empty before update() call
            if (mStateStack.isEmpty())
                mWindow.close();
        }

        render();
    }
}

void Application::processInput()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        mStateStack.handleEvent(event);

        if(event.type == sf::Event::Closed)
        {
            mWindow.close();
        }
    }
}

void Application::update(sf::Time dt)
{
    mStateStack.update(dt);
}

void Application::render()
{
    mWindow.clear();

    mStateStack.draw();

    mWindow.setView(mWindow.getDefaultView());

    mWindow.display();
}

void Application::registerStates()
{
    mStateStack.registerState<TitleState>(States::Title);
    //mStateStack.registerState<GameState>(States::Game);
    mStateStack.registerState<MenuState>(States::Menu);
    mStateStack.registerState<LoadingState>(States::Loading);
    mStateStack.registerState<SettingsState>(States::Settings);
}
