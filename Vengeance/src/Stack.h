#pragma once
#include <vector> 
#include <cassert>

template <typename T>
class Stack
{
public:
	void Push(const T& element)
	{
		elements.push_back(element);
	}
	void Pop()
	{
		assert(!Empty());
		elements.pop_back();
	}
	const T& Top() const
	{
		assert(!Empty());
		return elements.back();
	}
	bool Empty() const
	{
		return elements.empty();
	}
private:
	std::vector<T> elements;
};