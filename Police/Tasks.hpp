#ifndef TASKS_H
#define TASKS_H

// CORE LIBRARY
#include "Sbires.hpp"
#include "Category.hpp"

// SFML LIBRARY
#include "SFML/System/Time.hpp"
#include "SFML/System/Vector2.hpp"

// STD LIBRARY
#include <vector>
#include <map>
#include <memory>


class Tasks
{
public:

    Tasks(Category_Tasks::ID category = Category_Tasks::ID::None);

    void                                    assigneSbire(std::shared_ptr<Sbires> sbireAssigne);
    std::vector<std::shared_ptr<Sbires>>&   getSbiresAssigne();
    bool                                    removeSbire(std::shared_ptr<Sbires> sbireRemove);

    void                                    setTime(sf::Time time);
    sf::Time&                               getTime();

    void                                    setCategory(Category_Tasks::ID category);
    Category_Tasks::ID                      getCategory() const;

    void                                    setPosition(std::vector<sf::Vector2i>& positionStack);
    void                                    setPosition(sf::Vector2i position);
    const sf::Vector2i&                     getDisponiblePosition();

    void                                    update(sf::Time dt);

private:

    std::vector<std::shared_ptr<Sbires>>    mSbireAssigne;
    std::map<sf::Vector2i,bool>             mPositionAssigne;
    Category_Tasks::ID                      mCategoryTask;
    sf::Time                                mTime;

};

#endif // TASKS_H
