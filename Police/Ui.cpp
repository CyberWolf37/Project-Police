#include "Ui.hpp"



Ui::Ui(sf::RenderWindow &window, FontHolder &fonts, TextureHolder &texture, SceneNode &SceneLayers)
    :mTarget(window)
    ,mUiView(mTarget.getView())
    ,mFonts(fonts)
    ,mTextures(texture)
    ,mSceneGraph(SceneLayers)
    ,mUiTexture()
    ,mMainContainer(window)
    ,mSbireManager(mSceneGraph)
    ,mTaskManager(mSbireManager)

{
    // Layer texture for user interface
    mUiTexture.create(mTarget.getSize().x, mTarget.getSize().y);

    // load Texture
    mTextures.load(Textures::PoliceAnimation,"Media/Textures/police_sprites.png");

    // SbireManager set texture
    mSbireManager.setTexture(mTextures.get(Textures::PoliceAnimation));

}

void Ui::update(sf::Time dt)
{
    mTaskManager.update(dt);
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
    viewEvent(Event);
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
    buildButton->setText("Sbire");
    buildButton->setCallback([this] ()
    {
        std::cout << "Pick the button Sbire" << std::endl;
        sf::Vector2i positionSbire (800,808);
        mSbireManager.createSbire(Category_Sbires::ID::WorkerSbire,positionSbire);

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

void Ui::viewEvent(const sf::Event &event)
{
    if(event.type == sf::Event::KeyPressed)
    {

        switch(event.key.code)
        {
            case sf::Keyboard::Z:
            mUiView.move(0.f,-PIXEL);
            break;

            case sf::Keyboard::Up:
            mUiView.move(0.f,-PIXEL);
            break;

            case sf::Keyboard::Q:
            mUiView.move(-PIXEL,0.f);
            break;

            case sf::Keyboard::Left:
            mUiView.move(-PIXEL,0.f);
            break;

            case sf::Keyboard::D:
            mUiView.move(PIXEL,0.f);
            break;

            case sf::Keyboard::Right:
            mUiView.move(PIXEL,0.f);
            break;

            case sf::Keyboard::S:
            mUiView.move(0.f,PIXEL);
            break;

            case sf::Keyboard::Down:
            mUiView.move(0.f,PIXEL);
            break;

            default:
            break;

        }
    }
}
