#ifndef TASKMANAGER_HPP
#define TASKMANAGER_HPP

// CORE LIBRARY
#include "Sbires.hpp"
#include "Category.hpp"
#include "Tasks.hpp"
#include "SbireManager.hpp"

// SFML LIBRARY
#include "SFML/System/Time.hpp"
#include "SFML/System/Vector2.hpp"

// STD LIBRARY
#include <vector>
#include <map>
#include <memory>


class TaskManager
{
public:

    typedef std::shared_ptr<Tasks>      TaskPtr;
    typedef std::shared_ptr<Sbires>     SbirePtr;

    typedef std::vector<Sbires*>        SbiresStack;
    typedef std::vector<TaskPtr>        TasksStack;


    TaskManager(SbiresStack& sbiresStack);
    TaskManager(SbireManager& sbireManager);

    void            insertTask(TaskPtr tasksPtr);
    TaskPtr         getTask(SbirePtr sbirePtr) const;
    SbiresStack&    getSbire(TaskPtr taskPtr) const;

    void            update(sf::Time dt);

private:

    SbiresStack&    mSbiresStack;
    TasksStack      mTasksStack;


};

#endif // TASKMANAGER_HPP
