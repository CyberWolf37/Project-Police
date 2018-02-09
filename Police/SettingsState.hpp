 #ifndef SETTINGSSTATE_H
#define SETTINGSSTATE_H

// GAME Library
#include "State.hpp"

// SFML Library
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Text.hpp"

class SettingsState : public State
{
public:
    SettingsState(StateStack& stack, Context context);

    virtual void                    draw();
    virtual bool                    update(sf::Time dt);
    virtual bool                    handleEvent(const sf::Event& event);

private:
    sf::Sprite                      mBackgroundSprite;
};

#endif // SETTINGSSTATE_H
