#ifndef RESOURCEIDENTIFIERS_HPP
#define RESOURCEIDENTIFIERS_HPP

// Forward declaration of SFML classes
namespace sf
{
    class Texture;
    class Font;
}

class IOFile;
class TextureSpliter;

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

typedef ResourceHolder<sf::Texture, Textures::ID>           TextureHolder;
typedef ResourceHolder<TextureSpliter, Textures::ID>        TextureSplite;
typedef ResourceHolder<sf::Font, Fonts::ID>                 FontHolder;
typedef ResourceHolder<IOFile, File::ID>                    FileHolder;

#endif // RESOURCEIDENTIFIERS_HPP
