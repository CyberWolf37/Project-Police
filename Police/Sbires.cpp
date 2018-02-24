#include "Sbires.hpp"

Sbires::Sbires(const sf::Texture& texture, Category_Sbires::ID category)
    :mData(initializeSbireData(texture))
    ,mCurrentAnimation()
    ,mInMovment(false)
    ,mCategory(category)
{

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
    getCurrentAnimation().setRepeating(true);
    getCurrentAnimation().update(dt);
}

void Sbires::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    mCurrentAnimation.draw(target,states);
}

void Sbires::setCurrentAnimation(Animation &animation)
{
    mCurrentAnimation = animation;
}

Animation &Sbires::getCurrentAnimation()
{
    return mCurrentAnimation;
}


