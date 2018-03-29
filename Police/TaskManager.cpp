#include "TaskManager.hpp"

TaskManager::TaskManager(SbiresStack& sbiresStack)
    :mSbiresStack(sbiresStack)
    ,mTasksStack()
{

}

TaskManager::TaskManager(SbireManager &sbireManager)
    :mSbiresStack(sbireManager.getSbireStack())
    ,mTasksStack()
{

}

void TaskManager::insertTask(TaskManager::TaskPtr tasksPtr)
{
    mTasksStack.push_back(tasksPtr);
}

TaskManager::TaskPtr TaskManager::getTask(TaskManager::SbirePtr sbirePtr) const
{
    return sbirePtr->getTask();
}

TaskManager::SbiresStack &TaskManager::getSbire(TaskManager::TaskPtr taskPtr) const
{
    return taskPtr->getSbiresAssigne();
}

void TaskManager::update(sf::Time dt)
{
    for(auto& child : mTasksStack)
    {
        child->update(dt);
    }
}
