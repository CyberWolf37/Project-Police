#include "LoadingState.hpp"
#include "Utility.h"
#include "ResourceHolder.hpp"

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/View.hpp"

LoadingState::LoadingState(StateStack& stack, Context context)
    : State(stack, context)
    , mLoadingTask()
    , mProgressBar(*context.fonts,*context.textures)
{

    // Set the Window
    sf::RenderWindow& window = *getContext().window;
    sf::Font& font = context.fonts->get(Fonts::Main);
    sf::Vector2f viewSize = window.getView().getSize();

    // Set the progressBar
    mProgressBar.setPosition(viewSize.x/2,viewSize.y/2);
    mProgressBar.setValue(0);

    mLoadingTask.execute();
}

void LoadingState::draw()
{
    sf::RenderWindow& window = *getContext().window;

    // For Test
    window.clear(sf::Color::Blue);

    window.setView(window.getDefaultView());

    window.draw(mProgressBar);
}

bool LoadingState::update(sf::Time dt)
{
    // Update the progress bar from the remote task or finish it
    if (mLoadingTask.isFinished())
    {
        requestStackPop();
        requestStackPush(States::Game);
    }
    else
    {
        setCompletion(mLoadingTask.getCompletion());
    }
    return true;
}

bool LoadingState::handleEvent(const sf::Event &event)
{
    return true;
}

void LoadingState::setCompletion(float percent)
{
    if (percent > 1.f) // clamp
    {
        percent = 1.f;
    }

    mProgressBar.setValue(percent*100);
}
