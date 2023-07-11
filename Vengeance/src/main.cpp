#include <iostream>
#include <type_traits>


template <typename T1, typename T2 >
std::common_type_t<T1,T2> Max(T1 a, T2 b)
{
	return b < a ? a : b;
}



int main(){

	int value1 = 1;
	float value2 = 6.2;



	

	std::cout << "Max : " << Max(value1, value2) << std::endl;

	auto temp = Max(value1, value2);

}