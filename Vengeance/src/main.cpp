#include <iostream>



template <typename T>
T Max(T a, T b)
{
	return b < a ? a : b;
}

int main(){

	auto value1 = "a";
	auto value2 = "b";

	std::cout << "Max : " << Max(value1, value2) << std::endl;

}