#include "Ui.hpp"



Ui::Ui(sf::RenderWindow &window, FontHolder &fonts, TextureHolder &texture, SceneNode &SceneGraph)
    :mTarget(window)
    ,mUiView(mTarget.getView())
    ,mFonts(fonts)
    ,mTextures(texture)
    ,mSceneGraph(SceneGraph)
    ,mUiTexture()
    ,mMainContainer(window)

{
    // Layer texture for user interface
    mUiTexture.create(mTarget.getSize().x, mTarget.getSize().y);
}

void Ui::update(sf::Time dt)
{

}

void Ui::draw()
{
    // Drawing the User interface
    mUiTexture.setView(mUiView);
    mUiTexture.draw(mMainContainer);
    mUiTexture.display();

    // Finaly draw the texture Scene
    mTarget.draw(sf::Sprite(mUiTexture.getTexture()));
}

bool Ui::handleEvent(const sf::Event &event)
{
    mMainContainer.handleEvent(event,sf::Mouse::getPosition(mTarget));
}

void Ui::buildUi()
{
    // Get the size of the defaultView
    sf::Vector2f centerView = mUiView.getSize();

    // Position button 1
    sf::Vector2f positionButton_1;
    positionButton_1.x = 0;
    positionButton_1.y = centerView.y - 50;

    // Position button 2
    sf::Vector2f positionButton_2 = positionButton_1;
    positionButton_2.x += 200;

    // Set button 1 for main container
    auto buildButton = std::make_shared<GUI::Button>(mFonts, mTextures);
    buildButton->setPosition(positionButton_1.x,positionButton_1.y);
    buildButton->setText("Build");
    buildButton->setCallback([this] ()
    {
        std::cout << "Pick the button Build" << std::endl;

    });

    // Set button 2 for main container
    auto exitButton = std::make_shared<GUI::Button>(mFonts, mTextures);
    exitButton->setPosition(positionButton_2.x,positionButton_2.y);
    exitButton->setText("Quit");
    exitButton->setCallback([this] ()
    {
        mTarget.close();
    });

    mMainContainer.pack(buildButton);
    mMainContainer.pack(exitButton);
}