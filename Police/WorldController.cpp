#include <WorldController.hpp>

#include <algorithm>
#include <cmath>
#include <limits>

WorldController::WorldController(sf::RenderWindow &window, FontHolder& fonts)
    : mWindow(window)
    , mFont(fonts)
    , mMainContainer()
    , mView(window.getView())
{
    // Set texture
    mTexture.load(Textures::Buttons,"Media/Textures/Buttons.png" );
    // Build button
    buildControl();

}

void WorldController::update(sf::Time dt)
{

}

void WorldController::draw()
{
    // function base
    //mWindow.clear();
    mWindow.draw(mMainContainer);
    mWindow.display();
}

void WorldController::buildControl()
{
    // Get the size of the defaultView
    sf::Vector2f sizeView = mView.getSize();

    // Position button 1
    sf::Vector2f positionButton_1;
    positionButton_1.x = 50;
    positionButton_1.y = sizeView.y -100;

    // Position button 2

    // Position button 3

    // Set button for main container
    auto buildButton = std::make_shared<GUI::Button>(mFont, mTexture);
    buildButton->setPosition(positionButton_1.x,positionButton_1.y);
    buildButton->setText("Build");
    buildButton->setCallback([this] ()
    {
        // ...
    });

    mMainContainer.pack(buildButton);


}

