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
    for(size_t i = 0; i < positionStack.size(); i++)
    {
        sf::Vector2i found {positionStack[i]};
        positionStack.erase(positionStack.begin()+i);
        //mPositionAssigne.insert(std::make_pair(found,false));
        //mPositionAssigne[found] = false;
    }
}

void Tasks::setPosition(sf::Vector2i position)
{
    //mPositionAssigne.insert(std::pair<sf::Vector2i,bool>(position,false));
    //mPositionAssigne[position] = false;
}

const sf::Vector2i& Tasks::getDisponiblePosition()
{
    for(const auto it : mPositionAssigne)
    {
        if(it.second == false)
        {
            return it.first;
        }
    }
}






