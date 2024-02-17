#include <iostream>
#include <type_traits>
#include <vector>
#include <wtypes.h>
#include <tuple>

#include "NastihanTimer.h"
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

// IsPointer
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

// StripPointer
template <typename T>
struct StripPointer 
{
	using type = T;
};

template <typename T>
struct StripPointer<T*>
{
	using type = T;
};

template <typename T>
void Print1(T t)
{
	using tWithoutPtr = StripPointer<T>::type;
	if constexpr(IsPointer<T>::value && std::is_floating_point<tWithoutPtr>::value)
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


template <bool condition, typename Then, typename Else>
struct If;

template <typename Then, typename Else>
struct If<true, Then, Else>
{
	using type = Then;
};

template<typename Then, typename Else>
struct If<false, Then, Else>
{
	using type = Else;
};

bool RuntimeContains(const std::string& search,const std::vector<std::string>& container, UINT startFrom = 0)
{
	if (search == container.at(startFrom))
		return true;
	else {
		if (startFrom == container.size() - 1)
			return false;
		else
			return RuntimeContains(search, container, startFrom + 1);
	}
}

template <typename Search, typename Tuple,UINT startFrom = 0>
struct Contains : ::If
	< (std::is_same<std::tuple_element_t<startFrom, Tuple>, Search>::value),
	// Then
	std::true_type,
	// Else
	typename ::If
		<
		// Condition
		(startFrom == std::tuple_size<Tuple>::value - 1),
		// Then
		std::false_type,
		// Else
		Contains<Search, Tuple, startFrom + 1>
		>::type
	>::type
{};




int main()
{
	std::tuple<int, float, std::string, UINT> tuple;
	//std::vector<std::string> vec{ "bool", "double", "int" };

	NastihanTimer timer{};

	//std::cout << std::boolalpha << RuntimeContains("bool", vec) << std::endl;

	//std::cout << std::boolalpha <<std::is_same<float, ::If<(1 < 2), float, double>::type>::value << std::endl;
	
	std::cout << std::boolalpha << Contains<double, decltype(tuple)>::value<< std::endl;

	std::cout << timer.Mark() << std::endl;


}


