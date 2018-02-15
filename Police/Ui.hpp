#ifndef UI_HPP
#define UI_HPP

// ALL about resources
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "TextureSpliter.hpp"
#include "SceneNode.hpp"
#include "SpriteNode.hpp"
#include "Utility.hpp"
#include "Container.hpp"
#include "Button.hpp"
#include "RectangleRoom.hpp"

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

//Forward declaration
namespace sf
{
    class RenderWindow;

}

class Ui : private sf::NonCopyable
{
public:
    explicit            Ui(sf::RenderWindow& window, FontHolder& fonts, TextureHolder& texture, SceneNode& SceneGraph);
    void                update(sf::Time dt);
    void                draw();
    bool                handleEvent(const sf::Event &event);
    void                buildUi();

private:

    sf::RenderWindow&   mTarget;
    sf::View            mUiView;
    FontHolder&         mFonts;
    TextureHolder&      mTextures;
    SceneNode&          mSceneGraph;
    sf::RenderTexture   mUiTexture;
    GUI::Container      mMainContainer;


};

#endif // UI_HPP
