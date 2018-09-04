#ifndef APPLICATION_H
#define APPLICATION_H

// GAME Library
#include <ResourceHolder.hpp>
#include <ResourceIdentifiers.hpp>
#include <StateStack.hpp>

// SFML Library
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>


class Application
{
public:
    Application();
    void                                run();

private:
    void                                processInput();
    void                                update(sf::Time dt);
    void                                render();

    void                                registerStates();

private:
    static const sf::Time               TimePerFrame;
    sf::RenderWindow                    mWindow;
    TextureHolder                       mTextures;
    FontHolder                          mFonts;

    StateStack                          mStateStack;
};

#endif // APPLICATION_H
