#include "object.hpp"

Object::Object()
    :m_isActive(true)
    ,m_bounds()
{

}

const bool& Object::isActive() const
{
    return m_isActive;
}

void Object::getType()
{
    std::cout << typeid(*this).name() << std::endl;
}
