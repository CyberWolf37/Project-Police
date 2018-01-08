#ifndef STACK_HPP
#define STACK_HPP

//STD Library
#include <vector>
#include <cassert>
#include <memory>
#include <stdexcept>
#include <functional>
#include <algorithm>

template <typename Resource>
class Stack
{

    typedef std::vector<std::unique_ptr<Resource>> stackResource;

public:
    Stack():m_stack() {}

    void            insert(std::unique_ptr<Resource> resource);
    Resource&       get(const int idx);
    void            tellType();

private:
    stackResource   m_stack;
};

#include "stack.inl"
#endif // STACK_HPP
