#pragma once
#include <chrono>

class NastihanTimer
{
public:
	NastihanTimer();
	float Peek();
	float Mark();

private:
	std::chrono::time_point<std::chrono::high_resolution_clock> last;

};