#ifndef COMMANDQUEUE_H
#define COMMANDQUEUE_H

// Game Library
#include "Command.hpp"

// STD Library
#include <queue>


class CommandQueue
{
public:

    CommandQueue();

    void                        push(const Command& command);
    Command                     pop();
    bool                        isEmpty() const;

private:
    std::queue<Command>         mQueue;
};

#endif // COMMANDQUEUE_H
