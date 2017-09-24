#ifndef RESOURCEIDENTIFIERS_HPP
#define RESOURCEIDENTIFIERS_HPP

// Forward declaration of SFML classes
namespace sf
{
    class Texture;
    class Font;
}

class IOFile;
class TextureHolding;

namespace Textures
{
    enum ID
    {
        TitleScreen,
        TileSetGround,
        TileSetBuild,
        Buttons,
        ProgressBar,
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

// Forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<TextureHolding, Textures::ID>   TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::ID>         FontHolder;
typedef ResourceHolder<IOFile, File::ID>            FileHolder;

#endif // RESOURCEIDENTIFIERS_HPP
