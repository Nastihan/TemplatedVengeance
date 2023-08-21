#pragma once
#include <vector>
#include <cassert>
#include <iostream>

template <typename T>
class Stack {
public:
    virtual void Push(const T& element) {
        elements.push_back(element);
    }

    virtual void Pop() {
        assert(!Empty());
        elements.pop_back();
    }

    virtual const T& Top() const {
        assert(!Empty());
        std::cout << "Main Stack" << std::endl;
        return elements.back();
    }

    virtual bool Empty() const {
        return elements.empty();
    }

protected:
    std::vector<T> elements;
};

//template <>
//class Stack<std::string> : public Stack<std::string> 
//{
//public:
//    void CustomFunction() {
//        std::vector<std::string>& myElements = this->elements;
//        std::cout << "Specialized Stack" << std::endl;
//        // Use or manipulate myElements vector as needed
//    }
//};
