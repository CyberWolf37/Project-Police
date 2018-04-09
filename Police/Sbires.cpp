#include "Sbires.hpp"

Sbires::Sbires(const sf::Texture& texture, Category_Sbires::ID category)
    :mData(initializeSbireData(texture))
    ,mCurrentAnimation(mData[category].moveLeft)
    ,mInMovment(false)
    ,mCategory(category)
    ,mIsDestroyed(false)
    ,mTask()
{
    getCurrentAnimation().setRepeating(true);
}

Sbires::Sbires()
    :mData()
    ,mCurrentAnimation()
    ,mInMovment(false)
    ,mCategory(Category_Sbires::ID::NoneSbire)
    ,mIsDestroyed(false)
    ,mTask()
{
    getCurrentAnimation().setRepeating(true);
}

void Sbires::setLifePoints(int &lifeP)
{
    mData[mCategory].lifePoints = lifeP;
}

const int &Sbires::getLifePoints() const
{
    return mData[mCategory].lifePoints;
}

void Sbires::setWorkPoints(int &workP)
{
    mData[mCategory].workPoints = workP;
}

const int &Sbires::getWorkPoints() const
{
    return mData[mCategory].workPoints;
}

void Sbires::setDefensePoints(int &defenseP)
{
    mData[mCategory].defensePoints = defenseP;
}

const int &Sbires::getDefensePoints() const
{
    return mData[mCategory].defensePoints;
}

void Sbires::setAttackPoints(int &attackP)
{
    mData[mCategory].attackPoints = attackP;
}

const int &Sbires::getAttackPoints() const
{
    return mData[mCategory].attackPoints;
}

void Sbires::setTask(std::shared_ptr<Tasks> tasks)
{
    mTask = std::move(tasks);
}

std::shared_ptr<Tasks> &Sbires::getTask()
{
    return mTask;
}

void Sbires::setCategorySbire(Category_Sbires::ID category)
{
    mCategory = category;
}

Category_Sbires::ID Sbires::getCategorySbire() const
{
    return mCategory;
}

void Sbires::printData()
{
    std::cout << std::endl;
    std::cout << "Life points : " << getLifePoints() << std::endl <<
                 "Work points : " << getWorkPoints() << std::endl <<
                 "Defense points : " << getDefensePoints() << std::endl <<
                 "Attack points : " << getAttackPoints() << std::endl;
}

void Sbires::updateCurrent(sf::Time dt, CommandQueue &commands)
{
    mCurrentAnimation.setPosition(this->getPosition());
    mCurrentAnimation.update(dt);
}

void Sbires::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    mCurrentAnimation.draw(target,states);
}

bool Sbires::isDestroyed() const
{
    return mIsDestroyed;
}

void Sbires::setCurrentAnimation(Animation &animation)
{
    mCurrentAnimation = animation;
}

Animation &Sbires::getCurrentAnimation()
{
    return mCurrentAnimation;
}


