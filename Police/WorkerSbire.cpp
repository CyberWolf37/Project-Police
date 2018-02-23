#include "WorkerSbire.hpp"

WorkerSbire::WorkerSbire()
    :Sbires(Category_Sbires::WorkerSbire)
{

}

void WorkerSbire::printData()
{
    std::cout << std::endl;
    std::cout << "I'm a Worker Sbire" << std::endl <<
                 "Life points : " << getLifePoints() << std::endl <<
                 "Work points : " << getWorkPoints() << std::endl <<
                 "Defense points : " << getDefensePoints() << std::endl <<
                 "Attack points : " << getAttackPoints() << std::endl;

}
