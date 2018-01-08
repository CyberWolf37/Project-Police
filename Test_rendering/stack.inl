#include <algorithm>
#include <typeinfo>
#include <iostream>

template<typename Resource>
void Stack<Resource>::insert(std::unique_ptr<Resource> resource)
{
    m_stack.push_back(std::move(resource));
}

template<typename Resource>
void Stack<Resource>::tellType()
{
    for(size_t idx = 0; idx < m_stack.size(); idx++)
    {
        m_stack[idx]->getType();
    }
}

template<typename Resource>
Resource& Stack<Resource>::get(const int idx)
{
    auto& found = m_stack[idx];
    return *found;
}
