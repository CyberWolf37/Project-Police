#ifndef WORKERSBIRE_HPP
#define WORKERSBIRE_HPP

#include "Sbires.hpp"


class WorkerSbire : public Sbires
{
public:
    WorkerSbire(const sf::Texture& textures);

    void        printData();
};

#endif // WORKERSBIRE_HPP
