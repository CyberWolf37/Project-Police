#include "Build.hpp"
#include "Category.hpp"

namespace BUILD_OBJECT
{

Build::Build(Category_Build::Type category)
    : mIsSelected(false)
    , mIsActive(false)
    , mCategory(category)
    , mProgressionTime(sf::Time::Zero)
    , mBounds()
{

}

unsigned int Build::getCategory() const
{
    return mCategory;
}

sf::IntRect Build::getBoundingRect() const
{
    return mBounds;
}

void Build::setBoundingRect(const sf::IntRect bounds)
{
    mBounds = bounds;
}

bool Build::isSelected() const
{
    return mIsSelected;
}

void Build::select()
{
    mIsSelected = true;
}

void Build::deselect()
{
    mIsSelected = false;
}

bool Build::isActive() const
{
    return mIsActive;
}

void Build::activate()
{
    mIsActive = true;
}

void Build::deactivate()
{
    mIsActive = false;
}

void Build::setProgressTime(const sf::Time time)
{
    mProgressFinish = false;
    mProgressionTime = time;
}

const sf::Time Build::getProgressTime() const
{
    return mProgressionTime;
}

const sf::Time Build::getProgressClock() const
{
    return mClock.getElapsedTime();
}

void Build::startClock()
{
    mClock.restart();
}

bool Build::checkIsFinish() const
{
    if(getProgressClock() >= mProgressionTime && !mProgressFinish)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Build::updateCurrent(sf::Time dt, CommandQueue &commands) const
{
    // Do nothing By default
}



} // End of namespace BUILD_OBJECT
