#ifndef POSITION_HPP
#define POSITION_HPP

// SFML Library
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/Transformable.hpp"
#include "SFML/System/Time.hpp"
#include "Settings.hpp"
#include "Category.hpp"

// STD Library
#include <memory>
#include <math.h>
#include <ostream>


class Position
{
public:
    Position();
    Position(const Position& copy);
    Position(sf::Transformable &object);
    Position(float& x,float& y);

    void                            setPositionRaw(const sf::Vector2f& positionSend);
    const sf::Vector2f              &getPositionRaw() const;

    void                            setPositionTuile(const sf::Vector2i& positionSend);
    const sf::Vector2i              getPositionTuile();

    const Category_Direction::ID&   getCurrentDirection() const;

    void                            moveTuile(Category_Direction::ID direction,const sf::Time& dt);
    void                            update(const sf::Time& dt);

    void                            afficher(std::ostream &flux) const;

    void                            operator<<(std::ostream& flux);
    void                            operator=(Position& right);

private:
    const sf::Vector2i              calculePositionTuile(const sf::Vector2f& positionRaw);
    const sf::Vector2f              calculePositionRaw(const sf::Vector2i& positionTuile);
    const sf::Vector2f              calculePositionMove();
    const sf::Vector2f              calculePositionMoveFinish();



private:
    std::unique_ptr<sf::Transformable>      mObject;
    sf::Vector2f                            mPositionRaw;

    bool                                    mIsMoving;
    sf::Time                                mTimeMoving;
    sf::Time                                mElapsedTime;
    sf::Vector2f                            mPositionInitial;
    Category_Direction::ID                  mCurrentDirection;
};

#endif // POSITION_HPP
