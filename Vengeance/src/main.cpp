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
void Print1(T t)
{
	std::cout << t;
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
	Print3(1, 2, 5);


}