#ifndef WORLDCONTROLLER_H
#define WORLDCONTROLLER_H

// All about resources
#include <ResourceHolder.hpp>
#include <ResourceIdentifiers.hpp>
#include <Container.hpp>
#include <Button.hpp>

// Systeme SFML
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


class WorldController : private sf::NonCopyable
{

    // Function to manage my Gui
public:

    explicit                WorldController(sf::RenderWindow& window, FontHolder& fonts);
    void                    update(sf::Time dt);
    void                    draw();

    void                    buildControl();

private:

    sf::RenderWindow&       mWindow;
    sf::View                mView;
    FontHolder&             mFont;
    TextureHolder           mTexture;

    // Container

    GUI::Container          mMainContainer;

};

#endif // WORLDCONTROLLER_H
