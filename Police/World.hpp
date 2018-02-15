#ifndef WORLD_H
#define WORLD_H

// ALL about resources
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "IOFile.hpp"
#include "TextureSpliter.hpp"
#include "SceneNode.hpp"
#include "SpriteNode.hpp"
#include "Utility.hpp"
#include "Container.hpp"
#include "Button.hpp"
#include "Tuile.hpp"
#include "RectangleRoom.hpp"
#include "Ui.hpp"

// System SFML
#include <SFML/System/Time.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

// STD library
#include <array>
#include <queue>
#include <string>
#include <vector>

// Configuration
#define PIX_WORLD 16


//Forward declaration
namespace sf
{
    class RenderWindow;

}

class World : private sf::NonCopyable
{

// Some of typdef to make my code more readable
public:
        typedef std::vector<sf::Vector2f> ArrayVector2f;
        typedef std::vector<std::unique_ptr<SpriteNode>> ArraySpriteNode;
        typedef std::map<unsigned int,sf::IntRect> ArrayUi;

        explicit                            World(sf::RenderWindow& window, FontHolder& fonts);
        void                                update(sf::Time dt);
        void                                draw();
        bool                                handleEvent(const sf::Event &event);
        void                                viewEvent(const sf::Event &event);


// Some fonctions to work my world
private:
        void                                loadTextures();
        void                                loadFile();

        const sf::Vector2i                  getPositionMouse();

        void                                buildScene();
        void                                checkView();

        ArrayVector2f                       splitWorldBounds();
        void                                buildFile();

// Private enum to manage my layouts
private:
        enum Layer
        {
            Background,
            //Building,
            //Object,
            LayerCount
        };

// Variables I need in my object
private:
        sf::RenderWindow&                   mTarget;
        sf::RenderTexture                   mSceneTexture;
        sf::RenderTexture                   mUiTexture;
        sf::View                            mWorldView;
        sf::View                            mUiView;
        TextureHolder                       mTextures;
        FontHolder&                         mFonts;
        FileHolder                          mFile;
        TextureSplite                       mTexturesSplite;
        sf::IntRect                         mWorldBounds;
        ArrayVector2f                       mGridWorld;
        sf::Vector2f                        mSpawnPosition;

        SceneNode                           mSceneGraph;
        std::array<SceneNode*, LayerCount>  mSceneLayers;

        bool                                mBuildState;
        BUILD_OBJECT::RectangleRoom         mBuildRoom;

        Ui                                  mUi;


};

#endif // WORLD_H
