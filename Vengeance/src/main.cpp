#include <iostream>



template <typename T1 , typename T2 >
T1 Max(T1 a, T2 b)
{
	return b < a ? a : b;
}

template <typename T = int>
void Foo(T t = 1)
{
	std::cout << "calling foo" << std::endl;
}

int main(){

	int value1 = 1;
	double value2 = 6.9;

	

	std::cout << "Max : " << Max<double>(value1, value2) << std::endl;

}