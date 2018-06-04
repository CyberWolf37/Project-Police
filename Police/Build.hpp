#ifndef BUILD_H
#define BUILD_H

// Core library
#include <ObjectBox.hpp>
#include "Category.hpp"
#include "ResourceHolder.hpp"

// SFML Library
#include "SFML/System/Clock.hpp"
#include "SFML/System/Time.hpp"
#include "SFML/Window/Event.hpp"


namespace BUILD_OBJECT
{
class Build : public ObjectBox
{
public:

                                Build(Category_Build::Type category = Category_Build::Type::None);

    virtual unsigned int        getCategory() const;

    virtual sf::IntRect         getBoundingRect() const;
    virtual void                setBoundingRect(const sf::IntRect bounds);

    bool                        isSelected() const;
    virtual void                select();
    virtual void                deselect();

    bool                        isActive() const;
    virtual void                activate();
    virtual void                deactivate();

    void                        setProgressTime(const sf::Time time = sf::Time::Zero);
    const sf::Time              getProgressTime() const;
    const sf::Time              getProgressClock() const;
    void                        startClock();
    bool                        checkIsFinish() const;

    virtual bool                checkColision(sf::Vector2i& position) = 0;

private:

    virtual void                updateCurrent(sf::Time dt, CommandQueue& commands) const;


private:

    bool                        mIsSelected;
    bool                        mIsActive;

    Category_Build::Type        mCategory;

    sf::IntRect                 mBounds;

    sf::Time                    mProgressionTime;
    bool                        mProgressFinish;
    sf::Clock                   mClock;


};

}   // End Of namespace BUILD_OBJECT

#endif // BUILD_H
