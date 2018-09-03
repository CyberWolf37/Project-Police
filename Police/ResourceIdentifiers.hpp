#ifndef RESOURCEIDENTIFIERS_HPP
#define RESOURCEIDENTIFIERS_HPP

#include "ObjectBox.hpp"
#include "Sbires.hpp"
#include "Tuile.hpp"

// Forward declaration of SFML classes
namespace sf
{
    class Texture;
    class Font;
}

class IOFile;
class TextureSpliter;
class Animation;

namespace Textures
{
    enum ID
    {
        TitleScreen,
        TileSetGround,
        TileSetBuild,
        Buttons,
        ProgressBar,
        Explosion,
        PoliceAnimation,
    };

}

namespace File
{
    enum ID
    {
        FirstLevel,
    };
}

namespace Fonts
{
    enum ID
    {
        Main,
    };
}

namespace Animations
{
    enum ID
    {
        // For sbire worker
        WorkerSbireMoveUp,
        WorkerSbireMoveDown,
        WorkerSbireMoveRight,
        WorkerSbireMoveLeft,

        // For sbire Office
        OfficeSbireMoveUp,
        OfficeSbireMoveDown,
        OfficeSbireMoveRight,
        OfficeSbireMoveLeft,
    };
}

// Forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID>           TextureHolder;
typedef ResourceHolder<TextureSpliter, Textures::ID>        TextureSplite;
typedef ResourceHolder<sf::Font, Fonts::ID>                 FontHolder;
typedef ResourceHolder<IOFile, File::ID>                    FileHolder;
typedef ResourceHolder<Animation, Animations::ID>           AnimationHolder;

// Forward declaration and few type definition for SceneNode
template <typename Resource>
class SceneNode;

typedef SceneNode<ObjectBox>    NodeObject;
typedef SceneNode<Sbires>       NodeSbire;
typedef SceneNode<Tuile>        NodeTuile;

#endif // RESOURCEIDENTIFIERS_HPP
