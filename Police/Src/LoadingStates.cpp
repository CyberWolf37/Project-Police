#include "LoadingState.hpp"
#include "Utility.h"
#include "ResourceHolder.hpp"

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/View.hpp"

LoadingState::LoadingState(StateStack& stack, Context context)
    : State(stack, context)
    , mWindow(*context.window)
    , mLoadingTask()
    , mProgressBar(*context.fonts,*context.textures)
{

    // Set the Window
    sf::Vector2f viewSize = mWindow.getView().getSize();

    // Set the progressBar
    mProgressBar.setPosition((viewSize.x/2)-100,(viewSize.y/2)-25);
    mProgressBar.setValue(0);

    mLoadingTask.execute();
}

void LoadingState::draw()
{
    sf::RenderWindow& window = *getContext().window;

    // For Test
    window.clear();

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
        return true;
    }
    else
    {
        setCompletion(mLoadingTask.getCompletion());
    }
    return true;
}

bool LoadingState::handleEvent(const sf::Event &event)
{
    if(event.type == sf::Event::Closed)
    {

    }
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
