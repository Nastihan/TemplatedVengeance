#include <iostream>
#include <type_traits>
#include "Stack.h"


class Part
{
public:
	Part()
	{
		std::cout << "part class constructor" << std::endl;
	}
	Part(int i)
		:i(i)
	{
		std::cout << "part class constructor" << std::endl;
	}

private:
	int i;
};

class Whole
{
public:
	Whole(std::string name)
		: name(name)
	{
		std::cout << "Whole class constructor" << std::endl;
	}

private:
	std::string name;
	Part part;

};


template <typename T> 
struct IsPointer
{
	static constexpr bool value = false;
};

template <typename T> 
struct IsPointer<T*>
{
	static constexpr bool value = true;
};

template <typename T>
void Print1(T t)
{
	if constexpr(IsPointer<T>::value)
	{
		std::cout << *t;
	}
	else
	{
		std::cout << t;
	}

}

template <typename A, typename B, typename C>
void Print3(A a, B b, C c)
{
	Print1(a);
	std::cout << ", ";
	Print1(b);
	std::cout << ", ";
	Print1(c);
	std::cout << '\n';
}


int main()
{

	int a = 10;
	Print3(&a, 2, 5);


}