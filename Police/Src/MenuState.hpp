#ifndef MENUSTATE_H
#define MENUSTATE_H

// GAME Library
#include "State.hpp"
#include "Container.hpp"
#include "Button.hpp"
#include "ProgressBar.hpp"
#include "Animation.hpp"


// SFML Library
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Text.hpp"


class MenuState : public State
{
public:
    MenuState(StateStack& stack, Context context);
    virtual void                    draw();
    virtual bool                    update(sf::Time dt);
    virtual bool                    handleEvent(const sf::Event &event); 
    
private:
    sf::Sprite                      mBackgroundSprite;
    GUI::Container                  mGuiContainer;
    Animation                       mAnimation;
    
};

#endif // MENUSTATE_H
