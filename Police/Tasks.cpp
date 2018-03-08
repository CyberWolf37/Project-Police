#include "Tasks.hpp"

Tasks::Tasks(Category_Tasks::ID category)
    :mSbireAssigne()
    ,mPositionAssigne()
    ,mCategoryTask(category)
    ,mTime(sf::Time::Zero)
{

}

void Tasks::assigneSbire(std::shared_ptr<Sbires> sbireAssigne)
{
    auto CpySbire = sbireAssigne;
    mSbireAssigne.push_back(std::move(CpySbire));
}

std::vector<sf::Vector2i>& Tasks::getSbiresAssigne() const
{
    return mSbireAssigne;
}

void Tasks::setTime(sf::Time time)
{
    mTime = time;
}

sf::Time& Tasks::getTime() const
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

void Tasks::setPosition(std::vector<sf::Vector2i> positionStack)
{
    for(size_t i = 0; i < positionStack.size(); i++)
    {
        mPositionAssigne.insert(std::pair<sf::Vector2i,bool>(positionStack[i],false));
    }
}

void Tasks::setPosition(sf::Vector2i position)
{
    mPositionAssigne.insert(pair<sf::Vector2i,bool>(position,false));
}

sf::Vector2i& Tasks::getDisponiblePosition() const
{
    for(auto& found : mPositionAssigne)
    {
        if(found.second() == false)
        {
            return found;
        }
    }
}






