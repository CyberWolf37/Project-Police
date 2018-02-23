#ifndef SBIRES_HPP
#define SBIRES_HPP

#include "SceneNode.hpp"
#include "Animation.hpp"
#include "Category.hpp"
#include "DataTables.hpp"

// STD library
#include <iostream>


class Sbires : public SceneNode
{
public:
    explicit            Sbires(Category_Sbires::ID category = Category_Sbires::NoneSbire);

    void                setLifePoints(int& lifeP);
    const int&          getLifePoints() const;

    void                setWorkPoints(int& workP);
    const int&          getWorkPoints() const;

    void                setDefensePoints(int& defenseP);
    const int&          getDefensePoints() const;

    void                setAttackPoints(int& attackP);
    const int&          getAttackPoints() const;

    //void              setTask(Task& task);
    //const Task&       getTask();

    void                setCategorySbire(Category_Sbires::ID category);
    Category_Sbires::ID getCategorySbire() const;

    virtual void        printData();

    virtual void        updateCurrent(sf::Time dt, CommandQueue& commands);

    virtual void        draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void        drawCurrent (sf::RenderTarget& target, sf::RenderStates states) const;


protected:

    virtual void        setCurrentAnimation(Animation& animation);
    virtual Animation&  getCurrentAnimation();

private:

    //Task              mTask
    std::vector<SbireData>              mData;
    Animation                           mCurrentAnimation;
    Category_Sbires::ID                 mCategory;
    bool                                mInMovment;




};

#endif // SBIRES_HPP
