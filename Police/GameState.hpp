#ifndef GAMESTATE_H
#define GAMESTATE_H

// GAME Library
#include <State.hpp>
#include <World.hpp>

// SFML Library
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

class GameState : public State
{
public:

    GameState(StateStack& stack, Context context);
    virtual void                draw();
    virtual bool                update(sf::Time dt);
    virtual bool                handleEvent(const sf::Event &event);

private:

    World                       mWorld;


};

#endif // GAMESTATE_H
