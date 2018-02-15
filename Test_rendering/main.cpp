#include <iostream>
#include <vector>

#include "object_one.hpp"
#include "object_two.hpp"
#include "stack.hpp"

using namespace std;

int main()
{
    cout << "Hello World" << endl;

    std::unique_ptr<Object_one> object1 (new Object_one());
    std::unique_ptr<Object_two> object2 (new Object_two());

    Stack<Object> stack;

    stack.insert(std::move(object1));
    stack.insert(std::move(object2));

    stack.tellType();

    auto& objectFound(stack.get(1));

    objectFound.tell();

    if(typeid(objectFound) == typeid(Object_one))
    {
        Object_one& objectOne(dynamic_cast<Object_one&>(objectFound));
        objectOne.tellMe();
    }
}

