// Library project
#include <World.hpp>
#include <foreach.hpp>

// Library SFML
#include <SFML/Graphics.hpp>

// Library STD
#include <algorithm>
#include <cmath>
#include <limits>
#include <string>

// For debug
#include "QDebug"

// Initialise object
World::World(sf::RenderWindow &window, FontHolder& fonts)
    : mTarget(window)
    , mSceneTexture()
    , mUiTexture()
    , mWorldView(window.getDefaultView())
    , mUiView(mWorldView.getCenter(),mWorldView.getSize())
    , mTextures()
    , mTexturesSplite()
    , mFonts(fonts)
    , mSceneGraph()
    , mSceneLayers()
    , mWorldBounds(0.f,0.f,PIX_WORLD*100,PIX_WORLD*100) // World Bounds for 100 tuile to 16 pix
    , mFile()
    , mSpawnPosition(0,0)
    , mMainContainer(mTarget)
{
    // Set Key repeted True
    mTarget.setKeyRepeatEnabled(true);

    // Layer texture for draw world
    mSceneTexture.create(mTarget.getSize().x, mTarget.getSize().y);

    // Layer texture for User interface
    mUiTexture.create(mTarget.getSize().x, mTarget.getSize().y);

    // Load decor
    loadTextures();
    loadFile();

    // Build the entire scene
    buildScene();

    // Build File
    buildFile();

    buildUI();

    // Prepare the view
    mWorldView.setCenter(784,1408);
    checkView();

}

// Update the world
void World::update(sf::Time dt)
{
}

// Drawing the world of the game
void World::draw()
{
    // Drawing the world ...
    mSceneTexture.setView(mWorldView);
    mSceneTexture.clear();
    mSceneTexture.draw(mSceneGraph);
    mSceneTexture.display();


    // Drawing the User interface
    mUiTexture.setView(mUiView);
    mUiTexture.draw(mMainContainer);
    mUiTexture.display();


    // Finaly draw the texture Scene
    mTarget.clear();
    mTarget.draw(sf::Sprite(mSceneTexture.getTexture()));
    mTarget.draw(sf::Sprite(mUiTexture.getTexture()));


}

bool World::handleEvent(const sf::Event &event)
{
    mMainContainer.handleEvent(event);
    mSceneGraph.handleEvent(event,mTarget,mWorldView);
    viewEvent(event);

    return false;
}

void World::viewEvent(const sf::Event &event)
{
    if(event.type == sf::Event::KeyPressed)
    {

        switch(event.key.code)
        {
            case sf::Keyboard::Z:
            mWorldView.move(0.f,-10.f);

            break;

            case sf::Keyboard::Up:
            mWorldView.move(0.f,-10.f);
            break;

            case sf::Keyboard::Q:
            mWorldView.move(-10.f,0.f);
            break;

            case sf::Keyboard::Left:
            mWorldView.move(-10.f,0.f);
            break;

            case sf::Keyboard::D:
            mWorldView.move(10.f,0.f);
            break;

            case sf::Keyboard::Right:
            mWorldView.move(10.f,0.f);
            break;

            case sf::Keyboard::S:
            mWorldView.move(0.f,10.f);
            break;

            case sf::Keyboard::Down:
            mWorldView.move(0.f,10.f);
            break;

            default:
            break;

        }
        checkView();
    }
}

/*CommandQueue& World::getCommandQueue()
{
    return mCommandQueue;
}*/

// Loading all textures we need for the game
void World::loadTextures()
{
    // Texture for tileset
    mTextures.load(Textures::TileSetGround, "Media/Textures/TileSetGround.png");
    mTexturesSplite.load(Textures::TileSetGround, "Media/Textures/TileSetGround.png");

    // Texture for tileset
    mTextures.load(Textures::Buttons,"Media/Textures/ButtonsPolice.png" );
}

// Load the file how we have some layout
void World::loadFile()
{
    // Load the file
    mFile.load(File::FirstLevel, "Media/Map/First_Level.txt");

}

// Build the different layout in a game
void World::buildScene()
{
    // Initialize the different layers
    for (std::size_t i = 0; i < LayerCount; i++)
    {
        Category::Layers category = (i == Background) ? Category::SceneGroundLayer : Category::None;
        SceneNode::Ptr layer(new SceneNode(category));
        mSceneLayers[i] = layer.get();

        mSceneGraph.attachChild(std::move(layer));
    }
}

// Move the view if is cross the bounds
void World::checkView()
{
    // Get the float rect
    sf::IntRect mWorldViewRect;

    // Set the right position of view
    mWorldViewRect.left = mWorldView.getCenter().x - (mWorldView.getSize().x/2);
    mWorldViewRect.top  = mWorldView.getCenter().y - (mWorldView.getSize().y/2);
    mWorldViewRect.width = mWorldView.getSize().x;
    mWorldViewRect.height = mWorldView.getSize().y;

    // initialise float rect for get intersection
    sf::IntRect intersection;

    // Intersection
    const bool checkIntersect = mWorldBounds.intersects(mWorldViewRect,intersection);

    // Some calcul of surface to use it
    float surfaceIntersect = intersection.width * intersection.height;
    float surfaceView = mWorldView.getSize().x * mWorldView.getSize().y;

    // If check
    if(checkIntersect && surfaceIntersect != surfaceView)
    {
        if(mWorldViewRect.top == intersection.top && mWorldViewRect.left == intersection.left)
        {
            mWorldView.move(-(mWorldViewRect.width - intersection.width),-(mWorldViewRect.height - intersection.height));
        }

        else if(mWorldViewRect.top < intersection.top || mWorldViewRect.left < intersection.left)
        {
            mWorldView.move((mWorldViewRect.width - intersection.width),(mWorldViewRect.height - intersection.height));
        }
    }
}

// Split the world for get position
World::ArrayVector2f World::splitWorldBounds()
{
    // Counter for x , Y And ArrayFloatRect
    size_t countX = mWorldBounds.width/PIX_WORLD;
    size_t countY = mWorldBounds.height/PIX_WORLD;

    // Array for save and Index to manage my boucle
    World::ArrayVector2f array;
    sf::Vector2f index(0,0);

    // Split the world bounds axe X
    for(size_t i = 0 ; i < countY ; i++)
    {
        // Axe y
        for(size_t j = 0 ; j < countX; j++)
        {
            // si j == 0 on remet à zero l'index
            if(j == 0)
            {
                index.x = 0;

                // Add in array
                array.push_back(index);
            }
            else
            {
                // On ajoute 16 sur X
                index.x += PIX_WORLD;

                // Ensuite on ajoute l'index
                array.push_back(index);
            }
        }

        // On ajoute 16 sur y
        index.y += PIX_WORLD;
    }

    // return world split vector
    return array;
}

// split the ressources to get an array of rect
World::ArrayUi World::splitResourceSprite(sf::Texture& texture)
{
    // Get world number of tile
    size_t countX = texture.getSize().x/PIX_WORLD;
    size_t countY = texture.getSize().y/PIX_WORLD;

    // Counter to split tile
    unsigned int counter = 0;

    // For save the split world in arrayUI
    World::ArrayUi array;

    // Index
    sf::IntRect index(0,0,PIX_WORLD,PIX_WORLD);

    // Split the texture
    for(size_t i = 0;i < countY; i++)
    {
        for(size_t j = 0;j < countX; j++ , counter++)
        {
            // si j = 0 on remet à zero l'index
            if(j == 0)
            {
                index.left = 0;

                // Add in ArrayUI
                array[counter] = index;
            }
            else
            {
                // On ajoute 16 sur X
                index.left += PIX_WORLD;

                // Ensuite on ajoute l'index
                array[counter] = index;
            }
        }

        // On ajoute 16 sur y
        index.top += PIX_WORLD;
    }

    // Return Array
    return array;

}

// Build the file we get
void World::buildFile()
{
    // Get the split texture
    TextureSpliter& texture = mTexturesSplite.get(Textures::TileSetGround);
    sf::Vector2u pix(16,16);
    texture.split(pix);
    TextureSpliter::MapPtr PtrMap (texture.getSplitMap());

    // Get the current world
    ArrayVector2f arrayPosition (splitWorldBounds());

    IOFile::File* file = mFile.get(File::FirstLevel).getFile();


    // Set the Tuile
    for(size_t i = 0; i < file->Layouts[0]->layerTile.size() ; i++)
    {
        std::shared_ptr<Tuile> Ptuile (new Tuile(*(*PtrMap)[file->Layouts[0]->layerTile[i]]));
        Ptuile->setPosition(arrayPosition[i]);
        mSceneLayers[Background]->attachChild(std::move(Ptuile));
    }

}

// Build User interface
void World::buildUI()
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

    // Position button 3

    // Set button 1 for main container
    auto buildButton = std::make_shared<GUI::Button>(mFonts, mTextures);
    buildButton->setPosition(positionButton_1.x,positionButton_1.y);
    buildButton->setText("Build");
    buildButton->setCallback([this] ()
    {
        std::cout << "Pick the button Build" << std::endl;

    });

    // Set button 2 for main container
    auto shareButton = std::make_shared<GUI::Button>(mFonts, mTextures);
    shareButton->setPosition(positionButton_2.x,positionButton_2.y);
    shareButton->setText("Quit");
    shareButton->setCallback([this] ()
    {
        mTarget.close();
    });

    mMainContainer.pack(buildButton);
    mMainContainer.pack(shareButton);

}


