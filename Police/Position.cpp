#include "Position.hpp"

Position::Position()
    :mObject(nullptr)
    ,mPositionRaw(0.f,0.f)
    ,mIsMoving(false)
    ,mTimeMoving(sf::Time::Zero)
    ,mElapsedTime(sf::Time::Zero)
    ,mPositionInitial()
    ,mCurrentDirection(Category_Direction::ID::None)
{

}

Position::Position(const Position &copy)
    :mObject()
    ,mPositionRaw(copy.getPositionRaw())
    ,mIsMoving(false)
    ,mTimeMoving(sf::Time::Zero)
    ,mElapsedTime(sf::Time::Zero)
    ,mPositionInitial()
    ,mCurrentDirection(copy.getCurrentDirection())
{

}

Position::Position(sf::Transformable &object)
    :mObject(&object)
    ,mPositionRaw(mObject->getPosition())
    ,mIsMoving(false)
    ,mTimeMoving(sf::Time::Zero)
    ,mElapsedTime(sf::Time::Zero)
    ,mPositionInitial()
    ,mCurrentDirection(Category_Direction::ID::None)
{
}

void Position::setPositionRaw(const sf::Vector2f &positionSend)
{
    if(mObject != nullptr)
    {
        mObject->setPosition(positionSend);
    }
    else
    {
        mPositionRaw    = positionSend;
    }
}

const sf::Vector2f& Position::getPositionRaw() const
{
    if(mObject != nullptr)
    {
        return mObject->getPosition();
    }
    else
    {
        return mPositionRaw;
    }
}

void Position::setPositionTuile(const sf::Vector2i &positionSend)
{
    if(mObject != nullptr)
    {
        mObject->setPosition(calculePositionRaw(positionSend));
    }
    else
    {
        mPositionRaw    = calculePositionRaw(positionSend);
    }
}

const sf::Vector2i Position::getPositionTuile()
{
    if(mObject != nullptr)
    {
        return calculePositionTuile(mObject->getPosition());
    }
    else
    {
        return calculePositionTuile(mPositionRaw);
    }
}

const Category_Direction::ID &Position::getCurrentDirection() const
{
    return mCurrentDirection;
}

void Position::moveTuile(Category_Direction::ID direction, const sf::Time &dt)
{
    if(!mIsMoving)
    {
        mTimeMoving = dt;
        mCurrentDirection = direction;
        mElapsedTime = sf::Time::Zero;

        if(mObject != nullptr)
        {
             mPositionInitial = mObject->getPosition();
        }
        else
        {
            mPositionInitial = mPositionRaw;
        }

        mIsMoving = true;
    }
}

void Position::update(const sf::Time &dt)
{
    if(mIsMoving && mElapsedTime < mTimeMoving)
    {
        mElapsedTime += dt;

        if(mObject != nullptr)
        {
            mObject->setPosition(calculePositionMove());
        }
        else
        {
            mPositionRaw = calculePositionMove();
        }
    }
    else if(mElapsedTime >= mTimeMoving)
    {
        if(mObject != nullptr)
        {
            mObject->setPosition(calculePositionMoveFinish());
        }
        else
        {
            mPositionRaw = calculePositionMoveFinish();
        }

        // Reset attribut
        mCurrentDirection = Category_Direction::ID::None;
        mTimeMoving = sf::Time::Zero;
        mElapsedTime = sf::Time::Zero;
        mPositionInitial = sf::Vector2f(0.f,0.f);
        mIsMoving = false;
    }
}

void Position::afficher(std::ostream &flux) const
{
    flux << " Position X : " << getPositionRaw().x
         << " Position Y : " << getPositionRaw().y;
}

std::ostream &Position::operator<<(std::ostream &flux)
{
    this->afficher(flux);
}

Position &Position::operator=(Position &left, Position &right)
{
    left.setPositionRaw(right.getPositionRaw());
    return left;
}

const sf::Vector2i Position::calculePositionTuile(const sf::Vector2f& positionRaw)
{
    sf::Vector2i result;

    // set Position X
    result.x = static_cast<int>(std::floor(positionRaw.x / PIXEL));


    // set Position Y
    result.y = static_cast<int>(std::floor(positionRaw.y / PIXEL));

    return result;
}

const sf::Vector2f Position::calculePositionRaw(const sf::Vector2i &positionTuile)
{
    sf::Vector2f result;

    // set Position X
    result.x = static_cast<float>((positionTuile.x * PIXEL) + (PIXEL/2));


    // set Position Y
    result.y = static_cast<float>((positionTuile.y * PIXEL) + (PIXEL/2));

    return result;
}

const sf::Vector2f Position::calculePositionMove()
{
    sf::Vector2f result = mPositionInitial;

    if(mCurrentDirection == Category_Direction::ID::Up)
    {
        result.y = (PIXEL * mElapsedTime.asSeconds())- mPositionInitial.y;

        return result;
    }
    else if(mCurrentDirection == Category_Direction::ID::Down)
    {
        result.y = (PIXEL * mElapsedTime.asSeconds())+ mPositionInitial.y;

        return result;
    }
    else if(mCurrentDirection == Category_Direction::ID::Left)
    {
        result.x = (PIXEL * mElapsedTime.asSeconds())- mPositionInitial.x;

        return result;
    }
    else if(mCurrentDirection == Category_Direction::ID::Right)
    {
        result.x = (PIXEL * mElapsedTime.asSeconds())+ mPositionInitial.x;

        return result;
    }
    else
    {
        return result;
    }


}

const sf::Vector2f Position::calculePositionMoveFinish()
{
    sf::Vector2f result = mPositionInitial;

    if(mCurrentDirection == Category_Direction::ID::Up)
    {
        result.y = PIXEL - mPositionInitial.y;

        return result;
    }
    else if(mCurrentDirection == Category_Direction::ID::Down)
    {
        result.y = PIXEL + mPositionInitial.y;

        return result;
    }
    else if(mCurrentDirection == Category_Direction::ID::Left)
    {
        result.x = PIXEL - mPositionInitial.x;

        return result;
    }
    else if(mCurrentDirection == Category_Direction::ID::Right)
    {
        result.x = PIXEL + mPositionInitial.x;

        return result;
    }
    else
    {
        return result;
    }
}
