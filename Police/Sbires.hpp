#ifndef SBIRES_HPP
#define SBIRES_HPP

// CORE Library
#include "ObjectBox.hpp"
#include "Animation.hpp"
#include "Category.hpp"
#include "DataTables.hpp"
#include "Tasks.hpp"

// STD library
#include <iostream>


class Sbires : public ObjectBox
{
public:
    explicit                Sbires(const sf::Texture& texture, Category_Sbires::ID category = Category_Sbires::NoneSbire);
                            Sbires();

    void                    setLifePoints(int& lifeP);
    const int&              getLifePoints() const;

    void                    setWorkPoints(int& workP);
    const int&              getWorkPoints() const;

    void                    setDefensePoints(int& defenseP);
    const int&              getDefensePoints() const;

    void                    setAttackPoints(int& attackP);
    const int&              getAttackPoints() const;

    void                    setTask(std::shared_ptr<Tasks> tasks);
    std::shared_ptr<Tasks>& getTask();

    void                    setCategorySbire(Category_Sbires::ID category);
    Category_Sbires::ID     getCategorySbire() const;

    virtual void            printData();

    virtual void            update(sf::Time dt, CommandQueue& commands);

    virtual void            draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual bool            isDestroyed() const;

private:
    std::shared_ptr<Tasks>              mTask;
    std::vector<SbireData>              mData;
    Animation                           mCurrentAnimation;
    Category_Sbires::ID                 mCategory;
    bool                                mInMovment;
    sf::Texture                         mTexture;
    bool                                mIsDestroyed;




};

#endif // SBIRES_HPP
