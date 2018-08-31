#ifndef WORLD_H
#define WORLD_H

// Settings
#include <Settings.hpp>

// ALL about resources
#include <ResourceHolder.hpp>
#include <ResourceIdentifiers.hpp>
#include <IOFile.hpp>
#include <TextureSpliter.hpp>
#include <SceneManager.hpp>
#include <Utility.hpp>
#include <Container.hpp>
#include <Button.hpp>
#include <ObjectBox.hpp>
#include <Ui.hpp>
#include <CommandQueue.hpp>
#include <Category.hpp>
#include <foreach.hpp>
#include <Position.hpp>

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
#include <algorithm>
#include <cmath>
#include <limits>

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

        void                                checkView();

        ArrayVector2f                       splitWorldBounds();
        void                                buildFile();

// Variables I need in my object
private:
        sf::RenderWindow&                   mTarget;
        Ui                                  mUi;

        sf::RenderTexture                   mSceneTexture;
        sf::View                            mWorldView;
        TextureHolder                       mTextures;
        FontHolder&                         mFonts;
        FileHolder                          mFile;
        TextureSplite                       mTexturesSplite;

        sf::IntRect                         mWorldBounds;
        Position                            mSpawnPosition;
        CommandQueue                        mComandeQueue;

        SceneManager                        mSceneGraph;
};

#endif // WORLD_H
