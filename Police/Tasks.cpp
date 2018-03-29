#include "Tasks.hpp"

Tasks::Tasks(Category_Tasks::ID category)
    :mSbireAssigne()
    ,mCategoryTask(category)
    ,mPositionAssigne()
    ,mTime(sf::Time::Zero)
{

}

void Tasks::assigneSbire(std::shared_ptr<Sbires> sbireAssigne)
{
    auto CpySbire = sbireAssigne;
    mSbireAssigne.push_back(std::move(CpySbire));
}

std::vector<std::shared_ptr<Sbires>>& Tasks::getSbiresAssigne()
{
    return mSbireAssigne;
}

bool Tasks::removeSbire(std::shared_ptr<Sbires> sbireRemove)
{
    for(std::vector<std::shared_ptr<Sbires>>::iterator it = mSbireAssigne.begin(); it != mSbireAssigne.end();it++)
    {
        if(*it == sbireRemove)
        {
            mSbireAssigne.erase(it);
            return true;
        }
    }
    return false;
}

void Tasks::setTime(sf::Time time)
{
    mTime = time;
}

sf::Time& Tasks::getTime()
{
    return mTime;
}

void Tasks::setCategory(Category_Tasks::ID category)
{
    mCategoryTask = category;
}

Category_Tasks::ID Tasks::getCategory() const
{
    return mCategoryTask;
}

void Tasks::setPosition(std::vector<sf::Vector2i>& positionStack)
{
    for(auto& position : positionStack )
    {
        auto ptrPosition = std::make_shared<sf::Vector2i>(position);
        mPositionAssigne[std::move(ptrPosition)] = false;
    }
}

void Tasks::setPosition(sf::Vector2i position)
{
    auto ptrPosition = std::make_shared<sf::Vector2i>(position);
    mPositionAssigne[std::move(ptrPosition)] = false;
}

void Tasks::setPosition(std::shared_ptr<sf::Vector2i> position)
{
    mPositionAssigne[std::move(position)] = false;
}

std::shared_ptr<sf::Vector2i> Tasks::getDisponiblePosition()
{
    for(auto& it : mPositionAssigne)
    {
        if(it.second == false)
        {
            return it.first;
        }
    }
}

void Tasks::update(sf::Time dt)
{
    // Do nothing for now
}






